#include "stdafx.h"
#include "_NPC.h"




_NPC::~_NPC()
{
}

void _NPC::update() {	
	if (posibleLocations.size() == 0) return;
	if (timer == 0) {
		lastTime = time->getTime();
		int i = rand() % posibleLocations.size();
		while (location == posibleLocations[i]) i = rand() % posibleLocations.size();
		location->removeEntity(this);
		location = posibleLocations[i];
		location->insertEntity(this);
	}
	timer = time->getTime() - lastTime - DIMITRI_MOVE_TIME;
}

string _NPC::getNextPosition()
{
	return location->getName() + M4 + to_string(-timer) + " segundos";
}

void _NPC::addPosibleLocations(Room* location)
{
	posibleLocations.push_back(location);
}

void _NPC::setTimer(Time &time)
{
	this->time = &time;
}
