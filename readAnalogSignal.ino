#include "Arduino.h"
#include "PCF8574.h"

PCF8574 first(0x27);
PCF8574 second(0x20);

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  // Read analog values from A0, A1, A2, and A3
  int sensorValueA0 = analogRead(A0);
  int sensorValueA1 = analogRead(A1);
  int sensorValueA2 = analogRead(A2);
  int sensorValueA3 = analogRead(A3);
  Wire.beginTransmission(WaterTankAddr);


  // Send the values to the Serial Plotter
  Serial.print(sensorValueA0);
  Serial.print(",");
  Serial.print(sensorValueA1);
  Serial.print(",");
  Serial.print(sensorValueA2);
  Serial.print(",");
  Serial.println(sensorValueA3);

  delay(100);
}


// https://miliohm.com/pcf8574-with-arduino-esp8266/