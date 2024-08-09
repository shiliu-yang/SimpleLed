#include "SimpleLed.h"

SimpleLed::SimpleLed() : _pin(-1) {}

SimpleLed::SimpleLed(int pin, int onLevel) {
  if (pin > 0) {
    _pin = pin;
    _onLevel = (onLevel == LOW) ? LOW : HIGH;

    pinMode(pin, OUTPUT);
    digitalWrite(pin, (_onLevel == HIGH) ? LOW : HIGH);
  }
}

void SimpleLed::_setLedState(LedState state, uint16_t blinkIntervalMs) {
  int outLevel = 0;

  if (_pin <= 0) {
    return;
  }

  if (_ledState == state && _blinkIntervalMs == blinkIntervalMs) {
    return;
  }

  _ledState = state;

  switch (state) {
    case (BLINK) : {
      _blinkIntervalMs = blinkIntervalMs;

      outLevel = (_onLevel == HIGH) ? (HIGH) : (LOW);
      _nowLevel = outLevel;

      _lastLedBlinkMs = millis();

      digitalWrite(_pin, outLevel);
    } break;
    case (ON) : {
      outLevel = (_onLevel == HIGH) ? (HIGH) : (LOW);
      digitalWrite(_pin, outLevel);
    } break;
    default : { // off
      outLevel = (_onLevel == HIGH) ? (LOW) : (HIGH);
      digitalWrite(_pin, outLevel);
    } break;
  }

  return;
}

// template <typename T, typename M>
// void SimpleLed::setState(T state, M blinkIntervalMs) {
//   uint8_t u8State = static_cast<T>(state);
//   LedState tmpState = (u8State == 1) ? (ON) : ((u8State == 2) ? BLINK : OFF);
//   uint16_t blinkMs = static_cast<uint16_t>(blinkIntervalMs);

//   setState(tmpState, blinkMs);
// }

// template <typename T>
// void SimpleLed::setState(T state) {
//   uint8_t u8State = static_cast<T>(state);
//   LedState tmpState = (u8State == 1) ? (ON) : ((u8State == 2) ? BLINK : OFF);

//   setState(tmpState, _blinkIntervalMs);
// }

// void SimpleLed::on(void)
// {
//   setState(LedState::ON, _blinkIntervalMs);
// }

// void SimpleLed::off(void)
// {
//   setState(LedState::OFF, _blinkIntervalMs);
// }

// template <typename M>
// void SimpleLed::blink(M ms)
// {
//   uint16_t blinkMs = static_cast<uint16_t>(ms);

//   setState(LedState::BLINK, blinkMs);
// }

// SimpleLed::LedState SimpleLed::getState() {
//   return _ledState;
// }

// template <typename T>
// T SimpleLed::getState()
// {
//   uint8_t tmpState = (_ledState == ON) ? (1) : ((_ledState == BLINK) ? (2) : (0));

//   T state = static_cast<T>(tmpState);

//   return state;
// }

void SimpleLed::update() {
  if (_pin <= 0) {
    return;
  }

  if (_ledState == BLINK && millis() >= _lastLedBlinkMs + _blinkIntervalMs) {
    _lastLedBlinkMs = millis();
    _nowLevel = (_nowLevel == LOW) ? HIGH : LOW;
    digitalWrite(_pin, _nowLevel);
  }
}
