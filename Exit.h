#pragma once
#include "Entity.h"
class Exit :
	public Entity
{
public:
	using Entity::Entity;
	~Exit();
	virtual void update();
};

