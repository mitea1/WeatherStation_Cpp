/*
 * I2C.hpp
 *
 *  Created on: Apr 19, 2016
 *      Author: Simon
 */
#ifndef TELTRONIC_I2C_CPP_HPP_
#define TELTRONIC_I2C_CPP_HPP_

/*----- Header-Files -------------------------------------------------------*/
#include <TELTRONIC_I2C.h>

/*----- Macros -------------------------------------------------------------*/
#define TIMEOUT_MAX         0x6000
#define I2C_CLOCK_SPEED		1000

/*----- Data ---------------------------------------------------------------*/
class I2C{
private:
	GPIO_InitTypeDef GPIO_InitStruct;
	static I2C_InitTypeDef I2C_InitStruct[2];
	static TELTRONIC_Port_Pin_t TELTRONIC_I2C_Port_Pin[2][4];

public:
	I2C();
	I2C(I2C_TypeDef *);
	~I2C();
	ERROR_CODES Write(I2C_TypeDef *I2Cx, uint8_t addr, uint16_t reg,
			uint8_t twoByte, uint8_t *pdata, uint16_t count);
	ERROR_CODES Read(I2C_TypeDef *I2Cx, uint8_t addr, uint16_t reg,
			uint8_t twoByte, uint8_t *pdata, uint16_t count);
};

#endif /* TELTRONIC_I2C_CPP_HPP_ */
