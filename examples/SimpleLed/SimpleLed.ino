#include "SimpleLed.h"

#define LED_PIN LED_BUILTIN

// Initialise the LED and light it up when the pin output is high
SimpleLed led(LED_PIN, HIGH);

void setup() {
  // Trun on LED
  led.on();
  delay(3000);

  // Trun off LED
  led.off();
  delay(3000);

  // Trun on LED
  led.setState(1);
  delay(3000);

  // Trun off LED
  led.setState(0);
  delay(3000);

  // LED blinking, status switching every 500ms
  led.blink(500);
}

void loop() {
  led.update();

  // Do other things...
}
