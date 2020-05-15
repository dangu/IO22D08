/**@file
IO22D08.h - Library for the 8 channel Pro mini PLC board
Created by Daniel Gullberg, May 5, 2020
Released into the public domain.
 */

#ifndef IO22D08_H
#define IO22D08_H

#include "Arduino.h"

class IO22D08
{
public:
	IO22D08();
	void test();
private:
	int _testvar;
	int _pin_595_0E; //!< Relay shift register NG-pin (Output enable)
	int _data;
	int _clock;
	int _latch;

};


#endif
