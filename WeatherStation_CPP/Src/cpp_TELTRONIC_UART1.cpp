/*
 * TELTRONIC_UART_CPP.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: Simon
 */


#include "cpp_TELTRONIC_UART.hpp"

/**
 * @brief 	Standard constructor for TODO I2C, uses I2C2
 * @return
 */
UART::UART(){
	Usart1Init();
}

/**
 * @brief 	Standard destructor for TODO I2C, uses I2C2
 * @return
 */
UART::~UART(){

}
/**
 * @brief 	Write to UART
 * @return
 */
void UART::Write(char *Buffer){
	UART1_Write(Buffer);
}

