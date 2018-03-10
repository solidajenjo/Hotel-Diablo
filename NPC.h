#pragma once
#include "Creature.h"
class NPC :
	public Creature
{
public:
	NPC();
	~NPC();
	virtual void update();
};

