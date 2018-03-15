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
	bool insertItem(Item* item, PrintUtilities* pu);
	void dropItem(Item* item, PrintUtilities* pu);
	bool hasItem(Item* item);
	set<Entity*> getInventory();
	void initActionManager();
	bool tryAction(string action);
	void init(World* world, PrintUtilities* pu);
	void setLucasDaughter();
	bool getLucasDaughter();
	void setLucasUnhanged();	
	void setGoodEnd();
	bool getR106Opened();
private:
	typedef bool(Player::*function)();
	bool lucasHang();
	bool openR106();
	bool makeMortalCocktail();
	bool killLucas();
	bool poisonMarge();
	bool openMaintenance();
	bool craftAxe();
	bool killDimitri();	
	bool openCloset();
	bool goodEnd();
	bool killLily();
	World* world;
	PrintUtilities* pu;
	set<Entity*> inventory;
	map<string, function> actions;
	bool lucasDaughter = false;
	bool lucasUnhanged = false;	
	bool poisonWhisky = false;
	bool closetOpened = false;
	bool r106Opened = false;
};

