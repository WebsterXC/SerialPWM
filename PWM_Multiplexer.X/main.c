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
#include "mcc_generated_files/pwm1.h"

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

    bool serviced = false;
    
    while(1)
    {
        
        if( DUTYUP_PORT == 1){
            IOCAF4_DefaultInterruptHandler();
        }else if( DUTYDN_PORT == 1 ){
            IOCAF5_DefaultInterruptHandler();
        }
        /*
        if( DUTYDN_PORT == 0 && serviced == true ){
            serviced = false;
        }else if( DUTYUP_PORT == 0 && serviced == true){
            serviced = false;
        }
        
        if( DUTYDN_PORT == 1 && serviced == false ){
            // Only if chip is enabled.
            if( EN_PORT == 0){
                if( PWMSEL0_PORT == 0 && PWMSEL1_PORT == 0){
                    PWM1_StepDutyValue(false);
                    serviced = true;
                }
                
            }
        }else if( DUTYUP_PORT == 1 && serviced == false){
            // Only if chip is enabled.
            if( EN_PORT == 0){
               if( PWMSEL0_PORT == 0 && PWMSEL1_PORT == 0){
                    PWM1_StepDutyValue(true);
                    serviced = true;
                }
               
            }
        }
        */
    }
}

