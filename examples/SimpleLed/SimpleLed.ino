#include "SimpleLed.h"

#define LED_PIN LED_BUILTIN

// Initialise the LED and light it up when the pin output is high
SimpleLed led(LED_PIN, HIGH);

uint8_t curLedState = 0;

void setup() {
  Serial.begin(115200);

  // Trun on LED
  led.setState(SimpleLed::LedState::ON);
  curLedState = led.getState();
  Serial.print("---> curLedState: "); Serial.println(curLedState);
  delay(1500);

  // Trun off LED
  led.setState(SimpleLed::LedState::OFF);
  curLedState = led.getState();
  Serial.print("---> curLedState: "); Serial.println(curLedState);
  delay(1500);

  // Trun on LED
  led.setState(1);
  delay(1500);

  // Trun off LED
  led.setState(0);
  delay(1500);

  // Trun on LED
  led.on();
  delay(1500);

  // Trun off LED
  led.off();
  delay(1500);

  // LED blinking, status switching every 100ms
  led.blink(100);
}

void loop() {
  led.update();
  // Do other things...

  delay(1);
}
