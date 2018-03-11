#pragma once
#include "Entity.h"
#include "Room.h"
#include "Exit.h"
#include "Player.h"
#include "_NPC.h"
#include <map>
class World
{
public:
	World();
	~World();
	virtual void update();
	Entity* getEntity(string name);
	void moveCreature(string name, Room* origin, Room* destination);
private:
	map<string, Entity*> entities;
};

