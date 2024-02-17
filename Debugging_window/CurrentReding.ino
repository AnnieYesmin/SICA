#include "SICA.h"
/*read AC Current Value and return the RMS*/
//this program is from the current sensor site
float readACCurrent(int Pin)
{
  
  int analogValue;             //analog value read from the sensor output pin
  int maxValue = 0;            // store max value
  int minValue = 4096;         // store min value
  unsigned long start_time = millis();
  analogReadResolution(12);
  while ((millis() - start_time) < 200) //sample for 0.2s
  {
    analogValue = analogRead(Pin);
    Serial.print("ANALOG: ");
    Serial.println(analogValue);
    if (analogValue > maxValue)
    {
      maxValue = analogValue;
    }
    if (analogValue < minValue)
    {
      minValue = analogValue;
    }
  }
  float Vpp = (maxValue - minValue) * Vref / 4096.0;
  float Vrms = (Vpp / 2.0 )* (0.707 / mVperAmp); //Vpp -> Vrms
  return Vrms;//-0.008263;//-0.050;//-0.000878;//+0.028618;

}

/*read reference voltage*/
long readVref()
{
  return (3300);                                 //Arduino Due arm
}
