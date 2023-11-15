// code name: gpioApp.cpp
// code by: Davis Farrow 
//
// CPE 422 HW 8 problem 3
// this code instantiates classes LED, AnalogIn, and GPIO
// The application shall perform the following tasks and then exits:
// a. Turn on user LEDs number 1 and 3.
// b. Flash user LED 2. Use LED’s flash function.
// c. Read the temperature sensor and display its value.
// d. Read the push button on P8.16.
// e. If the push button in item 4 was pushed, turn on the LED on P9.12. 
// 
// to run this code:
// ./build_gpio
// ./gpioApp

#include<iostream>
#include<unistd.h>
#include "AnalogIn.h"
#include "GPIO.h"
#include "myLED.h"

using namespace exploringBB;
using namespace std;

int main() {
	LED leds[4] = { LED(0), LED(1), LED(2), LED(3) };
	AnalogIn AIN0(0);
	GPIO outGPIO(60), inGPIO(46);

	cout << "a) turning on user LEDs number 1 and 3" << endl;
	leds[0].turnOn();
	leds[2].turnOn();
	cout << endl;

	cout << "b) flashing user LED number 2" << endl;
	leds[1].flash("100");
	cout << endl;
	sleep(0.5); //hold for 500 ms

	cout << "c) reading temperature sensor and displaying value" << endl;
        float temp = AIN0.readAdcSample();
        float fahr = 32 + ((temp * 9)/5);    // convert deg. C to deg. F
	cout << "Temperature is " << temp << "°C (" << fahr << "°F)" << endl;
	cout << endl;
	sleep(0.5); // hold for 500 ms

	cout << "d) reading push button on p8.16" << endl;  
	inGPIO.setDirection(INPUT);
	cout << "The value of the input is: "<< inGPIO.getValue() << endl;
	cout << endl;

	cout << "e) if push button is pressed, turning on external LED on p9.12" << endl;
	outGPIO.setDirection(OUTPUT);
	if (inGPIO.getValue() ==0) {
		cout << "push button is pressed, turning on LED" << endl;
		outGPIO.setValue(HIGH);
	} else {
		cout << "push button is NOT pressed, LED stays off" << endl;
		outGPIO.setValue(LOW);
	}
	cout << endl;

	return 0;
}
