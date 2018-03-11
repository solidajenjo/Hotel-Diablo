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
}


