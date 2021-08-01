#ifndef ACT2TEMPERATURESENSOR_H_INCLUDED
#define ACT2TEMPERATURESENSOR_H_INCLUDED

/**

* @file   Act2TemperatureSensor.h
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
 * @brief Setting MACROS for Starting ADC read, checking if ADC register is loaded, Channel Select
 */
#define ADC_Start (ADCSRA |= (1<<ADSC))             /// Enabling the ADC Start Conversion bit in the control register
#define ADC_Load (!(ADCSRA&(1<<ADIF)))              /// Checking if the Interrupt Flag is being cleared
#define ADC_Input_Channel 0                         /// Selecting 0 channel for PIN C0

/**
 * @brief Function to initalize the ADC Registers with appropriate values
 *
 * @param [in] ch To select the Channel
 */
void initialize_ADC(uint8_t ch);

/**
 * @brief To Read the ADC input which is the set temperature, read using the ADC channel
 *
 * @return uint16_t Since ADC is a 10-bit register using uint16_t to return the ADC register
 */
uint16_t get_temperature();


#endif // ACT2TEMPERATURESENSOR_H_INCLUDED
