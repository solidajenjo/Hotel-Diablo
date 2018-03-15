#include "stdafx.h"
#include "PrintUtilities.h"

using namespace std;

PrintUtilities::PrintUtilities()
{
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	order = "";
	newOrder = true;
	//init game output
	for (int i = 0; i < GAME_OUTPUT_SIZE; ++i) {
		gameOutput.push_back("");
	}
	consoleClearLine = "";
	for (int i = 0; i < OUTPUT_LENGTH; ++i) consoleClearLine += ' ';
	//draw game screen

	//center line
	for (int i = 0; i < INPUT_Y; ++i) {
		coutXY(CENTRAL_LINE, i, "|");
	}
	//time underline
	coutXY(CENTRAL_LINE + 1, TIME_LINE, "_________________________________________________________");
	//inventory	
	coutXY(INVENTORY_X, INVENTORY_Y, "Inventario 0/3");

	coutXY(INVENTORY_X, INVENTORY_Y + 8, "Escribe");
	coutXY(INVENTORY_X, INVENTORY_Y + 9, "AYUDA");
	coutXY(INVENTORY_X, INVENTORY_Y + 10, "para info.");
	coutXY(INVENTORY_X, INVENTORY_Y + 11, "comandos");
}

void PrintUtilities::help(){
	//help
	this->consoleCout("ORDENES (* opcional)");
	this->consoleCout("------------------------------------------------");
	this->consoleCout("Movimiento:");
	this->consoleCout("N/NORTE | E/ESTE | S/SUR | O/OESTE");
	this->consoleCout("ATRAVESAR puerta");
	this->consoleCout("Acciones:");
	this->consoleCout("USAR objeto | USAR objeto EN obj / pers");
	this->consoleCout("COGER objeto | DEJAR objeto");
	this->consoleCout("COMBINAR objeto CON objeto (CON objeto)*");
	this->consoleCout("ABRIR objeto | EMPUJAR objeto ");
	this->consoleCout("EXAMINAR obj/pers | HABLAR CON persona");
	this->consoleCout("MIRAR");	
	
}


PrintUtilities::~PrintUtilities()
{
}

void PrintUtilities::coutXY(int x, int y, string msg)
{
	destCoord.X = x;
	destCoord.Y = y;
	SetConsoleCursorPosition(hStdout, destCoord);
	cout << msg;
}

void PrintUtilities::consoleCout(std::string msg)
{
	int linesToSkip = msg.size() / OUTPUT_LENGTH;
	for (int ii = 0; ii < linesToSkip + 1; ++ii) {		
		for (int i = 1; i < gameOutput.size(); ++i) {
			gameOutput[i - 1] = gameOutput[i];
		}
	}	
	int l = 0;
	string buffer = ":";	
	int line;
	for (auto c : msg) {
		line = gameOutput.size() - 1 - linesToSkip + l;
		buffer += c;
		if (buffer.size() % OUTPUT_LENGTH == 0) {
			gameOutput[line] = buffer;
			buffer = "";
			l++;
		}
	}
	if (buffer != "") gameOutput[line] = buffer;
	render();
}

void PrintUtilities::render()
{
	//draw console
	for (int i = 0; i < gameOutput.size(); ++i) {
		coutXY(OUTPUT_LINE_START_X, OUTPUT_START_Y + i, consoleClearLine);
		coutXY(OUTPUT_LINE_START_X, OUTPUT_START_Y + i, gameOutput[i]);
	}
}

string PrintUtilities::manageInput()
{			
	if (newOrder) {		
		xInput = 1;
		yInput = INPUT_Y;
	}	
	//restore cursor position
	destCoord.X = xInput;
	destCoord.Y = yInput;
	SetConsoleCursorPosition(hStdout, destCoord);
	if (newOrder) {
		cout << CLEAR_LINE;
		order = "";
		SetConsoleCursorPosition(hStdout, destCoord);
		cout << ">";
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
			newOrder = true;
			return order;
		}
		else if (order.size() < MAX_INPUT_SIZE){
			order += c;
			cout << c;
		}
	}
	//store cursor position
	CONSOLE_SCREEN_BUFFER_INFO cbsi;
	if (GetConsoleScreenBufferInfo(hStdout, &cbsi))
	{
		xInput = cbsi.dwCursorPosition.X;
		yInput = cbsi.dwCursorPosition.Y;
	}
	return "";
}

void PrintUtilities::updateInventory(set<Entity*> inventory)
{
	coutXY(INVENTORY_X, INVENTORY_Y, "Inventario " + to_string(inventory.size()) + "/3");
	coutXY(INVENTORY_X, INVENTORY_Y + 1, "                   ");
	coutXY(INVENTORY_X, INVENTORY_Y + 2, "                   ");
	coutXY(INVENTORY_X, INVENTORY_Y + 3, "                   ");


	int i = 1;
	for (set<Entity*>::iterator it = inventory.begin(); it != inventory.end(); ++it) {
		coutXY(INVENTORY_X, INVENTORY_Y + (i++), (*it)->getName());
	}
}
