/*
 * Test.cpp
 *
 *  Created on: Apr 13, 2016
 *      Author: Adrian
 */

#include <Test.h>

Test::Test() {
	// TODO Auto-generated constructor stub
	int i = 0;
	i++;
}

Test::Test(int value) {
	// TODO Auto-generated constructor stub
	this->myValue=value;
}

Test::~Test() {
	// TODO Auto-generated destructor stub
}

void Test::doSomething(){
	this->myValue++;
}

