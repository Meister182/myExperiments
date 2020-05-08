#ifndef ANALOG_ACTUATOR_H
#define ANALOG_ACTUATOR_H

#include "Base_Actuator.hpp"

class Analog_Actuator : public Base_Actuator
{
  public:
    Analog_Actuator(int PIN, int ID, int initial_state) : 
        Base_Actuator(PIN, ID, initial_state){}
    Analog_Actuator(int PIN, int ID) : 
        Base_Actuator(PIN, ID){}
    Analog_Actuator(int PIN) : 
        Base_Actuator(PIN){}
 
    virtual int write(int val)
    {
      if(val != m_state && val >= 0 && val <= 255){
        m_state = val;
        analogWrite(m_PIN, m_state);
      }
    }
};

#endif
