/*
 * cpp_Humid_Temp_Sensor.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: Simon
 */
/*----- Header-Files -------------------------------------------------------*/
#include "cpp_Humid_Temp_Sensor.hpp"

/*----- Macros -------------------------------------------------------------*/

/*----- Data types ---------------------------------------------------------*/

/*----- Data ---------------------------------------------------------------*/

/*----- Implementation -----------------------------------------------------*/
/**
 * @brief Constructor for HumTemp_Sensor class
 */
HumTemp_Sensor::HumTemp_Sensor(){
	HMDTEMP_initWeatherMonitoring();
}
/**
 * @brief Destructor for HumTemp_Sensor class
 */
HumTemp_Sensor::~HumTemp_Sensor(){

}
/**
 * @brief Returns Temperature value. Needs to be corrected:
 * 			Return Value / 100 = Temperature in Grad Celsius
 */
int32_t HumTemp_Sensor::getTemperature(){
	return HMDTEMP_getTemperature();
}
/**
 * @brief Returns Pressure value. Needs to be corrected:
 * 			Return Value / 100 = hPa
 */
int32_t HumTemp_Sensor::getPressure(){
	return HMDTEMP_getPressure();
}
/**
 * @brief Returns Humidity value.
 */
int32_t HumTemp_Sensor::getHumidity(){
	return HMDTEMP_getHumidity();
}
