#include <windows.h>
#include "casilla.h"
#include "tablero.h"
#include "tc.h"
#include <iostream>
using namespace std;
#include "convierte.h"
#define decir cout <<

extern HANDLE hConsole;
const Casilla& Tablero::getCasilla(int i) const {
    return casillas[i];
}

// Devuelve una casilla (versión modificable)
Casilla& Tablero::getCasilla(int i) {
    return casillas[i];
}

Tablero::Tablero() {
    inicializar(); // Inicializa posición inicial
}

void Tablero::inicializar() {
    // Limpiar todas las casillas
    for (int i = 1; i <= 64; ++i) {
        casillas[i].pieza = 0;
        casillas[i].color = 0;
        casillas[i].tocab = 0;
        casillas[i].tocan = 0;
        casillas[i].peon2 = 0;
        casillas[i].clavada = 0;
    }

    // Peones blancos – fila 2 → i=49..56
    for (int i = 49; i <= 56; ++i) {
        casillas[i].pieza = 6; // Peón
        casillas[i].color = 1; // Blanco
    }

    // Peones negros – fila 7 → i=9..16
    for (int i = 9; i <= 16; ++i) {
        casillas[i].pieza = 6; // Peón
        casillas[i].color = 2; // Negro
    }

    // Blancas – fila 1 → i=57..64
    casillas[57].pieza = 3; casillas[57].color = 1; // Torre a1
    casillas[58].pieza = 5; casillas[58].color = 1; // Caballo b1
    casillas[59].pieza = 4; casillas[59].color = 1; // Alfil c1
    casillas[60].pieza = 2; casillas[60].color = 1; // Dama d1
    casillas[61].pieza = 1; casillas[61].color = 1; // Rey e1
    casillas[62].pieza = 4; casillas[62].color = 1; // Alfil f1
    casillas[63].pieza = 5; casillas[63].color = 1; // Caballo g1
    casillas[64].pieza = 3; casillas[64].color = 1; // Torre h1

// Negras – fila 8 → i=1..8
casillas[1].pieza = 3; casillas[1].color = 2; // Torre a8
casillas[2].pieza = 5; casillas[2].color = 2; // Caballo b8
casillas[3].pieza = 4; casillas[3].color = 2; // Alfil c8
casillas[4].pieza = 2; casillas[4].color = 2; // Dama d8
casillas[5].pieza = 1; casillas[5].color = 2; // Rey e8
casillas[6].pieza = 4; casillas[6].color = 2; // Alfil f8
casillas[7].pieza = 5; casillas[7].color = 2; // Caballo g8
casillas[8].pieza = 3; casillas[8].color = 2; // Torre h8
}

// Equivale a vertablero
void Tablero::mostrar() const {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    #define crom(color) SetConsoleTextAttribute(hConsole, color)

    crom(4);
    decir "\n\t\t< * > < * > < * > < * > < * > < * > < * > < * >\n";
    crom(7);

    // Bucle por filas, de 8 a 1
    for (int fila = 8; fila >= 1; --fila) {
        decir "\t\t";
            WORD colorFondo = (fila % 2 == 0 ) ? 112 : 97; // 112 = gris claro, 97 = marrón claro
            // Alternar colores de fondo por fila
            for (int col = 1; col <= 8; ++col) {
            int i = indiceDesdeXY(col, fila);
            const Casilla& c = casillas[i];
            crom(colorFondo);
            decir "|";
           // crom(7); // Texto blanco

            if (c.pieza == 0) {
                decir "   ";
            } else {
                switch (c.pieza) {
                    case 1: decir " R"; break;
                    case 2: decir " D"; break;
                    case 3: decir " T"; break;
                    case 4: decir " A"; break;
                    case 5: decir " C"; break;
                    case 6: decir " P"; break;
                }
                decir (c.color == 1 ? "b" : "n");
            }
            decir " ";
        }
        crom(7);
        decir "|\n";
    }

    crom(4);
    decir "\t\t< * > < * > < * > < * > < * > < * > < * > < * >\n\n";
    crom(7);
}

void Tablero::mostrarAmenazas() const{
//    decir "\n\t\t< * > < * > < * > < * > < * > < * > < * > < * >\n\n";
    for (int fila = 8; fila >= 1; --fila) {
        decir "\n\n\t\t"; // Espaciado entre filas

        for (int col = 1; col <= 8; ++col) {
            int i = indiceDesdeXY(col, fila); // Debe estar definida
            const Casilla& c = casillas[i];
            if (c.pieza == 0) {
                 decir "--" << c.peon2 <<"- " ;
            } else {
                switch (c.pieza) {
                    case 1: decir "-R"; break;
                    case 2: decir "-D"; break;
                    case 3: decir "-T"; break;
                    case 4: decir "-A"; break;
                    case 5: decir "-C"; break;
                    case 6: decir "-P"; break;
                    default: decir "?";
                }

                switch (c.color) {
                    case 0: decir "----"; break;
                    case 1: decir "b- " ; break;
                    case 2: decir "n- " ; break;
                }
            }
        }
    }

    decir "\n\t\t\n\n";
}


/**************************    vertablero.h   *************************/
void aux(int i) { //toma el valor de cada casilla en la estructura tablerocompleto y la vuelca en vt
	switch (ti.pieza) {
	case 0: decir "| " ; break;
	case 1: decir "| R"; break;
	case 2: decir "| D"; break;
	case 3: decir "| T"; break;
	case 4: decir "| A"; break;
	case 5: decir "| C"; break;
	case 6: decir "| P"; break;
	}
	switch (ti.color) {
	case 0: decir "   |"  /*<< ti.tocab << ti.tocan << "-|"*/;  break;
	case 1: decir "b |"  /*<< ti.tocab << ti.tocan  << "-|"*/; break;
	case 2: decir "n |"  /*<< ti]tocab << ti.tocan  << "-|"*/;  break;
	}
}

    void vt() {
    int i;
#define crom SetConsoleTextAttribute(hConsole,
        crom 4);
        decir "\n\t\t< * > < * > < * > < * > < * > < * > < * > < * >\n";
        crom 7);
        decir "\t\t+----++----++----++----++----++----++----++----+\t" << endl;
        crom 112); decir "\t\t|    |";
        crom 97); decir "|    |";
        crom 112); decir "|    |";
        crom 97); decir "|    |";
        crom 112); decir "|    |";
        crom 97); decir "|    |";
        crom 112); decir "|    |";
        crom 97); decir "|    |" ;
    crom 7);
        decir "\n\t\t";
        for (i = 1; i <= 8; i++)   { if(i % 2){crom 112);} else {crom 97);} aux(i); }
        crom 7);
        decir "\n\t\t";
        decir "+----++----++----++----++----++----++----++----+" << endl;
        crom 97); decir "\t\t|    |";
        crom 112); decir "|    |";
        crom 97); decir "|    |";
        crom 112); decir "|    |";
        crom 97); decir "|    |";
        crom 112); decir "|    |";
        crom 97); decir "|    |";
        crom 112); decir "|    |" ;
    crom 7);
        decir "\n\t\t";
        for (i = 9; i <= 16; i++)  { if(i % 2){crom 97);} else {crom 112);} aux(i); }
        crom 7);
        decir "\n\t\t";
        decir "+----++----++----++----++----++----++----++----+" << endl;
        crom 112); decir "\t\t|    |";
        crom 97); decir "|    |";
        crom 112); decir "|    |";
        crom 97); decir "|    |";
        crom 112); decir "|    |";
        crom 97); decir "|    |";
        crom 112); decir "|    |";
        crom 97); decir "|    |" ;
    crom 7);
        decir "\n\t\t";
        for (i = 17; i <= 24; i++)  { if(i % 2){crom 112);} else {crom 97);} aux(i); }
        crom 7);
        decir "\n\t\t";
        decir "+----++----++----++----++----++----++----++----+" << endl;
        crom 97); decir "\t\t|    |";
        crom 112); decir "|    |";
        crom 97); decir "|    |";
        crom 112); decir "|    |";
        crom 97); decir "|    |";
        crom 112); decir "|    |";
        crom 97); decir "|    |";
        crom 112); decir "|    |" ;
    crom 7);
        decir "\n\t\t";	for (i = 25; i <= 32; i++) { if(i % 2){crom 97);} else {crom 112);} aux(i); }
        crom 7);
        decir "\n\t\t";
        decir "+----++----++----++----++----++----++----++----+" << endl;
        crom 112); decir "\t\t|    |";
        crom 97); decir "|    |";
        crom 112); decir "|    |";
        crom 97); decir "|    |";
        crom 112); decir "|    |";
        crom 97); decir "|    |";
        crom 112); decir "|    |";
        crom 97); decir "|    |";
    crom 7);
        decir "\n\t\t";
        for (i = 33; i <= 40; i++) { if(i % 2){crom 112);} else {crom 97);} aux(i); }
        crom 7);
        decir "\n\t\t";
        decir "+----++----++----++----++----++----++----++----+" << endl;
        crom 97); decir "\t\t|    |";
        crom 112); decir "|    |";
        crom 97); decir "|    |";
        crom 112); decir "|    |";
        crom 97); decir "|    |";
        crom 112); decir "|    |";
        crom 97); decir "|    |";
        crom 112); decir "|    |";
    crom 7);
        decir "\n\t\t";
        for (i = 41; i <= 48; i++) { if(i % 2){crom 97);} else {crom 112);} aux(i); }
        crom 7);
        decir "\n\t\t";
        decir "+----++----++----++----++----++----++----++----+" << endl;
        crom 112); decir "\t\t|    |";
        crom 97); decir "|    |";
        crom 112); decir "|    |";
        crom 97); decir "|    |";
        crom 112); decir "|    |";
        crom 97); decir "|    |";
        crom 112); decir "|    |";
        crom 97); decir "|    |";
    crom 7);
        decir "\n\t\t";
        for (i = 49; i <= 56; i++) { if(i % 2){crom 112);} else {crom 97);} aux(i); }
    crom 7);
        decir "\n\t\t";
        decir "+----++----++----++----++----++----++----++----+" << endl;
        crom 97); decir "\t\t|    |";
        crom 112); decir "|    |";
        crom 97); decir "|    |";
        crom 112); decir "|    |";
        crom 97); decir "|    |";
        crom 112); decir "|    |";
        crom 97); decir "|    |";
        crom 112); decir "|    |";
    crom 7);
        decir "\n\t\t";
        for (i = 57; i <= 64; i++) { if(i % 2){crom 97);} else {crom 112);} aux(i); }
    crom 7);
        decir "\n\t\t";
        decir "+----++----++----++----++----++----++----++----+";
    crom 4);
        decir "\n\t\t< * > < * > < * > < * > < * > < * > < * > < * >\n\n\n";
    crom 7);
    }
int aux2(int i) { //toma el valor de cada casilla en la estructura tablerocompleto y la vuelca en vt
	switch (ti.pieza) {
	case 0: decir "| " ; break;
	case 1: decir "| R"; break;
	case 2: decir "| D"; break;
	case 3: decir "| T"; break;
	case 4: decir "| A"; break;
	case 5: decir "| C"; break;
	case 6: decir "|P"; decir t[i].peon2;break;
	}
	switch (ti.color) {
	case 0: decir "   |"  << t[i].tocab << t[i].tocan/*<< "-|"*/;  break;
	case 1: decir "b |"  << t[i].tocab << t[i].tocan /*<< "-|"*/; break;
	case 2: decir "n |"  << t[i].tocab << t[i].tocan /*<< "-|"*/;  break;
	}
	return i;
}
