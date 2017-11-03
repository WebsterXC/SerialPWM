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

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp */
#include "pwm.h"

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

#define DUTYUP  PORTAbits.RA4
#define DUTYDN  PORTAbits.RA5
#define INHIBIT PORTCbits.RC0


/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/
void main(void)
{
    /* Configure the oscillator for the device */
    ConfigureOscillator();

    /* Initialize I/O and Peripherals for application */
    InitApp();

    static bool commandUP = true;
    static bool commandDN = true;

    while(1)
    {
        if( DUTYDN == 1 ){
          commandDN = true;
        }
        if( DUTYUP == 1 ){
          commandUP = true;
        }

        if( DUTYDN == 0 && commandDN == true && INHIBIT == 0){
            decDutyCycle(getPWMSEL());
            commandDN = false;
        }
        if( DUTYUP == 0 && commandUP == true && INHIBIT == 0){
            incDutyCycle(getPWMSEL());
            commandUP = false;
        }
    }

}
