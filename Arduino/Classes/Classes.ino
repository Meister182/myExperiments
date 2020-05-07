#include "Digital_Sensor.hpp"
#include "Analog_Sensor.hpp"

#include "Digital_Actuator.hpp"
#include "Analog_Actuator.hpp"

// (PIN, ID, Initial_State)
Digital_Sensor btn(13, 1, 0);
Digital_Actuator D_led(12, 3, 0);

Analog_Sensor pot(0, 2, 0);
Analog_Actuator A_led(11, 4, 0);

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

  delay(100);
}

void m_print(int ID, int val)
{
  Serial.print("ID: ");
  Serial.print(ID);
  Serial.print(" VAL: ");
  Serial.println(val);
}
