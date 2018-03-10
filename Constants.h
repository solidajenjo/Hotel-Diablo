#pragma once
//enumerations
enum entityType {
	NPC, PLAYER, EXIT, ITEM, ROOM
};

enum directions {
	NORTH, EAST, SOUTH, WEST
};

//verbos
#define TAKE "COJER"
#define LOOK "MIRAR"
#define PUSH "EMPUJAR"
#define USE "USAR"

//movimientos
#define NORTH "NORTE"
#define SHORT_NORTH "N"
#define EAST "ESTE"
#define SHORT_EAST "E"
#define WEST "WEST"
#define SHORT_WEST "W"
#define SOUTH "SUR"
#define SHORT_SOUTH "S"

//keycodes
#define KEY_BACKSPACE 8
#define KEY_ENTER 13

//game input/output
#define OUTPUT_LENGTH 60
#define OUTPUT_LINE_START_X 59
#define OUTPUT_START_Y 5
#define INPUT_Y 30
#define CENTRAL_LINE 57
#define TIME_LINE 4
#define INVENTORY_Y 2
#define INVENTORY_X 15
#define ORDERS_Y 20
#define ORDERS_X 15
#define GAME_OUTPUT_SIZE 24
#define MAX_INPUT_SIZE 117
#define TIME_Y 3
#define TIME_X 98
//messages
// á \240 | é \202 | í \241 | ó \242 | ú \243 | ñ \244
#define BAD_GRAMMAR_CODE 1
#define BAD_GRAMMAR "No entiendo lo que quieres decir."
#define CLEAR_LINE "                                                                                                             "
#define WELCOME_MSG "Aturdido te esfuerzas por abrir los ojos. Cuando por fin loconsigues te encuentras en lo que parece el hall de un      hotel. A tu lado un extra\244o hombre vestido como un botones  te saluda diciendo:\"Bienvenido al hotel diablo se\244or\".      Instantaneamente el hombre se esfuma dejando una nube negra que se disipa poco a poco."
#define MINUTE_10_WARNING "Te quedan 10 minutos. Yo que t\243 espabilar\241a un poco"
#define MINUTE_5_WARNING "5 minutos. Tiene pinta de que vas a fracasar."
#define MINUTE_1_WARNING "1 minuto. MUAHAHAHAHAHA..."
#define OUT_OF_TIME "Se acabo el tiempo. Justo debajo de tus pies se abre un    agujero. Caes hacia el abismo. Te quedas flotando en el     vacio por toda la eternidad lamentando tu torpeza.          Gracias por visitar el Hotel Diablo, te animo a intentarlo  de nuevo."
//time

#define TOTAL_TIME 1*60 //10 minutes
                                                                                                                                                                                                                                  