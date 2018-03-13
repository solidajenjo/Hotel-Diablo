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
#define ORDERS_Y 20
#define ORDERS_X 15
#define GAME_OUTPUT_SIZE 24
#define MAX_INPUT_SIZE 117
#define TIME_Y 3
#define TIME_X 98
#define INVENTORY_X 5
#define INVENTORY_Y 5
//messages
// � \240 | � \202 | � \241 | � \242 | � \243 | � \244
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
#define NOT_IN_POSSESSION "No tienes eso."
#define NOT_TAKE_PERSON "No voy a coger una persona. Estoy cansado."
#define UNLOCK_HALL "Se desbloquean las puertas del HALL."
//time
#define TOTAL_TIME 15*60 //10 minutes
#define DIMITRI_MOVE_TIME 30 //moves each 30 seconds
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
#define DESC_AXE "Un hacha rudimentaria. No creo que aguante mas de un golpe."
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


#define LOCK_PICTURE "Est\240 bien clavado en la pared."
#define LOCK_DRINK "MARGE: Ni se te ocurra mierdecilla."
#define LOCK_SCREW "Necesitar\241a una herramienta"
#define LOCK_LOCK "Est\240 agarrado al armario"
#define LOCK_CLOSET "Pesa demasiado."
#define LOCK_CASE "Me da verguenza que me vean con eso por ah\241."
#define LOCK_KEY "No puedo mientras MARGE est\240 vigilando."
#define LOCK_H106 "No creo que pueda abrirla sin la LLAVE."
#define LOCK_FOREVER "No se abrira de ninguna manera."
#define LOCK_MAINT "Esta cerrada. No parece muy solida. La podr\241a romper si    tuviera un HACHA."
#define LOCK_CHAIR "Esta LUCAS encima. Mejor la dejo."
#define LOCK_HALL "Las puertas estan cerradas y no tienen tirador. Se deben   abrir desde otra parte."
//action result

#define LUCAS_DEATH "Lucas patalea durante un momento hasta que deja de moverse. Se ha meado encima. Se le cae una PIEDRA del bolsillo."

//conversation
#define M0 "La recepcionista del hotel MARGE te dirije una mirada      condenscendiente.                                           MARGE: \"Que es lo que quieres?\"                             1 - Que significa la cuenta atras?"
#define M1 "La recepcionista del hotel MARGE te dirije una mirada      condenscendiente.                                           MARGE: \"Que es lo que quieres?\"                             1 - Que significa la cuenta atras?                          2 - Huespedes                                               3 - Donde esta Dimitri?                                     4 - BEBIDA?"
#define M2 "Ah si eso, eso es que te quedan unos 15 minutos para       escapar de aqui. Que putada no? Deberias haber recuperado elconocimiento antes. En este hotel, ademas de ti, hay 2      huespedes,solo el ultimo que quede al final podr� salir del hotel con vida. Hay una que es una buena pieza, me da ganas de vomitar. La tenemos encerrada en la H106 porque es       peligrosa. El otro es un tal LUCAS no se donde se habra     metido. DIMITRI el de mantenimiento me parece que debe saberalgo mas de el. Te voy a desbloquear las puertas del HALL   para que vayas a llorar en privado o lo que sea que te      apetezca  hacer antes del final."
#define M3 "Se mueve muy a menudo de sitio. Cada 30 segundos mas o     menos. Dimitri estara en "
#define M4 " hasta dentro de "