/******************************************************************************/
/*Files to Include                                                            */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#include "pwm.h"

/* Aliases for PWMSEL inputs. */
#define PWMSEL0 PORTCbits.RC4
#define PWMSEL1 PORTCbits.RC2

/******************************************************************************/
/* Interrupt Routines                                                         */
/******************************************************************************/

/* Baseline devices don't have interrupts. Note that some PIC16's
 * are baseline devices.  Unfortunately the baseline detection macro is
 * _PIC12 */
#ifndef _PIC12

void interrupt isr(void)
{
    /* Check which pin caused the interrupt. */

    // Interrupt on change for RA4 (DUTYUP)
    if(IOCAFbits.IOCAF4 == 1)
    {
        /* Read the PWMSEL inputs. */
        if( PWMSEL0 == 0 && PWMSEL1 == 0 ){
            incDutyCycle(PWM_CH1);
        }else if( PWMSEL0 == 0 && PWMSEL1 == 1 ){
            incDutyCycle(PWM_CH2);
        }else if( PWMSEL0 == 1 && PWMSEL1 == 0 ){
            incDutyCycle(PWM_CH3);
        }else if( PWMSEL0 == 1 && PWMSEL1 == 1 ){
            incDutyCycle(PWM_CH4);
        }else{
            /* Do nothing. */
        }

        /* Reset interrupt flag. */
        IOCAFbits.IOCAF4 = 0;
    }

    // Interrupt on change for RA5 (DUTYDN)
    if(IOCAFbits.IOCAF5 == 1)
    {
        /* Read the PWMSEL inputs. */
        if( PWMSEL0 == 0 && PWMSEL1 == 0 ){
            decDutyCycle(PWM_CH1);
        }else if( PWMSEL0 == 0 && PWMSEL1 == 1 ){
            decDutyCycle(PWM_CH2);
        }else if( PWMSEL0 == 1 && PWMSEL1 == 0 ){
            decDutyCycle(PWM_CH3);
        }else if( PWMSEL0 == 1 && PWMSEL1 == 1 ){
            decDutyCycle(PWM_CH4);
        }else{
            /* Do nothing. */
        }

        /* Reset interrupt flag. */
        IOCAFbits.IOCAF5 = 0;
    }

}   //ISR
#endif
