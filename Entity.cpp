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

void Entity::insertEntity(Entity* item)
{
	contains.push_back(item);
}

void Entity::removeEntity(Entity * item)
{
	contains.remove(item);
}

void Entity::setType(entityType type)
{
	this->type = type;
}

entityType Entity::getType()
{
	return type;
}
