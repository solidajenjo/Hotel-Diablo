#include "stdafx.h"
#include "World.h"


World::World(PrintUtilities* pu)
{
	this->pu = pu;
	//hotel initialitzation	
	entities["HALL"] = new Room(DESC_HALL);
	entities["HALL"]->setType(ROOM);
	entities["HALL"]->setName("Hall");
	entities["CORRIDOR1"] = new Room(DESC_CORRIDOR1);
	entities["CORRIDOR1"]->setType(ROOM);
	entities["CORRIDOR1"]->setName("Pasillo 1");
	entities["CORRIDOR2"] = new Room(DESC_CORRIDOR2);
	entities["CORRIDOR2"]->setType(ROOM);
	entities["CORRIDOR2"]->setName("Pasillo 2");
	entities["KITCHEN"] = new Room(DESC_KITCHEN);
	entities["KITCHEN"]->setType(ROOM);
	entities["KITCHEN"]->setName("Cocina");
	entities["R101"] = new Room(DESC_R101);
	entities["R101"]->setType(ROOM);
	entities["R101"]->setName("Habitacion 101");
	entities["R102"] = new Room(DESC_R102);
	entities["R102"]->setType(ROOM);
	entities["R102"]->setName("Habitacion 102");
	entities["R103"] = new Room("");
	entities["R103"]->setType(ROOM);
	entities["R103"]->setName("Habitacion 103");
	Room* R103 = (Room*)entities["R103"];
	R103->lockDoor();
	entities["R104"] = new Room(DESC_R104);
	entities["R104"]->setType(ROOM);
	entities["R104"]->setName("Habitacion 104");
	entities["R105"] = new Room("");
	entities["R105"]->setType(ROOM);
	entities["R105"]->setName("Habitacion 105");
	Room* R105 = (Room*)entities["R105"];
	R105->lockDoor();
	entities["R106"] = new Room(DESC_R106);
	entities["R106"]->setType(ROOM);
	entities["R106"]->setName("Habitacion 106");
	Room* R106 = (Room*)entities["R106"];
	R106->lockDoor();
	entities["R107"] = new Room(DESC_R107);
	entities["R107"]->setType(ROOM);
	entities["R107"]->setName("Habitacion 107");
	entities["R108"] = new Room(DESC_R108);
	entities["R108"]->setType(ROOM);
	entities["R108"]->setName("Habitacion 108");
	entities["MAINTENANCE"] = new Room(DESC_MAINTENANCE);
	entities["MAINTENANCE"]->setType(ROOM);
	entities["MAINTENANCE"]->setName("Cuarto de mantenimiento");
	Room* maintenance = (Room*)entities["MAINTENANCE"];
	maintenance->lockDoor();

	//items	
	entities["PALO"] = new Item(DESC_STICK, "PALO", ITEM, false, "");
	entities["PIEDRA"] = new Item(DESC_STONE, "PIEDRA", ITEM, false, "");
	entities["JARRON"] = new Item(DESC_VASE, "JARRON", ITEM, false, "");
	entities["MATARRATAS"] = new Item(DESC_POISON, "MATARRATAS", ITEM,false,"");
	entities["HERRAMIENTA"] = new Item(DESC_WRENCH, "HERRAMIENTA", ITEM,false,"");
	entities["MARTILLO"] = new Item(DESC_HAMMER, "MARTILLO", ITEM, false, "");
	entities["CLAVOS"] = new Item(DESC_NAILS, "CLAVOS", ITEM, false, "");
	entities["LLAVE106"] = new Item(DESC_KEYR106, "LLAVE106", ITEM, true, LOCK_KEY);
	entities["MALETA"] = new Item(DESC_CASE, "MALETA", ITEM, true, LOCK_CASE);
	entities["ROPITA"] = new Item(DESC_CLOTHES, "ROPITA", ITEM, false, "");
	entities["POLLO"] = new Item(DESC_CHICKEN, "POLLO", ITEM, false, "");
	entities["SILLA"] = new Item(DESC_CHAIR, "SILLA", ITEM, true, LOCK_CHAIR);
	entities["CORDEL"] = new Item(DESC_CORD, "CORDEL", ITEM, false, "");
	entities["ARMARIO"] = new Item(DESC_CLOSET, "ARMARIO", ITEM, true, LOCK_CLOSET);
	entities["CANDADO"] = new Item(DESC_LOCK, "CANDADO", ITEM, true, LOCK_LOCK);
	entities["TORNILLO"] = new Item(DESC_SCREW, "TORNILLO", ITEM, true, LOCK_SCREW);
	entities["BEBIDA"] = new Item(DESC_DRINK, "BEBIDA", ITEM, true, LOCK_DRINK);
	entities["WHISKY"] = new Item(DESC_WHISKY, "WHISKY", ITEM, false, "");
	entities["OLLA"] = new Item(DESC_POT, "OLLA", ITEM, false, "");
	entities["CUCHILLO"] = new Item(DESC_KNIFE, "CUCHILLO", ITEM, false, "");
	entities["CUADRO"] = new Item(DESC_PICTURE, "CUADRO", ITEM, true, LOCK_PICTURE);
	entities["HACHA"] = new Item(DESC_AXE, "HACHA", ITEM, false, "");

	//NPCs	
	entities["DIMITRI"] = new _NPC(DESC_DIMI1);
	entities["DIMITRI"]->setType(NPC);
	entities["DIMITRI"]->setName("DIMITRI");
	entities["LUCAS"] = new _NPC(DESC_LUCAS1);
	entities["LUCAS"]->setType(NPC);
	entities["LUCAS"]->setName("LUCAS");
	entities["LILY"] = new _NPC(DESC_LILY1);
	entities["LILY"]->setType(NPC);
	entities["LILY"]->setName("LILY");
	entities["MARGE"] = new _NPC(DESC_MARGE1);
	entities["MARGE"]->setType(NPC);
	entities["MARGE"]->setName("MARGE");
	
	_NPC* dimi = (_NPC*)entities["DIMITRI"];
	dimi->addPosibleLocations((Room*)entities["R101"]);
	dimi->addPosibleLocations((Room*)entities["R102"]);
	dimi->addPosibleLocations((Room*)entities["R104"]);
	dimi->addPosibleLocations((Room*)entities["R106"]);
	dimi->addPosibleLocations((Room*)entities["R107"]);
	dimi->addPosibleLocations((Room*)entities["R108"]);
	dimi->addPosibleLocations((Room*)entities["MAINTENANCE"]);
	dimi->addPosibleLocations((Room*)entities["KITCHEN"]);
	dimi->addPosibleLocations((Room*)entities["CORRIDOR1"]);
	dimi->addPosibleLocations((Room*)entities["CORRIDOR2"]);
	dimi->setCurrentRoom((Room*)entities["MAINTENANCE"]);
	//exits
	
	entities["EAST_HALL_EXIT"] = new Exit("ESTE", _EAST, (Room*)entities["CORRIDOR1"], true, LOCK_HALL);
	entities["WEST_HALL_EXIT"] =  new Exit("OESTE", _WEST, (Room*)entities["CORRIDOR2"], true, LOCK_HALL);
	entities["EAST_CORRIDOR2_EXIT"] = new Exit("ESTE", _EAST, (Room*)entities["HALL"], false, "");
	entities["WEST_CORRIDOR2_EXIT"] = new Exit("OESTE", _WEST, (Room*)entities["MAINTENANCE"], true, LOCK_MAINT);
	entities["EAST_CORRIDOR1_EXIT"] = new Exit("ESTE", _EAST, (Room*)entities["KITCHEN"], false, "");
	entities["WEST_CORRIDOR1_EXIT"] = new Exit("OESTE", _WEST, (Room*)entities["HALL"], false, "");
	entities["WEST_KITCHEN_EXIT"] = new Exit("OESTE", _WEST, (Room*)entities["CORRIDOR1"], false, "");
	entities["EAST_MAINTENANCE_EXIT"] = new Exit("ESTE", _EAST, (Room*)entities["CORRIDOR2"], false, "");
	entities["R101_EXIT"] = new Exit("H101", ATRAVESARH101, (Room*)entities["R101"], false, "");
	entities["R101_CORRIDOR_EXIT"] = new Exit("H101", ATRAVESARH101, (Room*)entities["CORRIDOR1"], false, "");
	entities["R102_EXIT"] = new Exit("H102", ATRAVESARH102, (Room*)entities["R102"], false, "");
	entities["R102_CORRIDOR_EXIT"] = new Exit("H102", ATRAVESARH102, (Room*)entities["CORRIDOR1"], false, "");
	entities["R103_EXIT"] = new Exit("H103", ATRAVESARH103, (Room*)entities["R103"], true, LOCK_FOREVER);
	entities["R104_EXIT"] = new Exit("H104", ATRAVESARH104, (Room*)entities["R104"], false, "");
	entities["R104_CORRIDOR_EXIT"] = new Exit("H104", ATRAVESARH104, (Room*)entities["CORRIDOR1"], false, "");
	entities["R105_EXIT"] = new Exit("H105", ATRAVESARH105, (Room*)entities["R105"], true, LOCK_FOREVER);
	entities["R106_EXIT"] = new Exit("H106", ATRAVESARH106, (Room*)entities["R106"], true, LOCK_H106);
	entities["R106_CORRIDOR_EXIT"] = new Exit("H106", ATRAVESARH106, (Room*)entities["CORRIDOR2"], false, "");
	entities["R107_EXIT"] = new Exit("H107", ATRAVESARH107, (Room*)entities["R107"], false, "");
	entities["R107_CORRIDOR_EXIT"] = new Exit("H107", ATRAVESARH107, (Room*)entities["CORRIDOR2"], false, "");
	entities["R108_EXIT"] = new Exit("H108", ATRAVESARH108, (Room*)entities["R108"], false, "");
	entities["R108_CORRIDOR_EXIT"] = new Exit("H108", ATRAVESARH108, (Room*)entities["CORRIDOR2"], false, "");

	
	//entities placement

	entities["LUCAS"]->insertEntity(entities["PIEDRA"]);
	entities["CORRIDOR1"]->insertEntity(entities["WEST_CORRIDOR1_EXIT"]);
	entities["CORRIDOR1"]->insertEntity(entities["EAST_CORRIDOR1_EXIT"]);
	entities["CORRIDOR1"]->insertEntity(entities["R101_EXIT"]);
	entities["CORRIDOR1"]->insertEntity(entities["R102_EXIT"]);
	entities["CORRIDOR1"]->insertEntity(entities["R103_EXIT"]);
	entities["CORRIDOR1"]->insertEntity(entities["R104_EXIT"]);


	entities["CORRIDOR2"]->insertEntity(entities["WEST_CORRIDOR2_EXIT"]);
	entities["CORRIDOR2"]->insertEntity(entities["EAST_CORRIDOR2_EXIT"]);
	entities["CORRIDOR2"]->insertEntity(entities["R105_EXIT"]);
	entities["CORRIDOR2"]->insertEntity(entities["R106_EXIT"]);
	entities["CORRIDOR2"]->insertEntity(entities["R107_EXIT"]);
	entities["CORRIDOR2"]->insertEntity(entities["R108_EXIT"]);

	entities["HALL"]->insertEntity(entities["EAST_HALL_EXIT"]);
	entities["HALL"]->insertEntity(entities["WEST_HALL_EXIT"]);
	entities["HALL"]->insertEntity(entities["BEBIDA"]);
	entities["HALL"]->insertEntity(entities["MARGE"]);
	entities["HALL"]->insertEntity(entities["LLAVE106"]);

	entities["MAINTENANCE"]->insertEntity(entities["CLAVOS"]);
	entities["MAINTENANCE"]->insertEntity(entities["HERRAMIENTA"]);
	entities["MAINTENANCE"]->insertEntity(entities["MARTILLO"]);
	entities["MAINTENANCE"]->insertEntity(entities["MATARRATAS"]);
	entities["MAINTENANCE"]->insertEntity(entities["EAST_MAINTENANCE_EXIT"]);	
	entities["MAINTENANCE"]->insertEntity(entities["DIMITRI"]);

	
	entities["MALETA"]->insertEntity(entities["ROPITA"]);
	entities["R107"]->insertEntity(entities["MALETA"]);
	entities["R107"]->insertEntity(entities["POLLO"]);
	entities["R107"]->insertEntity(entities["R107_CORRIDOR_EXIT"]);

	entities["R108"]->insertEntity(entities["CORDEL"]);
	entities["R108"]->insertEntity(entities["CUADRO"]);
	entities["R108"]->insertEntity(entities["R108_CORRIDOR_EXIT"]);

	entities["R106"]->insertEntity(entities["LILY"]);
	entities["R106"]->insertEntity(entities["R106_CORRIDOR_EXIT"]);

	entities["R101"]->insertEntity(entities["LUCAS"]);
	entities["R101"]->insertEntity(entities["SILLA"]);
	entities["R101"]->insertEntity(entities["R101_CORRIDOR_EXIT"]);

	entities["R102"]->insertEntity(entities["PALO"]);
	entities["R102"]->insertEntity(entities["R102_CORRIDOR_EXIT"]);
	
	entities["R104"]->insertEntity(entities["JARRON"]);
	entities["R104"]->insertEntity(entities["R104_CORRIDOR_EXIT"]);
	
	entities["KITCHEN"]->insertEntity(entities["ARMARIO"]);
	entities["ARMARIO"]->insertEntity(entities["WHISKY"]);
	entities["KITCHEN"]->insertEntity(entities["CANDADO"]);
	entities["KITCHEN"]->insertEntity(entities["CUCHILLO"]);
	entities["KITCHEN"]->insertEntity(entities["OLLA"]);
	entities["KITCHEN"]->insertEntity(entities["TORNILLO"]);
	entities["KITCHEN"]->insertEntity(entities["WEST_KITCHEN_EXIT"]);

	
}

World::~World()
{
}

void World::update() {
	for (map<string, Entity*>::iterator it = entities.begin(); it != entities.end(); ++it) {
		it->second->update();
	}
}

Entity* World::getEntity(string name)
{
	if (entities.find(name) != entities.end()) return entities[name];
	else return nullptr;
}

void World::insertEntity(string name, Entity * entity)
{
	entities[name] = entity;
}


void World::moveCreature(string name, Room * origin, Room * destination)
{
	origin->removeEntity(entities[name]);
	destination->insertEntity(entities[name]);
}
