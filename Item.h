#pragma once
#include "Entity.h"
class Item :
	public Entity
{
public:
	Item(string description, string name, entityType type, bool locked, string lockMsg);
	~Item();
	virtual void update();
	bool isLocked();
	void unlock();
	string getLockMsg();
private:
	bool locked;
	string lockMsg;
};

