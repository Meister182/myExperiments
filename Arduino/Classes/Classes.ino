#include "Digital_Sensor.hpp"
#include "Digital_Actuator.hpp"

Digital_Sensor m_btn(7, 1, 0);
Digital_Actuator m_led(2, 2, 0);

void setup() {
  Serial.begin(9600);
}

void loop() {

  if(m_btn.read() >= 0){
    Serial.println(m_btn.get_state());
    m_led.write(m_btn.get_state());
  }

  delay(100);
}
