#pragma once
#include "Creature.h"
class Player :
	public Creature
{
public:	
	using Creature::Creature;
	~Player();
	virtual void update();
};

