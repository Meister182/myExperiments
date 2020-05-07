#ifndef ACTUATOR_H
#define ACTUATOR_H

#include "Arduino.h"

class Actuator : public BaseIO
{
    public:
      Actuator(int PIN, int ID, int initial_state) : 
          BaseIO(PIN, ID, initial_state){setup();}
      Actuator(int PIN, int ID) : 
          BaseIO(PIN, ID){setup();}
      Actuator(int PIN) : 
          BaseIO(PIN){setup();}

      virtual void setup(){pinMode(m_PIN, OUTPUT);}

      virtual int write(int val) = 0;
};

#endif
