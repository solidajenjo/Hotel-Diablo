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
	//inventory.insert(world->getEntity("HERRAMIENTA"));
	
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

bool Player::getR106Opened()
{
	return r106Opened;
}

void Player::initActionManager() {
	actions["EMPUJARSILLA"] = &Player::lucasHang;
	actions["COMBINARPALOCONPIEDRACONCORDEL"] = &Player::craftAxe;
	actions["COMBINARCORDELCONPALOCONPIEDRA"] = &Player::craftAxe;
	actions["COMBINARCORDELCONPIEDRACONPALO"] = &Player::craftAxe;
	actions["COMBINARPALOCONCORDELCONPIEDRA"] = &Player::craftAxe;
	actions["COMBINARPIEDRACONCORDELCONPALO"] = &Player::craftAxe;
	actions["COMBINARPIEDRACONPALOCONCORDEL"] = &Player::craftAxe;
	actions["COMBINARWHISKYCONMATARRATAS"] = &Player::makeMortalCocktail;
	actions["COMBINARMATARRATASCONWHISKY"] = &Player::makeMortalCocktail;
	actions["USARCUCHILLOENLUCAS"] = &Player::killLucas;
	actions["USARCUCHILLOENLILY"] = &Player::killLily;
	actions["USARHACHAENMANTENIMIENTO"] = &Player::openMaintenance;	
	actions["USARCUCHILLOENDIMITRI"] = &Player::killDimitri;
	actions["USARHERRAMIENTAENTORNILLO"] = &Player::openCloset;
	actions["USARWHISKYENBEBIDA"] = &Player::poisonMarge;
	actions["USARLLAVE106ENH106"] = &Player::openR106;
	actions["ATRAVESARH106"] = &Player::goodEnd;
}
bool Player::tryAction(string action)
{
	if (actions.find(action) == actions.end()) return false;
	bool actionResult = (*this.*actions[action])();
	return actionResult;
}
bool Player::insertItem(Item * item, PrintUtilities * pu)
{
	if (inventory.size() < 3) {
		inventory.insert(item);
		location->removeEntity(item);
		return true;
	}
	else {
		pu->consoleCout(INVENTORY_FULL);
		return false;
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
		((Creature*)world->getEntity("LUCAS"))->removeEntity(world->getEntity("PIEDRA"));
		return true;
	}
	pu->consoleCout(I_CANT_DO_THAT);
	return true;
}
bool Player::openR106()
{
	if (this->hasItem((Item*)world->getEntity("LLAVE106"))
		&& location == world->getEntity("CORRIDOR2")) {
		pu->consoleCout(H106_OPEN);
		((Exit*)world->getEntity("R106_EXIT"))->unLock();
		r106Opened = true;
		return true;
	}
	pu->consoleCout(I_CANT_DO_THAT);
	return true;
}
bool Player::makeMortalCocktail() {
	if (this->hasItem((Item*)world->getEntity("MATARRATAS"))
		and this->hasItem((Item*)world->getEntity("WHISKY"))) {
		((Item*)world->getEntity("WHISKY"))->setDescription(DESC_WHISKY2);
		this->removeEntity(world->getEntity("MATARRATAS"));		
		pu->consoleCout(DESC_WHISKY2);
		poisonWhisky = true;
		return true;
	}
	pu->consoleCout(I_CANT_DO_THAT);
	return true;
}
bool Player::killLucas()
{
	if (!((Creature*)world->getEntity("LILY"))->isDead()
		&& location == world->getEntity("R101")
		&& this->hasItem((Item*)world->getEntity("CUCHILLO"))) {
		pu->consoleCout(KILL_LUCAS);
		((_NPC*)world->getEntity("LUCAS"))->kill();
		location->setDescription(DESC_R101_3);
		location->removeEntity(world->getEntity("LUCAS"));
		if (((_NPC*)world->getEntity("LUCAS"))->hasItem((Item*)world->getEntity("PIEDRA"))) {
			world->getEntity("R101")->insertEntity(world->getEntity("PIEDRA"));
			pu->consoleCout(LUCAS_DEATH2);
		}			
		return true;
	}
	pu->consoleCout(I_CANT_DO_THAT);
	return true;
}

bool Player::poisonMarge()
{
	if (this->hasItem((Item*)world->getEntity("WHISKY")) and location == world->getEntity("HALL"))
		if (!poisonWhisky) {
			pu->consoleCout(WHISKY_DRINK);			
		}
		else {
			if (!((_NPC*) world->getEntity("MARGE"))->isDead())
				pu->consoleCout(WHISKY_DRINK2);
				((_NPC*)world->getEntity("MARGE"))->kill();
				((Item*)world->getEntity("LLAVE106"))->unlock();
				location->setDescription(DESC_HALL2);
		}
	return true;
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

bool Player::killDimitri()
{
	if (location->containsEntity(world->getEntity("DIMITRI"))
		and this->hasItem((Item*)world->getEntity("CUCHILLO"))) {
		pu->consoleCout(KILL_DIMITRI2);
		pu->consoleCout(KILL_DIMITRI);
		((_NPC*)world->getEntity("DIMITRI"))->resetTimer();
		return true;
	}
	pu->consoleCout(I_CANT_DO_THAT);
	return true;
}

bool Player::openCloset()
{
	if (!closetOpened and this->hasItem((Item*)world->getEntity("HERRAMIENTA"))
		and location == (Room*)world->getEntity("KITCHEN")) {
		world->getEntity("ARMARIO")->removeEntity(world->getEntity("WHISKY"));
		location->insertEntity(world->getEntity("WHISKY"));		
		pu->consoleCout(DESC_WHISKY);
		closetOpened = true;
		return true;
	}
	pu->consoleCout(I_CANT_DO_THAT);
	return true;
}

bool Player::goodEnd()
{
	if (location == (Room*)world->getEntity("R106")) return false;
	if (!((Exit*)world->getEntity("R106_EXIT"))->isLocked()) {
		pu->consoleCout(DESC_R106);
		pu->consoleCout(GOOD_END_0);
		location = (Room*)world->getEntity("R106");
		if (!((_NPC*)world->getEntity("LUCAS"))->isDead()) {
			pu->consoleCout(GOOD_END);
			r106Opened = false;			
		}
		return true;
	}
	pu->consoleCout(I_CANT_DO_THAT);
	return true;
}

bool Player::killLily()
{
	if (!((Creature*)world->getEntity("LILY"))->isDead()
		&& location == world->getEntity("R106")
		&& this->hasItem((Item*)world->getEntity("CUCHILLO"))) {
		pu->consoleCout(KILL_LILY);
		((_NPC*)world->getEntity("LILY"))->kill();
		location->setDescription(DESC_R106_2);
		location->removeEntity(world->getEntity("LILY"));
		return true;
	}
	pu->consoleCout(I_CANT_DO_THAT);
	return true;
}
