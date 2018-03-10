#pragma once

#include "Constants.h"
#include "PrintUtilities.h"
#include <string>
#include <list>
using namespace std;

class Entity
{
public:
	Entity();
	~Entity();
	virtual void update();
protected:

	entityType type;
	string name;
	string description;
	list<Entity*> contains;
	
};

