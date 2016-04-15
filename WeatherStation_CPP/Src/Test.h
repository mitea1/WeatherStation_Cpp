/*
 * Test.h
 *
 *  Created on: Apr 13, 2016
 *      Author: Adrian
 */

#ifndef TEST_H_
#define TEST_H_

class Test {
public:
	Test();
	Test(int);
	virtual ~Test();
	void doSomething(void);
private:
	int myValue;
};

#endif /* TEST_H_ */
