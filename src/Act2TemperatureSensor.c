/**

* @file   Act2TemperatureSensor.c
* @author Debarpan Mazumder
* @brief
* @version Code::Blocks 20.03
* @date
*

* @copyright Copyright (c) 2021
*
*/

#include "Act2TemperatureSensor.h"

void initialize_ADC(uint8_t channel)
{
    ADMUX = (1<<REFS0);                                                         /// Setting AVcc to Aref
    ADCSRA = (1<<ADEN) | (1<<ADIE) | (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2);      /// Setting ADC Enable, Interrupt Enable, Prescaler

    ADMUX &= 0xF8;                                                              /// Logic to set the correct channel based on input
    channel &= 0b00000111;
    ADMUX |= channel;                                                           /// Selecting the channel in ADMUX

    ADC_Start;                                                                  /// Starting ADC conversion
    while(ADC_Load);                                                            /// Waiting for ADC Register to get the values
}

uint16_t get_temperature()
{
    ADCSRA |= (1<<ADIF);                                                        /// Clearing the Interrupt Flag
    return (ADC);                                                               /// Returning the ADC Register
}

