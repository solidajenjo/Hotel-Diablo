#include "stdafx.h"
#include "Exit.h"



void Exit::setDirection(directions direction)
{
	this->direction = direction;
}

directions Exit::getDirection()
{
	return direction;
}

void Exit::setDestination(Room* room)
{
	this->destination = room;
}

Room * Exit::getDestination()
{
	return destination;
}

bool Exit::isLocked()
{
	return locked;
}

void Exit::unLock()
{
	locked = false;
}

string Exit::getLockMsg()
{
	return lockMsg;
}


Exit::Exit(string name, directions direction, Room * destination, bool locked, string lockMsg)
{
	Entity("");
	this->type = EXIT;	
	this->name = name;
	this->direction = direction;
	this->destination = destination;
	this->locked = locked;
	this->lockMsg = lockMsg;
}

Exit::~Exit()
{
}

void Exit::update() {

}