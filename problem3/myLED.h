/** code name: derek_LED.h
 *  original code written by Derek Molloy
 *  modified code written by Davis Farrow
 *
 *  this code is a modification of object orientented makeLEDs.cpp so that
 *  file is separted into multiple files. 
 *  this code is the header file containing the declaration of the class LED 
 */

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

#define LED_PATH "/sys/class/leds/beaglebone:green:usr"

class LED{
   private:
      string path;
      int number;
      virtual void writeLED(string filename, string value);
      virtual void removeTrigger();
   public:
      LED(int number);
      virtual void turnOn();
      virtual void turnOff();
      virtual void flash(string delayms);
      virtual void outputState();
      virtual ~LED();
};
