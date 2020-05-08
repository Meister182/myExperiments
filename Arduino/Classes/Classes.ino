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

// (PIN, ID, Initial_State)
Digital_Sensor btn(11, 1, 0);
Digital_Actuator D_led(12, 3, 0);

Analog_Sensor pot(0, 2, 0);
Analog_Actuator A_led(13, 4, 0);

void m_print(int ID, int val)
{
  Serial.print("ID: ");
  Serial.print(ID);
  Serial.print(" VAL: ");
  Serial.println(val);
}

void setup() {
  Serial.begin(9600);
}

void loop() {

  // Digital I/O
  if(btn.read() >= 0){
    m_print(btn.get_ID(), btn.get_state());
    D_led.write(btn.get_state());
  }

  // Analog I/O
  if(pot.read() >= 0){
    m_print(pot.get_ID(), pot.get_state());
    A_led.write(map(pot.get_state(), 0, 1023, 0, 255));
  }

  delay(10);
}
