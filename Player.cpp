#include "stdafx.h"
#include "Player.h"



Player::~Player()
{
}

void Player::update() {

}

void Player::init(World * world, PrintUtilities* pu) {
	this->world = world;
	this->pu = pu;
}
void Player::initActionManager() {
	actions["EMPUJARSILLA"] = &Player::lucasHang;
	actions["COMBINARPALOCONPIEDRACONCORDEL"] = &Player::craftAxe;
	actions["COMBINARCORDELCONPALOCONPIEDRA"] = &Player::craftAxe;
	actions["COMBINARCORDELCONPIEDRACONPALO"] = &Player::craftAxe;
	actions["COMBINARPALOCONCORDELCONPIEDRA"] = &Player::craftAxe;
	actions["COMBINARPIEDRACONCORDELCONPALO"] = &Player::craftAxe;
	actions["COMBINARPIEDRACONPALOCONCORDEL"] = &Player::craftAxe;
	//actions["USAR MATARRATAS EN BEBIDA"] = &Player::poisonMarge;
}
bool Player::tryAction(string action)
{
	if (actions.find(action) == actions.end()) return false;
	bool actionResult = (*this.*actions[action])();
	return actionResult;
}
void Player::insertItem(Item * item, PrintUtilities * pu)
{
	if (inventory.size() < 3) {
		inventory.insert(item);
		location->removeEntity(item);
	}
	else {
		pu->consoleCout(INVENTORY_FULL);
	}
}

void Player::dropItem(Item * item, PrintUtilities * pu)
{
	set<Entity*>::iterator it = inventory.find(item);
	if (it != inventory.end()) {
		inventory.erase(item);
		location->insertEntity(item);
	}
	else {
		pu->consoleCout(UNOWNED_OBJECT);
	}
}

bool Player::hasItem(Item * item)
{
	if (inventory.find(item) != inventory.end()) return true;
	else return false;
}

set<Entity*> Player::getInventory()
{
	return inventory;
}

bool Player::lucasHang() {
	if (!((Creature*)world->getEntity("LUCAS"))->isDead()
		&& location == world->getEntity("R101")) {
		location->setDescription(DESC_R101_2);
		pu->consoleCout(LUCAS_DEATH);
		world->getEntity("R101")->insertEntity(world->getEntity("PIEDRA"));
		((Creature*)world->getEntity("LUCAS"))->kill();
		return true;
	}
	pu->consoleCout(I_CANT_DO_THAT);
	return true;
}

bool Player::poisonMarge()
{
	return false;
}

bool Player::craftAxe()
{
	if (this->hasItem((Item*)world->getEntity("PALO"))
		and this->hasItem((Item*)world->getEntity("PIEDRA"))
		and this->hasItem((Item*)world->getEntity("CORDEL"))) {
		inventory.erase(world->getEntity("PALO"));
		inventory.erase(world->getEntity("PIEDRA"));
		inventory.erase(world->getEntity("CORDEL"));
		inventory.insert(world->getEntity("HACHA"));
		pu->consoleCout(DESC_AXE);		
		pu->updateInventory(inventory);
		return true;
	}
	pu->consoleCout(I_CANT_DO_THAT);
	return true;
}
