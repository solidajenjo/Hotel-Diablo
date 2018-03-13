#pragma once
#include "Entity.h"
#include "Room.h"
#include "Exit.h"
//#include "Player.h"
#include "_NPC.h"
#include <map>
class World
{	
public:
	World(PrintUtilities* pu);
	~World();
	virtual void update();
	Entity* getEntity(string name);
	void insertEntity(string name, Entity* entity);
	void moveCreature(string name, Room* origin, Room* destination);
private:
	map<string, Entity*> entities;
	PrintUtilities* pu;

};

