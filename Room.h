#pragma once
#include "Entity.h"
class Room :
	public Entity
{
public:
	Room();
	~Room();
	virtual void update();
private:
	directions direction;
	Room* source;
	Room* destination;
};

