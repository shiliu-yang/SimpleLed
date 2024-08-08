# SimpleLed

[English](./README.md) | [中文](./README_ZH.md)

`SimpleLed` is an Arduino library that controls the on, off, and blink functions of LEDs. It's a particularly simple project that aims to control LED blinking without using blocking delays.

## 1. Including header files

You need to include `SimpleLed.h` in your project.
```cpp
#include "SimpleLed.h"
```

## 2. Initialize LED
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

## 3. Control LED

### 3.1 Turn on the LED
```cpp
    led.setState(SimpleLed::LedState::ON);
```
Or:
```cpp
    led.setState(1);
```
Or:
```cpp
    led.on();
```

### 3.2 Turn off the LED
```cpp
    led.setState(SimpleLed::LedState::OFF);
```
Or:
```cpp
    led.setState(0);
```
Or:
```cpp
    led.off();
```

### 3.3 Blink the LED
The LED switches state every 1s (on-1s->off-1s->on ->...) and you need to call update() in loop():
```cpp
void setup() {
    led.setState(SimpleLed::LedState::BLINK, 1000);
}

void loop() {
    led.update();
}
```
Or:
```cpp
void setup() {
    led.blink(1000);
}

void loop() {
    led.update();
}
```
