#ifndef BASE_SENSOR_H
#define BASE_SENSOR_H

#define INVALID_READING -1

#include "BaseIO.hpp"

class Base_Sensor: public BaseIO
{
    public:
      Base_Sensor(int PIN, int ID, int initial_state) : 
          BaseIO(PIN, ID, initial_state){}
      Base_Sensor(int PIN, int ID) : 
          BaseIO(PIN, ID){}
      Base_Sensor(int PIN) : 
          BaseIO(PIN){}

      /* Note:
       *  On power-up, all pins initialize as a digital 
       * high-impedance INPUT, therefore there is no need 
       * to call setup on Sensors. However it is in
       * place and can be used.
       */
      virtual void setup(){
        if(!set){
          set = true;
          pinMode(m_PIN, INPUT);
        }
      }

      virtual int read()
      {
        Serial.println("Trying to BASE read..");
        update_state(INVALID_READING);
      }
  
      //  Returns current state if there was an update
      // otherwise returns -1
      int update_state(int reading)
      {
        int ret = INVALID_READING;
        if(reading != INVALID_READING && reading != m_state)
        {
          m_state = reading;
          ret = m_state;
        }
        return ret;
      }
};

#endif
