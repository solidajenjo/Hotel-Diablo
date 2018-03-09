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

//messages
// á \240 | é \202 | í \241 | ó \242 | ú \243
#define BAD_GRAMMAR_CODE 1
#define BAD_GRAMMAR "No entiendo lo que quieres decir. Escribe ayuda si est\240s perdido."