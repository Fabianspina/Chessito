#ifndef REY_H
#define REY_H
#include <iostream>
using namespace std;
#include "convierte.h"
#include "tc.h"
#define decir cout <<
#define decirnt cout << "\n\t"
#define rojo system("color 4F")
#define bucle (int i=1;i<=64;i++)
#define ti t[i]
bool jaquemate(int casilladelrey);
void actualiza();
void borrapeon2();
void conviertedestino();
void convierteorigen();
void eligepieza();
void enroquecorto();
void enroquelargo();
void validadama();
void validarey();
void pruebemoverrey();
void resolverjaque();
void validarey();
void validadama();
void validaalfil();
void validatorre();
void validacaballo();
void validapeon();
void vt();
void vtaux();
extern int rodearey[8];
extern int turn;
extern char cas[2];
extern char casdes[2];
extern short int mp;
typedef struct {
    short int col;
    short int fil;
    short int colr;
    short int ab;
    short int an;
    short int rmb;
    short int rmn;
}reyes;
extern char *b;
extern char *d;
extern reyes rey[3];

#endif // REY_H
