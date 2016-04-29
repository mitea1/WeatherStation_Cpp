/*
 * cpp_Task.cpp
 *
 *  Created on: Apr 24, 2016
 *      Author: Simon
 */
/*----- Header-Files -------------------------------------------------------*/
#include "cpp_Task.hpp"
#include "cpp_Light_Sensor.hpp"
#include "cpp_TELTRONIC_I2C.hpp"
#include "cpp_TELTRONIC_UART.hpp"
#include "cpp_Humid_Temp_Sensor.hpp"
/*----- Macros -------------------------------------------------------------*/

/*----- Data types ---------------------------------------------------------*/

/*----- Function prototypes ------------------------------------------------*/

/*----- Data ---------------------------------------------------------------*/

/*----- Implementation -----------------------------------------------------*/
//
//BaseType_t create(TaskFunction_t pvTaskCode,
//		const char * const pcName,
//		unsigned short usStackDepth,
//		void *pvParameters,
//		UBaseType_t uxPriority,
//		TaskHandle_t *pxCreatedTask){
//	return xTaskCreate(pvTaskCode, pcName, usStackDepth, pvParameters, uxPriority, pxCreatedTask);
//}
//void cpp_Delay( const TickType_t xTicksToDelay){
//	vTaskDelay(xTicksToDelay);
//}
//void cpp_kDelayUntil( TickType_t *pxPreviousWakeTime,
//		const TickType_t xTimeIncrement){
//	vTaskDelayUntil(pxPreviousWakeTime, xTimeIncrement);
//}

//TaskBase::~TaskBase() {
//	//#if INCLUDE_vTaskDelete
//	vTaskDelete(handle);
//	//#endif
//
//	return;
//}

//// TODO removed "=configMINIMAL_STACK_SIZE" after stackDepth
//TaskClass::TaskClass(char const*name, unsigned portBASE_TYPE priority,
//		unsigned portSHORT stackDepth) {
//
//	// "this-pointer" needed to get linkage with Task
//	xTaskCreate(&taskfun, (signed char*)name, stackDepth, this, priority, &handle);
//}

//// Memberfunction act as a task
//void TaskClass::taskfun(void* parm) {
//	// Start the individual task function
//	static_cast<Task>(parm).run();
//	//static_cast(parm)->task();
//
//	//#if INCLUDE_vTaskDelete
//	xTaskDelete(handle);
//	//#else
//	//    while(1)
//	//      vTaskDelay(10000);
//	//#endif
//}
//int TaskClass::cpp_Delay(void){
//
//}
//
//void TaskClass::cpp_Delay( const TickType_t xTicksToDelay ){
//
//}
//void TaskClass::cpp_kDelayUntil( TickType_t *pxPreviousWakeTime,
//		const TickType_t xTimeIncrement ){
//
//}
//LightTask::task(void){
//	uint64_t Lux = 0;
//	for(;;){
//		Lux = MyLightSensor.Light_Sensor_getLux();
//		MyUART.Write((char*)Lux);
//		vTaskDelay(500);
//	}
//
//}

