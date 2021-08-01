#ifndef ACT4USARTDATA_H_INCLUDED
#define ACT4USARTDATA_H_INCLUDED

/**

* @file   Act4USARTdata.h
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
 * @brief MACRO for checking if the Transmission is complete
 */
#define Transmission_check (!(UCSR0A & (1<<UDRE0)))

/**
 * @brief Function to Initalize the Registers for Transmission of Data using USART
 *
 * @param baud_rate [in] To set the baud Rate
 */
void USART_initialization(uint16_t baud_rate);

/**
 * @brief Function to send the Data using UDR0 Register
 *
 * @param [in] data The Character to be sent
 */
void Write_char_usart(char data);

/**
 * @brief Function to Send Data using USART based on an option
 *
 * @param [in] option To select the temperature to be displayed
 */
void Manage_display(int option);

#endif // ACT4USARTDATA_H_INCLUDED
