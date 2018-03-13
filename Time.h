#pragma once
#include "Entity.h"
#include "PrintUtilities.h"
#include <time.h>

class Time{
public:
	
	Time(PrintUtilities* pu);
	~Time();
	virtual void update();
	bool isFinished();
	int getTime();
private:
	int startTime;
	int endTime;
	int timeInSeconds;
	int minutes, seconds, lastSecond;
	PrintUtilities* pu;
	bool minute10Warning = false, minute5Warning = false, minute1Warning = false
		, outOfTime = false;
};

