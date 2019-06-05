/*
  Lopa_Button.h - Library for debounce buttons.
  Created by Lopatoid.
*/
#ifndef LOPA_BUTTON_H
#define LOPA_BUTTON_H

#include <Arduino.h>

namespace Lopa {
  class Button {
    public:
      Button(uint8_t pin, uint8_t mode);
      void setDebounceTimeout(uint16_t debounce_timeout);
      bool isPressed();
      bool isReleased();
      bool onPressed();
      bool onReleased();
    private:
      uint8_t _pin;
      uint16_t _debounce_timeout = 20; // ms
      unsigned long time = 0;
      bool _prev_state = true;
      bool _cur_state = true;
      bool _has_been_pressed  = false;
      bool _has_been_released = false;
      void _processButton();
  };
}
#endif