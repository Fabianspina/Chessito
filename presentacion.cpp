#define decir cout <<
#define decirn cout << "\n"
#define decirnt cout << "\n\t" <<
#define decirt cout << "\t" <<
#define pausa system ("pause >> misc/null")
#define borrar system("cls")
#define blanca system("color F0")
#define aqua system("color 3F")
#define negra system("color 0F")
#define azul system("color 97")
#define amarillo system("color 0E")
#define rojo system("color 4F")
#define grande system("mode con cols=560 lines=160")
#define chica system("mode con cols=60 lines=40")
#define bucle (i=1;i<=64;i++)
#define bucleori (ori=1;ori<=64;ori++)
#define marca cout << "\n\t momento marcado en línea: \t" <<
#include <windows.h>
#include <iostream>
using namespace std;
#include "presentacion.h"

void presentacion() {
	azul;
    borrar;
    gotoxy(2,3);
	decir "\t\t Programacion de un interprete de ajedrez\n\n";
	pausa;
	borrar;
    gotoxy(3,2);
	decir "\t\t\t por Fabian Spinazzola\n\n";
	pausa;
	borrar;
    gotoxy(6,5);
	decir "\tHola! Bienvenidos!! Soy Chessito 16, un programa de ajedrez \n";
    decir "\t\t capaz de jugar.\n\n\n";
	decir "\n\t\t< * > < * > < * > < * > < * > < * > < * > < * >\n\n\n";
	decir "\n\t Mi fuerza de juego actual se ira incrementando desde los\n\n\n";
	decir "\n\t\t -1615pts elo hasta -615. \n\n\n";
	decir "\n\t\t -1615 pts o -615 dice que, en ambos casos, voy a perder\n\t\t todas las partidas. \n\n\n";
	decir "\n\t\t pero dice también que va a ser divertido. \n\n\n";
	decir "\n\t\t< * > < * > < * > < * > < * > < * > < * > < * >\n\n\n";
		PlaySound( "PICK.WAV", NULL, SND_FILENAME | SND_SYNC);
	pausa;
	borrar;
	decir "\tYa aprendi a reconocer las casillas del tablero.\n\n";
	decir "\tYa aprendi como se mueven las piezas y varias reglas, como el enroque.\n\n";
	decir "\tYa aprendi cuantas movidas posibles hay en cada turno \n\n";
	decir "\tYa aprendi algunas movidas\n\n";
	decir "\tTodavia debo empezar a valorar posiciones.\n\n\n";
   		PlaySound( "PICK.WAV", NULL, SND_FILENAME | SND_SYNC);
	pausa;
	borrar;
	decir "\tPara visualizar correctamente la pantalla de juego\n\n";
	decir "\tAgrande la ventana y subala hasta arriba con la rueda del mouse.\n\n";
	decir "\tMejor hagalo ahora para no olvidarlo\n\n";
	decir "\tVea la ayuda para conocer como se anota una jugada.";
        PlaySound( "entel.WAV", NULL, SND_FILENAME | SND_SYNC);
	pausa;
	borrar;
return;
}

void gotoxy(int x, int y){
coord.X=x;
coord.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
