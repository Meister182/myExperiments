#ifndef DIGITAL_SENSOR_H
#define DIGITAL_SENSOR_H

#include "Base_Sensor.hpp"

class Digital_Sensor : public Base_Sensor
{
  public:
    Digital_Sensor(int PIN, int ID, int initial_state) : 
        Base_Sensor(PIN, ID, initial_state){}
    Digital_Sensor(int PIN, int ID) : 
        Base_Sensor(PIN, ID){}
    Digital_Sensor(int PIN) : 
        Base_Sensor(PIN){}
 
    virtual int read(){return update_state(digitalRead(m_PIN));}
};

#endif
