#pragma once
#include <windows.h>
#include <string>
#include <vector>
#include <iostream>
#include <conio.h>
#include <set>
#include "Item.h"
#include "Constants.h"

using namespace std;

class PrintUtilities
{
public:
	PrintUtilities();
	~PrintUtilities();

	void coutXY(int x, int y, string msg);
	void consoleCout(string msg);
	void render();
	string manageInput();
	void updateInventory(set<Entity*> inventory);

private:
	HANDLE hStdout;
	COORD destCoord;
	vector<string> gameOutput;
	string order;
	char c;
	bool newOrder;
	int xInput, yInput;
	string consoleClearLine;
};

