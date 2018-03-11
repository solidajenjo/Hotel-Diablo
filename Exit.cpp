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

Exit::~Exit()
{
}

void Exit::update() {

}