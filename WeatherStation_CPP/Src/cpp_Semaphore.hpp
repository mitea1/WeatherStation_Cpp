/*
 * cpp_Semaphore.hpp
 *
 *  Created on: Apr 24, 2016
 *      Author: Simon
 */

#ifndef CPP_SEMAPHORE_HPP_
#define CPP_SEMAPHORE_HPP_

/*----- Header-Files -------------------------------------------------------*/
#include <stdint.h>

#include "FreeRTOS.h"
#include "queue.h"
#include <semphr.h>					/* FreeRTOS semaphores					*/

/*----- Macros -------------------------------------------------------------*/

/*----- Data ---------------------------------------------------------------*/
class Semaphore{
private:

public:
	Semaphore();
	~Semaphore();
	BaseType_t cpp_Take( SemaphoreHandle_t xSemaphore,
			TickType_t xTicksToWait);
	BaseType_t cpp_TakeFromISR(SemaphoreHandle_t xSemaphore,
			BaseType_t *pxHigherPriorityTaskWoken);
	BaseType_t cpp_Give( SemaphoreHandle_t xSemaphore);
	BaseType_t cpp_GiveFromISR(SemaphoreHandle_t xSemaphore,
			BaseType_t *pxHigherPriorityTaskWoken);
	void cpp_Delete( SemaphoreHandle_t xSemaphore);
};

class CountingSemaphore:Semaphore{
public:
	SemaphoreHandle_t cpp_Create(UBaseType_t uxMaxCount,
	        UBaseType_t uxInitialCount);
};
class BinarySemaphore:Semaphore{
public:
	SemaphoreHandle_t cpp_Create();
};
class Mutex:Semaphore{

};

#endif /* CPP_SEMAPHORE_HPP_ */
