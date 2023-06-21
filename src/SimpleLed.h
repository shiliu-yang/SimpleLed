#pragma once

#include <Arduino.h>

class SimpleLed
{
public:
  enum LedState {
    LED_OFF = 0,
    LED_ON,
    LED_BLINK,
  };

  SimpleLed();
  SimpleLed(const int pin, const int onLevel=HIGH);

  void setState(const LedState state, const int blinkIntervalMs=500);
  LedState getState(void);

  void update(void);

private:
  int _pin = -1;
  int _onLevel = HIGH;
  LedState _ledState = LED_OFF;

  int _blinkIntervalMs = 500;
  int _nowLevel = LOW;
  unsigned long _lastLedBlinkMs = 0;
};
