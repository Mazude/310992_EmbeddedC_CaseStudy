#ifndef ACT3PWMOUTPUT_H_INCLUDED
#define ACT3PWMOUTPUT_H_INCLUDED

/**

* @file   Act3PWMoutput.h
* @author Debarpan Mazumder
* @brief
* @version Code::Blocks 20.03
* @date
*

* @copyright Copyright (c) 2021
*
*/
/**
 * @brief Include Files for referencing AVR atmega defined names
 */
#include <avr/io.h>
#include <avr/interrupt.h>

/**
 * @brief Setting Macros for the output PWM compare value to obtain the desired PWM width
 *
 */
#define PWM_20_percent (205)
#define PWM_40_percent (410)
#define PWM_70_percent (842)
#define PWM_95_percent (970)

/**
 * @brief MACRO for calling the Output Compare Register for channel A (PIN B1)
 *
 */
#define Output_pwm (OCR1A)

/**
 * @brief Function to initialize bits for timer to generate pwm in PIN B1
 *
 */
void initialize_timer1_pwm();

#endif // ACT3PWMOUTPUT_H_INCLUDED
