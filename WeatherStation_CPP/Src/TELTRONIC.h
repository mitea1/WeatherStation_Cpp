/*
 * teltronic.h
 *
 *  Created on: Mar 19, 2016
 *      Author: Adrian
 */
#ifndef TELTRONIC_H_
#define TELTRONIC_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*----- Header-Files -------------------------------------------------------*/

/*----- Macros -------------------------------------------------------------*/
#define TELTRONIC_NO_ERROR 			0x0
#define TELTRONIC_ERROR_I2C_BASE   	0x60

/*----- Data types ---------------------------------------------------------*/
typedef uint8_t ERROR_CODES;
typedef struct _TELTRONIC_Port_Pin_t {
     GPIO_TypeDef* GPIOx;
     uint16_t GPIO_Pin;
     GPIOMode_TypeDef GPIO_Mode;
     uint8_t GPIO_AF;
} TELTRONIC_Port_Pin_t;

/*----- Function prototypes ------------------------------------------------*/

/*----- Data ---------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* TELTRONIC_H_ */
