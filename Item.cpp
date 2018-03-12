#include "stdafx.h"
#include "Item.h"


Item::Item(string description, string name, entityType type, bool locked, string lockMsg)
{
	this->description = description;
	this->name = name;
	this->type = type;
	this->locked = locked;
	this->lockMsg = lockMsg;
}

Item::~Item()
{
}

void Item::update() {

}

bool Item::isLocked()
{
	return locked;
}

string Item::getLockMsg()
{
	return lockMsg;
}
