#include "stdafx.h"
#include "World.h"


World::World()
{
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
	entities["STICK"] = new Item(DESC_STICK);
	entities["STICK"]->setName("PALO");
	entities["STICK"]->setType(ITEM);
	entities["STONE"] = new Item(DESC_STONE);
	entities["STONE"]->setName("PIEDRA");
	entities["STONE"]->setType(ITEM);
	entities["VASE"] = new Item(DESC_VASE);
	entities["VASE"]->setName("JARRON");
	entities["VASE"]->setType(ITEM);
	entities["POISON"] = new Item(DESC_POISON);
	entities["POISON"]->setName("MATARRATAS");
	entities["POISON"]->setType(ITEM);
	entities["WRENCH"] = new Item(DESC_WRENCH);
	entities["WRENCH"]->setName("HERRAMIENTA");
	entities["WRENCH"]->setType(ITEM);
	entities["HAMMER"] = new Item(DESC_HAMMER);
	entities["HAMMER"]->setName("MARTILLO");
	entities["HAMMER"]->setType(ITEM);
	entities["NAILS"] = new Item(DESC_NAILS);
	entities["NAILS"]->setName("CLAVOS");
	entities["NAILS"]->setType(ITEM);
	entities["KEY_H106"] = new Item(DESC_KEYR106);
	entities["KEY_H106"]->setName("LLAVE106");
	entities["KEY_H106"]->setType(ITEM);
	entities["CASE"] = new Item(DESC_CASE);
	entities["CASE"]->setName("MALETA");
	entities["CASE"]->setType(ITEM);
	entities["GUN"] = new Item(DESC_GUN);
	entities["GUN"]->setName("PISTOLA");
	entities["GUN"]->setType(ITEM);
	entities["CHICKEN"] = new Item(DESC_CHICKEN);
	entities["CHICKEN"]->setName("POLLO");
	entities["CHICKEN"]->setType(ITEM);
	entities["CHAIR"] = new Item(DESC_CHAIR);
	entities["CHAIR"]->setName("SILLA");
	entities["CHAIR"]->setType(ITEM);
	entities["CORD"] = new Item(DESC_CORD);
	entities["CORD"]->setName("CORDEL");
	entities["CORD"]->setType(ITEM);
	entities["CLOSET"] = new Item(DESC_CLOSET);
	entities["CLOSET"]->setName("ARMARIO");
	entities["CLOSET"]->setType(ITEM);
	entities["LOCK"] = new Item(DESC_LOCK);
	entities["LOCK"]->setName("CANDADO");
	entities["LOCK"]->setType(ITEM);
	entities["SCREW"] = new Item(DESC_SCREW);
	entities["SCREW"]->setName("TORNILLO");
	entities["SCREW"]->setType(ITEM);
	entities["DRINK"] = new Item(DESC_DRINK);
	entities["DRINK"]->setName("BEBIDA");
	entities["DRINK"]->setType(ITEM);
	entities["WHISKY"] = new Item(DESC_WHISKY);
	entities["WHISKY"]->setName("WHISKY");
	entities["WHISKY"]->setType(ITEM);
	entities["POT"] = new Item(DESC_POT);
	entities["POT"]->setName("OLLA");
	entities["POT"]->setType(ITEM);
	entities["KNIFE"] = new Item(DESC_KNIFE);
	entities["KNIFE"]->setName("CUCHILLO");
	entities["KNIFE"]->setType(ITEM);
	entities["PICTURE"] = new Item(DESC_PICTURE);
	entities["PICTURE"]->setName("CUADRO");
	entities["PICTURE"]->setType(ITEM);

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
	
	//exits
	Exit* exit1 = new Exit("");
	exit1->setType(EXIT);
	exit1->setName("ESTE");
	exit1->setDirection(_EAST);
	exit1->setDestination((Room*)entities["CORRIDOR1"]);
	entities["EAST_HALL_EXIT"] = exit1;
	
	Exit* exit2 = new Exit("");
	exit2->setType(EXIT);
	exit2->setName("OESTE");
	exit2->setDirection(_WEST);
	exit2->setDestination((Room*)entities["CORRIDOR2"]);
	entities["WEST_HALL_EXIT"] = exit2;

	Exit* exit3 = new Exit("");
	exit3->setType(EXIT);
	exit3->setName("ESTE");
	exit3->setDirection(_EAST);
	exit3->setDestination((Room*)entities["HALL"]);
	entities["EAST_CORRIDOR2_EXIT"] = exit3;

	Exit* exit4 = new Exit("");
	exit4->setType(EXIT);
	exit4->setName("OESTE");
	exit4->setDirection(_WEST);
	exit4->setDestination((Room*)entities["MAINTENANCE"]);
	entities["WEST_CORRIDOR2_EXIT"] = exit4;

	Exit* exit5 = new Exit("");
	exit5->setType(EXIT);
	exit5->setName("ESTE");
	exit5->setDirection(_EAST);
	exit5->setDestination((Room*)entities["KITCHEN"]);
	entities["EAST_CORRIDOR1_EXIT"] = exit5;

	Exit* exit6 = new Exit("");
	exit6->setType(EXIT);
	exit6->setName("OESTE");
	exit6->setDirection(_WEST);
	exit6->setDestination((Room*)entities["HALL"]);
	entities["WEST_CORRIDOR1_EXIT"] = exit6;

	Exit* exit7 = new Exit("");
	exit7->setType(EXIT);
	exit7->setName("OESTE");
	exit7->setDirection(_WEST);
	exit7->setDestination((Room*)entities["CORRIDOR1"]);
	entities["WEST_KITCHEN_EXIT"] = exit7;

	Exit* exit8 = new Exit("");
	exit8->setType(EXIT);
	exit8->setName("ESTE");
	exit8->setDirection(_EAST);
	exit8->setDestination((Room*)entities["CORRIDOR2"]);
	entities["EAST_MAINTENANCE_EXIT"] = exit8;

	Exit* exit9 = new Exit("");
	exit9->setType(EXIT);
	exit9->setName("H101");
	exit9->setDirection(ATRAVESARH101);
	exit9->setDestination((Room*)entities["R101"]);
	entities["R101_EXIT"] = exit9;
	
	Exit* exit10 = new Exit("");
	exit10->setType(EXIT);
	exit10->setName("H101");
	exit10->setDirection(ATRAVESARH101);
	exit10->setDestination((Room*)entities["CORRIDOR1"]);
	entities["R101_CORRIDOR_EXIT"] = exit10;

	Exit* exit11 = new Exit("");
	exit11->setType(EXIT);
	exit11->setName("H102");
	exit11->setDirection(ATRAVESARH102);
	exit11->setDestination((Room*)entities["R102"]);
	entities["R102_EXIT"] = exit11;

	Exit* exit12 = new Exit("");
	exit12->setType(EXIT);
	exit12->setName("H102");
	exit12->setDirection(ATRAVESARH102);
	exit12->setDestination((Room*)entities["CORRIDOR1"]);
	entities["R102_CORRIDOR_EXIT"] = exit12;

	Exit* exit13 = new Exit("");
	exit13->setType(EXIT);
	exit13->setName("H103");
	exit13->setDirection(ATRAVESARH103);
	exit13->setDestination((Room*)entities["R103"]);
	entities["R103_EXIT"] = exit13;

	Exit* exit14 = new Exit("");
	exit14->setType(EXIT);
	exit14->setName("H104");
	exit14->setDirection(ATRAVESARH104);
	exit14->setDestination((Room*)entities["R104"]);
	entities["R104_EXIT"] = exit14;

	Exit* exit15 = new Exit("");
	exit15->setType(EXIT);
	exit15->setName("H104");
	exit15->setDirection(ATRAVESARH104);
	exit15->setDestination((Room*)entities["CORRIDOR1"]);
	entities["R104_CORRIDOR_EXIT"] = exit15;

	Exit* exit16 = new Exit("");
	exit16->setType(EXIT);
	exit16->setName("H105");
	exit16->setDirection(ATRAVESARH105);
	exit16->setDestination((Room*)entities["R105"]);
	entities["R105_EXIT"] = exit16;

	Exit* exit17 = new Exit("");
	exit17->setType(EXIT);
	exit17->setName("H106");
	exit17->setDirection(ATRAVESARH106);
	exit17->setDestination((Room*)entities["R106"]);
	entities["R106_EXIT"] = exit17;

	Exit* exit18 = new Exit("");
	exit18->setType(EXIT);
	exit18->setName("H106");
	exit18->setDirection(ATRAVESARH106);
	exit18->setDestination((Room*)entities["CORRIDOR2"]);
	entities["R106_CORRIDOR_EXIT"] = exit18;

	Exit* exit19 = new Exit("");
	exit19->setType(EXIT);
	exit19->setName("H107");
	exit19->setDirection(ATRAVESARH107);
	exit19->setDestination((Room*)entities["R107"]);
	entities["R107_EXIT"] = exit19;

	Exit* exit20 = new Exit("");
	exit20->setType(EXIT);
	exit20->setName("H107");
	exit20->setDirection(ATRAVESARH107);
	exit20->setDestination((Room*)entities["CORRIDOR2"]);
	entities["R107_CORRIDOR_EXIT"] = exit20;

	Exit* exit21 = new Exit("");
	exit21->setType(EXIT);
	exit21->setName("H108");
	exit21->setDirection(ATRAVESARH108);
	exit21->setDestination((Room*)entities["R108"]);
	entities["R108_EXIT"] = exit21;

	Exit* exit22 = new Exit("");
	exit22->setType(EXIT);
	exit22->setName("H108");
	exit22->setDirection(ATRAVESARH108);
	exit22->setDestination((Room*)entities["CORRIDOR2"]);
	entities["R108_CORRIDOR_EXIT"] = exit22;


	//entities placement
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
	entities["HALL"]->insertEntity(entities["DRINK"]);
	entities["HALL"]->insertEntity(entities["MARGE"]);
	entities["HALL"]->insertEntity(entities["KEY_H106"]);

	entities["MAINTENANCE"]->insertEntity(entities["NAILS"]);
	entities["MAINTENANCE"]->insertEntity(entities["WRENCH"]);
	entities["MAINTENANCE"]->insertEntity(entities["HAMMER"]);
	entities["MAINTENANCE"]->insertEntity(entities["POISON"]);
	entities["MAINTENANCE"]->insertEntity(entities["EAST_MAINTENANCE_EXIT"]);	
	
	entities["CASE"]->insertEntity(entities["GUN"]);
	entities["R107"]->insertEntity(entities["CASE"]);
	entities["R107"]->insertEntity(entities["CHICKEN"]);
	entities["R107"]->insertEntity(entities["R107_CORRIDOR_EXIT"]);

	entities["R108"]->insertEntity(entities["CORD"]);
	entities["R108"]->insertEntity(entities["PICTURE"]);
	entities["R108"]->insertEntity(entities["R108_CORRIDOR_EXIT"]);

	entities["R106"]->insertEntity(entities["LILY"]);
	entities["R106"]->insertEntity(entities["R106_CORRIDOR_EXIT"]);

	entities["R101"]->insertEntity(entities["LUCAS"]);
	entities["R101"]->insertEntity(entities["CHAIR"]);
	entities["R101"]->insertEntity(entities["R101_CORRIDOR_EXIT"]);

	entities["R102"]->insertEntity(entities["STICK"]);
	entities["R102"]->insertEntity(entities["R102_CORRIDOR_EXIT"]);

	entities["R104"]->insertEntity(entities["STONE"]);
	entities["R104"]->insertEntity(entities["VASE"]);
	entities["R104"]->insertEntity(entities["R104_CORRIDOR_EXIT"]);

	entities["CLOSET"]->insertEntity(entities["WHISKY"]);
	entities["KITCHEN"]->insertEntity(entities["CLOSET"]);
	entities["KITCHEN"]->insertEntity(entities["LOCK"]);
	entities["KITCHEN"]->insertEntity(entities["KNIFE"]);
	entities["KITCHEN"]->insertEntity(entities["POT"]);
	entities["KITCHEN"]->insertEntity(entities["SCREW"]);
	entities["KITCHEN"]->insertEntity(entities["WEST_KITCHEN_EXIT"]);

	//player
	Player* player = new Player("Tu mismo.");
	player->setName("JUGADOR");
	player->setCurrentRoom((Room*)entities["HALL"]);
	entities["PLAYER"] = player;

	entities["HALL"]->insertEntity(entities["PLAYER"]);
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

void World::moveCreature(string name, Room * origin, Room * destination)
{
	origin->removeEntity(entities[name]);
	destination->insertEntity(entities[name]);
}
