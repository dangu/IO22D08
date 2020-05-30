#include "Arduino.h"
#include "IO22D08.h"
#include <Timer.h>


IO22D08 io22d08;

Timer timer;



void testCallback()
{
	static uint8_t idx;
	static uint8_t charIdx[4] = {0,1,2,3};


	switch(idx)
	{
	case 0:
	case 1:
	case 2:
		io22d08.setCharacter(charIdx[idx], idx);
		++idx;
		break;
	case 3:
		io22d08.setCharacter(charIdx[idx], idx);
		idx=0;
		break;
	default:
		// TODO: Should never be here
		break;
	}

	io22d08.updateShiftregs();
}

void setup() {
	Serial.begin(9600);
	io22d08.init();

	int tickEvent = timer.every(5, testCallback);
	Serial.print("1 second tick started id=");
	Serial.println(tickEvent);
}

void loop() {
	timer.update();
}
