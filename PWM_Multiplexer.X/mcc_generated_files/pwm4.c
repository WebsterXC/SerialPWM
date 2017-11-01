 /**
   PWM4 Generated Driver File
 
   @Company
     Microchip Technology Inc.
 
   @File Name
     pwm4.c
 
   @Summary
     This is the generated driver implementation file for the PWM4 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs 
 
   @Description
     This source file provides implementations for driver APIs for PWM4.
     Generation Information :
         Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs  - 1.45
         Device            :  PIC16LF1503
         Driver Version    :  2.00
     The generated drivers are tested against the following:
         Compiler          :  XC8 1.35
         MPLAB             :  MPLAB X 3.40
 */ 

 /*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/
 
 /**
   Section: Included Files
 */

 #include <xc.h>
 #include "pwm4.h"
 #include "../user.h"

 static uint16_t pwm4_current_duty_cycle;

 void PWM4_Initialize(void)
 {
     // Set the PWM to the options selected in the PIC10 / PIC12 / PIC16 / PIC18 MCUs .
     // PWM4POL active_hi; PWM4OE enabled; PWM4EN enabled; 
     PWM4CON = 0xC0;
     
     // PWM4DCH 2; 
     PWM4DCH = 0x02;
     
     // PWM4DCL 1; 
     PWM4DCL = 0x40;
     
     // Load the default 50% duty cycle.
     PWM4_LoadDutyValue(PWM4_INITIALIZE_DUTY_VALUE);
 }

 void PWM4_LoadDutyValue(uint16_t dutyValue)
 {
     // Control which values we can write to the duty cycle register.
     if(dutyValue > DUTY_CYCLE_MAX){
         dutyValue = DUTY_CYCLE_MAX;
     }else if(dutyValue < DUTY_CYCLE_MIN){
         // This is technically not possible but we include it for good measure.
         dutyValue = DUTY_CYCLE_MIN;
     }
     // Writing to 8 MSBs of PWM duty cycle in PWMDCH register
     PWM4DCH = (dutyValue & 0x03FC)>>2;
     
     // Writing to 2 LSBs of PWM duty cycle in PWMDCL register
     PWM4DCL = (dutyValue & 0x0003)<<6;
     
     pwm4_current_duty_cycle = dutyValue;
 }
 
 void PWM4_StepDutyValue(bool direction){
     if(direction == true){
         PWM4_LoadDutyValue(pwm4_current_duty_cycle + 1);
     }else{
         PWM4_LoadDutyValue(pwm4_current_duty_cycle - 1);
     }
 }
