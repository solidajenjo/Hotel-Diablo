#pragma once
#include "Entity.h"
#include "Room.h"

class Creature :
	public Entity
{
public:
	using Entity::Entity;
	~Creature();
	virtual void update();
private:
	Room* location;
};

