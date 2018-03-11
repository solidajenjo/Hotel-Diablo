#pragma once

#include "Entity.h"
#include "Room.h"
class Exit :
	public Entity	
{
public:
	using Entity::Entity;
	Exit(string name, directions direction, Room* destination);
	~Exit();
	virtual void update();
	void setDirection(directions direction);
	directions getDirection();
	void setDestination(Room* room);
	Room* getDestination();	
	
private:
	directions direction;
	Room* destination;
};

