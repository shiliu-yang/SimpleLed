#include "SimpleLed.h"

SimpleLed::SimpleLed(void)
{
  _pin = -1;
}

SimpleLed::SimpleLed(const int pin, const int onLevel)
{
  if (pin <= 0) {
    return;
  }

  _pin = pin;
  _onLevel = (onLevel == LOW) ? (LOW) : (HIGH);

  pinMode(pin, OUTPUT);
  digitalWrite(pin, (_onLevel == HIGH) ? (LOW) : (HIGH));
}

void SimpleLed::setState(const LedState state, const uint16_t blinkIntervalMs)
{
  int outLevel = 0;

  if (_pin <= 0) {
    return;
  }

  if (_ledState == state && _blinkIntervalMs == blinkIntervalMs) {
    return;
  }

  if (BLINK == state) {
    _blinkIntervalMs = blinkIntervalMs;
    _ledState = BLINK;
    outLevel = (_onLevel == HIGH) ? (HIGH) : (LOW);
    digitalWrite(_pin, outLevel);
    _lastLedBlinkMs = millis();
    _nowLevel = outLevel;
  } else if (ON == state) {
    outLevel = (_onLevel == HIGH) ? (HIGH) : (LOW);
    digitalWrite(_pin, outLevel);
    _ledState = ON;
  } else {
    // turn off LED
    outLevel = (_onLevel == HIGH) ? (LOW) : (HIGH);
    digitalWrite(_pin, outLevel);
    _ledState = OFF;
  }

  return;
}

void SimpleLed::setState(const uint8_t state, const uint16_t blinkIntervalMs)
{
  LedState tmpState = OFF;

  if (1 == state) {
    tmpState = ON;
  } else if (2 == state) {
    tmpState = BLINK;
  } else {
    tmpState = OFF;
  }
  setState(tmpState, blinkIntervalMs);
}

SimpleLed::LedState SimpleLed::getState(void)
{
  return _ledState;
}

void SimpleLed::update(void)
{
  unsigned long nowMs = 0;
  int outLevel = 0;

  if (_ledState != BLINK) {
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
