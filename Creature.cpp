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

bool Creature::isDead()
{
	return dead;
}

void Creature::kill()
{
	dead = true;
}
