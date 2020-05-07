#ifndef ANALOG_ACTUATOR_H
#define ANALOG_ACTUATOR_H

#include "Actuator.hpp"

class Analog_Actuator : public Actuator
{
  public:
    Analog_Actuator(int PIN, int ID, int initial_state) : 
        Actuator(PIN, ID, initial_state){}
    Analog_Actuator(int PIN, int ID) : 
        Actuator(PIN, ID){}
    Analog_Actuator(int PIN) : 
        Actuator(PIN){}
 
    virtual int write(int val)
    {
      if(val != m_state && val >= 0 && val <= 255){
        m_state = val;
        analogWrite(m_PIN, m_state);
      }
    }
};

#endif
