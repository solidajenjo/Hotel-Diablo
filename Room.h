#pragma once
#include "Entity.h"
class Room :
	public Entity
{
public:
	Room();
	~Room();
private:
	directions direction;
	Room* source;
	Room* destination;
};

