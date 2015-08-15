//
//Date: 8/14/15
//Version: 1.0
//
//Comments:
//This sketch reads an analog temperature sensor and writes the temperature in F to the LCD display. 
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
//
// Analog Temperature Sensor Connection:
// Vout Pin: Connect to analog input 0.
//

// Arduino LCD Display Library
#include <LiquidCrystal.h>

// Call the library with the right pin configuration
// In this sketch we are using: lcd(RS,EN,D4,D5,D6,D7) in 4 bit mode
LiquidCrystal lcd(2,3,4,5,6,7);

// The AREF pin is tied to the 3.3V output pin to be used as an external reference for the ADC
#define aref_ext_voltage 3.3

// Assign Arduino analog input pin to be connected to temp sensor 
int tempPin = 0;        

// Assign a variable to hold the temperature sensor reading                        
int tempVal;        // the analog reading from the sensor

// The setup runs once when you press reset or power on the board
void setup() {
  // Setup the LCD display column and row
  // We are using a 20x4 display in this example
  lcd.begin(20, 4);
    
  // Need to tell Arduino that we are using an external voltage reference for ADC
  // Always have to set this first before calling analogRead() or else you could short out your board
  analogReference(EXTERNAL);
  // Allow voltage on ADC to settle out before reading
  analogRead(0);
 
}

void loop() {

  // Read the temperature sensor and store the value
  tempVal = analogRead(tempPin);  
 
  // Convert the digitized number 0-1023 from the ADC into a voltage based on the reference voltage
  // For an external reference voltage of 3.3V => (ADC value) * (3.3V/1024)
  float voltageConvert = tempVal * aref_ext_voltage;
  voltageConvert /= 1024.0; 
 
  // Convert the voltage into temperature using the linear graph data from the TMP36 datasheet
  // TMP36 has 500mV offset and 10mV/C degree scale
  // Temp in C = (Voltage - 500mV)/10
  // Voltage is in Volts so multiply by 100 instead of divide by 10 to get correct result (1000mV=1V)
  float tempC = (voltageConvert - 0.5) * 100 ;  
                                               
  // Convert C to F
  float tempF = (tempC * 9.0 / 5.0) + 32.0;
  
  // Print a message to the LCD.
  lcd.setCursor(0, 0);  // set the start of the message to be first column first row
  lcd.print("The current temp is ");
  lcd.print(tempF);
  lcd.print(" degrees F");

}

