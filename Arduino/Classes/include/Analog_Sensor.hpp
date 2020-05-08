#ifndef ANALOG_SENSOR_H
#define ANALOG_SENSOR_H

#include "Base_Sensor.hpp"

class Analog_Sensor : public Base_Sensor
{
  public:
    Analog_Sensor(int PIN, int ID, int initial_state) : 
        Base_Sensor(PIN, ID, initial_state){}
    Analog_Sensor(int PIN, int ID) : 
        Base_Sensor(PIN, ID){}
    Analog_Sensor(int PIN) : 
        Base_Sensor(PIN){}
 
     virtual int read_method(){return analogRead(m_PIN);}
};

#endif
