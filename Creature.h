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
private:
	Room* location;
};

