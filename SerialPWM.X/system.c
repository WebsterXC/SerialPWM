/******************************************************************************/
/*Files to Include                                                            */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#include "system.h"


void ConfigureOscillator(void)
{
    /* Setup the internal FRC for 500kHz. */
    OSCCON = 0x3B;

    /* Disable the Watchdog Timer */
    WDTCON = 0x00;
}
