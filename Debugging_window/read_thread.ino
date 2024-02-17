#include "SICA.h"

/*
This thread calls the sensorThread() function remotely
every second. Result is printed to the RPC1 stream.
*/

void read_data()
{  while (true) 
  {
    if(START_flag == 1)
    {
      digitalWrite(RelayPIN, LOW);
      //-------------------------------read the pt100 temp------------------------------
      float rtdResistance = max31865.readRTD(); 
      temperature = max31865.temperature(PT100_RNOMINAL, REF_RESISTOR);
      //--------------------------------------------------------------------------------

      /*If you are reading AC current, use this function to read AC current*/
      CurrentValue=  readACCurrent(currentSensorPin);//(0.8280545237* (readACCurrent(currentSensorPin)-0.001)) + 0.0117297941;//-0.15;//(0.1236841*((0.8280545237* readACCurrent(currentSensorPin)) - 0.0882702059))+0.005-0.016;
      //the below samples are just for testing purpose the current       
      if(CurrentValue>1)
      {
        sample=50;
      }
      else
      {
        sample=10;
      }
      //only read current when the start flag is pressed
      for(avg_iter=0;avg_iter<sample && START_flag == 1;avg_iter++)
      {
        CurrentValue=   readACCurrent(currentSensorPin);//(0.8280545237* readACCurrent(currentSensorPin)) + 0.0117297941;//-0.001944;//-0.13;//(0.1236841*((0.8280545237* readACCurrent(currentSensorPin)) - 0.0882702059))+0.005-0.016;
        arr_current[avg_iter]=CurrentValue;
        Serial.println(avg_iter);
        Serial.println(arr_current[avg_iter],6);
      }

      Serial.print("1st reading:");
      Serial.println(arr_current[0],6);

      Serial.print("10th reading:");
      Serial.println(arr_current[9],6);

      for(int i=0;i<5;i++)
      {
        sum=sum+arr_current[i];
      }  
      sum=sum/5;
      CurrentValue=sum;
      Serial.print("5 avg-----------------");
      Serial.println(sum,6);
      //after reading reset the start flag to stop reading the current again
      START_flag=0;
      digitalWrite(RelayPIN, HIGH);
      sum=0;
      display_current=CurrentValue;
      display_temp=temperature;
      processingFLAG=1;
      
    }
      //------------------------------Here I am just calculating the current I am getting is salt concentration------------------------------
      //display flag is updated when the reading is finished
    if(update_display_flag==1)
    {
      if(dd_flag==1) //this flag is for unit PTB
      {
        
        display_current=CurrentValue;
        display_temp=temperature;
        float divide=display_temp * 9.0/5;
        display_temp=divide+ 32;
        float salt =display_current*0.00220462;
        display_current=salt;
        update_current();
        update_temp();
        dd_flag=7;
      }
      else if(dd_flag==3) //this is for unit  mg/kg
      {
        display_current= CurrentValue;
        temperature = max31865.temperature(PT100_RNOMINAL, REF_RESISTOR);
        display_temp=temperature;
        update_current();
        update_temp();
        dd_flag=7;

      }
    }
    digitalWrite(RelayPIN, HIGH);

  }

/* ----------------------------------------------------------------------------------------------------------------------- */
}
