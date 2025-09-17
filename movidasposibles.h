#ifndef MP_H_
#define MP_H_
#include <iostream>
using namespace std;
#include "tc.h"
#include "turno.h"
#define decir cout <<
#define ti t[i]
#define pausa system("pause >> misc/null")
extern short int mp;
short int mpr;
bool jaque();
void pruebemoveralfil();
void pruebemovercaballo();
void pruebemoverdama();
void pruebemovertorre();
void pruebemoverrey();
void pruebemoverpeon();
void vt();
#endif // MP_H
