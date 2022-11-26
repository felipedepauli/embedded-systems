#include <setup.h>
#include "inc/tm4c129encpdt.h"


void initLeds() {

// To configure the GPIO pins of a particular port, follow these steps:

// 1.   Enable the clock to the port by setting the appropriate bits in the RCGCGPIO register (see
//      page 389). In addition, the SCGCGPIO and DCGCGPIO registers can be programmed in the
//      same manner to enable clocking in Sleep and Deep-Sleep modes.
        SYSCTL_RCGCGPIO_R    |= PORT_F | PORT_N; // Enable clock for GPIOF

// 2.   Verifica no PRGPIO se as portas estao prontas para uso. 
//	    So vai para frente quando estiveres prontas.
        //while ((SYSCTL_PRGPIO_R & (PORT_F | PORT_N)) != (PORT_F | PORT_N)){};

// 3.   Limpar o AMSEL para desabilitar a funcao analogica (sera a digital).
        GPIO_PORTF_AHB_AMSEL_R 	= 0x00;
        GPIO_PORTN_AMSEL_R		= 0x00; 

// 4.   Limpar PCTL para selecionar o GPIO.
		GPIO_PORTF_AHB_PCTL_R 	= 0x00;
        GPIO_PORTN_PCTL_R		= 0x00;

// 5.   Set the direction of the GPIO port pins by programming the GPIODIR register. A write of a 1
//      indicates output and a write of a 0 indicates input.
        GPIO_PORTF_AHB_DIR_R    |= LED3 | LED4;   
        GPIO_PORTN_DIR_R		|= LED1 | LED2;

// 6.   Configure the GPIOAFSEL register to program each bit as a GPIO or alternate pin. If an alternate
//      pin is chosen for a bit, then the PMCx field must be programmed in the GPIOPCTL register for
//      the specific peripheral required. There are also two registers, GPIOADCCTL and GPIODMACTL,
//      which can be used to program a GPIO pin as a ADC or μDMA trigger, respectively.
        GPIO_PORTN_AFSEL_R		= 0x00;
        GPIO_PORTF_AHB_AFSEL_R 	= 0x00;

// 7.   To enable GPIO pins as digital I/Os, set the appropriate DEN bit in the GPIODEN register. To
//      enable GPIO pins to their analog function (if available), set the GPIOAMSEL bit in the
//      GPIOAMSEL register.
        GPIO_PORTN_DEN_R		|= LED1 | LED2;
        GPIO_PORTF_AHB_DEN_R 	|= LED3 | LED4;


// 8.  Turning the LEDs on, off and on for Debug.   
        GPIO_PORTN_DATA_R         |= LED1 | LED2;     // Turn on LED
        GPIO_PORTF_AHB_DATA_R     |= LED3 | LED4;     // Turn on LED

        GPIO_PORTN_DATA_R         &= ~LED1 & ~LED2;   // Turn off LED
        GPIO_PORTF_AHB_DATA_R     &= ~LED3 & ~LED4;   // Turn off LED

        GPIO_PORTN_DATA_R         |= LED1 | LED2;     // Turn on LED
        GPIO_PORTF_AHB_DATA_R     |= LED3 | LED4;     // Turn on LED

}