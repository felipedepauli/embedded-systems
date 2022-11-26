#ifndef __FUTILS_H__
#define __FUTILS_H__

#include <stdint.h>



namespace futils {
  void      turnLedOn(uint8_t led, bool isOn);
  uint8_t   getButtonState(uint8_t sw);
  void      console(char c);
  char      getChar();
 
};




#endif // __FUTILS_H__