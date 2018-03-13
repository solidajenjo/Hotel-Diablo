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
	void setCurrentRoom(Room* room);
	Room* getCurrentRoom();
	bool isDead();
	void kill();
protected:
	Room* location;
	bool dead = false;
};

