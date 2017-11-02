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

}

void _init_gpio(void){
    
}
