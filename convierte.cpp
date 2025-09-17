#include "convierte.h"
#include <iostream>
using namespace std;

/*
Estas dos funciones tienen la misión de convertir la jugada tipeada en la
consola en dos enteros que simbolizan la casilla de origen y de destino.
Es para que el usuario pueda comunicarse con el programa en los términos
que  un humano entiende, es decir la notación pgn. En la etapa actual esta
función no  se modifica, así que pasa a la carpeta de interfaz
*/
    char cas[2];
    char casdes[2];
    short int ori;
    short int dest;

void convierteorigen(){
	if (cas[0] == 'a' && cas[1] == '8') ori = 1;
	if (cas[0] == 'b' && cas[1] == '8') ori = 2;
	if (cas[0] == 'c' && cas[1] == '8') ori = 3;
	if (cas[0] == 'd' && cas[1] == '8') ori = 4;
	if (cas[0] == 'e' && cas[1] == '8') ori = 5;
	if (cas[0] == 'f' && cas[1] == '8') ori = 6;
	if (cas[0] == 'g' && cas[1] == '8') ori = 7;
	if (cas[0] == 'h' && cas[1] == '8') ori = 8;
	if (cas[0] == 'a' && cas[1] == '7') ori = 9;
	if (cas[0] == 'b' && cas[1] == '7') ori = 10;
	if (cas[0] == 'c' && cas[1] == '7') ori = 11;
	if (cas[0] == 'd' && cas[1] == '7') ori = 12;
	if (cas[0] == 'e' && cas[1] == '7') ori = 13;
	if (cas[0] == 'f' && cas[1] == '7') ori = 14;
	if (cas[0] == 'g' && cas[1] == '7') ori = 15;
	if (cas[0] == 'h' && cas[1] == '7') ori = 16;
	if (cas[0] == 'a' && cas[1] == '6') ori = 17;
	if (cas[0] == 'b' && cas[1] == '6') ori = 18;
	if (cas[0] == 'c' && cas[1] == '6') ori = 19;
	if (cas[0] == 'd' && cas[1] == '6') ori = 20;
	if (cas[0] == 'e' && cas[1] == '6') ori = 21;
	if (cas[0] == 'f' && cas[1] == '6') ori = 22;
	if (cas[0] == 'g' && cas[1] == '6') ori = 23;
	if (cas[0] == 'h' && cas[1] == '6') ori = 24;
	if (cas[0] == 'a' && cas[1] == '5') ori = 25;
	if (cas[0] == 'b' && cas[1] == '5') ori = 26;
	if (cas[0] == 'c' && cas[1] == '5') ori = 27;
	if (cas[0] == 'd' && cas[1] == '5') ori = 28;
	if (cas[0] == 'e' && cas[1] == '5') ori = 29;
	if (cas[0] == 'f' && cas[1] == '5') ori = 30;
	if (cas[0] == 'g' && cas[1] == '5') ori = 31;
	if (cas[0] == 'h' && cas[1] == '5') ori = 32;
	if (cas[0] == 'a' && cas[1] == '4') ori = 33;
	if (cas[0] == 'b' && cas[1] == '4') ori = 34;
	if (cas[0] == 'c' && cas[1] == '4') ori = 35;
	if (cas[0] == 'd' && cas[1] == '4') ori = 36;
	if (cas[0] == 'e' && cas[1] == '4') ori = 37;
	if (cas[0] == 'f' && cas[1] == '4') ori = 38;
	if (cas[0] == 'g' && cas[1] == '4') ori = 39;
	if (cas[0] == 'h' && cas[1] == '4') ori = 40;
	if (cas[0] == 'a' && cas[1] == '3') ori = 41;
	if (cas[0] == 'b' && cas[1] == '3') ori = 42;
	if (cas[0] == 'c' && cas[1] == '3') ori = 43;
	if (cas[0] == 'd' && cas[1] == '3') ori = 44;
	if (cas[0] == 'e' && cas[1] == '3') ori = 45;
	if (cas[0] == 'f' && cas[1] == '3') ori = 46;
	if (cas[0] == 'g' && cas[1] == '3') ori = 47;
	if (cas[0] == 'h' && cas[1] == '3') ori = 48;
	if (cas[0] == 'a' && cas[1] == '2') ori = 49;
	if (cas[0] == 'b' && cas[1] == '2') ori = 50;
	if (cas[0] == 'c' && cas[1] == '2') ori = 51;
	if (cas[0] == 'd' && cas[1] == '2') ori = 52;
	if (cas[0] == 'e' && cas[1] == '2') ori = 53;
	if (cas[0] == 'f' && cas[1] == '2') ori = 54;
	if (cas[0] == 'g' && cas[1] == '2') ori = 55;
	if (cas[0] == 'h' && cas[1] == '2') ori = 56;
	if (cas[0] == 'a' && cas[1] == '1') ori = 57;
	if (cas[0] == 'b' && cas[1] == '1') ori = 58;
	if (cas[0] == 'c' && cas[1] == '1') ori = 59;
	if (cas[0] == 'd' && cas[1] == '1') ori = 60;
	if (cas[0] == 'e' && cas[1] == '1') ori = 61;
	if (cas[0] == 'f' && cas[1] == '1') ori = 62;
	if (cas[0] == 'g' && cas[1] == '1') ori = 63;
	if (cas[0] == 'h' && cas[1] == '1') ori = 64;

}
void conviertedestino(){
	if (casdes[0] == 'a' && casdes[1] == '8') dest = 1;
	if (casdes[0] == 'b' && casdes[1] == '8') dest = 2;
	if (casdes[0] == 'c' && casdes[1] == '8') dest = 3;
	if (casdes[0] == 'd' && casdes[1] == '8') dest = 4;
	if (casdes[0] == 'e' && casdes[1] == '8') dest = 5;
	if (casdes[0] == 'f' && casdes[1] == '8') dest = 6;
	if (casdes[0] == 'g' && casdes[1] == '8') dest = 7;
	if (casdes[0] == 'h' && casdes[1] == '8') dest = 8;
	if (casdes[0] == 'a' && casdes[1] == '7') dest = 9;
	if (casdes[0] == 'b' && casdes[1] == '7') dest = 10;
	if (casdes[0] == 'c' && casdes[1] == '7') dest = 11;
	if (casdes[0] == 'd' && casdes[1] == '7') dest = 12;
	if (casdes[0] == 'e' && casdes[1] == '7') dest = 13;
	if (casdes[0] == 'f' && casdes[1] == '7') dest = 14;
	if (casdes[0] == 'g' && casdes[1] == '7') dest = 15;
	if (casdes[0] == 'h' && casdes[1] == '7') dest = 16;
	if (casdes[0] == 'a' && casdes[1] == '6') dest = 17;
	if (casdes[0] == 'b' && casdes[1] == '6') dest = 18;
	if (casdes[0] == 'c' && casdes[1] == '6') dest = 19;
	if (casdes[0] == 'd' && casdes[1] == '6') dest = 20;
	if (casdes[0] == 'e' && casdes[1] == '6') dest = 21;
	if (casdes[0] == 'f' && casdes[1] == '6') dest = 22;
	if (casdes[0] == 'g' && casdes[1] == '6') dest = 23;
	if (casdes[0] == 'h' && casdes[1] == '6') dest = 24;
	if (casdes[0] == 'a' && casdes[1] == '5') dest = 25;
	if (casdes[0] == 'b' && casdes[1] == '5') dest = 26;
	if (casdes[0] == 'c' && casdes[1] == '5') dest = 27;
	if (casdes[0] == 'd' && casdes[1] == '5') dest = 28;
	if (casdes[0] == 'e' && casdes[1] == '5') dest = 29;
	if (casdes[0] == 'f' && casdes[1] == '5') dest = 30;
	if (casdes[0] == 'g' && casdes[1] == '5') dest = 31;
	if (casdes[0] == 'h' && casdes[1] == '5') dest = 32;
	if (casdes[0] == 'a' && casdes[1] == '4') dest = 33;
	if (casdes[0] == 'b' && casdes[1] == '4') dest = 34;
	if (casdes[0] == 'c' && casdes[1] == '4') dest = 35;
	if (casdes[0] == 'd' && casdes[1] == '4') dest = 36;
	if (casdes[0] == 'e' && casdes[1] == '4') dest = 37;
	if (casdes[0] == 'f' && casdes[1] == '4') dest = 38;
	if (casdes[0] == 'g' && casdes[1] == '4') dest = 39;
	if (casdes[0] == 'h' && casdes[1] == '4') dest = 40;
	if (casdes[0] == 'a' && casdes[1] == '3') dest = 41;
	if (casdes[0] == 'b' && casdes[1] == '3') dest = 42;
	if (casdes[0] == 'c' && casdes[1] == '3') dest = 43;
	if (casdes[0] == 'd' && casdes[1] == '3') dest = 44;
	if (casdes[0] == 'e' && casdes[1] == '3') dest = 45;
	if (casdes[0] == 'f' && casdes[1] == '3') dest = 46;
	if (casdes[0] == 'g' && casdes[1] == '3') dest = 47;
	if (casdes[0] == 'h' && casdes[1] == '3') dest = 48;
	if (casdes[0] == 'a' && casdes[1] == '2') dest = 49;
	if (casdes[0] == 'b' && casdes[1] == '2') dest = 50;
	if (casdes[0] == 'c' && casdes[1] == '2') dest = 51;
	if (casdes[0] == 'd' && casdes[1] == '2') dest = 52;
	if (casdes[0] == 'e' && casdes[1] == '2') dest = 53;
	if (casdes[0] == 'f' && casdes[1] == '2') dest = 54;
	if (casdes[0] == 'g' && casdes[1] == '2') dest = 55;
	if (casdes[0] == 'h' && casdes[1] == '2') dest = 56;
	if (casdes[0] == 'a' && casdes[1] == '1') dest = 57;
	if (casdes[0] == 'b' && casdes[1] == '1') dest = 58;
	if (casdes[0] == 'c' && casdes[1] == '1') dest = 59;
	if (casdes[0] == 'd' && casdes[1] == '1') dest = 60;
	if (casdes[0] == 'e' && casdes[1] == '1') dest = 61;
	if (casdes[0] == 'f' && casdes[1] == '1') dest = 62;
	if (casdes[0] == 'g' && casdes[1] == '1') dest = 63;
	if (casdes[0] == 'h' && casdes[1] == '1') dest = 64;
}

int indiceDesdeXY(int x, int y) {
    if (x < 1 || x > 8 || y < 1 || y > 8)
        return -1;

    int filaInvertida = 9 - y;
    return (filaInvertida - 1) * 8 + x;
}

void obtenerXY(int i, int& x, int& y) {
    if (i < 1 || i > 64) {
        x = -1;
        y = -1;
        return;
    }

    int filaInvertida = (i - 1) / 8 + 1;
    x = (i - 1) % 8 + 1;
    y = 9 - filaInvertida;
}

int convertirCasilla(const std::string& casilla) {
    if (casilla.length() < 2)
        return -1;

    char col = tolower(casilla[0]);
    char fil = casilla[1];

    if (col < 'a' || col > 'h' || fil < '1' || fil > '8')
        return -1;

    int x = col - 'a' + 1;
    int y = fil - '1' + 1;

    // Tu sistema: fila 1 está abajo (como e2)
    return (8 - y) * 8 + x;
}
