// Hotel Diablo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <set>;
#include <vector>
#include <algorithm>
#include <windows.h>
#include "Constants.h"
#include "PrintUtilities.h"
#include <time.h>
#include "Time.h"
#include "Exit.h"
#include "World.h"
#include "Player.h"

using namespace std;

int move(directions direction, World *world, PrintUtilities* pu, Player* player) {
	vector<Entity*> exits = player->getCurrentRoom()->getExits();
	for (auto exit : exits) {
		Exit* castedExit = (Exit*)exit;
		if (castedExit->getDirection() == direction) {
			if (!castedExit->isLocked()) {
				world->moveCreature("PLAYER", player->getCurrentRoom(), castedExit->getDestination());
				player->setCurrentRoom(castedExit->getDestination());
				pu->consoleCout(castedExit->getDestination()->getName());
			}
			else pu->consoleCout(castedExit->getLockMsg());
			return 0;
		}
	}
	return I_CANT_DO_THAT_CODE;
}
int processOrder(string order, Player* player, PrintUtilities* pu, World* world) {	
	if (order == "") return 0;	
	vector<string> words;
	string buffer = "";
	string orderCaps = "";
	for (auto c : order) {
		if (c == ' ') {
			transform(buffer.begin(), buffer.end(), buffer.begin(), toupper);
			words.push_back(buffer);			
			orderCaps += buffer;
			buffer = "";
		}
		else buffer += c;
	}
	transform(buffer.begin(), buffer.end(), buffer.begin(), toupper);
	orderCaps += buffer;
	words.push_back(buffer);
	//try pre-programed actions
	if (player->tryAction(orderCaps)) return 0;	

	//try common actions
	if (words[0] == "MIRAR") {
		player->getCurrentRoom()->showRoom(pu);
		return 0;
	}
	if (words[0] == "AYUDA") {
		pu->help();
		return 0;
	}
	if (words[0] == "E" || words[0] == "ESTE") return move(_EAST, world, pu, player);
	if (words[0] == "O" || words[0] == "OESTE") return move(_WEST, world, pu, player);
	if (words[0] == "N" || words[0] == "NORTE") return move(_NORTH, world, pu, player);
	if (words[0] == "S" || words[0] == "SUR") return move(_SOUTH, world, pu, player);	
	if (words.size() > 1) {
		if (words[0] + words[1] == "ATRAVESARH101") return move(ATRAVESARH101, world, pu, player);
		if (words[0] + words[1] == "ATRAVESARH102") return move(ATRAVESARH102, world, pu, player);
		if (words[0] + words[1] == "ATRAVESARH103") return move(ATRAVESARH103, world, pu, player);
		if (words[0] + words[1] == "ATRAVESARH104") return move(ATRAVESARH104, world, pu, player);
		if (words[0] + words[1] == "ATRAVESARH105") return move(ATRAVESARH105, world, pu, player);
		if (words[0] + words[1] == "ATRAVESARH106") return move(ATRAVESARH106, world, pu, player);
		if (words[0] + words[1] == "ATRAVESARH107") return move(ATRAVESARH107, world, pu, player);
		if (words[0] + words[1] == "ATRAVESARH108") return move(ATRAVESARH108, world, pu, player);	
		if (words[0] == "EXAMINAR") {
			if (player->getCurrentRoom()->containsEntity(world->getEntity(words[1]))) {
				pu->consoleCout(world->getEntity(words[1])->getDescription());
				return 0;
			}
		}
		if (words[0] == "COGER") {
			if (player->getCurrentRoom()->containsEntity(world->getEntity(words[1]))){
				if (world->getEntity(words[1])->getType() == ITEM) {
					if (!((Item*)world->getEntity(words[1]))->isLocked()) {
						if (player->insertItem((Item*)world->getEntity(words[1]), pu)) {
							player->getCurrentRoom()->removeEntity((Item*)world->getEntity(words[1]));
							pu->updateInventory(player->getInventory());
						}
					}
					else {
						pu->consoleCout(((Item*)world->getEntity(words[1]))->getLockMsg());
					}
				}
				else {
					pu->consoleCout(NOT_TAKE_PERSON);
				}
				return 0;
			}
			else {
				pu->consoleCout(NOT_NEAR_OBJECT);
				return 0;
			}
		}

		if (words[0] == "DEJAR") {
			if (player->hasItem((Item*)world->getEntity(words[1]))) {
				player->dropItem((Item*)world->getEntity(words[1]), pu);				
				pu->updateInventory(player->getInventory());
				return 0;
			}
			else {
				pu->consoleCout(NOT_IN_POSSESSION);
				return 0;
			}
		}
		if (words[0] == "EXAMINAR") {
			if (player->hasItem((Item*)world->getEntity(words[1]))) {				
				pu->consoleCout(world->getEntity(words[1])->getDescription());
				return 0;
			}
			if (player->getCurrentRoom()->containsEntity(world->getEntity(words[1]))) {
				pu->consoleCout(world->getEntity(words[1])->getDescription());
				return 0;
			}
			else {				
				return I_CANT_DO_THAT_CODE;
			}
		}
		if (words[0] == "ABRIR"){			
			if (player->getCurrentRoom()->containsEntity(world->getEntity(words[1])) 
				and ((Item*)world->getEntity(words[1]))->isLocked()) {
				((Item*)world->getEntity(words[1]))->unlock();
				list<Entity*> content = world->getEntity(words[1])->getContents();
				pu->consoleCout(OPEN);
				for (list<Entity*>::iterator it = content.begin(); it != content.end(); ++it) {
					player->getCurrentRoom()->insertEntity(*it);
					world->getEntity(words[1])->removeEntity(*it);
				}
				return 0;
			}
			else {
				return I_CANT_DO_THAT_CODE;
			}
		}
	}
	if (words.size() > 2) {
		if (words[0] == "HABLAR" and words[1] == "CON" and words[2] == "MARGE" 
			and !((_NPC*)world->getEntity("MARGE"))->isDead() 
			and player->getCurrentRoom() == ((Room*)world->getEntity("HALL"))) {
			bool doorLocked = ((Exit*)player->getCurrentRoom()->getExits()[0])->isLocked();
			if (doorLocked) pu->consoleCout(M0);
			else pu->consoleCout(M1);
			char op = _getch();
			if (op == '1') {
				pu->consoleCout(M2);
				if (doorLocked) {
					pu->consoleCout(UNLOCK_HALL);
					((Exit*)player->getCurrentRoom()->getExits()[0])->unLock();
					((Exit*)player->getCurrentRoom()->getExits()[1])->unLock();
				}
			}
			else if (op == '2' && !doorLocked) {
				pu->consoleCout(M5);
			}
			else if (op == '3' && !doorLocked) {
				_NPC* dimi = (_NPC*)world->getEntity("DIMITRI");
				pu->consoleCout(M3 + dimi->getNextPosition());
			}
			else if (op == '4' && !doorLocked) {
				pu->consoleCout(M6);
			}
			return 0;
		}
		if (words[0] == "HABLAR" and words[1] == "CON" and words[2] == "DIMITRI"
			and !((_NPC*)world->getEntity("DIMITRI"))->isDead()
			and player->getCurrentRoom()->containsEntity(world->getEntity("DIMITRI"))) {
			pu->consoleCout(D0);
			char op = _getch();
			if (op == '1') {
				pu->consoleCout(D1);
				pu->consoleCout(D3);
				((_NPC*)world->getEntity("DIMITRI"))->resetTimer();
				player->setLucasDaughter();
			}
			else if (op == '2') {
				pu->consoleCout(D2);
				pu->consoleCout(D3);
				((_NPC*)world->getEntity("DIMITRI"))->resetTimer();
			}
			return 0;
		}
		if (words[0] == "HABLAR" and words[1] == "CON" and words[2] == "LUCAS"
			and !((_NPC*)world->getEntity("LUCAS"))->isDead()
			and player->getCurrentRoom() == ((Room*)world->getEntity("R101"))) {			
			if (!player->getLucasDaughter())
				pu->consoleCout(L0);
			else pu->consoleCout(L1);
			char op = _getch();
			if (op == '1') {
				pu->consoleCout(L2);				
			}			
			else if (op == '2') {
				pu->consoleCout(L3);
				pu->consoleCout(L4);
				player->setLucasUnhanged();
				((Creature*)world->getEntity("LUCAS"))->removeEntity(world->getEntity("PIEDRA"));
				player->getCurrentRoom()->insertEntity(world->getEntity("PIEDRA"));
			}
			return 0;
		}
	}
	return BAD_GRAMMAR_CODE;
}

int main()
{	
	//window configuration
	//Disable resizable console
	
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 620, 500, TRUE); // 800 width, 100 height
	DWORD dwStyle = GetWindowLong(console, GWL_STYLE);
	dwStyle &= ~(WS_SIZEBOX);
	SetWindowLong(console, GWL_STYLE, dwStyle);
	/*HMENU hMenu = GetSystemMenu(console, FALSE);
	DeleteMenu(hMenu, 1, MF_BYPOSITION); // disable 'Move'
	DeleteMenu(hMenu, 1, MF_BYPOSITION); // disable 'Size'
	DeleteMenu(hMenu, 2, MF_BYPOSITION); // disable 'Maximize'
	 */
	//init game

	PrintUtilities* pu = new PrintUtilities();
	
	Time gameTime(pu);
	
	World* world = new World(pu);

	//player
	
	Player* player = new Player("Tu mismo.");
	player->setName("JUGADOR");
	player->setCurrentRoom((Room*)world->getEntity("HALL"));
	world->insertEntity("PLAYER", player);
	world->getEntity("HALL")->insertEntity(world->getEntity("PLAYER"));
	((_NPC*)world->getEntity("DIMITRI"))->setTimer(gameTime);
	player->init(world, pu);
	player->initActionManager();
	//game start
	pu->consoleCout(WELCOME_MSG);	
	//pu->consoleCout(GOOD_END);
	bool gameOver = false;
	while (1) {//game loop	
		//check ends
		if (!gameOver) {
			if (((_NPC*)world->getEntity("LUCAS"))->isDead()
				and ((_NPC*)world->getEntity("LILY"))->isDead()) {
				pu->consoleCout(BAD_END);
				gameOver = true;
			}
			if (!((Exit*)world->getEntity("R106_EXIT"))->isLocked()
				and !player->getR106Opened()) {
				gameOver = true;
			}
			gameTime.update();
			world->update();
			if (!gameTime.isFinished()) {
				string order = pu->manageInput();
				int orderCod = processOrder(order, player, pu, world);
				switch (orderCod) {
				case BAD_GRAMMAR_CODE:
					pu->consoleCout(BAD_GRAMMAR);
					break;
				case I_CANT_DO_THAT_CODE:
					pu->consoleCout(I_CANT_DO_THAT);
					break;
				default:
					break;
				}
			}
		}
	}
    return 0;
}

