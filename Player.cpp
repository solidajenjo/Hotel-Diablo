#include "stdafx.h"
#include "Player.h"



Player::~Player()
{
}

void Player::update() {

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
