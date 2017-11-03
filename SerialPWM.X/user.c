/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#include "user.h"
#include "pwm.h"

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

void InitApp(void)
{

    /* Setup analog functionality and port direction */
    _init_gpio();

    /* Initialize peripherals */
    _init_timer2();
    _init_pwm();

    /* Enable interrupts */

}

void _init_timer2(void){

    /* Load configuration. */
    T2CON = 0x00;

    /* Load the period. */
    PR2 = 0x04;

    /* Ensure a fresh holding register. */
    TMR2 = 0x00;

    /* Start the timer. */
    T2CONbits.TMR2ON = 1;
}

void _init_gpio(void){
    /* Set control inputs, PWM outputs. */
    LATA = 0x00;
    LATC = 0x00;

    TRISA = 0x33;
    TRISC = 0x15;

    /* Set all analog inputs to disabled. */
    ANSELA = 0x00;
    ANSELC = 0x00;

    /* Disabled positive-edge IOC on RA4 and RA5. Disable WPU function. */
    WPUA = 0x00;
    //OPTION_REGbits.nWPUEN = 0;

    //IOCAP = 0x30;
    //IOCAF = 0x00;       // Clear interrupt flags.

    /* Enable global interrupts. */
    //INTCONbits.IOCIE = 1;
}
