#include "casilla.h"
#include <iostream>
using namespace std;

Casilla :: Casilla()
: fila(0), columna(0) , pieza(0), color(0), tocab(0), tocan(0){}

int Casilla::getPieza() const {
    return pieza;
}
int Casilla::getColor() const {
    return color;
}

bool Casilla::vacia() const {
    return pieza == 0;
}

/*
Casilla::Casilla()
    : pieza(0), color(0), amenaza_b(0), amenaza_n(0) {}


int Casilla::amenazaBlancas() const {
    return amenaza_b;
}

int Casilla::amenazaNegras() const {
    return amenaza_n;
}

void Casilla::limpiarAmenazas() {
    amenaza_b = 0;
    amenaza_n = 0;
}

void Casilla::setAmenazaBlancas(int valor) {
    amenaza_b = valor;
}

void Casilla::setAmenazaNegras(int valor) {
    amenaza_n = valor;
}

int Casilla::setColor(int color_) {
    color = color_;
}*/
