#ifndef SENSOR_H
#define SENSOR_H

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

      virtual int read_method() = 0;
  
      int read()
      {
        int reading = this->read_method();  
        int ret = -1;
        if(reading != m_state)
        {
          m_state = reading;
          ret = m_state;
        }
        return ret;
      }
};

#endif
