#ifndef BASEIO_H
#define BASEIO_H

#include "Arduino.h"

class BaseIO
{
    public:
        BaseIO(int PIN, int ID, int initial_state) : 
        m_PIN{PIN},
        m_ID{ID},
        m_state{initial_state},
        set{false}
        {}

        BaseIO(int PIN, int ID) : 
        m_PIN{PIN},
        m_ID{ID},
        m_state{0},
        set{false}
        {}

        BaseIO(int PIN) : 
        m_PIN{PIN},
        m_ID{0},
        m_state{0},
        set{false}
        {}
        
        virtual void setup() = 0;
        
        int get_pin(){return m_PIN;}
        int get_ID(){return m_ID;}
        int get_state(){return m_state;}

    protected:
        int m_ID;
        int m_PIN;
        int m_state;
        int set;
};

#endif
