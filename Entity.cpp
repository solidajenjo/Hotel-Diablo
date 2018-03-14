#include "stdafx.h"
#include "Entity.h"


Entity::Entity()
{
}

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

list<Entity*> Entity::getContents()
{
	return contains;
}

void Entity::setType(entityType type)
{
	this->type = type;
}

string Entity::getDescription()
{
	return description;
}

void Entity::setDescription(string description)
{
	this->description = description;
}

entityType Entity::getType()
{
	return type;
}
