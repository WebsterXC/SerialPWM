/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.26
        Device            :  PIC16LF1503
        Version           :  1.01
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


#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA2 procedures
#define RA2_SetHigh()    do { LATAbits.LATA2 = 1; } while(0)
#define RA2_SetLow()   do { LATAbits.LATA2 = 0; } while(0)
#define RA2_Toggle()   do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define RA2_GetValue()         PORTAbits.RA2
#define RA2_SetDigitalInput()   do { TRISAbits.TRISA2 = 1; } while(0)
#define RA2_SetDigitalOutput()  do { TRISAbits.TRISA2 = 0; } while(0)
#define RA2_SetPullup()     do { WPUAbits.WPUA2 = 1; } while(0)
#define RA2_ResetPullup()   do { WPUAbits.WPUA2 = 0; } while(0)
#define RA2_SetAnalogMode() do { ANSELAbits.ANSA2 = 1; } while(0)
#define RA2_SetDigitalMode()do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set DUTYUP aliases
#define DUTYUP_TRIS               TRISAbits.TRISA4
#define DUTYUP_LAT                LATAbits.LATA4
#define DUTYUP_PORT               PORTAbits.RA4
#define DUTYUP_WPU                WPUAbits.WPUA4
#define DUTYUP_ANS                ANSELAbits.ANSA4
#define DUTYUP_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define DUTYUP_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define DUTYUP_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define DUTYUP_GetValue()           PORTAbits.RA4
#define DUTYUP_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define DUTYUP_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define DUTYUP_SetPullup()      do { WPUAbits.WPUA4 = 1; } while(0)
#define DUTYUP_ResetPullup()    do { WPUAbits.WPUA4 = 0; } while(0)
#define DUTYUP_SetAnalogMode()  do { ANSELAbits.ANSA4 = 1; } while(0)
#define DUTYUP_SetDigitalMode() do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set DUTYDN aliases
#define DUTYDN_TRIS               TRISAbits.TRISA5
#define DUTYDN_LAT                LATAbits.LATA5
#define DUTYDN_PORT               PORTAbits.RA5
#define DUTYDN_WPU                WPUAbits.WPUA5
#define DUTYDN_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define DUTYDN_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define DUTYDN_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define DUTYDN_GetValue()           PORTAbits.RA5
#define DUTYDN_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define DUTYDN_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define DUTYDN_SetPullup()      do { WPUAbits.WPUA5 = 1; } while(0)
#define DUTYDN_ResetPullup()    do { WPUAbits.WPUA5 = 0; } while(0)

// get/set EN aliases
#define EN_TRIS               TRISCbits.TRISC0
#define EN_LAT                LATCbits.LATC0
#define EN_PORT               PORTCbits.RC0
#define EN_ANS                ANSELCbits.ANSC0
#define EN_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define EN_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define EN_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define EN_GetValue()           PORTCbits.RC0
#define EN_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define EN_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define EN_SetAnalogMode()  do { ANSELCbits.ANSC0 = 1; } while(0)
#define EN_SetDigitalMode() do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()    do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()   do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()   do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()         PORTCbits.RC1
#define RC1_SetDigitalInput()   do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()  do { TRISCbits.TRISC1 = 0; } while(0)
#define RC1_SetAnalogMode() do { ANSELCbits.ANSC1 = 1; } while(0)
#define RC1_SetDigitalMode()do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set PWMSEL1 aliases
#define PWMSEL1_TRIS               TRISCbits.TRISC2
#define PWMSEL1_LAT                LATCbits.LATC2
#define PWMSEL1_PORT               PORTCbits.RC2
#define PWMSEL1_ANS                ANSELCbits.ANSC2
#define PWMSEL1_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define PWMSEL1_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define PWMSEL1_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define PWMSEL1_GetValue()           PORTCbits.RC2
#define PWMSEL1_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define PWMSEL1_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define PWMSEL1_SetAnalogMode()  do { ANSELCbits.ANSC2 = 1; } while(0)
#define PWMSEL1_SetDigitalMode() do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()    do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()   do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()   do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()         PORTCbits.RC3
#define RC3_SetDigitalInput()   do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()  do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetAnalogMode() do { ANSELCbits.ANSC3 = 1; } while(0)
#define RC3_SetDigitalMode()do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set PWMSEL0 aliases
#define PWMSEL0_TRIS               TRISCbits.TRISC4
#define PWMSEL0_LAT                LATCbits.LATC4
#define PWMSEL0_PORT               PORTCbits.RC4
#define PWMSEL0_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define PWMSEL0_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define PWMSEL0_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define PWMSEL0_GetValue()           PORTCbits.RC4
#define PWMSEL0_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define PWMSEL0_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)

// get/set RC5 procedures
#define RC5_SetHigh()    do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()   do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()   do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()         PORTCbits.RC5
#define RC5_SetDigitalInput()   do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()  do { TRISCbits.TRISC5 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF4 pin functionality
 * @Example
    IOCAF4_ISR();
 */
void IOCAF4_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF4 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF4 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF4_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF4_SetInterruptHandler(void* InterruptHandler);

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF4 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF4_SetInterruptHandler() method.
    This handler is called every time the IOCAF4 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF4_SetInterruptHandler(IOCAF4_InterruptHandler);

*/
extern void (*IOCAF4_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF4 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF4_SetInterruptHandler() method.
    This handler is called every time the IOCAF4 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF4_SetInterruptHandler(IOCAF4_DefaultInterruptHandler);

*/
void IOCAF4_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF5 pin functionality
 * @Example
    IOCAF5_ISR();
 */
void IOCAF5_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF5 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF5 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF5_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF5_SetInterruptHandler(void* InterruptHandler);

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF5 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF5_SetInterruptHandler() method.
    This handler is called every time the IOCAF5 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF5_SetInterruptHandler(IOCAF5_InterruptHandler);

*/
extern void (*IOCAF5_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF5 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF5_SetInterruptHandler() method.
    This handler is called every time the IOCAF5 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF5_SetInterruptHandler(IOCAF5_DefaultInterruptHandler);

*/
void IOCAF5_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/