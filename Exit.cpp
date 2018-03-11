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


Exit::Exit(string name, directions direction, Room * destination)
{
	Entity("");
	this->type = EXIT;	
	this->name = name;
	this->direction = direction;
	this->destination = destination;
}

Exit::~Exit()
{
}

void Exit::update() {

}