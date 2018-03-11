#include "stdafx.h"
#include "Room.h"


Room::~Room()
{
}

void Room::update() {

}

void Room::showRoom(PrintUtilities * pu)
{
	list<Entity*>::iterator it = contains.begin();
	pu->consoleCout(description);
	pu->consoleCout("\bObjetos:");
	while (it != contains.end()) {
		Entity* item = *it;
		if (item->getType() == ITEM) {
			pu->consoleCout("\b  " + item->getName());
		}
		it++;
	}
	it = contains.begin();
	pu->consoleCout("\bPersonas:");
	while (it != contains.end()) {
		Entity* npc = *it;
		if (npc->getType() == NPC) {
			pu->consoleCout("\b  " + npc->getName());
		}
		it++;
	}
	it = contains.begin();
	pu->consoleCout("\bSalidas:");
	while (it != contains.end()) {
		Entity* exit = *it;
		if (exit->getType() == EXIT) {
			pu->consoleCout("\b  " + exit->getName());
		}
		it++;
	}
}

vector<Entity*> Room::getExits()
{
	list<Entity*>::iterator it = contains.begin();
	vector<Entity*> exits;
	while (it != contains.end()) {
		Entity* exit = *it;
		if (exit->getType() == EXIT) {
			exits.push_back(exit);
		}
		it++;
	}
	return exits;
}

bool Room::isLocked()
{
	return locked;
}

bool Room::containsItem(Item * item)
{
	if (item == nullptr) return false;
	for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); it++) {
		if (*it == item) return true;
	}
	return false;
}

void Room::lockDoor()
{
	locked = true;
}



