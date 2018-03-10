#include "stdafx.h"
#include "Entity.h"


Entity::Entity(string description)
{
	this->description = description;
}


Entity::~Entity()
{
}

void Entity::update() {

}

void Entity::setName(string name)
{
	this->name = name;
}

string Entity::getName()
{
	return name;
}

void Entity::insertItem(Entity* item)
{
	contains.push_back(item);
}
