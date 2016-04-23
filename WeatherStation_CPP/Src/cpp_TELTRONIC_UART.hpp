/*
 * TELTRONIC_UART_CPP.hpp
 *
 *  Created on: Apr 23, 2016
 *      Author: Simon
 */
#ifndef TELTRONIC_UART_CPP_HPP_
#define TELTRONIC_UART_CPP_HPP_

/*----- Header-Files -------------------------------------------------------*/
#include "TELTRONIC_UART.h"

/*----- Macros -------------------------------------------------------------*/

/*----- Data ---------------------------------------------------------------*/
class UART{
private:

public:
	UART();
	~UART();
	void Write(char *Buffer);
};

#endif /* TELTRONIC_UART_CPP_HPP_ */
