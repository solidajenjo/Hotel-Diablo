#pragma once

#include "Constants.h"
#include "PrintUtilities.h"
#include <string>
#include <list>
using namespace std;

class Entity
{
public:
	explicit Entity(string description);
	~Entity();
	virtual void update();

	void setName(string name);
	string getName();
	void insertItem(Entity* item);

protected:

	entityType type;
	string name;
	string description;
	list<Entity*> contains;
	
};

