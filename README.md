# SimpleLed

[English](./README.md) | [中文](./README_ZH.md)

`SimpleLed` is an Arduino library that controls the on, off, and blink functions of LEDs. It's a particularly simple project that aims to control LED blinking without using blocking delays.

## Get start

You need to include `SimpleLed.h` in your project.
```cpp
#include "SimpleLed.h"
```

### How to initialize
After initializing the LED pin, the LED will be set to the off state by default.

To turn on the LED when the pin output is high:
```cpp
#define LED_PIN LED_BUILTIN

SimpleLed led(LED_PIN);
```
Or:
```cpp
#define LED_PIN LED_BUILTIN

SimpleLed led(LED_PIN, HIGH);
```

To turn on the LED when the pin output is low:
```cpp
#define LED_PIN LED_BUILTIN

SimpleLed led(LED_PIN, LOW);
```

### How to control the LED

Turn on the LED:
```cpp
    led.setState(SimpleLed::LedState::ON);
```

Turn off the LED:
```cpp
    led.setState(SimpleLed::LedState::OFF);
```

The LED switches state every 1s (on-1s->off-1s->on ->...) and you need to call update() in loop():
```cpp
void setup() {
    led.setState(SimpleLed::LedState::BLINK, 1000);
}

void loop() {
    led.update();
}
```
