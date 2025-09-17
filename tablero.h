#ifndef TABLERO_H
#define TABLERO_H
#include "casilla.h"
#define ti t[i]
#define crom SetConsoleTextAttribute(hConsole,
extern HANDLE hConsole;

class Tablero{

public:
Tablero();
    // Acceso a casillas
    const Casilla& getCasilla(int i) const;
    Casilla& getCasilla(int i);
    void mostrar() const;
    void mostrarAmenazas() const;
//    ~Tablero();
private:
    void inicializar(); // posición inicial
    Casilla casillas[65]; // Índices 1..64
};
#endif // TABLERO_H
