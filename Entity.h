#pragma once

#include "Constants.h"
#include <string>
#include <list>
using namespace std;

class Entity
{
public:
	explicit Entity();
	explicit Entity(string description);
	~Entity();
	virtual void update();

	void setName(string name);
	string getName();
	void insertEntity(Entity* item);
	void removeEntity(Entity* item);
	void setType(entityType type);
	string getDescription();
	void setDescription(string description);
	entityType getType();
protected:

	entityType type;
	string name;
	string description;
	list<Entity*> contains;
	
};

