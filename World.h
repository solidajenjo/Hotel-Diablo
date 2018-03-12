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
	World(PrintUtilities* pu);
	~World();
	virtual void update();
	Entity* getEntity(string name);
	bool tryAction(string action);
	void moveCreature(string name, Room* origin, Room* destination);
private:
	typedef bool(World::*function)();
	bool lucasHang();
	void poisonMarge();
	map<string, Entity*> entities;
	map<string, function> actions;
	PrintUtilities* pu;

};

