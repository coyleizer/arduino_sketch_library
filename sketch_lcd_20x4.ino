//
//Date: 8/2/15
//Version: 1.0
//
//Comments:
//This sketch writes a message to a 20x4 character LCD display. 
//
// LCD Pinout Connection:
// RS Pin: Connect to digital input 2.
// Enable Pin: Connect to digital input 3.
// D4 Pin: Connect to digital input pin 4.
// D5 Pin: Connect to digital input pin 5.
// D6 Pin: Connect to digital input pin 6.
// D7 Pin: Connect to digital input pin 7.
// R/W Pin: Connect to Ground so in write mode which is logic low "0".
// Vo Pin: Connect to the 10K pot that is connected between power and ground.


// Arduino LCD Display Library
#include <LiquidCrystal.h>

// Call the library with the right pin configuration
// In this sketch we are using: lcd(RS,EN,D4,D5,D6,D7) in 4 bit mode
LiquidCrystal lcd(2,3,4,5,6,7);

// The setup runs once when you press reset or power on the board
void setup() {
  // Setup the LCD display column and row
  // We are using a 20x4 display in this example
  lcd.begin(20, 4);
 
}

// Main code for Arduino goes in the loop function to be run over and over again
void loop() {
  lcd.setCursor(0, 0);  // set the start of the message to be first column first row
  lcd.print("Line 1");  // print a message to the LCD  
  lcd.setCursor(0, 1);  // set the cursor to print beginning of second line
  lcd.print("Line 2");  // print a message to the LCD
  lcd.setCursor(0,2);   // set the cursor to print beginning of third line
  lcd.print("Line 3");  // print a message to the LCD
  lcd.setCursor(0,3);   // set the cursor to print beginning of fourth line
  lcd.print("Line 4");  // print a message to the LCD
}

