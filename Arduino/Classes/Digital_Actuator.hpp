#ifndef DIGITAL_ACTUATOR_H
#define DIGITAL_ACTUATOR_H

#include "Actuator.hpp"

class Digital_Actuator : public Actuator
{
  public:
    Digital_Actuator(int PIN, int ID, int initial_state) : 
        Actuator(PIN, ID, initial_state){}
    Digital_Actuator(int PIN, int ID) : 
        Actuator(PIN, ID){}
    Digital_Actuator(int PIN) : 
        Actuator(PIN){}
 
    virtual int write(int val)
    {
      if(val != m_state){
        m_state = val;
        if(m_state > 0){
          digitalWrite(m_PIN, HIGH);
        }else{
          digitalWrite(m_PIN, LOW);      
        }
      }
    }
};

#endif
