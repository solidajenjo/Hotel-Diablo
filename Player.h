#pragma once
#include "Creature.h"
class Player :
	public Creature
{
public:	
	~Player();
	virtual void update();
};

