#pragma once
//enumerations
enum entityType {
	NPC, PLAYER, EXIT, ITEM, ROOM
};

enum directions {
	_NORTH, _EAST, _SOUTH, _WEST, ATRAVESARH105, ATRAVESARH107, ATRAVESARH106, ATRAVESARH108, ATRAVESARH101, ATRAVESARH102, ATRAVESARH104, ATRAVESARH103
};


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
#define INVENTORY_X 5
#define INVENTORY_Y 10
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
#define I_CANT_DO_THAT_CODE 2
#define I_CANT_DO_THAT "No puedo hacer eso."
#define INVENTORY_FULL "No puedes llevar m\240s cosas."
#define UNOWNED_OBJECT "No tienes ese objeto."
#define NOT_NEAR_OBJECT "No veo eso por aqu\241 cerca."
//time
#define TOTAL_TIME 15*60 //10 minutes

//room definitions
#define DESC_HALL "El hall de un hotel de estilo Art d\202co. Se puede vislumbrarla belleza del lugar debajo de la capa de mugre que cubre   todos los rincones del mismo. Hay un mostrador en el centro en el que una mujer fuma con la vista perdida."
#define DESC_CORRIDOR1 "Un pasillo de hotel estandard. Hay 4 puertas(H101, H102,   H103, H104). Al este hay una cocina."
#define DESC_CORRIDOR2 "Un pasillo de hotel estandard. Hay 4 puertas(H105, H106,   H107, H108). Al oeste hay una puerta de MANTENIMIENTO."
#define DESC_KITCHEN "Puaj que asco. El panorama es dantesco. Hay comida podrida por doquier. Hay un ARMARIO con un CANDADO. Me pregunto que habr\240 dentro?"
#define DESC_KITCHEN2 "Puaj que asco. El panorama es dantesco. Hay comida podrida por doquier. Hay un ARMARIO. Me pregunto que habr\240 dentro?"
#define DESC_KITCHEN3 "Puaj que asco. El panorama es dantesco. Hay comida podrida por doquier. Hay un ARMARIO."
#define DESC_R101 "La t\241pica habitacion de hotel s\242lo que llena de mugre. De  la lampara cuelga una horca. Hay un hombre subido a una     silla bajo la horca lloriqueando."
#define DESC_R101_2 "La t\241pica habitacion de hotel s\242lo que llena de mugre. De  la lampara cuelga una horca. Hay un hombre ahorcado         balanceandose con la brisa."
#define DESC_R102 "La t\241pica habitacion de hotel s\242lo que llena de mugre."
#define DESC_R104 "La t\241pica habitacion de hotel s\242lo que llena de mugre."
#define DESC_R106 "La t\241pica habitacion de hotel s\242lo que llena de mugre."
#define DESC_R107 "La t\241pica habitacion de hotel s\242lo que llena de mugre. Hay una MALETA."
#define DESC_R108 "La t\241pica habitacion de hotel s\242lo que llena de mugre. Hay un CUADRO de un hacha primitiva."
#define DESC_MAINTENANCE "El cuarto de mantenimiento esta limpio como una patena.    Este sitio no dejar\240 de sorprendereme nunca."

//NPCs descriptions
#define DESC_DIMI1 "Un ruso con cara de pocos amigos."
#define DESC_DIMI2 "Un ruso muerto como cualquier otro."
#define DESC_LUCAS1 "Un hombre delgado bastante pat\202tico."
#define DESC_LUCAS2 "Un hombre delgado ahorcado. Parece feliz."
#define DESC_LILY1 "Una ni\244a de unos cinco a\244os. No para de llorar y preguntar por su madre."
#define DESC_LILY2 "Una ni\244a de unos cinco a\244os muerta. Ya no llora."
#define DESC_MARGE1 "La recepcionista. No parece muy simp\240tica."
#define DESC_MARGE2 "La recepcionista del hotel muerta. Sigue sin parecer       simp\240tica."
//Items descriptions
#define DESC_EMPTY_GUN "Un revolver sin balas."
#define DESC_STICK "Un palo."
#define DESC_STONE "Una piedra con forma triangular. Esta afilada"
#define DESC_VASE "Una jarr\242n de lo mas elegante."
#define DESC_POISON "Matarratas marca ACME."
#define DESC_WRENCH "Una llave inglesa."
#define DESC_HAMMER "Un martillo."
#define DESC_NAILS "Una docena de clavos."
#define DESC_KEYR106 "La llave de la habitaci\242n 106."
#define DESC_CASE "Un maleta de pokemon. Podria usarla para llevar mas cosas  pero me da verguenza."
#define DESC_GUN "Un revolver con una bala."
#define DESC_CHICKEN "Un pollo de goma. Me decepciona que no tenga una polea."
#define DESC_CHAIR "Una silla medio podrida."
#define DESC_CORD "Un cordel para atar cosas."
#define DESC_CLOSET "Un armario de madera. Tiene un TORNILLO suelto."
#define DESC_LOCK "Un candado."
#define DESC_SCREW "Un TORNILLO suelto. Sujeta la puerta."
#define DESC_DRINK "Un vaso con lo que parece WHISKY. Queda muy poco."
#define DESC_WHISKY "WHISKY del barato."
#define DESC_WHISKY2 "WHISKY del barato envenenado."
#define DESC_POT "Una olla con restos de comida pegada."
#define DESC_KNIFE "Una cuchillo de carnicero."
#define DESC_PICTURE "Una cuadro de un hacha primitiva. Esta hecha con un PALO,  una PIEDRA y CORDEL."