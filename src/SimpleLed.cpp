#include "SimpleLed.h"

SimpleLed::SimpleLed(void)
{
  _pin = -1;
}

SimpleLed::SimpleLed(const int pin, const int onLevel)
{
  _pin = pin;
  _onLevel = (onLevel == LOW) ? (LOW) : (HIGH);

  pinMode(pin, OUTPUT);

}

void SimpleLed::setState(const LedState state, const int blinkIntervalMs)
{
  int outLevel = 0;

  if (_pin <= 0) {
    return;
  }

  if (LED_BLINK == state) {
    _blinkIntervalMs = blinkIntervalMs;
    _ledState = LED_BLINK;
    outLevel = (_onLevel == HIGH) ? (HIGH) : (LOW);
    digitalWrite(_pin, outLevel);
    _lastLedBlinkMs = millis();
    _nowLevel = outLevel;
  } else if (LED_ON == state) {
    outLevel = (_onLevel == HIGH) ? (HIGH) : (LOW);
    digitalWrite(_pin, outLevel);
    _ledState = LED_ON;
  } else {
    // turn off LED
    outLevel = (_onLevel == HIGH) ? (LOW) : (HIGH);
    digitalWrite(_pin, outLevel);
    _ledState = LED_OFF;
  }

  return;
}

SimpleLed::LedState SimpleLed::getState(void)
{
  return _ledState;
}

void SimpleLed::update(void)
{
  unsigned long nowMs = 0;
  int outLevel = 0;

  if (_ledState != LED_BLINK) {
    return;
  }
  
  nowMs = millis();
  if (nowMs >= _lastLedBlinkMs + _blinkIntervalMs) {
    _lastLedBlinkMs = nowMs;
    outLevel = (_nowLevel == LOW) ? (HIGH) : (LOW);
    digitalWrite(_pin, outLevel);
    _nowLevel = outLevel;
  }

  return;
}
