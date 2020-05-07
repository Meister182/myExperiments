#ifndef ANALOG_SENSOR_H
#define ANALOG_SENSOR_H

#include "Sensor.hpp"

class Analog_Sensor : public Sensor
{
  public:
    Analog_Sensor(int PIN, int ID, int initial_state) : 
        Sensor(PIN, ID, initial_state){}
    Analog_Sensor(int PIN, int ID) : 
        Sensor(PIN, ID){}
    Analog_Sensor(int PIN) : 
        Sensor(PIN){}
 
     virtual int read_method(){return analogRead(m_PIN);}
};

#endif
