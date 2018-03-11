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

using namespace std;

int move(directions direction, World &world, PrintUtilities* pu, Player* player) {
	vector<Entity*> exits = player->getCurrentRoom()->getExits();
	for (auto exit : exits) {
		Exit* castedExit = (Exit*)exit;
		if (castedExit->getDirection() == direction) {
			world.moveCreature("PLAYER", player->getCurrentRoom(), castedExit->getDestination());
			player->setCurrentRoom(castedExit->getDestination());
			pu->consoleCout(castedExit->getDestination()->getName());
			return 0;
		}
	}
	return I_CANT_DO_THAT_CODE;
}
int processOrder(string order, Player* player, PrintUtilities* pu, World &world) {
	if (order == "") return 0;	
	vector<string> words;
	string buffer = "";
	for (auto c : order) {
		if (c == ' ') {
			transform(buffer.begin(), buffer.end(), buffer.begin(), toupper);
			words.push_back(buffer);
			buffer = "";
		}
		else buffer += c;
	}
	transform(buffer.begin(), buffer.end(), buffer.begin(), toupper);
	words.push_back(buffer);
	if (words[0] == "MIRAR") {
		player->getCurrentRoom()->showRoom(pu);
		return 0;
	}
	if (words[0] == "E" || words[0] == "EAST") return move(_EAST, world, pu, player);
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
	MoveWindow(console, r.left, r.top, 930, 500, TRUE); // 800 width, 100 height
	DWORD dwStyle = GetWindowLong(console, GWL_STYLE);
	dwStyle &= ~(WS_SIZEBOX);
	SetWindowLong(console, GWL_STYLE, dwStyle);
	HMENU hMenu = GetSystemMenu(console, FALSE);
	DeleteMenu(hMenu, 1, MF_BYPOSITION); // disable 'Move'
	DeleteMenu(hMenu, 1, MF_BYPOSITION); // disable 'Size'
	DeleteMenu(hMenu, 2, MF_BYPOSITION); // disable 'Maximize'
	
	//init game

	PrintUtilities* pu = new PrintUtilities();
	
	Time gameTime(pu);
	
	World world;

	Player* player = (Player*) world.getEntity("PLAYER");
	//game start
	pu->consoleCout(WELCOME_MSG);	

	while (1) {//game loop		
		gameTime.update();
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
    return 0;
}

