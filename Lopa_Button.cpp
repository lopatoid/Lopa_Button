#include <Arduino.h>
#include <Lopa_Button.h>

namespace Lopa {

  /** mode -- INPUT or INPUT_PULLUP **/
  Button::Button(uint8_t pin, uint8_t mode)
  {
    _pin = pin;
    pinMode(_pin, mode);
    _prev_state = (digitalRead(_pin) == HIGH);
  }


  void Button::setDebounceTimeout(uint16_t debounce_timeout) {
    _debounce_timeout = debounce_timeout;
  }


  bool Button::onPressed() {
    _processButton();
    if (_has_been_pressed) {
      _has_been_pressed = false;
      return true;
    } else
      return false;
  }


  bool Button::onReleased() {
    _processButton();
    if (_has_been_released) {
      _has_been_released = false;
      return true;
    } else
      return false;
  }

  bool Button::isPressed() {
    _processButton();
    return !_prev_state;
  }


  bool Button::isReleased() {
    _processButton();
    return _prev_state;
  }

  //private

  void Button::_processButton() {
    _cur_state = (digitalRead(_pin) == HIGH);
    if (_prev_state == _cur_state)
      time = millis();
    else {
      if (millis() - time > _debounce_timeout) {
        _has_been_pressed = _prev_state;
        _has_been_released = !_prev_state;
        _prev_state = _cur_state;
      }
    }
  }
}