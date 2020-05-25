#ifndef BASE_ACTUATOR_H
#define BASE_ACTUATOR_H

#include "Arduino.h"

class Base_Actuator : public BaseIO
{
    public:
      Base_Actuator(int PIN, int ID, int initial_state) : 
          BaseIO(PIN, ID, initial_state){setup();}
      Base_Actuator(int PIN, int ID) : 
          BaseIO(PIN, ID){setup();}
      Base_Actuator(int PIN) : 
          BaseIO(PIN){setup();}

      virtual void setup(){
        if(!set){
          set = true;
          pinMode(m_PIN, OUTPUT);
        }
      }

      virtual void write(int val){};
};

#endif
