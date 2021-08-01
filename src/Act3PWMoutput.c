/**

* @file   Act3PWMoutput.c
* @author Debarpan Mazumder
* @brief
* @version Code::Blocks 20.03
* @date
*

* @copyright Copyright (c) 2021
*
*/

#include "Act3PWMoutput.h"

void initialize_timer1_pwm(){
    TCCR1A |= (1<<COM1A1) | (1<<WGM11) | (1<<WGM10);        /// Selecting The channel 1 for PIN B1, Selecting FAST PWM mode in 10-bit
    TCCR1B |= (1<<CS11) | (1<<CS10) | (1<<WGM12);           /// Selecting 64 prescaler, Selecting FAST PWM mode in 10-bit
    DDRB |= (1<<PORTB1);                                    /// Setting B1 to output port
}
