// code name: myGpioApp.cpp
// code by: Davis Farrow
//
// CPE 422 HW 8 problem 1
// this code instantiates objects with MYGPIO class: 
// a. Instantiate an object as an output gpio using pin p9.12.
// b. Instantiate an object as an input gpio using pin p8.16.
// c. Set p9.12 high for 3 seconds, and then set it low. Print out its value in both cases.
// d. Read p8.16 and print out its value. 
//
// to run this file: 
// ./build_myGpio
// ./myGpioApp

#include<iostream>
#include<unistd.h> //for usleep
#include"myGpio.h"
using namespace std;

int main() {
	MYGPIO outGPIO(60), inGPIO(46);

	// Set p9.12 high for 3 seconds, and then set it low. Print out its value in both cases.
	outGPIO.setDirection(OUTPUT);
	outGPIO.setValue(HIGH);
	cout << "pin 9.12 is set: " << outGPIO.getValue() << " for 3 secs" << endl;
	sleep(3); //sleep 3 seconds
        outGPIO.setValue(LOW);
	cout << "pin 9.12 is set: " << outGPIO.getValue() << " now" <<  endl;

	// Read p8.16 and print out its value.	
	inGPIO.setDirection(INPUT);
	cout << "The value of the input is: "<< inGPIO.getValue() << endl;
	
	return 0;
}
