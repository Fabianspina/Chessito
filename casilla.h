#ifndef CASILLA_H
#define CASILLA_H
#include <string>
#include <iostream>
using namespace std;

class Casilla{
public:
    int indice;
    int desde;
    int hasta;
    short int peon2;
    short int clavada;
    short int fila;
    short int columna;
    short int pieza;
    short int color;
    short int tocab;
    short int tocan;
    string origin;
    string destiny;

    Casilla();// Constructor por defecto
    Casilla(int indice);         		// Desde �ndice (1..64)
    int getColor() const;
    int getPieza() const;
    bool vacia() const;
};
#endif // CASILLA_H

/*
    // Constructores

    Casilla(int x, int y);			// Desde coordenadas cartesianas
    Casilla(const std::string& pgn);		// Desde notaci�n algebraica (ej: "e2")

    // Acceso a datos
    bool vacia() const;

    // Informaci�n t�ctica
    int amenazaBlancas() const;
    int amenazaNegras() const;
    void limpiarAmenazas();
    void setAmenazaBlancas(int valor);
    void setAmenazaNegras(int valor);
    int setColor;
private:
    int amenaza_b;
    int amenaza_n;
    // M�todos de conversi�n
    int x; // Columna: 1 a 8
    int y; // Fila: 1 a 8
};
*/
