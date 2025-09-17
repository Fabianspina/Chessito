#ifndef INPUT_H
#define INPUT_H
#include "tc.h"
#define decir cout <<
#define decirnt cout << "\n\t"
#define pausa system("pause >> misc/null")
#include "misc/elo.h"

void destino();
void conviertedestino();
void convierteorigen();
void eligepieza();
void validaalfil();
void validacaballo();
void validadama();
void validarey();
void validatorre();
bool jaque();
bool origen();
void beep();
void resolverjaque();
void validapeon();
extern string origin;
extern string destiny;
extern char cas[2];
extern char casdes[2];
extern char *b;
extern char *d;
#endif // INPUT_H
