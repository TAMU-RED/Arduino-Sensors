// analog-plot
// 
// Read analog values from A1 and print them to serial port.
//

#include "Arduino.h"

void setup()
{
  // initialize serial comms
  Serial.begin(9600); 
}

void loop()
{
  //Tells Arduino that input is in port A1 on Arduino
  int sensorVal=analogRead(A1);
  
  //Converts input value into voltage
  float voltage = (sensorVal*5.0)/1024.0;
  
  //Convert voltage to pressure in pascals
  float pressure_pascal = (3.0*((float)voltage-0.47))*1000000.0;
  
  //Convert pascals to bars
  float pressure_bar = pressure_pascal / 10e5;
  
  //Send pressure in bars to serial port
  Serial.print(pressure_bar);

  //place comma between each value outputted.
  Serial.print(",");
   
  //Serial.println(" bars");
  delay(250);

}
