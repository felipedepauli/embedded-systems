#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

#include <setup.h>
#include <futils.h>

using futils::turnLedOn;
using futils::getButtonState;
using futils::console;
using futils::getChar;

int main()
{
	initLeds();
	initButtons();
	initInterruptions();
	initUART();
        char o = 'x';
        char c;
	while(1) {
          o = c;
          c = getChar();
          if (o != c) console(c);
          o = c;
          if (c == 'q') break;
	}

	return 0;
}

void loop_01() {
	turnLedOn(1, getButtonState(0));
	turnLedOn(2, getButtonState(1));
}