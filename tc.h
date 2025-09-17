#ifndef _TC_H
#define _TC_H
struct tc {
	short int columna;
	short int fila;
	short int pieza;
	short int color;
	short int peon2;
	short int clavada;
	short int tocab;
	short int tocan;
	short int amenaza;
	int cantidad;
	float valc;
};
extern struct tc t[65];

#endif //_TC_H
