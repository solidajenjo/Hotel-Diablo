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
void Player::setLucasDaughter()
{
	lucasDaughter = true;
}
bool Player::getLucasDaughter()
{
	return lucasDaughter;
}
void Player::setLucasUnhanged()
{
	lucasUnhanged = true;
}
void Player::setGoodEnd()
{
	goodEnd = true;
}
bool Player::getGoodEnd()
{
	return goodEnd;
}
void Player::initActionManager() {
	actions["EMPUJARSILLA"] = &Player::lucasHang;
	actions["COMBINARPALOCONPIEDRACONCORDEL"] = &Player::craftAxe;
	actions["COMBINARCORDELCONPALOCONPIEDRA"] = &Player::craftAxe;
	actions["COMBINARCORDELCONPIEDRACONPALO"] = &Player::craftAxe;
	actions["COMBINARPALOCONCORDELCONPIEDRA"] = &Player::craftAxe;
	actions["COMBINARPIEDRACONCORDELCONPALO"] = &Player::craftAxe;
	actions["COMBINARPIEDRACONPALOCONCORDEL"] = &Player::craftAxe;
	actions["USARCUCHILLOENLUCAS"] = &Player::killLucas;
	actions["USARHACHAENMANTENIMIENTO"] = &Player::openMaintenance;	

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
	if (!lucasUnhanged and !((Creature*)world->getEntity("LUCAS"))->isDead()
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

bool Player::killLucas()
{
	if (!lucasUnhanged and !((Creature*)world->getEntity("LUCAS"))->isDead()
		&& location == world->getEntity("R101")
		&& this->hasItem((Item*)world->getEntity("CUCHILLO"))) {
		pu->consoleCout(KILL_LUCAS);
		pu->consoleCout(LUCAS_DEATH2);
		((_NPC*)world->getEntity("LUCAS"))->kill();
		location->setDescription(DESC_R101_3);
		location->removeEntity(world->getEntity("LUCAS"));
		world->getEntity("R101")->insertEntity(world->getEntity("PIEDRA"));
		return true;
	}
	pu->consoleCout(I_CANT_DO_THAT);
	return true;
}

bool Player::poisonMarge()
{
	return false;
}

bool Player::openMaintenance()
{
	if (this->hasItem((Item*)world->getEntity("HACHA"))
		and location == (Room*)world->getEntity("CORRIDOR2")) {
		pu->consoleCout(MAINT_OPEN);
		vector<Entity*> exits = location->getExits();
		for (auto exit : exits) {
			if (exit->getName() == "OESTE") ((Exit*)exit)->unLock();
		}
	}
	return true;
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
