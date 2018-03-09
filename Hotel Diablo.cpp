// Hotel Diablo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <set>;
#include <vector>
#include "Constants.h"
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
	for (auto s : words) {
		cout <<endl << s;
	}
	return BAD_GRAMMAR_CODE;
}

int main()
{		
	set<string> verbs;
	set<string> moves;
	initWordGroups(verbs, moves);

	string order = "";
	char c;
	bool newOrder = true;
	while (1) {//game loop		
		if (newOrder) {
			cout << endl << ">";
			newOrder = false;
		}

		if (_kbhit() != 0) {
			c = _getch();			
			if (c == KEY_BACKSPACE) {
				//erase last char
				if (order != "") {
					cout << c << ' ' << c;
					order.pop_back();
				}
			}
			else if (c == KEY_ENTER) {
				//process order
				int orderCod = processOrder(order);
				switch (orderCod) {
				case 1:
					cout << endl << BAD_GRAMMAR << endl;
					break;
				default:
					break;
				}
				order = "";
				newOrder = true;
			}
			else {
				order += c;
				cout << c;
			}
		}
	}
    return 0;
}

