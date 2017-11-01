/**
  Generated Pin Manager File

  Company:
    Microchip Technology Inc.

  File Name:
    pin_manager.c

  Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.26
        Device            :  PIC16LF1503
        Driver Version    :  1.02
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/

#include <xc.h>
#include "pin_manager.h"
#include "stdbool.h"

#include "pwm1.h"
#include "pwm2.h"
#include "pwm3.h"
#include "pwm4.h"

void (*IOCAF4_InterruptHandler)(void);
void (*IOCAF5_InterruptHandler)(void);


void PIN_MANAGER_Initialize(void)
{
    /**
    LATx registers
    */   
    LATA = 0x00;    
    LATC = 0x00;    

    /**
    TRISx registers
    */    
    TRISA = 0x3B;
    TRISC = 0x15;

    /**
    ANSELx registers
    */   
    ANSELC = 0x0A;
    ANSELA = 0x07;

    /**
    WPUx registers
    */ 
    WPUA = 0x3F;
    OPTION_REGbits.nWPUEN = 0;

    
    /**
    APFCONx registers
    */
    APFCON = 0x00;

    /**
    IOCx registers
    */
    // interrupt on change for group IOCAF - flag
    IOCAFbits.IOCAF4 = 0;
    IOCAFbits.IOCAF5 = 0;
    // interrupt on change for group IOCAN - negative
    IOCANbits.IOCAN4 = 0;
    IOCANbits.IOCAN5 = 0;
    // interrupt on change for group IOCAP - positive
    IOCAPbits.IOCAP4 = 1;
    IOCAPbits.IOCAP5 = 1;

    // register default IOC callback functions at runtime; use these methods to register a custom function
    IOCAF4_SetInterruptHandler(IOCAF4_DefaultInterruptHandler);
    IOCAF5_SetInterruptHandler(IOCAF5_DefaultInterruptHandler);
   
    // Enable IOCI interrupt 
    INTCONbits.IOCIE = 1; 
    
}       

void PIN_MANAGER_IOC(void)
{   
    // Interrupt on change for RA4 ()
    if(IOCAFbits.IOCAF4 == 1)
    {
        IOCAF4_ISR();  
    }                          

    // Interrupt on change for RA5 ()
    if(IOCAFbits.IOCAF5 == 1)
    {
        IOCAF5_ISR();  
    }                          


}

/**
   IOCAF4 Interrupt Service Routine
*/
void IOCAF4_ISR(void) {

    // Add custom IOCAF4 code

    // Call the interrupt handler for the callback registered at runtime
    if(IOCAF4_InterruptHandler)
    {
        IOCAF4_InterruptHandler();
    }
    IOCAFbits.IOCAF4 = 0;
}

/**
  Allows selecting an interrupt handler for IOCAF4 at application runtime
*/
void IOCAF4_SetInterruptHandler(void* InterruptHandler){
    IOCAF4_InterruptHandler = InterruptHandler;
}

/* Interrupt handler for DUTY UP. */
void IOCAF4_DefaultInterruptHandler(void){
    /* External signal requests incrementing the duty cycle. */
    
    // Read the selection inputs.
    
    // Increment the correct duty cycle.
}

/**
   IOCAF5 Interrupt Service Routine
*/
void IOCAF5_ISR(void) {

    // Add custom IOCAF5 code

    // Call the interrupt handler for the callback registered at runtime
    if(IOCAF5_InterruptHandler)
    {
        IOCAF5_InterruptHandler();
    }
    IOCAFbits.IOCAF5 = 0;
}

/**
  Allows selecting an interrupt handler for IOCAF5 at application runtime
*/
void IOCAF5_SetInterruptHandler(void* InterruptHandler){
    IOCAF5_InterruptHandler = InterruptHandler;
}

/* Interrupt handler for DUTY DOWN. */
void IOCAF5_DefaultInterruptHandler(void){
    /* External signal requests decrementing the duty cycle. */
    
    // Read the selection inputs.
    
    // Decrement the correct duty cycle.
}