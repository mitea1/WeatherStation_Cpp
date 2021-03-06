/*
 * UART_Print.h
 *
 *  Created on: Mar 16, 2016
 *      Author: Adrian
 */
#ifndef UART_PRINT_H_
#define UART_PRINT_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*----- Header-Files -------------------------------------------------------*/
#include "stm32l1xx.h"
#include "stm32l1xx_rcc.h"
#include "stm32l1xx_gpio.h"
#include "stm32l1xx_usart.h"


/*----- Macros -------------------------------------------------------------*/

/*----- Data types ---------------------------------------------------------*/

/*----- Function prototypes ------------------------------------------------*/
extern void Usart1Init(void);
//TODO  extern void UART1_Write(char *);
extern void UART1_Write(char *Buffer); // replaced with this

/*----- Data ---------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* UART_PRINT_H_ */
