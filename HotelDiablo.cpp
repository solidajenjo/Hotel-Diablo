// Hotel Diablo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <set>;
#include <vector>
#include <windows.h>
#include "Constants.h"
#include "PrintUtilities.h"

using namespace std;

void initWordGroups(set<string> &verbs, set<string> &moves) {
	//verbs
	verbs.insert(TAKE);
	verbs.insert(PUSH);
	verbs.insert(USE);
	verbs.insert(LOOK);
	//movements
	moves.insert(NORTH);
	moves.insert(SHORT_NORTH);
	moves.insert(EAST);
	moves.insert(SHORT_EAST);
	moves.insert(WEST);
	moves.insert(SHORT_WEST);
	moves.insert(SOUTH);
	moves.insert(SHORT_SOUTH);
}

int processOrder(string order) {
	if (order == "") return 0;	
	vector<string> words;
	string buffer = "";
	for (auto c : order) {
		if (c == ' ') {
			words.push_back(buffer);
			buffer = "";
		}
		else buffer += c;
	}
	words.push_back(buffer);	
	return BAD_GRAMMAR_CODE;
}

int main()
{		
	set<string> verbs;
	set<string> moves;
	PrintUtilities pu;
	vector<string> gameOutput;
	for (int i = 0; i < 20; ++i) {
		gameOutput.push_back("");
	}
	initWordGroups(verbs, moves);
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

	string order = "";
	char c;
	bool newOrder = true;
	pu.consoleCout(WELCOME_MSG);
	while (1) {//game loop		
		string order = pu.manageInput();		
		int orderCod = processOrder(order);		
		switch (orderCod) {
		case 1:
			pu.consoleCout(BAD_GRAMMAR);
			break;
		default:
			break;
		}
	}
    return 0;
}

