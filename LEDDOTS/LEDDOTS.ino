//-----------------------------------------------//
// SPARK CORE Adafruit_WS2801 LIBRARY & EXAMPLE  //
//===============================================//
// Copy this into a new application at:          //
// https://www.spark.io/build and go nuts!       //
// Read comments in APPLICATION.CPP section for  //
// Hookup details!                               //
//-----------------------------------------------//
// Technobly / BDub - Jan 9th, 2014              //
//===============================================//
//
// NOTE: Library is kind of hacked up at the moment
// Look for 4 '////' for all areas commented out
// Will clean up after verified working!
//
// YES, I'M SHOUTING! xD

// Code From: https://gist.github.com/technobly/8339548#file-sparkcorews2801-cpp-L370

/* ========================== Adafruit_WS2801.h =========================== */

///#if (ARDUINO >= 100)
//// #include <Arduino.h>
///#else
/// #include <WProgram.h>
/// #include <pins_arduino.h>
///#endif

// Not all LED pixels are RGB order; 36mm type expects GRB data.
// Optional flag to constructors indicates data order (default if
// unspecified is RGB).  As long as setPixelColor/getPixelColor are
// used, other code can always treat 'packed' colors as RGB; the
// library will handle any required translation internally.
#define WS2801_RGB 0
#define WS2801_GRB 1

#define boolean bool

class Adafruit_WS2801 {

 public:

  // Configurable pins:
  Adafruit_WS2801(uint16_t n, uint8_t dpin, uint8_t cpin, uint8_t order=WS2801_RGB);
  Adafruit_WS2801(uint16_t x, uint16_t y, uint8_t dpin, uint8_t cpin, uint8_t order=WS2801_RGB);
  // Use SPI hardware; specific pins only:
  Adafruit_WS2801(uint16_t n, uint8_t order=WS2801_RGB);
  // Empty constructor; init pins/strand length/data order later:
  Adafruit_WS2801();
  // Release memory (as needed):
  ~Adafruit_WS2801();

  void
    begin(void),
    show(void),
    setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b),
    setPixelColor(uint16_t n, uint32_t c),
    setPixelColor(uint16_t x, uint16_t y, uint8_t r, uint8_t g, uint8_t b),
    setPixelColor(uint16_t x, uint16_t y, uint32_t c),
    updatePins(uint8_t dpin, uint8_t cpin), // Change pins, configurable
    updatePins(void), // Change pins, hardware SPI
    updateLength(uint16_t n), // Change strand length
    updateOrder(uint8_t order); // Change data order
  uint16_t
    numPixels(void);
  uint32_t
    getPixelColor(uint16_t n);

 private:

  uint16_t
    numLEDs,
    width,     // used with matrix mode
    height;    // used with matrix mode
  uint8_t
    *pixels,   // Holds color values for each LED (3 bytes each)
    rgb_order, // Color order; RGB vs GRB (or others, if needed in future)
    clkpin    , datapin,     // Clock & data pin numbers
    clkpinmask, datapinmask; // Clock & data PORT bitmasks
  volatile uint8_t
    *clkport  , *dataport;   // Clock & data PORT registers
  void
    alloc(uint16_t n),
    startSPI(void);
  boolean
    hardwareSPI, // If 'true', using hardware SPI
    begun;       // If 'true', begin() method was previously invoked
};

/* ========================== Adafruit_WS2801.cpp =========================== */

////#include "SPI.h"
////#include "Adafruit_WS2801.h"

// Example to control WS2801-based RGB LED Modules in a strand or strip
// Written by Adafruit - MIT license
/*****************************************************************************/

// Constructor for use with hardware SPI (specific clock/data pins):
Adafruit_WS2801::Adafruit_WS2801(uint16_t n, uint8_t order) {
  rgb_order = order;
  alloc(n);
  updatePins();
}

// Constructor for use with arbitrary clock/data pins:
Adafruit_WS2801::Adafruit_WS2801(uint16_t n, uint8_t dpin, uint8_t cpin, uint8_t order) {
  rgb_order = order;
  alloc(n);
  updatePins(dpin, cpin);
}

// Constructor for use with a matrix configuration, specify w, h for size of matrix
// assumes configuration where string starts at coordinate 0,0 and continues to w-1,0, w-1,1
// and on to 0,1, 0,2 and on to w-1,2 and so on. Snaking back and forth till the end.
// other function calls with provide access to pixels via an x,y coordinate system
Adafruit_WS2801::Adafruit_WS2801(uint16_t w, uint16_t h, uint8_t dpin, uint8_t cpin, uint8_t order) {
  rgb_order = order;
  alloc(w * h);
  width = w;
  height = h;
  updatePins(dpin, cpin);
}

// Allocate 3 bytes per pixel, init to RGB 'off' state:
void Adafruit_WS2801::alloc(uint16_t n) {
  begun   = false;
  numLEDs = ((pixels = (uint8_t *)calloc(n, 3)) != NULL) ? n : 0;
}

// via Michael Vogt/neophob: empty constructor is used when strand length
// isn't known at compile-time; situations where program config might be
// read from internal flash memory or an SD card, or arrive via serial
// command.  If using this constructor, MUST follow up with updateLength()
// and updatePins() to establish the strand length and output pins!
// Also, updateOrder() to change RGB vs GRB order (RGB is default).
Adafruit_WS2801::Adafruit_WS2801(void) {
  begun     = false;
  numLEDs   = 0;
  pixels    = NULL;
  rgb_order = WS2801_RGB;
  updatePins(); // Must assume hardware SPI until pins are set
}

// Release memory (as needed):
Adafruit_WS2801::~Adafruit_WS2801(void) {
  if (pixels != NULL) {
    free(pixels);
  }
}

// Activate hard/soft SPI as appropriate:
void Adafruit_WS2801::begin(void) {
  if(hardwareSPI == true) {
    startSPI();
  } else {
    pinMode(datapin, OUTPUT);
    pinMode(clkpin , OUTPUT);
  }
  begun = true;
}

// Change pin assignments post-constructor, switching to hardware SPI:
void Adafruit_WS2801::updatePins(void) {
  hardwareSPI = true;
  datapin     = clkpin = 0;
  // If begin() was previously invoked, init the SPI hardware now:
  if(begun == true) startSPI();
  // Otherwise, SPI is NOT initted until begin() is explicitly called.

  // Note: any prior clock/data pin directions are left as-is and are
  // NOT restored as inputs!
}

// Change pin assignments post-constructor, using arbitrary pins:
void Adafruit_WS2801::updatePins(uint8_t dpin, uint8_t cpin) {

  if(begun == true) { // If begin() was previously invoked...
    // If previously using hardware SPI, turn that off:
    if(hardwareSPI == true) SPI.end();
    // Regardless, now enable output on 'soft' SPI pins:
    pinMode(dpin, OUTPUT);
    pinMode(cpin, OUTPUT);
  } // Otherwise, pins are not set to outputs until begin() is called.

  // Note: any prior clock/data pin directions are left as-is and are
  // NOT restored as inputs!

  hardwareSPI = false;
  datapin     = dpin;
  clkpin      = cpin;
  ////clkport     = portOutputRegister(digitalPinToPort(cpin));
  ////clkpinmask  = digitalPinToBitMask(cpin);
  ////dataport    = portOutputRegister(digitalPinToPort(dpin));
  ////datapinmask = digitalPinToBitMask(dpin);
}

// Enable SPI hardware and set up protocol details:
void Adafruit_WS2801::startSPI(void) {
    SPI.begin();
    SPI.setBitOrder(MSBFIRST);
    SPI.setDataMode(SPI_MODE0);
    SPI.setClockDivider(SPI_CLOCK_DIV128); // 1 MHz max, else flicker (set to 72MHz/128 = 562.5kHz)
}

uint16_t Adafruit_WS2801::numPixels(void) {
  return numLEDs;
}

// Change strand length (see notes with empty constructor, above):
void Adafruit_WS2801::updateLength(uint16_t n) {
  if(pixels != NULL) free(pixels); // Free existing data (if any)
  // Allocate new data -- note: ALL PIXELS ARE CLEARED
  numLEDs = ((pixels = (uint8_t *)calloc(n, 3)) != NULL) ? n : 0;
  // 'begun' state does not change -- pins retain prior modes
}

// Change RGB data order (see notes with empty constructor, above):
void Adafruit_WS2801::updateOrder(uint8_t order) {
  rgb_order = order;
  // Existing LED data, if any, is NOT reformatted to new data order.
  // Calling function should clear or fill pixel data anew.
}

void Adafruit_WS2801::show(void) {
  uint16_t i, nl3 = numLEDs * 3; // 3 bytes per LED
  ////uint8_t  bit;

  // Write 24 bits per pixel:
  ////if(hardwareSPI) {
    for(i=0; i<nl3; i++) {
      SPI.transfer(pixels[i]);
      ////while(!(SPSR & (1<<SPIF)));
    }
    ////
    /*} else {
    for(i=0; i<nl3; i++ ) {
      for(bit=0x80; bit; bit >>= 1) {
        if(pixels[i] & bit) *dataport |=  datapinmask;
        else                *dataport &= ~datapinmask;
        *clkport |=  clkpinmask;
        *clkport &= ~clkpinmask;
      }
    }
  }*/

  delay(1); // Data is latched by holding clock pin low for 1 millisecond
}

// Set pixel color from separate 8-bit R, G, B components:
void Adafruit_WS2801::setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b) {
  if(n < numLEDs) { // Arrays are 0-indexed, thus NOT '<='
    uint8_t *p = &pixels[n * 3];
    // See notes later regarding color order
    if(rgb_order == WS2801_RGB) {
      *p++ = r;
      *p++ = g;
    } else {
      *p++ = g;
      *p++ = r;
    }
    *p++ = b;
  }
}

// Set pixel color from separate 8-bit R, G, B components using x,y coordinate system:
void Adafruit_WS2801::setPixelColor(uint16_t x, uint16_t y, uint8_t r, uint8_t g, uint8_t b) {
  boolean evenRow = ((y % 2) == 0);
  // calculate x offset first
  uint16_t offset = x % width;
  if (!evenRow) {
    offset = (width-1) - offset;
  }
  // add y offset
  offset += y * width;
  setPixelColor(offset, r, g, b);
}

// Set pixel color from 'packed' 32-bit RGB value:
void Adafruit_WS2801::setPixelColor(uint16_t n, uint32_t c) {
  if(n < numLEDs) { // Arrays are 0-indexed, thus NOT '<='
    uint8_t *p = &pixels[n * 3];
    // To keep the show() loop as simple & fast as possible, the
    // internal color representation is native to different pixel
    // types.  For compatibility with existing code, 'packed' RGB
    // values passed in or out are always 0xRRGGBB order.
    if(rgb_order == WS2801_RGB) {
      *p++ = c >> 16; // Red
      *p++ = c >>  8; // Green
    } else {
      *p++ = c >>  8; // Green
      *p++ = c >> 16; // Red
    }
    *p++ = c;         // Blue
  }
}

// Set pixel color from 'packed' 32-bit RGB value using x,y coordinate system:
void Adafruit_WS2801::setPixelColor(uint16_t x, uint16_t y, uint32_t c) {
  boolean evenRow = ((y % 2) == 0);
  // calculate x offset first
  uint16_t offset = x % width;
  if (!evenRow) {
    offset = (width-1) - offset;
  }
  // add y offset
  offset += y * width;
  setPixelColor(offset, c);
}

// Query color from previously-set pixel (returns packed 32-bit RGB value)
uint32_t Adafruit_WS2801::getPixelColor(uint16_t n) {
  if(n < numLEDs) {
    uint16_t ofs = n * 3;
    // To keep the show() loop as simple & fast as possible, the
    // internal color representation is native to different pixel
    // types.  For compatibility with existing code, 'packed' RGB
    // values passed in or out are always 0xRRGGBB order.
    return (rgb_order == WS2801_RGB) ?
      ((uint32_t)pixels[ofs] << 16) | ((uint16_t) pixels[ofs + 1] <<  8) | pixels[ofs + 2] :
      (pixels[ofs] <<  8) | ((uint32_t)pixels[ofs + 1] << 16) | pixels[ofs + 2];
  }

  return 0; // Pixel # is out of bounds
}

/* ========================== Application.cpp =========================== */

////#include "SPI.h"
////#include "Adafruit_WS2801.h"

/*****************************************************************************
Example sketch for driving Adafruit WS2801 pixels on the Spark Core!


  Designed specifically to work with the Adafruit RGB Pixels!
  12mm Bullet shape ----> https://www.adafruit.com/products/322
  12mm Flat shape   ----> https://www.adafruit.com/products/738
  36mm Square shape ----> https://www.adafruit.com/products/683

  These pixels use SPI to transmit the color data, and have built in
  high speed PWM drivers for 24 bit color per pixel
  2 pins are required to interface

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution

*****************************************************************************/

// The colors of the wires may be totally different so
// BE SURE TO CHECK YOUR PIXELS TO SEE WHICH WIRES TO USE!

// SPARK CORE SPI PINOUTS
// http://docs.spark.io/#/firmware/communication-spi
// Spark Core   WS2801
// VIN       -- +5V
// A3 (SCK)  -- Green wire on Adafruit Pixels, CI (Clock Input) on strips
// A5 (MOSI) -- Yellow wire on Adafruit Pixels, DI (Data Input) on strips
// GND       -- GND

// Don't forget to connect the ground wire to Arduino ground,
// and the +5V wire to a +5V supply

// Set the argument to the NUMBER of pixels. 25 = 25 pixels in a row
Adafruit_WS2801 strip = Adafruit_WS2801(54,WS2801_RGB);

// For 36mm LED pixels: these pixels internally represent color in a
// different format.  Either of the above constructors can accept an
// optional extra parameter: WS2801_RGB is conventional RGB order
// WS2801_GRB is the GRB order required by the 36mm pixels.  Other
// than this parameter, your code does not need to do anything different;
// the library will handle the format change.  Example:
//Adafruit_WS2801 strip = Adafruit_WS2801(25, WS2801_GRB);

// Initialze the pct value for the showPercent() function to 0
int pct = 0;
// Initialize the delay that will be used when setting pixel colors.
int dly=5;  //Leave at least some delay in.  It doesn't appear to work without a delay. 

//Flag to indicate if a showPercentage update is already in progress
bool updating = false;

void setup() {
    
  strip.begin();

  // Update LED contents, to start they are all 'off'
  strip.show();
  
  Spark.function("showPercent",showPercent);
  Spark.function("setDelay",setDelay);
  
  Serial.begin(9600);
}


void loop() {
  // Some example procedures showing how to display to the pixels
  
  //colorWipe(Color(255, 0, 0), 50);
  //colorWipe(Color(0, 255, 0), 50);
  //colorWipe(Color(0, 0, 255), 50);
  //rainbow(20);
  //rainbowCycle(20);
  
  
}

int setDelay(String delayString) {

  //get the new delay value from the string
  int newDly = delayString.toInt();
  //make sure that the delay is at least 1
  dly = max(1,newDly);
  //make sure the delay is no more than 50
  dly = min(50,dly);
  
  return dly;
    
}

int showPercent(String percent)
{
    

    Serial.print("percent: ");
    Serial.println(percent);
    
    int newPct = percent.toInt();
    
    Serial.print("newPct: ");
    Serial.println(newPct);
    
    if(newPct == pct) {
        return 0;
    }
    
    if(updating) {
      return 0;
    }

    updating = true;

    pct = newPct;
    

    rainbow(dly);
    
    colorWipe(Color(255,255,255),dly);
    colorWipe(Color(0,0,0),dly);
    colorWipe(Color(255,255,255),dly);
    colorWipe(Color(0,0,0),dly);
    colorWipe(Color(255,255,255),dly);
    colorWipe(Color(0,0,0),dly);
    
    
    int pixels = (int)(strip.numPixels() * (pct / 100.0));
    int pixel;
    
    
    Serial.print("Num pixels: ");
    Serial.println(pixels);
    
    
    //Determine the color based on the percentage
    //If the pct is less than 98, full red component, otherwise no red component
    int r = (pct < 98) ? 255 : 0;
    //If the pct <= 92, no green cpt, if it is <= 98, half green component if it is > 98, full green component
    int g = (pct > 92) ? ((pct > 98) ? 255 : 128) : 0;
  
    uint32_t c = Color(r, g, 0);
    
    for (pixel=0; pixel < pixels; pixel++) {
        strip.setPixelColor(pixel, c);
        strip.show();
        delay(dly);
     }
     
    if(pixels < strip.numPixels()) {
        c = Color(128,128,128);
        for(pixel = pixels; pixel < strip.numPixels(); pixel++) {
            strip.setPixelColor(pixel,c);
            strip.show();
            delay(dly);
        }
         
    }
     
    updating = false;
     
    return pct;
    
}


void rainbow(uint8_t wait) {
  int i, j;
   
  for (j=0; j < 256; j++) {     // 3 cycles of all 256 colors in the wheel
    for (i=0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel( (i + j) % 255));
    }  
    strip.show();   // write all the pixels out
    delay(wait);
  }
}

// Slightly different, this one makes the rainbow wheel equally distributed 
// along the chain
void rainbowCycle(uint8_t wait) {
  int i, j;
  
  for (j=0; j < 256 * 5; j++) {     // 5 cycles of all 25 colors in the wheel
    for (i=0; i < strip.numPixels(); i++) {
      // tricky math! we use each pixel as a fraction of the full 96-color wheel
      // (thats the i / strip.numPixels() part)
      // Then add in j which makes the colors go around per pixel
      // the % 96 is to make the wheel cycle around
      strip.setPixelColor(i, Wheel( ((i * 256 / strip.numPixels()) + j) % 256) );
    }  
    strip.show();   // write all the pixels out
    delay(wait);
  }
}

// fill the dots one after the other with said color
// good for testing purposes
void colorWipe(uint32_t c, uint8_t wait) {
  int i;
  
  for (i=0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}

/* Helper functions */

// Create a 24 bit color value from R,G,B
uint32_t Color(byte r, byte g, byte b)
{
  uint32_t c;
  c = r;
  c <<= 8;
  c |= g;
  c <<= 8;
  c |= b;
  return c;
}

//Input a value 0 to 255 to get a color value.
//The colours are a transition r - g -b - back to r
uint32_t Wheel(byte WheelPos)
{
  if (WheelPos < 85) {
   return Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if (WheelPos < 170) {
   WheelPos -= 85;
   return Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170; 
   return Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
