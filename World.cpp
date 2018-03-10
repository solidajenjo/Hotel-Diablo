#include "stdafx.h"
#include "World.h"


World::World()
{
	//hotel initialitzation	
	entities["HALL"] = new Room(DESC_HALL);
	entities["CORRIDOR1"] = new Room(DESC_CORRIDOR1);
	entities["CORRIDOR2"] = new Room(DESC_CORRIDOR2);
	entities["KITCHEN"] = new Room(DESC_KITCHEN);
	entities["R101"] = new Room(DESC_R101);
	entities["R102"] = new Room(DESC_R102);
	entities["R104"] = new Room(DESC_R104);
	entities["R106"] = new Room(DESC_R106);
	entities["R107"] = new Room(DESC_R107);
	entities["R108"] = new Room(DESC_R108);
	entities["MAINTENANCE"] = new Room(DESC_MAINTENANCE);

	//items

	entities["STICK"] = new Item("Un palo.");
	entities["STICK"]->setName("PALO");
	entities["STONE"] = new Item("Una piedra con forma triangular. Esta afilada");
	entities["STONE"]->setName("PIEDRA");
	entities["VASE"] = new Item("Una jarr\242n de lo mas elegante.");
	entities["VASE"]->setName("JARRON");

	//objects placement

	entities["R108"]->insertItem(entities["VASE"]);
	entities["R108"]->insertItem(entities["STONE"]);
}


World::~World()
{
}

void World::update() {

}

Entity* World::getEntity(string name)
{
	return entities[name];
}
