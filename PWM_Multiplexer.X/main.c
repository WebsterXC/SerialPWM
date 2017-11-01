/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#include "mcc_generated_files/mcc.h"
/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/* No globals. */

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/
void main(void)
{
    /* Initialize the MCU resources:
     * 
     * Pin GPIO
     * Oscillator (FRC 500kHz)
     * Watchdog Timer (Disabled)
     * PWM 1-4
     * Timer 2
     *
     */
    SYSTEM_Initialize();

    while(1)
    {
        /* Just stay in an empty while-loop.
         * 
         * SerialPWM is an interrupt driven design, and
         * since all we're doing is interpreting GPIO from
         * IOC inputs, there are no housekeeping steps that
         * would normally go here.
         * 
         */
    }

}

