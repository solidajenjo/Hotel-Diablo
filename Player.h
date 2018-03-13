#pragma once
#include "Creature.h"
#include "World.h"
#include "PrintUtilities.h"
#include <set>
class Player :
	public Creature
{
public:	
	using Creature::Creature;
	~Player();
	virtual void update();
	void insertItem(Item* item, PrintUtilities* pu);
	void dropItem(Item* item, PrintUtilities* pu);
	bool hasItem(Item* item);
	set<Entity*> getInventory();
	void initActionManager();
	bool tryAction(string action);
	void init(World* world, PrintUtilities* pu);
private:
	typedef bool(Player::*function)();
	bool lucasHang();
	bool poisonMarge();
	bool craftAxe();
	World* world;
	PrintUtilities* pu;
	set<Entity*> inventory;
	map<string, function> actions;
};

