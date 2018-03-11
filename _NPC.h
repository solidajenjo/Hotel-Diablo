#pragma once
#include "Creature.h"

class _NPC :
	public Creature
{
public:	
	using Creature::Creature;
	~_NPC();
	virtual void update();
};

