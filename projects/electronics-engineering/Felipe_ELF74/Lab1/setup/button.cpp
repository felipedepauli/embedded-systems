#include <setup.h>
#include "inc/tm4c129encpdt.h"


void initButtons() {

// // To configure the GPIO pins of a particular port, follow these steps:

// 1.   Enable the clock to the port by setting the appropriate bits in the RCGCGPIO register (see
//      page 389). In addition, the SCGCGPIO and DCGCGPIO registers can be programmed in the
//      same manner to enable clocking in Sleep and Deep-Sleep modes.
        SYSCTL_RCGCGPIO_R    |= PORT_J; // Enable clock for GPIOJ

// 2.   Set the direction of the GPIO port pins by programming the GPIODIR register. A write of a 1
//      indicates output and a write of a 0 indicates input.
        GPIO_PORTJ_AHB_AMSEL_R 	= 0x00;
        GPIO_PORTJ_AHB_PCTL_R 	= 0x00;
        GPIO_PORTJ_AHB_DIR_R    &= ~(SW0) & ~(SW1); 
        GPIO_PORTJ_AHB_AFSEL_R 	&= ~(SW0) & ~(SW1);
        GPIO_PORTJ_AHB_DEN_R 	|= SW0 | SW1;

        GPIO_PORTJ_AHB_PUR_R      |= SW0 | SW1; // Enable internal pull-up resistors
//      This will set the button 1 when released and 0 when pressed.

// // 4.   Configure the GPIOAFSEL register to program each bit as a GPIO or alternate pin. If an alternate
// //      pin is chosen for a bit, then the PMCx field must be programmed in the GPIOPCTL register for
// //      the specific peripheral required. There are also two registers, GPIOADCCTL and GPIODMACTL,
// //      which can be used to program a GPIO pin as a ADC or μDMA trigger, respectively.

// // 4.   Set the EDMn field in the GPIOPC register as shown in Table 10-3 on page 761.

// // 5.   Set or clear the GPIODR4R register bits as shown in Table 10-3 on page 761.

// // 6.   Set or clear the GPIODR8R register bits as shown in Table 10-3 on page 761.

// // 7.   Set or clear the GPIODR12R register bits as shown in Table 10-3 on page 761.


// // Program each pad in the port to have either pull-up, pull-down, or open drain functionality through
// // the GPIOPUR, GPIOPDR, GPIOODR register. Slew rate may also be programmed, if needed,
// // through the GPIOSLR register.

// 9.   To enable GPIO pins as digital I/Os, set the appropriate DEN bit in the GPIODEN register. To
//      enable GPIO pins to their analog function (if available), set the GPIOAMSEL bit in the
//      GPIOAMSEL register.
       

// // 10.  Program the GPIOIS, GPIOIBE, GPIOEV, and GPIOIM registers to configure the type, event,
// //      and mask of the interrupts for each port.
// //      Note: To prevent false interrupts, the following steps should be taken when re-configuring
// //      GPIO edge and interrupt sense registers:
// //              a. Mask the corresponding port by clearing the IME field in the GPIOIM register.
// //              b. Configure the IS field in the GPIOIS register and the IBE field in the GPIOIBE
// //                 register.
// //              c. Clear the GPIORIS register.
// //              d. Unmask the port by setting the IME field in the GPIOIM register.

// // 11.  Optionally, software can lock the configurations of the NMI and JTAG/SWD pins on the GPIO
// //      port pins, by setting the LOCK bits in the GPIOLOCK register.
// //      When the internal POR signal is asserted and until otherwise configured, all GPIO pins are configured
// //      to be undriven (tristate): GPIOAFSEL=0, GPIODEN=0, GPIOPDR=0, and GPIOPUR=0Table
// //      10-4 on page 762 shows all possible configurations of the GPIO pads and the control register settings
// //      required to achieve them. Table 10-5 on page 763 shows how a rising edge interrupt is configured
// //      for pin 2 of a GPIO port.
    
}