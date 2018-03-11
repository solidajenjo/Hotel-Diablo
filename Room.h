#pragma once
#include "Entity.h"
#include "Item.h"
#include "PrintUtilities.h"

class Room :
	public Entity
{
public:
	using Entity::Entity;
	~Room();
	virtual void update();
	void showRoom(PrintUtilities* pu);
	vector<Entity*> getExits();
	bool isLocked();
	bool containsItem(Item* item);
	void lockDoor();
private:
	bool locked = false;
};

