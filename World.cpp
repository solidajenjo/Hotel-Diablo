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
	entities["STICK"]->setType(ITEM);
	entities["STONE"] = new Item("Una piedra con forma triangular. Esta afilada");
	entities["STONE"]->setName("PIEDRA");
	entities["STONE"]->setType(ITEM);
	entities["VASE"] = new Item("Una jarr\242n de lo mas elegante.");
	entities["VASE"]->setName("JARRON");
	entities["VASE"]->setType(ITEM);
	entities["POISON"] = new Item("Matarratas marca ACME.");
	entities["POISON"]->setName("MATARRATAS");
	entities["POISON"]->setType(ITEM);
	entities["WRENCH"] = new Item("Una llave inglesa.");
	entities["WRENCH"]->setName("HERRAMIENTA");
	entities["WRENCH"]->setType(ITEM);
	entities["HAMMER"] = new Item("Un martillo.");
	entities["HAMMER"]->setName("MARTILLO");
	entities["HAMMER"]->setType(ITEM);
	entities["NAILS"] = new Item("Una docena de clavos.");
	entities["NAILS"]->setName("CLAVOS");
	entities["NAILS"]->setType(ITEM);
	entities["KEY_H106"] = new Item("La llave de la habitaci\242n 106.");
	entities["KEY_H106"]->setName("LLAVE106");
	entities["KEY_H106"]->setType(ITEM);
	entities["CASE"] = new Item("Un maleta de pokemon. Podria usarla para llevar mas cosas  pero me da verguenza.");
	entities["CASE"]->setName("MALETA");
	entities["CASE"]->setType(ITEM);
	entities["GUN"] = new Item("Un revolver con una bala.");
	entities["GUN"]->setName("PISTOLA");
	entities["GUN"]->setType(ITEM);
	entities["CHICKEN"] = new Item("Un pollo de goma. Me decepciona que no tenga una polea.");
	entities["CHICKEN"]->setName("POLLO");
	entities["CHICKEN"]->setType(ITEM);
	entities["CHAIR"] = new Item("Una silla medio podrida.");
	entities["CHAIR"]->setName("SILLA");
	entities["CHAIR"]->setType(ITEM);
	entities["CORD"] = new Item("Un cordel para atar cosas.");
	entities["CORD"]->setName("CORDEL");
	entities["CORD"]->setType(ITEM);
	entities["CLOSET"] = new Item("Un armario de madera. Tiene un TORNILLO suelto.");
	entities["CLOSET"]->setName("ARMARIO");
	entities["CLOSET"]->setType(ITEM);
	entities["LOCK"] = new Item("Un candado.");
	entities["LOCK"]->setName("CANDADO");
	entities["LOCK"]->setType(ITEM);
	entities["SCREW"] = new Item("Un TORNILLO suelto. Sujeta la puerta.");
	entities["SCREW"]->setName("TORNILLO");
	entities["SCREW"]->setType(ITEM);
	entities["DRINK"] = new Item("Un vaso con lo que parece WHISKY. Queda muy poco.");
	entities["DRINK"]->setName("BEBIDA");
	entities["DRINK"]->setType(ITEM);
	entities["WHISKY"] = new Item("WHISKY del barato.");
	entities["WHISKY"]->setName("WHISKY");
	entities["WHISKY"]->setType(ITEM);
	entities["POT"] = new Item("Una olla con restos de comida pegada.");
	entities["POT"]->setName("OLLA");
	entities["POT"]->setType(ITEM);
	entities["KNIFE"] = new Item("Una cuchillo de carnicero.");
	entities["KNIFE"]->setName("CUCHILLO");
	entities["KNIFE"]->setType(ITEM);
	entities["PICTURE"] = new Item("Una cuadro de un hacha primitiva. Esta hecha con un PALO,  una PIEDRA y CORDEL.");
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
	
	//entities placement

	entities["HALL"]->insertEntity(entities["DRINK"]);
	entities["HALL"]->insertEntity(entities["MARGE"]);

	entities["MAINTENANCE"]->insertEntity(entities["NAILS"]);
	entities["MAINTENANCE"]->insertEntity(entities["WRENCH"]);
	entities["MAINTENANCE"]->insertEntity(entities["HAMMER"]);
	entities["MAINTENANCE"]->insertEntity(entities["POISON"]);

	entities["CASE"]->insertEntity(entities["GUN"]);
	entities["R107"]->insertEntity(entities["CASE"]);
	entities["R107"]->insertEntity(entities["CHICKEN"]);

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
