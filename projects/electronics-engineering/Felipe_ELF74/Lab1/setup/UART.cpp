#include <setup.h>
#include "inc/tm4c129encpdt.h"
#include ""

void initUART() {

// //
// // The interrupt handler function.
// //
// extern void IntHandler(void);
// //
// // Register the interrupt handler function for UART 0.
// //
// IntRegister(INT_UART0, IntHandler);
// //
// // Enable the interrupt for UART 0.
// //
// IntEnable(INT_UART0);
// //
// // Enable UART 0.
// //
// IntMasterEnable();



// //  This documentation was taken from datasheet.
// //  Page 1296

// //  INITIALIZATION AND CONFIGURATION
// //
// //  To enable and initialize the UART, the following steps are necessary:
// //
// //  1.  Enable the UART module using the RCGCUART register (see page 395).
// //
// //      --  The RCGCUART register provides software the capability to enable and disable the UART modules
// //      --  in Run mode. When enabled, a module is provided a clock and accesses to module registers are
// //      --  allowed. When disabled, the clock is disabled to save power and accesses to module registers
// //      --  generate a bus fault.

// //      Register Clock Gating Control
//         SYSCTL_RCGCUART_R |= UART_0; // Enable clock for UART0

// // 2.   Enable the clock to the appropriate GPIO module via the RCGCGPIO register (see page 389).
//         SYSCTL_RCGCGPIO_R |= PORT_A; // Enable clock for GPIOA
// //      To find out which GPIO port to enable, refer to Table 29-5 on page 1932.
// //
// // 3.   Set the GPIO AFSEL bits for the appropriate pins (see page 778). To determine which GPIOs to
// //      configure, see Table 29-4 on page 1921.
// //      The GPIOAFSEL register is the mode control select register. If a bit is clear, the pin is used as a
// //      GPIO and is controlled by the GPIO registers. Setting a bit in this register configures the
// //      corresponding GPIO line to be controlled by an associated peripheral. Several possible peripheral
// //      functions are multiplexed on each GPIO. The GPIO Port Control (GPIOPCTL) register is used to
// //      select one of the possible functions. Table 29-5 on page 1932 details which functions are muxed on
// //      each GPIO pin. The reset value for this register is 0x0000.0000 for GPIO ports that are not listed
// //      in the table below. 778
// //      In this case, this register is used by UART, and not by GPIO.
// //      
//         GPIO_PORTA_AHB_AFSEL_R |= (1<<0) | (1<<1); // We need two bits (0 and 1) to Rx and Tx.

// // 4.   Configure the GPIO current level and/or slew rate as specified for the mode selected (see
// //      page 780 and page 788).
// //      ----

// // 5.   Configure the PMCn fields in the GPIOPCTL register to assign the UART signals to the appropriate
// //      pins (see page 795 and Table 29-5 on page 1932).
//         GPIO_PORTA_AHB_PCTL_R |= (1<<0) | (1<<4); // 



//         GPIO_PORTA_AHB_DEN_R  |= (1<<0) | (1<<1); // 

// // To use the UART, the peripheral clock must be enabled by setting the appropriate bit in the
// // RCGCUART register (page 395). In addition, the clock to the appropriate GPIO module must be
// // enabled via the RCGCGPIO register (page 389) in the System Control module. To find out which
// // GPIO port to enable, refer to Table 29-5 on page 1932.

// // This section discusses the steps that are required to use a UART module. For this example, the
// // UART clock is assumed to be 20 MHz, and the desired UART configuration is:

// //      ■ 115200 baud rate
// //      ■ Data length of 8 bits
// //      ■ One stop bit
// //      ■ No parity
// //      ■ FIFOs disabled
// //      ■ No interrupts

    
// // The first thing to consider when programming the UART is the baud-rate divisor (BRD), because
// // the UARTIBRD and UARTFBRD registers must be written before the UARTLCRH register. Using
// // the equation described in “Baud-Rate Generation” on page 1289, the BRD can be calculated:
// // BRD = 20,000,000 / (16 * 115,200) = 10.8507
// // which means that the DIVINT field of the UARTIBRD register (see page 1308) should be set to 10
// // decimal or 0xA. The value to be loaded into the UARTFBRD register (see page 1309) is calculated
// // by the equation:

// //      UARTFBRD[DIVFRAC] = integer(0.8507 * 64 + 0.5) = 54
// // With the BRD values in hand, the UART configuration is written to the module in the following order:

// //  1.  Disable the UART by clearing the UARTEN bit in the UARTCTL register.
//         UART0_CTL_R  &= (~(1<<0)) & (~(1<<8)) & (~(1<<9)); // Disable UART0

// //      IBRD = UARTSysClk / (ClkDiv * BaudRate)
// //      FBRD = round(64 * (IBRD - integer(IBRD)))

// //  2.  Write the integer portion of the BRD to the UARTIBRD register.
//         UART0_IBRD_R  = 104;

// //  3.  Write the fractional portion of the BRD to the UARTFBRD register.
//         UART0_FBRD_R  = 11;

// //  4.  Write the desired serial parameters to the UARTLCRH register (in this case, a value of
// //      0x0000.0060).
//         UART0_LCRH_R = (
// 					UART_LCRH_WLEN_8| 	// palavra com 8 bits
// 					UART_LCRH_FEN
// 				);

// //  5.  Configure the UART clock source by writing to the UARTCC register.
//         UART0_CC_R    = 0x5; // Select clock source

// //  6.  Optionally, configure the µDMA channel (see “Micro Direct Memory Access (μDMA)” on page 686)
// //      and enable the DMA option(s) in the UARTDMACTL register.
// //      ---

// //  7.  Enable the UART by setting the UARTEN bit in the UARTCTL register.
//         UART0_CTL_R = (
// 					UART_CTL_TXE |
// 					UART_CTL_RXE |
// 					UART_CTL_UARTEN
// 				);

}