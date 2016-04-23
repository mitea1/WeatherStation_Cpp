/*
 * I2C.cpp
 *
 *  Created on: Apr 19, 2016
 *      Author: Simon
 */

#include "cpp_TELTRONIC_I2C.hpp"
//#include <stm32l1xx.h>             	/* Processor STM32               			*/
//#include "TELTRONIC.h"          	/* Teltronic Module                         */
//#include <stm32l1xx_gpio.h>

/**
 * @brief Standard constructor for I2C, uses I2C2
 * @return
 */
I2C::I2C(){
	TELTRONIC_I2C_Init(I2C2);
}
/**
 * @brief Standard constructor overloaded to choose I2C interface
 * @param I2Cx		set I2C interface, possible values: I2C1, I2C2
 * @return
 */
I2C::I2C(I2C_TypeDef *I2Cx) {
	TELTRONIC_I2C_Init(I2Cx);
}
/**
 * @brief Standard constructor for I2C, uses I2C2
 * @return
 */
I2C::~I2C(){

}
ERROR_CODES I2C::Read(I2C_TypeDef *I2Cx, uint8_t addr, uint16_t reg, uint8_t twoByte, uint8_t *pdata, uint16_t count){
	return TELTRONIC_I2C_Read(I2Cx, addr, reg, twoByte, pdata, count);
}
ERROR_CODES I2C::Write(I2C_TypeDef *I2Cx, uint8_t addr, uint16_t reg, uint8_t twoByte, uint8_t *pdata, uint16_t count){
	return TELTRONIC_I2C_Write(I2Cx, addr, reg, twoByte, pdata, count);
}
