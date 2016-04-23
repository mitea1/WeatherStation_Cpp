/*
 * Light_Sensor_CPP.cpp
 *
 *  Created on: Apr 20, 2016
 *      Author: Simon
 */
/*----- Header-Files -------------------------------------------------------*/
#include "cpp_Light_Sensor.hpp"

/*----- Macros -------------------------------------------------------------*/

/*----- Data types ---------------------------------------------------------*/

/*----- Data ---------------------------------------------------------------*/

/*----- Implementation -----------------------------------------------------*/
/**
 * @brief 	Constructor for Light_Sensor class
 */
Light_Sensor::Light_Sensor(){
	LIGHT_SENSOR_init();
}
/**
 * @brief 	Destructor for Light_Sensor class
 */
Light_Sensor::~Light_Sensor(){

}
/**
 * @brief 	Gets Lux form Light Sensor
 * @return	Brightness in Lux
 */
double Light_Sensor::getLux(){
	return LIGHT_SENSOR_getLux();
}
