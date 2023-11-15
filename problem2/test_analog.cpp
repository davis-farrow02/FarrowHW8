// code name: test_analog.cpp
// code by: Davis Farrow
//
// CPE 422 HW 8 problem 2
// this code instantiates objects with AnalogIn class
// and reads temperature sensor to read analog values.
//
// This test application simply instantiates an AnalogIn
// object with number zero, then calls getNumber(), and finally calls readAdcSample().  
//
// to use this code:
// ./build_analog
// ./test_analog

#include<iostream>
#include "AnalogIn.h"
using namespace std;

int main() {
	AnalogIn AIN0(0);	
	cout << "Starting the AnalogIn AIN0 code" << endl;
	cout << "The ADC value input is: " << AIN0.getNumber() << endl;
	float temp = AIN0.readAdcSample();
	float fahr = 32 + ((temp * 9)/5);    // convert deg. C to deg. F
	cout << "Temperature is " << temp << "°C (" << fahr << "°F)" << endl;

	return 0;
}
