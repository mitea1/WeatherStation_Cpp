/*
 * cpp_Humid_Temp_Sensor.hpp
 *
 *  Created on: Apr 23, 2016
 *      Author: Simon
 */
#ifndef CPP_HUMID_TEMP_SENSOR_HPP_
#define CPP_HUMID_TEMP_SENSOR_HPP_

/*----- Header-Files -------------------------------------------------------*/
#import <Humid_Temp_Sensor.h>

/*----- Macros -------------------------------------------------------------*/

/*----- Data ---------------------------------------------------------------*/
class HumTemp_Sensor{
private:

public:
	HumTemp_Sensor();
	~HumTemp_Sensor();
	int32_t getTemperature();
	int32_t getPressure();
	int32_t getHumidity();
};

#endif /* CPP_HUMID_TEMP_SENSOR_HPP_ */
