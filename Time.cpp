#include "stdafx.h"
#include "Time.h"


Time::Time(PrintUtilities* pu)
{
	this->pu = pu;
	time_t timer;
	struct tm * timeinfo;
	time(&timer);
	startTime = timer;
	endTime = startTime + TOTAL_TIME;	
	lastSecond = 99;
}


Time::~Time()
{
}

void Time::update()
{
	if (outOfTime) return;
	time_t timer;
	struct tm * timeinfo;
	time(&timer);
	int currentTime = timer;
	int remainingTime = (endTime - currentTime);
	minutes = remainingTime  / 60;
	seconds = remainingTime  % 60;
	if (minutes == 10 && seconds == 0 && !minute10Warning) {
		pu->consoleCout(MINUTE_10_WARNING);
		minute10Warning = true;
	}
	if (minutes == 5 && seconds == 0 && !minute5Warning) {
		pu->consoleCout(MINUTE_5_WARNING);
		minute5Warning = true;
	}
	if (minutes == 0 && seconds == 0 && !outOfTime) {
		pu->consoleCout(OUT_OF_TIME);
		outOfTime = true;
	}
	if (minutes == 1 && seconds == 0 && !minute1Warning) {
		pu->consoleCout(MINUTE_1_WARNING);
		minute1Warning = true;
	}
	if (seconds != lastSecond) {
		string strSecond = to_string(seconds);
		//Beep(523, 20);
		if (seconds < 10) strSecond = '0' + strSecond;
		string strMinute = to_string(minutes);
		if (minutes < 10) strMinute = '0' + strMinute;
		pu->coutXY(TIME_X, TIME_Y, "                                  ");
		pu->coutXY(TIME_X, TIME_Y, "Tiempo restante " + strMinute + ":" + strSecond);
		lastSecond = seconds;
	}
}
