#ifndef SENSOR_H
#define SENSOR_H

#include "BaseIO.hpp"

class Sensor: public BaseIO
{
    public:
      Sensor(int PIN, int ID, int initial_state) : 
          BaseIO(PIN, ID, initial_state){setup();}
      Sensor(int PIN, int ID) : 
          BaseIO(PIN, ID){setup();}
      Sensor(int PIN) : 
          BaseIO(PIN){setup();}
  
      virtual void setup(){pinMode(m_PIN, INPUT);}

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
