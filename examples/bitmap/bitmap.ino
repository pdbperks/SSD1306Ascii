/*

 */
#ifndef UNIT_TEST
#include <Arduino.h>
#endif

#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"
#include "bitmaps.h"

// 0X3C+SA0 - 0x3C or 0x3D
#define I2C_ADDRESS 0x3C

// Define proper RST_PIN if required.
#define RST_PIN -1

SSD1306AsciiWire display;

//SSD1306AsciiWire oled;
// Define proper RST_PIN if required.
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

const uint16_t kIrLed = 4;  // ESP8266 GPIO pin to use. Recommended: 4 (D2).
unsigned long delayStart = 0; // the time the delay started
bool delayRunning = false; // true if still waiting for delay to finish
int cursorY;

void setup(void) {
  Wire.begin();
  //Wire.begin(0,2);    //   (D3)0 as SDA and (D4)2 as SCL - use for NodeMCU pins 
  Serial.begin(115200);
#if RST_PIN >= 0
  display.begin(&Adafruit128x64, I2C_ADDRESS, RST_PIN);
#else // RST_PIN >= 0
  display.begin(&Adafruit128x64, I2C_ADDRESS);
#endif // RST_PIN >= 0
  //display.displayRemap(true);
  display.setFont(Adafruit5x7);
  display.clear(); 
 display.setCursor(0,0);
   display.print(F("SSD1306ascii+bitmap+"));delay(1000);
     display.setCursor(0,1);
  display.print("Progress 0");
 display.writeProgressBar(0, 2, 0);
delay(500);
 for (uint8_t prog = 0; prog < 100; prog++) {
   display.setCursor(0,1);
   display.print("Progress ");display.print(prog);display.print(" "); 
   display.writeProgressBar(0, 2, prog);
   delay(20);
 }
 delay(500); 
   
display.writeBitmap((uint8_t*) arrow,0,31,4,7);delay(500);
display.writeBitmap((uint8_t*) arrow,32,63,4,7);delay(500);
display.writeBitmap((uint8_t*) head55x56,70,124,1,7);
delay(500);
 for (uint8_t prog = 0; prog < 100; prog++) {
   display.setCursor(0,1);
  display.print("Progress ");display.print(99-prog);display.print(" ");
   display.writeProgressBar(0, 2, 100-prog);
   delay(20);
 }
 delay(2000);

 display.writeBitmap((uint8_t*) mona4,0,127,0,7); 

}

void loop(void) {

}
