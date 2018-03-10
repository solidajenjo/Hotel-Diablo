#pragma once
#include "Entity.h"
#include "Item.h"
class Room :
	public Entity
{
public:
	using Entity::Entity;
	~Room();
	virtual void update();
	void showRoom(PrintUtilities* pu);

private:
	directions direction;
	Room* source;
	Room* destination;
};

