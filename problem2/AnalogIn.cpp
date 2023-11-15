// code name: AnalogIn.cpp
// code by: Davis Farrow
//
// CPE 422 HW 8 problem 2
// this code is the implementation of the AnalogIn class

#include<iostream>
#include<fstream>
#include<sstream>
#include "AnalogIn.h"
using namespace std;

#define ADC_PATH "/sys/bus/iio/devices/iio:device0/in_voltage"
#define ADC 0

AnalogIn::AnalogIn() {
}

AnalogIn::AnalogIn(unsigned int n) {
	number = n;
}

void  AnalogIn::setNumber(unsigned int n) {
	number = n;
}

int AnalogIn::readAdcSample() {
	stringstream ss;
	ss << ADC_PATH << number << "_raw";
	fstream fs;
	fs.open(ss.str().c_str(), fstream::in);
	fs >> number;
	fs.close();
	
	float cur_voltage = number * (1.80f/4096.0f); // Vcc = 1.8V, 12-bit
	float diff_degreesC = (cur_voltage-0.75f)/0.01f;
	return (25.0f + diff_degreesC);
}

AnalogIn::~AnalogIn() {
}
