#pragma once
#include "Entity.h"
#include "Room.h"
#include <map>
class World
{
public:
	World();
	~World();
	virtual void update();
	Entity* getEntity(string name);
private:
	map<string, Entity*> entities;
};

