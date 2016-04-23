/*
 * Light_Sensor_CPP.hpp
 *
 *  Created on: Apr 20, 2016
 *      Author: Simon
 */
#ifndef LIGHT_SENSOR_CPP_HPP_
#define LIGHT_SENSOR_CPP_HPP_

/*----- Header-Files -------------------------------------------------------*/
#include <Light_Sensor.h>

/*----- Macros -------------------------------------------------------------*/

/*----- Data ---------------------------------------------------------------*/
class Light_Sensor{
private:
	char string[20];
public:
	Light_Sensor();
	~Light_Sensor();
	double getLux(void);
};

#endif /* LIGHT_SENSOR_CPP_HPP_ */
