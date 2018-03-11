#include "stdafx.h"
#include "Creature.h"



Creature::~Creature()
{
}

void Creature::update() {

}

void Creature::setCurrentRoom(Room * room)
{
	this->location = room;
}

Room * Creature::getCurrentRoom()
{
	return location;
}
