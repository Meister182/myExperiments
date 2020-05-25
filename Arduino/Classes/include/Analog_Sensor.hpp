#ifndef ANALOG_SENSOR_H
#define ANALOG_SENSOR_H

#include "Base_Sensor.hpp"

class Analog_Sensor : public Base_Sensor
{
  public:
    Analog_Sensor(int PIN, int ID, int initial_state) : 
        m_sensibility{5},
        Base_Sensor(PIN, ID, initial_state){}
    Analog_Sensor(int PIN, int ID) : 
        m_sensibility{5},
        Base_Sensor(PIN, ID){}
    Analog_Sensor(int PIN) : 
        m_sensibility{5},
        Base_Sensor(PIN){}
 
    /* Note:
     *  Analog Input pins are used to measure a voltage. 
     * Therefore there is no need to set pin mode for 
     * Analog sensors.
     */
    virtual void setup() {}

    virtual int read(){return m_filter(analogRead(m_PIN));}

    void set_sensibility(int sensibility)
    {
        m_sensibility = sensibility;
    }

  private:

    int m_filter(int current)
    {
        int ret = m_state;
        if(abs(m_state - current) >= m_sensibility)
        {
            ret = current;
        }
        return update_state(ret);
    }

    int m_sensibility;
};

#endif
