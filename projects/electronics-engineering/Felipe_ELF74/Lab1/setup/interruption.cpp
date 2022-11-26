#include <setup.h>
#include "inc/tm4c129encpdt.h"

#include <futils.h>

using futils::turnLedOn;
// using futils::getChar;
// using futils::console;
// using futils::getButtonState;

void initInterruptions() {
// The interrupt capabilities of each GPIO port are controlled by a set of seven registers. These registers
// are used to select
//      -> the source of the interrupt,
//      -> its polarity,
//      -> and the edge properties.
//  When one or more GPIO inputs cause an interrupt, a single interrupt output is sent to the interrupt controller for
//  the entire GPIO port. For edge-triggered interrupts, software must clear the interrupt to enable any
//  further interrupts. For a level-sensitive interrupt, the external source must hold the level constant
//  for the interrupt to be recognized by the controller.
//  Page 758 of the datasheet

// The GPIOIS register is the interrupt sense register. Setting a bit in the GPIOIS register configures
// the corresponding pin to detect LEVELS, while clearing a bit configures the corresponding pin to detect
// EDGES. All bits are cleared by a reset.//  Enable interruptions for SW0 and SW1.
//  Disable interruptions for configuration of SW0 and SW1.
    GPIO_PORTJ_AHB_IM_R   = 0x00;
//  -------------------------------------------------
//  Detect edges
    GPIO_PORTJ_AHB_IS_R   = 0x00;
//  [0] Edge
//  [1] Level
//  -------------------------------------------------
//  Detect only one edge
    GPIO_PORTJ_AHB_IBE_R  = 0x00;
//  [0] Unique
//  [1] Double
//  -------------------------------------------------
//  Detect falling edges
    GPIO_PORTJ_AHB_IEV_R  = 0x00;
//  [0] Falling or low
//  [1] Rising or high
//  -------------------------------------------------
//  Clear any pending interrupts for SW0 and SW1.
    GPIO_PORTJ_AHB_ICR_R  = 0x03; //
//  Activate SW0 and SW1 to receive interruptions. They are not masked.
//  [0] Deactivate
//  [1] Activate
//  -------------------------------------------------
//  Enable interruptions for SW0 and SW1.
    GPIO_PORTJ_AHB_IM_R   = 0x03;
//  -------------------------------------------------


//  Bit 51 of the NVIC registers is the Interrupt Set-Enable Register for GPIOJ.
//  Set the NVIC register for enabling the EXTI for GPIOJ.
    NVIC_EN1_R      = (1<<19); // 51 - 32 = 19 => EN1 bit 19

//  Set the priority for the GPIOJ interrupt
    NVIC_PRI12_R    = (uint32_t)(5<<29); // Priority 5

}
void GPIOPortJ_Handler() {
    if (GPIO_PORTJ_AHB_RIS_R & (1<<0)) {
        turnLedOn(1, true);
        // console('0');
        GPIO_PORTJ_AHB_ICR_R &= ~(1<<0);
    }
    if (GPIO_PORTJ_AHB_RIS_R & (1<<1)) {
        turnLedOn(1, false);
        // console('1');
        GPIO_PORTJ_AHB_ICR_R &= ~(1<<1);
    }
    GPIO_PORTJ_AHB_ICR_R = 0x03;
}