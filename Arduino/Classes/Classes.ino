/*
 * Example Code:
 *    Easily add Analog and Digital I/O to Arduino
 *    
 * Connections:
 *    Digital Input - button connected to pin 11
 *    Digital Output - LED connected to pin 12
 *    
 *    Analog Input - Pot connected to ANALOG IN pin 0
 *    Analog output - LED connected to pin 13 (PWM capable)
 */
#include "include/Digital_Sensor.hpp"
#include "include/Digital_Actuator.hpp"

#include "include/Analog_Sensor.hpp"
#include "include/Analog_Actuator.hpp"

void m_print(int ID, int val);

// (PIN, ID, Initial_State)
/* --------- Sensors --------- */
int num_of_sensors = 2;
Base_Sensor *Sensors[] = {
  new Digital_Sensor(11, 1, 0), // button 
  new Analog_Sensor(0, 2, 0)    // potentiometer
};

/* --------- Actuators --------- */
int num_of_actuators = 2;
Base_Actuator *Actuators[] = {
  new Digital_Actuator(12, 3, 0),  // on/off led
  new Analog_Actuator(13, 4, 0)    // pwm led
};


void setup() {
  Serial.begin(9600);
}

void loop() {
  // ------------------------------------------
  // Example:
  //   Digital In connected to Digital Out
  //   Analog In connected to Analog Out
  // ------------------------------------------
  for(int i=0; i<num_of_sensors; i++)
  {
    if(Sensors[i]->read() >= 0)
    {
      m_print(Sensors[i]->get_ID(), Sensors[i]->get_state());
      Actuators[i]->write(Sensors[i]->get_state());
    }
  }
  delay(10);
}


void m_print(int ID, int val)
{
  Serial.print("ID: ");
  Serial.print(ID);
  Serial.print(" VAL: ");
  Serial.println(val);
}
