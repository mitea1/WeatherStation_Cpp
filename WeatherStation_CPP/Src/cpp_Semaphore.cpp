/*
 * cpp_Semaphore.cpp
 *
 *  Created on: Apr 24, 2016
 *      Author: Simon
 */

#include "cpp_Semaphore.hpp"


Semaphore::Semaphore(){

}
Semaphore::~Semaphore(){

}
BaseType_t Semaphore::cpp_Take( SemaphoreHandle_t xSemaphore,TickType_t xTicksToWait ){
	return xSemaphoreTake(xSemaphore, xTicksToWait);
}
// TODO replaced signed - before: signed BaseType_t *pxHigherPriorityTaskWoken
BaseType_t Semaphore::cpp_TakeFromISR(SemaphoreHandle_t xSemaphore, BaseType_t *pxHigherPriorityTaskWoken){
	return xSemaphoreTakeFromISR(xSemaphore, pxHigherPriorityTaskWoken);
}
BaseType_t Semaphore::cpp_Give( SemaphoreHandle_t xSemaphore ){
	return xSemaphoreGive(xSemaphore);
}
// TODO replaced signed - before: signed BaseType_t *pxHigherPriorityTaskWoken
BaseType_t Semaphore::cpp_GiveFromISR(SemaphoreHandle_t xSemaphore, BaseType_t *pxHigherPriorityTaskWoken){
	return xSemaphoreGiveFromISR(xSemaphore,pxHigherPriorityTaskWoken);
}
void Semaphore::cpp_Delete( SemaphoreHandle_t xSemaphore ){
	vSemaphoreDelete(xSemaphore);
}

SemaphoreHandle_t BinarySemaphore::cpp_Create(){
	return xSemaphoreCreateBinary();
}

SemaphoreHandle_t CountingSemaphore::cpp_Create(UBaseType_t uxMaxCount,
        UBaseType_t uxInitialCount){
	return xSemaphoreCreateCounting(uxMaxCount, uxInitialCount);
}
