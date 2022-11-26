#include <futils.h>
#include <setup.h>
#include "inc/tm4c129encpdt.h"

void futils::turnLedOn(uint8_t led, bool isOn) {
    switch (led) {
        case 1: 
                if (isOn) GPIO_PORTN_DATA_R  |= (LED1);
                else      GPIO_PORTN_DATA_R  &= ~(LED1);
                break;
        case 2:
                if (isOn) GPIO_PORTN_DATA_R  |= (LED2);
                else      GPIO_PORTN_DATA_R  &= ~(LED2);
                break;
        case 3:
                if (isOn) GPIO_PORTF_AHB_DATA_R  |= (LED3);
                else      GPIO_PORTF_AHB_DATA_R  &= ~(LED3);
                break;
        case 4:
                if (isOn) GPIO_PORTF_AHB_DATA_R  |= (LED4);
                else      GPIO_PORTF_AHB_DATA_R  &= ~(LED4);
                break;
        default:
                break;
    }
}

void delay (uint32_t time) {
    while (time--);
}

void futils::console(char c) {
        while((UART0_FR_R & (1<<5)) != 0);
        UART0_DR_R = c;
        delay(1000000);
}

char futils::getChar() {
        while((UART0_FR_R & (1<<5)) != 0);
        char data = UART0_DR_R;
        return data;
}


uint8_t futils::getButtonState(uint8_t sw) {
    return (sw == 0) ? ((GPIO_PORTJ_AHB_DATA_R & SW0) >> 0) : ((GPIO_PORTJ_AHB_DATA_R & SW1) >> 1);
}