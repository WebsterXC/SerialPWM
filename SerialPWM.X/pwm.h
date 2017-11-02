/* */

#ifndef _PWM_H_
#define _PWM_H_

#include <stdint.h>
#include <stdbool.h>

/* Initialize each channel at 50% duty cycle. */
#define INIT_DUTY_CYCLE     9

/* Define min and max values based on PR2. */
#define MIN_DUTY_CYCLE      0
#define MAX_DUTY_CYCLE      19

/* Define the amount to increment/decrement every step. */
#define STEP_DUTY_CYCLE     1

/* Enumerate the four channels. */
enum PWMChannel{
    PWM_CH1,
    PWM_CH2,
    PWM_CH3,
    PWM_CH4
};

/* Initializes all 4 PWM channels at an initial duty cycle. */
void _init_pwm(void);

/* Increments / Decrements a channel's duty cycle. These are separated
 * in an attempt to reduce instruction count; since both DUTYUP and DUTYDN
 * have their own ISR's, we no longer need an if-else to see which direction
 * to step the duty cycle. */
void incDutyCycle(PWMChannel);
void decDutyCycle(PWMChannel);

#endif
