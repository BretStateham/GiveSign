<a name="Title" />
# Give Sign Assembly Instructions #

These instructions outline the steps for assembling the GIVE sign. 

<a name="Inventory" />
## Inventory ##

![in001-GiveSignFront](images/in001-givesignfront.png?raw=true "Give Sign Front")

![in002-GiveSignBackAndParts](images/in002-givesignbackandparts.png?raw=true "Give Sign Back and Parts")

The give sign consists of

1. Four base plates (one for each letter)
1. Four Letters (G,I,V,E) with LEDs attached
1. Spark Core and Circut Board (should be attached to "G" base plate)
1. 12V/5A DC Power Supply with 2.1mm male plug. 
1. Spare 4 x 1/2 panhead screws in case they are needed to secure LEDs (not pictured) 

---

<a name="CircuitLayout" />
## Circuit Layout ##

The Spark Core is inserted in a socket on a circuit board that is inside the blue enclosure on the "G" base board.  You can flip the clips out to remove the lid.  YOU DO NOT NEED TO OPEN THE ENCLOSURE AS PART OF NORMAL OPERATION.  You only need to open the enclosure to perform actions on the Spark Core.  

![cir002-Layout](images/cir002-layout.png?raw=true "Layout")

1. There is a schematic of the circuit at the end of this document: [Circuit Schematic](#CircuitSchematic)

---

<a name="tasks" />
## Tasks ##

The remainder of this document walks you through a number of tasks.

1. [Assembling the Sign](#Task1)
1. [Installing the Spark Core Windows USB Driver](#Task2)
1. [Installing the Spark-CLI](#Task3)
1. [Configuring WiFi for a Pre-Programmed Spark Core](#Task4)
1. [Flashing the LEDDOTS Sketch](#Task5)
1. [Identifying your Spark Core](#Task6)
1. [Testing the Spark Core](#Task7)

---

<a name="Task1" />
## Assembling the Sign ##

The sign assembly is pretty simple.  Basically, just connect the base boards together, then connect the letters to the base boards, and finally connect the cables up.  Easy!

FYI, a number of the pictures were taken under a shade tree.  Apologies for the poor picture quality. 

1. Identify each base board by looking on the bottom:

	![01010-BaseBoardLabels](images/01010-baseboardlabels.png?raw=true "Base Board Labels")

1. Connect the base boards in order (G,I,V,E) using the dowels and holes:

	![01020-BaseBoardDowels](images/01020-baseboarddowels.png?raw=true "Base Board Dowels")
 
1. Place each letter on it's corresponding base board, again using the dowels and holes:

	> **Note:** the holes on the base board are off center and CLOSER to the FRONT.  So make sure the front of the letter (with the LED bulbs showing) is closer to the front of the base board. 

	![01030-LetterDowels](images/01030-letterdowels.png?raw=true "letter Dowels")

	![01040-EAttached](images/01040-eattached.png?raw=true "E Attached")

1. When the bases and Letters are all attached it should look something like this (minus the lit LEDs): 

	![in001-GiveSignFront](images/in001-givesignfront.png?raw=true "Give Sign Front")

1. **As you work with the connectors, make sure the handle them by the white plastic parts.  DO NOT PULL THE WIRES GOING INTO THE CONNECTORS.  They can be pulled out of the connector.**  

	![01045-MolexConnectorUsage](images/01045-molexconnectorusage.png?raw=true "Molex Connector Usage")

1. Connect the NUMBERED connectors in the back. ("0","1","2","3")

	> **Note:** The "letter" connectors ("A","B","C","D" and "E") are connectors within a letter and do not need to be messed with unless there is a problem.  As mentioned though, if you do feel a need to disconnect and re-connect one, please take care to handle them only by the white plastic of the connector. 

	![01050-Connectors](images/01050-connectors.png?raw=true "Connector Numbers")

	- **0**: Goes from the Spark Core enclosure to the corresponding "0" connector on the "tongue" of the letter "G".  Route the wires from the Spark Core enclosure through the LED strip wires to help keep it in place. 

	- **1**: Goes from the cable leaving the "G" and to the corresponding connector at the bottom of the letter "I"

	- **2**: Goes from the "I" to the corresponding connector at the bottom of the letter "V"

	- **3**: Goes from the "V" to the bottom of the letter "E"

1. When you are done connecting the wires, attempt to clean the wires up some by tucking them in where you can.  Seeing the wires is part of the "character" of the sign though, so don't worry about trying to hide them altogether.

1. The only step that remains is to connect the power supply to the Spark Core.  You can wait to do this until you have configured the Spark Core as described in the following steps.

---

<a name="Task2" />
## Installing the Spark Core Windows USB Driver ##

### <span style="color: #090">IF YOU ALREADY HAVE THE WINDOWS USB DRIVER INSTALLED YOU CAN SKIP THIS TASK</span> ###

The steps covered here are specific to configuring a Spark Core using the Command Line Interface on a Windows machine. If you will be working with the spark core from a Mac or Linux box, you can can refer to the [online documentation](http://docs.spark.io/ "Spark.IO Documentation") for configuring a Spark Core. 

1. Before you work with the Spark Core on a Windows Machine, you will need to install the Windows USB Driver.  First, you'll need to download the driver from https://s3.amazonaws.com/spark-website/Spark.zip . Download the .zip file and extract it to a folder on your computer.  

	> **Note:** You can also refer to the documentation for [Connecting to the Spark Core via USB](http://docs.spark.io/connect/#connecting-your-core-connect-over-usb)

1. Connect the Spark Core to your computer via the USB, and ensure that the Spark Core is in **["Listening Mode"](http://docs.spark.io/connect/#connecting-your-core-listening-mode)** by confirming that the RGB LED on the board is flashing blue.  If it isn't, [hold the **"MODE"** button on the Spark Core for about three seconds until it begins flashing blue](https://vine.co/v/hFHlpBDELeU):

	![02005-ListeningMode](images/02005-listeningmode.png?raw=true "Listening Mode")


1. Open your computer's **"Device Manager"**.  Under **"Other Devices"** you should see the **"Spark Core with WiFi"**.  Right click on the **"Spark Core with WiFi"** and select **"Update Driver Software..."** from the pop-up menu: 

	![02010-SparkInOtherDevices](images/02010-sparkinotherdevices.png?raw=true "Spark in Other Devices")

1. Select the **"Browse my computer for driver software"** option:

	![02020-Browse](images/02020-browse.png?raw=true "Browse")

1. Then browse to the folder where you extracted the Spark.zip file you downloaded previously with the Windows USB driver.  (There should be a **spark_core.inf** and **spark_core.cat** file in the folder), then click **"Next"**:

	![02030-SparkDriverFolder](images/02030-sparkdriverfolder.png?raw=true "Spark Driver Folder")

1. In the **"Windows Security"** window, click **"Install"** to install the driver:

	![02040-Install](images/02040-install.png?raw=true "Install")

1. You should see a confirmation that the **"Spark Core with Wifi and Arduino Compatability"** driver was installed.  Click **"Close"** to close the window. 

	![02050-DriverInstalled](images/02050-driverinstalled.png?raw=true "Driver Installed")

1. Finally, back in the **"Device Manager"** you should see the Spark Core listed under **"Ports"**:

	![02060-SparkOnComPort](images/02060-sparkoncomport.png?raw=true "Spark Core on COM Port")

1. At this point, if you were to use a terminal program (Like [PuTTY](http://www.chiark.greenend.org.uk/~sgtatham/putty/download.html)) you could connect serially to the Spark Core via the COM port listed (COM4 in this case) and issue [some commands](http://docs.spark.io/connect/#connecting-your-core-connect-over-usb).  However, the Spark Command Line Interface (Spark-CLI) offers significantly more functionality, so we'll use that.  

---

<a name="Task3" />
## Installing the Spark-CLI ##

### <span style="color: #090">IF YOU ALREADY HAVE THE LATEST VERSION OF THE SPARK-CLI INSTALLED YOU CAN SKIP THIS TASK</span> ###

The S**park Command Line Interface (Spark-CLI)** is a **Node.js** application that allows you to manage your spark cores, and the code that runs on them.  The Spark-CLI source is available from GitHub at https://github.com/spark/spark-cli and you can read the docs here: http://docs.spark.io/cli/

1.  First, ensure that you have Node.js installed.  You can install it from here: http://nodejs.org/

	> **Note:** It helps if you let the installer install the Node Package Manager (npm) as well as to add Node to the system path.  If you add node the path, you can use node from any Windows Command Prompt. 

1. To install the Spark-CLI using node, you can open a Node.js Command Prompt (or any command administrator prompt if you allowed the Node.js installer to add Node to the path) and issue the following command:

	`npm install -g spark-cli`

	![03010-InstallSparkCLI](images/03010-installsparkcli.png?raw=true "Install Spark-CLI")

1. This documentation was written with the Spark-CLI version 0.4.1.  If you already have the Spark-CLI installed, you can determine its version using the following command:

	`npm list -g spark-cli`

	![03020-SparkCliVersion](images/03020-sparkcliversion.png?raw=true "SparkCliVersion")

1. In addition, you can always upgrade to the latest version of the Spark-CLI using the command: 

	`npm update -g spark-cli`

---

<a name="Task4" />
## Configuring WiFi for a Pre-Programmed Spark Core ##

### <span style="color: #900; font-weight: bold">IF YOU ARE ADDING YOUR OWN SPARK CORE, OR NEED TO RE-PROGRAM AN EXISTING SPARK CORE, SKIP THIS STEP AND GO TO [Flashing the LEDDOTS Sketch](#Task5)</span> ###

If you received the GIVE sign with a Spark Core that has been pre-programmed, you only need to configure the Spark Core to connect to your local WiFi.

1. Connect the Spark Core to your PC via USB, and place the Spark Core into **"[Listening Mode](http://docs.spark.io/connect/#connecting-your-core-listening-mode)"** by holding down the **"Mode"** button on the spark core until the RGB LED flashes blue repeatedly.

1. Open a Node Command Prompt, and issue the following command 

	`spark setup wifi`

1. Follow the prompts to configure the Spark Core for your WiFi network.  


	> **Note:** Some MiFi wifi hot spots (like my Verizon MiFi), and other networks take the user to a start screen on the first load.  If connecting to your mifi, the Spark might fail to connect the first time.  Try cycling the power on your Spark Core to get it to restart and connect.  If the WiFi network you are connecting to requires a browser based authentication process, you won't be able to connect your Spark Core to it.  You must know the WiFi SSID, Security Mode, and Password.  

	![04010-SparkSetupWifi](images/04010-sparksetupwifi.png?raw=true "spark setup wifi")

1. When the WiFi setup is complete, you should see the RGB LED on the Spark Core "Breathing Cyan".  This means that [it should have a cyan color (light blue) and should repeatedly fade in and out.](https://vine.co/v/OmOAlMg17Y9) 

---

<a name="Task5" />
## Flashing the LEDDOTS Sketch ##

If your Spark Core has not been claimed, you need to do that first. 

If the Spark Core you want to claim has already been claimed by another account, you will have to have that account owner remove the core before you can claim it:

`spark core remove <core name / core id>`

If your Spark Core is new, or is available to be claimed you can use the Spark-CLI commands:

```
spark cloud login
spark setup
```

You can find instructions for connecting and claiming a core here: [http://docs.spark.io/connect](http://docs.spark.io/connect)

The **"LEDDOTS"** sketch (app) we use below is used to drive a spark core that is connected to a string of 30mm LED Dots from Adafruit (https://www.adafruit.com/products/1547).  These LED strips provide are a powerful way to create extremely active and colorful visualizations.  The LEDs are controlled using a [WS2801](http://www.adafruit.com/datasheets/WS2801.pdf) chip.  It allows a string of LEDs (54 in the case of the GIVE Sign) to be strung together and controlled with only two pins on a Microcontroller. Super cool!

The sketch uses a modified version of the [Adafruit_WS2801](https://github.com/adafruit/Adafruit-WS2801-Library) library.  The code has been modified to work with the Spark Core:  https://gist.github.com/technobly/8339548#file-sparkcorews2801-cpp-L370 . The modified version of the code was provided via GitHub by [Technobly](https://github.com/technobly)

The LEDDOTS sketch has two methods, `showPercent(string)` and `setDelay(string)`.  The `setDelay(string)` method is used really more for debugging purposes.  It sets the delay (ms) used by the various animations.  Setting the delay lower speeds up the animations.  However, the default delay is only 5ms so you can't make them much faster.  

The `showPercent(string)` function is the main purpose of the sketch.  It takes in a string command that has a single integer in it representing a percentange between 0 and 100. 

It then uses that displays that percentage as a number of dots in the LED dot stream.  0% = 0 dots, 50% = 27 dots, 100% = 54 dots.  The dots fill with the following pattern:

> **Note:** the following picture was taken when the percentage was 48% or 26 dots (rounded up).

![05005-DotFillPattern](images/05005-dotfillpattern.png?raw=true "Dot Fill Pattern")

The color of the "filled" dots will be based on the percentage (note, this may change in the future):

- 00 - 92% = Red

- 93 - 97% = Yellow

- 98 - 100% = Green

The Spark Core that is shipped with the GIVE sign should already have the LEDDOTS sketch flashed on it, however if you need to program another Spark Core, you can follow these steps:

1. Login to the [Spark Build](http://spark.io/build) web development environment with your Spark.IO credentials (the same credentials you used to claim your Spark Core): https://www.spark.io/build 

1. If this isn't your first sketch, clik the **"CREATE NEW APP"** button:

	![05010-CreateNewApp](images/05010-createnewapp.png?raw=true "Create New App")

1. When prompted, enter **"LEDDOTS"** as the name for your new app:

	![05020-LEDDOTSAppname](images/05020-leddotsappname.png?raw=true "LEDDOTS App Name")

1. Paste the following code into the code window:

	> **Note:** This is a big code piece.  You can also just open the source file at [LEDDOTS.ino](./LEDDOTS/leddots.ino).  Also, while the code file has the arduino **&lowast;.ino** extension, you CAN NOT open and compile this in the Arduino IDE.  

	````C++
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
	````
1. Click the **"Save"** button (looks like a folder, don't ask me why) to save the sketch:

	![05030-SaveApp](images/05030-saveapp.png?raw=true "Save App")

1. You can the **"Verify"** your sketch:

	![05040-VerifySketch](images/05040-verifysketch.png?raw=true "Verify Sketch")

1. If you have claimed multiple cores with your account, make sure that the correct Spark Core is set as the target by choosing the **"Cores"** option along the left, then clicking on the **"Star"** icon next to the core you want to flash:

	![05050-SelectCore](images/05050-selectcore.png?raw=true "Select Target Core")

1. Finally, you can flash the code to your Spark Core: 

	> **Note:** The Spark Core's LED should blink purple while it is being flashed

	![05060-FlashCode](images/05060-flashcode.png?raw=true "Flash Code")

1. You know your core is ready when it is once again **"[breathing cyan](https://vine.co/v/OmOAlMg17Y9)"**

---

<a name="Task6" />
## Identifying your Spark Core ##

1. Before you can call the **"showPercent"** function on your Spark Core, you need to know

	- The Spark Cores Core ID
	- The Access Token for your account

We'll walk through finding both of these here:

1. You can determine your Spark Core's Core ID using the Spark-CLI if it is connected to your PC and **"[breathing cyan](https://vine.co/v/OmOAlMg17Y9)"** by issuing the following commands:

	```
	spark cloud login
	spark cloud list
	```

	![06010-SparkList](images/06010-sparklist.png?raw=true "Spark List")

1. You can also determine your Spark Core's ID from the **"[Spark Build](htps://spark.io/build)"** web interface.  Login to **"[Spark Build](htps://spark.io/build)"**, and from the **"Cores"** page, click on the arrow next to your core to see it's Core ID:

	![06020-CoreIDInBuild](images/06020-coreidinbuild.png?raw=true "CoreIDInBuild")

1. Your access token can also be retrieved from the Spark Build web interface.  Click on the **"Settings"** link, and copy your Access Token from there: 

	![06030-AccessToken](images/06030-accesstoken.png?raw=true "Access Token")

---

<a name="Task7" />
## Testing the Spark Core ##

Ok, if you got this far it is assumed that you have a Spark Core connected to a GIVE sign.  You can now disconnect the Spark Core from your computer (disconnect the USB cable), and power it from the 12V/5A DC Power Supply instead.  

We will be using the **[Spark REST API](http://docs.spark.io/api)** to call the **"showPercent"** function published by the **"LEDDOTS"** app we flashed onto the Spark Core. 

The REST Api requires that all requests include the **"access_token"** for the account that the Spark Core belongs to, as well as the Spark core's devic ID (Core ID).  Use the instructions in the **"[Identifying your Spark Core](#Task6)"** section to retrieve those values if needed. 

The `showPercent(string)` method takes a single string "command" that represents an integer.  The integer is a percent between 0 and 100. 

The showPercent function only applies the new value if it is different from the current value.  When a new value is receive it plays an animation (cycles the rainbow colors, then does a chase of white dots) before showing the new value. 

You can call the **"showPercent"** function on the spark a number of ways:

- Spark-CLI
- Curl
- A REST Client Tool
- A custom App

We will cover the first three here and leave the custom app implementation to you:

1. Connect the 12VDC Power Supply to the Spark Core circuit in the enclosure:

	![07010-ConnectPowerSupply](images/07010-connectpowersupply.png?raw=true "Connect Power Supply")

1. To use the Spark-CLI to call the showPercent function on your Spark Core, first make sure you are logged in via the Spark CLI:

	`spark cloud login`

	Then run either:

	`spark call <core id> showPercent 50`

	or 

	`spark call <core name. showPercent 50`

	for example: 
	
	![07020-SparkCLICall](images/07020-sparkclicall.png?raw=true "Spark CLI Call")

	> **Note:** showPercent returns the percent that was set.  It returns 0 if the new percent is the same as the old percent. Feel free to change the percentage to try different values.  
	
1. You can also use [curl](http://curl.haxx.se/download.html) to test your spark using the following format:

	`curl https://api.spark.io/v1/devices/<core id>/showPercent -k -d access_token=<access token> -d params=<pct>`

	For example:

	![07030-CurlCall](images/07030-curlcall.png?raw=true "Curl Call")

1. Finally, you can also use a REST client like the **"[Advanced Rest Client](http://chromerestclient.appspot.com/)"** app for Chrome.

	![07040-RestClient](images/07040-restclient.png?raw=true "REST Client")

1. To create a custom app (A Windows or Windows Phone App, Web App, iOS, Android, etc) you can read up on the **"[Spark REST Api](http://docs.spark.io/api)"** and implement your client code accordingly.

---

<a name="CircuitSchematic" />
## Circuit Schematic ##

![cir001-schematic](images/cir001-schematic.png?raw=true "Schematic")
