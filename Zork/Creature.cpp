#include "stdafx.h"
#include "Creature.h"



Creature::~Creature()
{
}

void Creature::update() {

}

bool Creature::hasItem(Item * item)
{
	for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); ++it) {
		if (*it == item) return true;
	}
	return false;
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
