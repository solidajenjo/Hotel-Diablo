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
	void insertEntity(Entity* item);
	void removeItem(Entity* item);
	void setType(entityType type);
	entityType getType();
protected:

	entityType type;
	string name;
	string description;
	list<Entity*> contains;
	
};

