#pragma once
#include "Entity.h"
#include <time.h>
class Time :
	public Entity
{
public:
	Time(PrintUtilities* pu);
	~Time();
	virtual void update();
private:
	int startTime;
	int endTime;
	int minutes, seconds, lastSecond;
	PrintUtilities* pu;
	bool minute10Warning = false, minute5Warning = false, minute1Warning = false
		, outOfTime = false;
};
