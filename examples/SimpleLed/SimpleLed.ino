#include "SimpleLed.h"

#define LED_PIN LED_BUILTIN

// Initialise the LED and light it up when the pin output is high
SimpleLed led(LED_PIN, HIGH);

void setup() {
  // Trun on LED
  led.setState(SimpleLed::LedState::ON);
  delay(1000);

  // Trun off LED
  led.setState(SimpleLed::LedState::OFF);
  delay(1000);

  // LED blinking, status switching every 500ms
  led.setState(SimpleLed::LedState::BLINK, 500);
}

void loop() {
  led.update();

  // Do other things...
}
