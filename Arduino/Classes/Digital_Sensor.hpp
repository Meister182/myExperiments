#ifndef DIGITAL_SENSOR_H
#define DIGITAL_SENSOR_H

#include "Sensor.hpp"

class Digital_Sensor : public Sensor
{
  public:
    Digital_Sensor(int PIN, int ID, int initial_state) : 
        Sensor(PIN, ID, initial_state){}
    Digital_Sensor(int PIN, int ID) : 
        Sensor(PIN, ID){}
    Digital_Sensor(int PIN) : 
        Sensor(PIN){}
 
     virtual int read_method(){return digitalRead(m_PIN);}
};

#endif
