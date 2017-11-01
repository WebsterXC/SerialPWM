/******************************************************************************/
/* User Level #define Macros                                                  */
/******************************************************************************/

/******************************************************************************/
/* User Function Prototypes                                                   */
/******************************************************************************/

#ifndef _USR_H_
#define _USR_H_

/* SerialPWM obviously supports duty cycles from 0-100%, but that's not what is
 * written to the duty cycle registers in the PWM API. The max duty cycle is a
 * function of the PR2 register, which is directly related to the system clock.
 * 
 * To increase the granularity of the duty cycle steps, we'd need to increase
 * the value of PR2. This would also require increasing the system clock. Since
 * SerialPWM tries to be power considerate, our clocks are set up for the lowest
 * speed possible to support 5% increments.
 * 
 * Duty Cycle Ratio = [PWMxDCH PWMxDCL] / 4(PR2 + 1)
 * 
 * So a 100% duty cycle would occur when [PWMxDCH PWMxDCL] = 4( PR2+1 ). For
 * default applications (5% increments) this is 20 since our PR2 = 4.
 * 
 */
#define DUTY_CYCLE_MIN 0
#define DUTY_CYCLE_MAX 20

void InitApp(void);         /* Unused. */

#endif
