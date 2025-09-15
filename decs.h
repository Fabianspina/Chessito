#ifndef _DECLS_H
#define _DECLS_H

#include <windows.h>
#include <fstream>
#include <iostream>
using namespace std;
#include <tchar.h>
#include <ctime>

#include "rey.h"
#include "tablero.h"
#include "valida.h"
#include "tc.h"
#include "turno.h"
#include "convierte.h"
#include "misc/adornos.h"
#include "misc/elo.h"
#define decir cout <<
#define decirn cout <<"\n"
#define decirnt cout << "\n\t"
#define decirt cout << "\t"
#define pausa system("pause >> misc/null")
#define borrar system("cls")
#define blanca system("color F0")
#define aqua system("color 3F")
#define negra system("color 0F")
#define azul system("color F1")
#define amarillo system("color 0E")
#define rojo system("color 4F")
#define marca cout << "\n\t momento marcado en línea: \t"
#define grande system("mode con cols=560 lines=160")
#define chica system("mode con cols=60 lines=40")
#define bucle (i=1;i<=64;i++)
#define bucleori (ori=1;ori<=64;ori++)
#define ti t[i]
#define crom SetConsoleTextAttribute(hConsole,

#define CM_VT 102
#define CM_SALIR 103
#define CM_TURNO 104
#define CM_AYUDA 105
#define CM_VERTABLERO 106
#define CM_MOVER 107
#define CM_VTAMENAZAS 108
#define CM_TABCHES 109
#define CM_TUTOR 110
#define CM_MOVIDASPOSIBLES 111
#define CM_CHESSITO 112
#define CM_ELO 113
#define CM_JAQUE 114
#define CM_AMBITOREY 115
#define CM_GUARDAR 116
#define CM_JAQUEMATE 117

#define IDD_MAIN_DIALOG   200
#define IDC_EDIT_JUGADA   201
#define IDC_BUTTON_MOVER  202
#define IDC_TABLERO       203
#define IDC_LABEL_TURNO   204

/**************           Declaración de Funciones             ************/
LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK DlgPruebaproc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam);
HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
TCHAR szClassName[ ] = _T("Chessito 16");
Tablero tablero;
bool dragging = false;
int selectedX = -1, selectedY = -1;
int offsetX = 0, offsetY = 0;

bool clavada();
bool origen();
bool jaque();
bool jaquefictblan();
bool jaquefictneg();
bool jaquemate();
bool mover(string& origen, string& destino);
bool siguepartida();
double valc();
int ambitorey();
int decide();
int menu();
int movidasposibles();
int turno();
void actualiza();
void actualizaconpeon();
void actualizadementira();
void actualizapeonalp1();
void actualizapeonalp2();
void actualizapeonalp3();
void actualizapeonalp4();
void ahogado();
void alternativa();
void asigna();
void aux(int);
void aux1(int);
void aux2(int);
void ayuda();
void beep();
void beep_cambio_pieza();
void beep_pieza();
void borra();
void borrapeon2();
void cambiarcolor();
void centro();
void chessito();
void colision(); // funcion de evalucion
void desarrollo();
void desconvierte();
void deshacerprobar();
void destino();
void dibujarTablero(HWND hwnd, HDC hdc, Tablero& tablero);
void eligepieza();
void enroquecorto();
void enroquelargo();
void escribe();
void espacio();
void extraejugada();
void faltamat();
void findelapartida();
void g_m_a(int r, int s);
void gotoxy(int x, int y);
void guardamovida();
void jugar();
void jugarconchessito();
void limpianterior();		// no está claro si es necesaria
void material();
void menuver();
void movidaficticia();
void muestrajugada(int dec);
void nodo();				// no influye
void presentacion();
void probarjugada();
void prueba();
void pruebemoveralfil();
void pruebemovercaballo();
void pruebemoverdama();
void pruebemovertorre();
void pruebemoverrey();
void pruebemoverpeon();
void rastreador();
void recuerda(int);
void resolverjaque();		// no influye
void seguridadrey();
void ubicarey();
void ubicareyficticio();
void validarey();
void validadama();
void validaalfil();
void validatorre();
void validacaballo();
void validapeon();
void validarconjaque();		// innecesaria
void vt();
void vt1();
void vtalp();
void vtalpficticio();
void vtamenaza();
void vtaux();
void vtaux1();
void vtpeon2();

float Ra, Rb, outcome;
char *b ;
char *d ;
short static int i;
string origin, destiny;
short int mp, rmb, rmn, num_jugada;

void escribe(short int &ori, short int &dest){
ofstream guarda("texto.txt");
if (guarda.is_open())
guarda << num_jugada << ori << dest;
else
std::cerr << "Error al abrir el archivo." << std::endl;
}

/*
La presentación se ejecuta sin las pausas. El enlace a presentación va bien
Ver tablero es una función hermosa. El enlace a Tablero anda bien
e2 e4 va a función actualiza y borra la casilla de origen (e2)
y no dibuja al peón en e4

El problema más grande es la documentación inicial cuenta todas las movidas
e2 e4 e7 e5 cuenta 25 porque faltan las cuatro movidas de dama
g2 g3 f8 e7 conto 27 jugadas, la primer movida de alfil toma la dama en d8

*/

#endif //_DECLS_H
