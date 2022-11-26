#ifndef __SETUP_H__
#define __SETUP_H__

#include <stdint.h>

#define PORT_A (1<<0)
#define PORT_B (1<<1)
#define PORT_C (1<<2)
#define PORT_D (1<<3)
#define PORT_E (1<<4)
#define PORT_F (1<<5)
#define PORT_G (1<<6)
#define PORT_H (1<<7)
#define PORT_J (1<<8)
#define PORT_K (1<<9)
#define PORT_L (1<<10)
#define PORT_M (1<<11)
#define PORT_N (1<<12)
#define PORT_O (1<<13)
#define PORT_P (1<<14)

#define LED1 (1<<1) // PN1
#define LED2 (1<<0) // PN0
#define LED3 (1<<4) // PF4
#define LED4 (1<<0) // PF0

#define SW0  (1<<0) // PJ0
#define SW1  (1<<1) // PJ1

#define UART_0 (1<<0)

void initLeds();
void initButtons();
void initInterruptions();
void initUART();
void initSystick();

namespace setup {
   
};

#endif // __SETUP_H__