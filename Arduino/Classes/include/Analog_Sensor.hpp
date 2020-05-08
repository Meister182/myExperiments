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
 
    /* Note:
     *  Analog Input pins are used to measure a voltage. 
     * Therefore there is no need to set pin mode for 
     * Analog sensors.
     */
    virtual void setup() {}

    virtual int read_method(){return analogRead(m_PIN);}
};

#endif
