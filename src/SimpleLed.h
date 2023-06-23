#pragma once

#include <Arduino.h>

class SimpleLed
{
public:
  enum LedState {
    OFF = 0,
    ON,
    BLINK,
  };

  SimpleLed();

  /**
   * Initialize the LED.
   * @param pin The pin for LED output.
   * @param onLevel Level value when the LED is turned on.
   */
  SimpleLed(const int pin, const int onLevel=HIGH);

  /**
   * Set LED status.
   * @param state The pin for LED output.
   * @param blinkIntervalMs LED state change time (ms) when the LED is blinking.
   *                When the LED is blinking, update() needs to be called periodically.
   */
  void setState(const LedState state, const int blinkIntervalMs=500);

  /**
   * When the LED is blinking,
   *  you need to call update() to calculate the time to change the LED state.
   */
  void update(void);

  /**
   * Get LED status.
   */
  LedState getState(void);

private:
  int _pin = -1;
  int _onLevel = HIGH;
  LedState _ledState = OFF;

  int _blinkIntervalMs = 500;
  int _nowLevel = LOW;
  unsigned long _lastLedBlinkMs = 0;
};
