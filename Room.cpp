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
		pu->consoleCout("\b  "+item->getName());
		it++;
	}
}


