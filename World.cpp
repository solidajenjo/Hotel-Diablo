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
	entities["PALO"] = new Item(DESC_STICK);
	entities["PALO"]->setName("PALO");
	entities["PALO"]->setType(ITEM);
	entities["PIEDRA"] = new Item(DESC_STONE);
	entities["PIEDRA"]->setName("PIEDRA");
	entities["PIEDRA"]->setType(ITEM);
	entities["JARRON"] = new Item(DESC_VASE);
	entities["JARRON"]->setName("JARRON");
	entities["JARRON"]->setType(ITEM);
	entities["MATARRATAS"] = new Item(DESC_POISON);
	entities["MATARRATAS"]->setName("MATARRATAS");
	entities["MATARRATAS"]->setType(ITEM);
	entities["HERRAMIENTA"] = new Item(DESC_WRENCH);
	entities["HERRAMIENTA"]->setName("HERRAMIENTA");
	entities["HERRAMIENTA"]->setType(ITEM);
	entities["MARTILLO"] = new Item(DESC_HAMMER);
	entities["MARTILLO"]->setName("MARTILLO");
	entities["MARTILLO"]->setType(ITEM);
	entities["CLAVOS"] = new Item(DESC_NAILS);
	entities["CLAVOS"]->setName("CLAVOS");
	entities["CLAVOS"]->setType(ITEM);
	entities["LLAVE106"] = new Item(DESC_KEYR106);
	entities["LLAVE106"]->setName("LLAVE106");
	entities["LLAVE106"]->setType(ITEM);
	entities["MALETA"] = new Item(DESC_CASE);
	entities["MALETA"]->setName("MALETA");
	entities["MALETA"]->setType(ITEM);
	entities["PISTOLA"] = new Item(DESC_GUN);
	entities["PISTOLA"]->setName("PISTOLA");
	entities["PISTOLA"]->setType(ITEM);
	entities["POLLO"] = new Item(DESC_CHICKEN);
	entities["POLLO"]->setName("POLLO");
	entities["POLLO"]->setType(ITEM);
	entities["SILLA"] = new Item(DESC_CHAIR);
	entities["SILLA"]->setName("SILLA");
	entities["SILLA"]->setType(ITEM);
	entities["CORDEL"] = new Item(DESC_CORD);
	entities["CORDEL"]->setName("CORDEL");
	entities["CORDEL"]->setType(ITEM);
	entities["ARMARIO"] = new Item(DESC_CLOSET);
	entities["ARMARIO"]->setName("ARMARIO");
	entities["ARMARIO"]->setType(ITEM);
	entities["CANDADO"] = new Item(DESC_LOCK);
	entities["CANDADO"]->setName("CANDADO");
	entities["CANDADO"]->setType(ITEM);
	entities["TORNILLO"] = new Item(DESC_SCREW);
	entities["TORNILLO"]->setName("TORNILLO");
	entities["TORNILLO"]->setType(ITEM);
	entities["BEBIDA"] = new Item(DESC_DRINK);
	entities["BEBIDA"]->setName("BEBIDA");
	entities["BEBIDA"]->setType(ITEM);
	entities["WHISKY"] = new Item(DESC_WHISKY);
	entities["WHISKY"]->setName("WHISKY");
	entities["WHISKY"]->setType(ITEM);
	entities["OLLA"] = new Item(DESC_POT);
	entities["OLLA"]->setName("OLLA");
	entities["OLLA"]->setType(ITEM);
	entities["CUCHILLO"] = new Item(DESC_KNIFE);
	entities["CUCHILLO"]->setName("CUCHILLO");
	entities["CUCHILLO"]->setType(ITEM);
	entities["CUADRO"] = new Item(DESC_PICTURE);
	entities["CUADRO"]->setName("CUADRO");
	entities["CUADRO"]->setType(ITEM);

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
	
	entities["EAST_HALL_EXIT"] = new Exit("ESTE", _EAST, (Room*)entities["CORRIDOR1"]);
	entities["WEST_HALL_EXIT"] =  new Exit("OESTE", _WEST, (Room*)entities["CORRIDOR2"]);
	entities["EAST_CORRIDOR2_EXIT"] = new Exit("ESTE", _EAST, (Room*)entities["HALL"]);
	entities["WEST_CORRIDOR2_EXIT"] = new Exit("OESTE", _WEST, (Room*)entities["MAINTENANCE"]);	
	entities["EAST_CORRIDOR1_EXIT"] = new Exit("ESTE", _EAST, (Room*)entities["KITCHEN"]);
	entities["WEST_CORRIDOR1_EXIT"] = new Exit("OESTE", _WEST, (Room*)entities["HALL"]);	
	entities["WEST_KITCHEN_EXIT"] = new Exit("OESTE", _WEST, (Room*)entities["CORRIDOR1"]);
	entities["EAST_MAINTENANCE_EXIT"] = new Exit("ESTE", _EAST, (Room*)entities["CORRIDOR2"]);
	entities["R101_EXIT"] = new Exit("H101", ATRAVESARH101, (Room*)entities["R101"]);
	entities["R101_CORRIDOR_EXIT"] = new Exit("H101", ATRAVESARH101, (Room*)entities["CORRIDOR1"]);
	entities["R102_EXIT"] = new Exit("H102", ATRAVESARH102, (Room*)entities["R102"]);	
	entities["R102_CORRIDOR_EXIT"] = new Exit("H102", ATRAVESARH102, (Room*)entities["CORRIDOR1"]);
	entities["R103_EXIT"] = new Exit("H103", ATRAVESARH103, (Room*)entities["R103"]);
	entities["R104_EXIT"] = new Exit("H104", ATRAVESARH104, (Room*)entities["R104"]);
	entities["R104_CORRIDOR_EXIT"] = new Exit("H104", ATRAVESARH104, (Room*)entities["CORRIDOR1"]);
	entities["R105_EXIT"] = new Exit("H105", ATRAVESARH105, (Room*)entities["R105"]);
	entities["R106_EXIT"] = new Exit("H106", ATRAVESARH106, (Room*)entities["R106"]);
	entities["R106_CORRIDOR_EXIT"] = new Exit("H106", ATRAVESARH106, (Room*)entities["CORRIDOR2"]);	
	entities["R107_EXIT"] = new Exit("H107", ATRAVESARH107, (Room*)entities["R107"]);	
	entities["R107_CORRIDOR_EXIT"] = new Exit("H107", ATRAVESARH107, (Room*)entities["CORRIDOR2"]);	
	entities["R108_EXIT"] = new Exit("H108", ATRAVESARH108, (Room*)entities["R108"]);	
	entities["R108_CORRIDOR_EXIT"] = new Exit("H108", ATRAVESARH108, (Room*)entities["CORRIDOR2"]);


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
	entities["HALL"]->insertEntity(entities["BEBIDA"]);
	entities["HALL"]->insertEntity(entities["MARGE"]);
	entities["HALL"]->insertEntity(entities["LLAVE106"]);

	entities["MAINTENANCE"]->insertEntity(entities["CLAVOS"]);
	entities["MAINTENANCE"]->insertEntity(entities["HERRAMIENTA"]);
	entities["MAINTENANCE"]->insertEntity(entities["MARTILLO"]);
	entities["MAINTENANCE"]->insertEntity(entities["MATARRATAS"]);
	entities["MAINTENANCE"]->insertEntity(entities["EAST_MAINTENANCE_EXIT"]);	
	
	entities["MALETA"]->insertEntity(entities["PISTOLA"]);
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

	entities["R104"]->insertEntity(entities["PIEDRA"]);
	entities["R104"]->insertEntity(entities["JARRON"]);
	entities["R104"]->insertEntity(entities["R104_CORRIDOR_EXIT"]);
	
	entities["KITCHEN"]->insertEntity(entities["ARMARIO"]);
	entities["ARMARIO"]->insertEntity(entities["WHISKY"]);
	entities["KITCHEN"]->insertEntity(entities["CANDADO"]);
	entities["KITCHEN"]->insertEntity(entities["CUCHILLO"]);
	entities["KITCHEN"]->insertEntity(entities["OLLA"]);
	entities["KITCHEN"]->insertEntity(entities["TORNILLO"]);
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
