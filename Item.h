#pragma once
#include "Entity.h"
class Item :
	public Entity
{
public:
	using Entity::Entity;
	~Item();
	virtual void update();
};

