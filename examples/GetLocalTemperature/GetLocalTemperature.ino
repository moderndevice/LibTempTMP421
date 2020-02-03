/****************************
   GetLocalTemperature
    An example sketch that prints the
    local temperature to the PC's serial port

    Tested with the TMP421-Breakout
    Temperature Sensor from Modern Device
 *****************************/
#include "Wire.h"
#include <LibTempTMP421.h>

/* Connect A0 or A1 for 7 alternative I2C addresses for multiple sensors
    on the same I2C pins
    either ground the pin or wire it high as per the chart below
    HIGH means connect the pin to +5 or +3.3 volt
    GND  means connt the pin to GND
    float means leave the pin unconnected a
    s they are from the factory

    I2C address Hex     A1 pin      A0 pin
    B0101010    0x2A     Float       Float     // default shipped from factory
    B0011100    0x1C     Float       GND
    B0011101    0x1D     Float       HIGH
    B0011110    0x1E     GND         Float
    B0011111    0x1F     HIGH        Float
    B1001100    0x4C     GND         GND
    B1001101    0x4D     GND         HIGH
    B1001110    0x4E     HIGH        GND
    B1001111    0x4F     HIGH        HIGH
*/

int I2Caddress = 0x2A;  // set this to 0x2A before uploading to Github

/* this low-current sensor can be powered from Arduino pins (optional) */
const int GNDpin = A2;  // A2 for UNO / 18 for Arduino Mega
const int PWRpin = A3;  // A3 for UNO / 19 for Arduino Mega

LibTempTMP421 temp = LibTempTMP421(0, I2Caddress);

void setup() {

  // powering sensor from Arduino pins (this is optional)
  pinMode(GNDpin, OUTPUT);        // GND pin
  pinMode(PWRpin, OUTPUT);        // VCC pin
  digitalWrite(PWRpin, HIGH);     

  Serial.begin(9600);
  // initalize power pins (if used) before calling init
  temp.Init();
}

void loop() {
  Serial.print("Temp: ");
  float C = temp.GetTemperature();
  Serial.print(C);
  Serial.print(" degC\t");
  float F = (C * 9.0) / 5.0 + 32.0;    // convert to Fehrenheit
  Serial.print(F);
  Serial.println(" degF");
  delay(100);
}

