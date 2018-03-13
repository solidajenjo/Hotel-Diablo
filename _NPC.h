#pragma once
#include "Creature.h"
#include "Time.h"

class _NPC :
	public Creature
{
public:	
	using Creature::Creature;
	~_NPC();
	virtual void update();
	string getNextPosition();
	void addPosibleLocations(Room* location);
	void setTimer(Time &time);
private:
	Room * nextPositon;
	vector<Room*> posibleLocations;
	Time* time;
	int timer = 0;
	int lastTime;
};

