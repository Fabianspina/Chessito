#include "movidasposibles.h"
#include "rey.h"
int i;
int movidasposibles(){
	mp = 0;
for (i=1; i<=64; i++){
		if (ti.color == turn) {
			switch (ti.pieza) {
			case 1: pruebemoverrey();     break;
			case 2: pruebemoverdama();    break;
			case 3: pruebemovertorre();   break;
			case 4: pruebemoveralfil();   break;
			case 5: pruebemovercaballo(); break;
			case 6: pruebemoverpeon();    break;
			}
		}
	}
    decir "son posibles: " << mp << " movimientos";pausa;
	return mp;
}
/*=====================================================================================*/
void pruebemoverrey(){
//if (turn == 1){
if (i > 8 && t[i - 8].color != turn){
if (!jaque()) { mp++; decir "\nRey avanza una casilla. Guardar en vector string con una función tipo actualiza, pero sin modificar el tablero"<< endl;}
}
if (i > 8 && t[i - 7].color != turn && t[i].columna <=7){
if (!jaque()) { mp++; decir "\nRey avanza en diagonal derecha arriba"<< endl;
}
}
if (i > 8 && t[i - 9].color != turn && t[i].columna >= 2){
if (!jaque()) { mp++; decir "\nRey avanza en diagonal izquierda arriba"<< endl;
}
}
if (i >= 2 && t[i - 1].color != turn && t[i].columna >= 2){
if (!jaque()) { mp++; decir "\nRey se corre a la izquierda"<< endl;
}
}
if (t[i + 1].color != turn && t[i].columna <= 7){
if (!jaque()) { mp++; decir "\nRey se corre a la derecha"<< endl;
}
}
if (i < 57 && t[i + 8].color != turn){
if (!jaque()) { mp++; decir "\nRey atrás una casilla"<< endl;
}
}
if (t[i + 7].color != turn && t[i].fila >= 2 && t[i].columna >= 2){
if (!jaque()) { mp++; decir "\nRey atrás a la izquierda"<< endl;
}
}
if ( t[i + 9].color != turn && t[i].fila >= 2 && t[i].columna <= 7){
if (!jaque()) { mp++; decir "\nRey atrás a la derecha"<< endl;
}
}
if(rey[1].rmb == 0 && t[i + 1].pieza == 0 && t[i+2].pieza == 0 && t[i+3].pieza == 3
&& t[i].tocan == 0 && t[i+1].tocan == 0 && t[i+2].tocan == 0){ mp++; decir "\nRey puede enrocar corto"<< endl;
}
if(rey[1].rmb == 0 && t[i - 1].pieza == 0 && t[i-2].pieza == 0 && t[i-3].pieza == 0 && t[i-4].pieza == 3
&& t[i].tocan == 0 && t[i-1].tocan == 0 && t[i-2].tocan == 0){ mp++; decir "\nRey puede enrocar largo"<< endl;
}
if(rey[1].rmn == 0 && t[i + 1].pieza == 0 && t[i + 2].pieza == 0 && t[i + 3].pieza == 3
&& t[i].tocab == 0 && t[i + 1].tocab == 0 && t[i + 2].tocab == 0){ mp++; decir "\nRey puede enrocar corto"<< endl;
}
if(rey[1].rmn == 0 && t[i - 1].pieza == 0 && t[i - 2].pieza == 0 && t[i - 3].pieza == 0 && t[i-4].pieza == 3
&& t[i].tocab == 0 && t[i - 1].tocab == 0 && t[i - 2].tocab == 0){ mp++; decir "\nRey puede enrocar largo"<< endl;
}
}
/*=====================================================================================*/

void pruebemoverdama(){
if (i >= 9 && t[i - 8].color != turn ) {mp++;decir "dama avanza una casilla "<<endl;}
if (i >= 17 && t[i - 8].color == 0 && t[i - 16].color != turn ) {mp++; decir "dama avanza dos casillas"<<endl;}
if (i >= 25 && t[i - 8].color == 0 && t[i - 16].color == 0 && t[i - 24].color != turn ) {mp++;decir "y avanza tres casillas"<<endl;}
if (i >= 33 && t[i - 8].color == 0 && t[i - 16].color == 0 && t[i - 24].color == 0 && t[i - 32].color != turn) {mp++;decir "dama avanza cuatro casilla"<<endl;}
if (i >= 41 && t[i - 8].color == 0 && t[i - 16].color == 0 && t[i - 24].color == 0 && t[i - 32].color == 0 && t[i - 40].color != turn ){mp++;decir "dama avanza la quinta casilla"<<endl;}
if (i >= 49 && t[i - 8].color == 0 && t[i - 16].color == 0 && t[i - 24].color == 0 && t[i - 32].color == 0 && t[i - 40].color == 0 && t[i - 48].color != turn ){mp++; decir " avanza seicasilla"<<endl;}
if (i >= 57 && t[i - 8].color == 0 && t[i - 16].color == 0 && t[i - 24].color == 0 && t[i - 32].color == 0 && t[i - 40].color == 0 && t[i - 48].color == 0 && t[i - 56].color != turn ){mp++; decir " y sietcasil"<<endl;}

if (i <= 56 && t[i + 8].color != turn ) {mp++; decir "y una patrás"<<endl;}
if (i <= 48 && t[i + 8].color == 0 && t[i + 16].color != turn ){mp++; decir "y dos patrás"<<endl;}
if (i <= 40 && t[i + 8].color == 0 && t[i + 16].color == 0 && t[i + 24].color != turn ){mp++; decir "tre patrá"<<endl;}
if (i <= 32 && t[i + 8].color == 0 && t[i + 16].color == 0 && t[i + 24].color == 0 && t[i + 32].color != turn ) {mp++;decir "atrasa cuatro"<< endl;}
if (i <= 24 && t[i + 8].color == 0 && t[i + 16].color == 0 && t[i + 24].color == 0 && t[i + 32].color == 0 && t[i + 40].color != turn ){mp++; decir "atrasinco"<< endl;}
if (i <= 16 && t[i + 8].color == 0 && t[i + 16].color == 0 && t[i + 24].color == 0 && t[i + 32].color == 0 && t[i + 40].color == 0 && t[i + 48].color != turn ){mp++; decir "atra sei"<< endl;}
if (i <= 8 && t[i + 8].color == 0 && t[i + 16].color == 0 && t[i + 24].color == 0 && t[i + 32].color == 0 && t[i + 40].color == 0 && t[i + 48].color == 0 && t[i + 56].color != turn ){mp++; decir "too pa trá 7"<< endl;}

if (t[i + 1].color != turn && t[i].columna <= 7) {mp++; decir "der 1"<<endl;}
if (t[i + 1].color == 0 && t[i + 2].color != turn && t[i].columna <= 6){mp++; decir "der 2"<<endl;}
if (t[i + 1].color == 0 && t[i + 2].color == 0 && t[i + 3].color != turn && t[i].columna <= 5){mp++; decir "der 3"<<endl;}
if (t[i + 1].color == 0 && t[i + 2].color == 0 && t[i + 3].color == 0 && t[i + 4].color != turn && t[i].columna <= 4){mp++; decir "der 4"<<endl;}
if (t[i + 1].color == 0 && t[i + 2].color == 0 && t[i + 3].color == 0 && t[i + 4].color == 0 && t[i + 5].color != turn && t[i].columna <= 3){mp++; decir "der 5"<<endl;}
if (t[i + 1].color == 0 && t[i + 2].color == 0 && t[i + 3].color == 0 && t[i + 4].color == 0 && t[i + 5].color == 0 && t[i + 6].color != turn && t[i].columna <= 2){mp++; decir "der 6"<<endl;}
if (t[i + 1].color == 0 && t[i + 2].color == 0 && t[i + 3].color == 0 && t[i + 4].color == 0 && t[i + 5].color == 0 && t[i + 6].color == 0 && t[i + 7].color != turn && t[i].columna <= 1){mp++; decir "der 7"<<endl;}

if (t[i - 1].color != turn && t[i].columna >= 2){mp++; decir "izq 1"<<endl;}
if (t[i - 1].color == 0 && t[i - 2].color != turn && t[i].columna >= 3){mp++; decir "izq 2"<<endl;}
if (t[i - 1].color == 0 && t[i - 2].color == 0 && t[i - 3].color != turn && t[i].columna >= 4){mp++; decir "izq 3"<<endl;}
if (t[i - 1].color == 0 && t[i - 2].color == 0 && t[i - 3].color == 0 && t[i - 4].color != turn && t[i].columna >= 5){mp++; decir "izq 4"<<endl;}
if (t[i - 1].color == 0 && t[i - 2].color == 0 && t[i - 3].color == 0 && t[i - 4].color == 0 && t[i - 5].color != turn && t[i].columna >= 6){mp++; decir "izq 5"<<endl;}
if (t[i - 1].color == 0 && t[i - 2].color == 0 && t[i - 3].color == 0 && t[i - 4].color == 0 && t[i - 5].color == 0 && t[i - 6].color != turn && t[i].columna >= 7){mp++; decir "izq 6"<<endl;}
if (t[i - 1].color == 0 && t[i - 2].color == 0 && t[i - 3].color == 0 && t[i - 4].color == 0 && t[i - 5].color == 0 && t[i - 6].color == 0 && t[i - 7].color != turn && t[i].columna >= 8){mp++; decir "izq 7"<<endl;}

if (t[i - 7].color != turn && t[i].columna <= 7 && t[i].fila <= 7) {mp++; decir "diag arr der 1"<<endl;}
if (t[i - 7].color == 0 && t[i - 14].color != turn && t[i].columna <= 6 && t[i].fila <= 6){mp++; decir "diag arr der 2"<<endl;}
if (t[i - 7].color == 0 && t[i - 14].color == 0 && t[i - 21].color != turn && t[i].columna <= 5 && t[i].fila <= 5){mp++; decir "diag arr der 3"<<endl;}
if (t[i - 7].color == 0 && t[i - 14].color == 0 && t[i - 21].color == 0 && t[i - 28].color != turn && t[i].columna <= 4 && t[i].fila <= 4){mp++; decir "diag arr der 4"<<endl;}
if (t[i - 7].color == 0 && t[i - 14].color == 0 && t[i - 21].color == 0 && t[i - 28].color == 0 && t[i - 35].color != turn && t[i].columna <= 3 && t[i].fila <= 3){mp++; decir "diag arr der 5"<<endl;}
if (t[i - 7].color == 0 && t[i - 14].color == 0 && t[i - 21].color == 0 && t[i - 28].color == 0 && t[i - 35].color == 0 && t[i - 42].color != turn && t[i].columna <= 2 && t[i].fila <= 2){mp++; decir "diag arr der 6"<<endl;}
if (t[i - 7].color == 0 && t[i - 14].color == 0 && t[i - 21].color == 0 && t[i - 28].color == 0 && t[i - 35].color == 0 && t[i - 42].color == 0 && t[i - 49].color != turn && t[i].columna == 1 && t[i].fila == 1){mp++; decir "diag arr der 7"<<endl;}
if (t[i - 9].color != turn && t[i].columna >= 2 && t[i].fila <= 7) {mp++; decir "diag arr izq 1"<<endl;}
if (t[i - 9].color == 0 && t[i - 18].color != turn && t[i].columna >= 3 && t[i].fila <= 6){mp++; decir "diag arr izq 2"<<endl;}
if (t[i - 9].color == 0 && t[i - 18].color == 0 && t[i - 27].color != turn && t[i].columna >= 4 && t[i].fila <= 5){mp++; decir "diag arr izq 3"<<endl;}
if (t[i - 9].color == 0 && t[i - 18].color == 0 && t[i - 27].color == 0 && t[i - 36].color != turn && t[i].columna >= 5 && t[i].fila <= 4){mp++; decir "diag arr izq 4"<<endl;}
if (t[i - 9].color == 0 && t[i - 18].color == 0 && t[i - 27].color == 0 && t[i - 36].color == 0 && t[i - 45].color != turn && t[i].columna >= 6 && t[i].fila <= 3){mp++; decir "diag arr izq 5"<<endl;}
if (t[i - 9].color == 0 && t[i - 18].color == 0 && t[i - 27].color == 0 && t[i - 36].color == 0 && t[i - 45].color == 0 && t[i - 54].color != turn && t[i].columna >= 7 && t[i].fila <= 2){mp++; decir "diag arr izq 6"<<endl;}
if (t[i - 9].color == 0 && t[i - 18].color == 0 && t[i - 27].color == 0 && t[i - 36].color == 0 && t[i - 45].color == 0 && t[i - 54].color == 0 && t[i - 63].color != turn && t[i].columna >= 8 && t[i].fila <= 1){mp++; decir "diag arr izq 7"<<endl;}
if (t[i + 7].color != turn && t[i].columna >= 2 && t[i].fila >= 2) {mp++; decir "diag ab izq 1"<<endl;}
if (t[i + 7].color == 0 && t[i + 14].color != turn && t[i].columna >= 3 && t[i].fila >= 3){mp++; decir "diag ab izq 2"<<endl;}
if (t[i + 7].color == 0 && t[i + 14].color == 0 && t[i + 21].color != turn && t[i].columna >= 4 && t[i].fila >= 4){mp++; decir "diag ab izq 3"<<endl;}
if (t[i + 7].color == 0 && t[i + 14].color == 0 && t[i + 21].color == 0 && t[i + 28].color != turn && t[i].columna >= 5 && t[i].fila >= 5){mp++; decir "diag ab izq 4"<<endl;}
if (t[i + 7].color == 0 && t[i + 14].color == 0 && t[i + 21].color == 0 && t[i + 28].color == 0 && t[i + 35].color != turn && t[i].columna >= 6 && t[i].fila >= 6){mp++; decir "diag ab izq 5"<<endl;}
if (t[i + 7].color == 0 && t[i + 14].color == 0 && t[i + 21].color == 0 && t[i + 28].color == 0 && t[i + 35].color == 0 && t[i + 42].color != turn && t[i].columna >= 7 && t[i].fila >= 7){mp++; decir "diag ab izq 6"<<endl;}
if (t[i + 7].color == 0 && t[i + 14].color == 0 && t[i + 21].color == 0 && t[i + 28].color == 0 && t[i + 35].color == 0 && t[i + 42].color == 0 && t[i + 49].color != turn && t[i].columna >= 8 && t[i].fila >= 8){mp++; decir "diag ab izq 7"<<endl;}
if (t[i + 9].color != turn && t[i].fila >= 2 && t[i].columna <= 7) {mp++; decir "diag ab der 1"<<endl;}
if (t[i + 9].color == 0 && t[i + 18].color != turn && t[i].fila >= 3 && t[i].columna <= 6){mp++; decir "diag ab der 2"<<endl;}
if (t[i + 9].color == 0 && t[i + 18].color == 0 && t[i + 27].color != turn && t[i].fila >= 4 && t[i].columna <= 5){mp++; decir "diag ab der 3"<<endl;}
if (t[i + 9].color == 0 && t[i + 18].color == 0 && t[i + 27].color == 0 && t[i + 36].color != turn && t[i].fila >= 5 && t[i].columna <= 4) {mp++; decir "diag ab der 4"<<endl;}
if (t[i + 9].color == 0 && t[i + 18].color == 0 && t[i + 27].color == 0 && t[i + 36].color == 0 && t[i + 45].color != turn && t[i].fila >= 6 && t[i].columna <= 3){mp++; decir "diag ab der 5"<<endl;}
if (t[i + 9].color == 0 && t[i + 18].color == 0 && t[i + 27].color == 0 && t[i + 36].color == 0 && t[i + 45].color == 0 && t[i + 54].color != turn && t[i].fila >= 7 && t[i].columna <= 2){mp++; decir "diag ab der 6"<<endl;}
if (t[i + 9].color == 0 && t[i + 18].color == 0 && t[i + 27].color == 0 && t[i + 36].color == 0 && t[i + 45].color == 0 && t[i + 54].color == 0 && t[i + 63].color != turn && t[i].fila >= 8 && t[i].columna <= 1){mp++; decir "diag ab der 7"<<endl;}
}

void pruebemoverpeon() { //falta captura al paso
if (turn == 1) {
if (i >= 9 && t[i - 8].pieza == 0) mp++;
if (t[i - 16].pieza == 0 && t[i - 8].pieza == 0 && t[i].fila == 2) mp++;
if (t[i - 9].color == 2) mp++;
if (t[i - 7].color == 2) mp++;
}
if (turn == 2) {
if (i <=56 && t[i + 8].pieza == 0) mp++;
if (t[i + 16].pieza == 0 && t[i + 8].pieza == 0 && t[i].fila == 7) mp++;
if (t[i + 9].color == 1) mp++;
if (t[i + 7].color == 1) mp++;
}
}

void pruebemovercaballo() {
switch (ti.columna) {
case 1:
if (t[i].fila == 1 && t[i - 6].color != turn)      { mp++; } //\/
if (t[i].fila == 1 && t[i - 15].color != turn)     { mp++; } //\/
if (t[i].fila == 2 && t[i + 10].color != turn)     { mp++; } //\/
if (t[i].fila == 2 && t[i - 6].color != 1)         { mp++; } //\/
if (t[i].fila == 2 && t[i - 15].color != 1)        { mp++; } //\/
if (t[i].fila == 3 && t[i + 17].color != turn)     { mp++; } //\/
if (t[i].fila == 3 && t[i + 10].color != turn)     { mp++; } //\/
if (t[i].fila == 3 && t[i - 6].color != turn)      { mp++; } //\/
if (t[i].fila == 3 && t[i - 15].color != turn)     { mp++; } //\/
if (t[i].fila == 4 && t[i + 17].color != turn)     { mp++; } //\/
if (t[i].fila == 4 && t[i + 10].color != turn)     { mp++; } //\/
if (t[i].fila == 4 && t[i - 6].color != turn)      { mp++; } //\/
if (t[i].fila == 4 && t[i - 15].color != turn)     { mp++; } //\/
if (t[i].fila == 5 && t[i + 17].color != turn)     { mp++; } //\/
if (t[i].fila == 5 && t[i + 10].color != turn)     { mp++; } //\/
if (t[i].fila == 5 && t[i - 6].color != turn)      { mp++; } //\/
if (t[i].fila == 5 && t[i - 15].color != turn)     { mp++; } //\/
if (t[i].fila == 6 && t[i + 17].color != turn)     { mp++; } //\/
if (t[i].fila == 6 && t[i + 10].color != turn)     { mp++; } //\/
if (t[i].fila == 6 && t[i - 6].color != turn)      { mp++; } //\/
if (t[i].fila == 6 && t[i - 15].color != turn)     { mp++; } //\/
if (t[i].fila == 7 && t[i + 17].color != turn)     { mp++; } //\/
if (t[i].fila == 7 && t[i + 10].color != 1)        { mp++; } //\/
if (t[i].fila == 7 && t[i - 6].color != 1)         { mp++; } //\/
if (t[i].fila == 8 && t[i + 17].color != turn)     { mp++; } //\/
if (t[i].fila == 8 && t[i + 10].color != turn)     { mp++; } //\/
break;
case 2:
if (t[i].fila == 1 && t[i - 6].color != turn)      { mp++; } //\///\/
if (t[i].fila == 1 && t[i - 15].color != turn)     { mp++; } //\/
if (t[i].fila == 1 && t[i - 17].color == 0)        { mp++; } //\/
if (t[i].fila == 2 && t[i - 6].color != turn)      { mp++; } //\/
if (t[i].fila == 2 && t[i - 15].color != turn)     { mp++; } //\/
if (t[i].fila == 2 && t[i - 17].color == 0)        { mp++; } //\/
if (t[i].fila == 2 && t[i + 10].color != turn)     { mp++; } //\/
if (t[i].fila == 3 && t[i - 6].color != turn)      { mp++; } //\/
if (t[i].fila == 3 && t[i - 15].color != turn)     { mp++; } //\/
if (t[i].fila == 3 && t[i - 17].color == 0)        { mp++; } //\/
if (t[i].fila == 3 && t[i - 10].color != turn)     { mp++; } //\/
if (t[i].fila == 3 && t[i + 15].color != turn)     { mp++; } //\/
if (t[i].fila == 3 && t[i + 17].color != turn)     { mp++; } //\/
if (t[i].fila == 4 && t[i - 6].color != turn)      { mp++; } //\/
if (t[i].fila == 4 && t[i - 15].color != turn)     { mp++; } //\/
if (t[i].fila == 4 && t[i - 17].color == 0)        { mp++; } //\/
if (t[i].fila == 4 && t[i + 10].color != turn)     { mp++; } //\/
if (t[i].fila == 4 && t[i + 15].color != turn)     { mp++; } //\/
if (t[i].fila == 4 && t[i + 17].color != turn)     { mp++; } //\/
if (t[i].fila == 5 && t[i - 6].color != turn)      { mp++; } //\/
if (t[i].fila == 5 && t[i - 15].color != turn)     { mp++; } //\/
if (t[i].fila == 5 && t[i - 17].color == 0)        { mp++; } //\/
if (t[i].fila == 5 && t[i + 10].color != turn)     { mp++; } //\/
if (t[i].fila == 5 && t[i + 15].color != turn)     { mp++; } //\/
if (t[i].fila == 5 && t[i + 17].color != turn)     { mp++; } //\/
if (t[i].fila == 6 && t[i - 6].color != turn)      { mp++; } //\/
if (t[i].fila == 6 && t[i - 15].color != turn)     { mp++; } //\/
if (t[i].fila == 6 && t[i - 17].color == 0)        { mp++; } //\/
if (t[i].fila == 6 && t[i + 10].color != turn)     { mp++; } //\/
if (t[i].fila == 6 && t[i + 15].color != turn)     { mp++; } //\/
if (t[i].fila == 6 && t[i + 17].color != turn)     { mp++; } //\/
if (t[i].fila == 7 && t[i - 6].color != turn)      { mp++; } //\/
if (t[i].fila == 7 && t[i + 15].color != turn)     { mp++; } //\/
if (t[i].fila == 7 && t[i + 17].color == 0)        { mp++; } //\/
if (t[i].fila == 7 && t[i + 10].color != turn)     { mp++; } //\/
if (t[i].fila == 8 && t[i + 15].color != turn)     { mp++; } //\/
if (t[i].fila == 8 && t[i + 17].color != turn)     { mp++; } //\/
if (t[i].fila == 8 && t[i + 10].color != turn)     { mp++; } //\/
break;
case 3:
case 4:
case 5:
case 6:
if (t[i].fila == 1 && t[i - 6].color != turn)      { mp++; } //\/
if (t[i].fila == 1 && t[i - 10].color != turn)     { mp++; } //\/
if (t[i].fila == 1 && t[i - 17].color != turn)     { mp++; } //\/
if (t[i].fila == 1 && t[i - 15].color != turn)     { mp++; } //\/
if (t[i].fila == 2 && t[i - 6].color != turn)      { mp++; } //\/
if (t[i].fila == 2 && t[i - 15].color != turn)     { mp++; } //\/
if (t[i].fila == 2 && t[i - 17].color != turn)     { mp++; } //\/
if (t[i].fila == 2 && t[i - 10].color != turn)     { mp++; } //\/
if (t[i].fila == 2 && t[i + 10].color != turn)     { mp++; } //\/
if (t[i].fila == 2 && t[i + 6].color != turn)      { mp++; } //\/
if (t[i].fila == 3 && t[i - 6].color != turn)      { mp++; } //\/
if (t[i].fila == 3 && t[i - 10].color != turn)     { mp++; } //\/
if (t[i].fila == 3 && t[i - 15].color != turn)     { mp++; } //\/
if (t[i].fila == 3 && t[i - 17].color != turn)     { mp++; } //\/
if (t[i].fila == 3 && t[i + 6].color != turn)      { mp++; } //\/
if (t[i].fila == 3 && t[i + 10].color != turn)     { mp++; } //\/
if (t[i].fila == 3 && t[i + 15].color != turn)     { mp++; } //\/
if (t[i].fila == 3 && t[i + 17].color != turn)     { mp++; } //\/
if (t[i].fila == 4 && t[i - 6].color != turn)      { mp++; } //\/
if (t[i].fila == 4 && t[i - 10].color != turn)     { mp++; } //\/
if (t[i].fila == 4 && t[i - 15].color != turn)     { mp++; } //\/
if (t[i].fila == 4 && t[i - 17].color != turn)     { mp++; } //\/
if (t[i].fila == 4 && t[i + 6].color != turn)      { mp++; } //\/
if (t[i].fila == 4 && t[i + 10].color != turn)     { mp++; } //\/
if (t[i].fila == 4 && t[i + 15].color != turn)     { mp++; } //\/
if (t[i].fila == 4 && t[i + 17].color != turn)     { mp++; } //\/
if (t[i].fila == 5 && t[i - 6].color != turn)      { mp++; } //\/
if (t[i].fila == 5 && t[i - 10].color != turn)     { mp++; } //\/
if (t[i].fila == 5 && t[i - 15].color != turn)     { mp++; } //\/
if (t[i].fila == 5 && t[i - 17].color != turn)     { mp++; } //\/
if (t[i].fila == 5 && t[i + 6].color != turn)      { mp++; } //\/
if (t[i].fila == 5 && t[i + 10].color != turn)     { mp++; } //\/
if (t[i].fila == 5 && t[i + 15].color != turn)     { mp++; } //\/
if (t[i].fila == 5 && t[i + 17].color != turn)     { mp++; } //\/
if (t[i].fila == 6 && t[i - 6].color != turn)      { mp++; } //\/
if (t[i].fila == 6 && t[i - 10].color != turn)     { mp++; } //\/
if (t[i].fila == 6 && t[i - 15].color != turn)     { mp++; } //\/
if (t[i].fila == 6 && t[i - 17].color != turn)     { mp++; } //\/
if (t[i].fila == 6 && t[i + 6].color != turn)      { mp++; } //\/
if (t[i].fila == 6 && t[i + 10].color != turn)     { mp++; } //\/
if (t[i].fila == 6 && t[i + 15].color != turn)     { mp++; } //\/
if (t[i].fila == 6 && t[i + 17].color != turn)     { mp++; } //\/
if (t[i].fila == 7 && t[i - 6].color != turn)      { mp++; } //\/
if (t[i].fila == 7 && t[i - 10].color != turn)     { mp++; } //\/
if (t[i].fila == 7 && t[i + 6].color != turn)      { mp++; } //\/
if (t[i].fila == 7 && t[i + 10].color != turn)     { mp++; } //\/
if (t[i].fila == 7 && t[i + 15].color != turn)     { mp++; } //\/
if (t[i].fila == 7 && t[i + 17].color != turn)     { mp++; } //\/
if (t[i].fila == 8 && t[i + 6].color != turn)      { mp++; } //\/
if (t[i].fila == 8 && t[i + 10].color != turn)     { mp++; } //\/
if (t[i].fila == 8 && t[i + 15].color != turn)     { mp++; } //\/
if (t[i].fila == 8 && t[i + 17].color != turn)     { mp++; } //\/
break;
case 7:
if (ti.fila == 1 && t[i - 10].color != turn)       { mp++; } //\/
if (t[i].fila == 1 && t[i - 15].color != turn)     { mp++; } //\/
if (t[i].fila == 1 && t[i - 17].color != turn)     { mp++; } //\/
if (t[i].fila == 2 && t[i - 10].color != turn)     { mp++; } //\/
if (t[i].fila == 2 && t[i - 15].color != turn)     { mp++; } //\/
if (t[i].fila == 2 && t[i - 17].color != turn)     { mp++; } //\/
if (t[i].fila == 2 && t[i + 6].color != turn)      { mp++; } //\/
if (t[i].fila == 3 && t[i - 10].color != turn)     { mp++; } //\/
if (t[i].fila == 3 && t[i - 15].color != turn)     { mp++; } //\/
if (t[i].fila == 3 && t[i - 17].color != turn)     { mp++; } //\/
if (t[i].fila == 3 && t[i + 6].color != turn)      { mp++; } //\/
if (t[i].fila == 3 && t[i + 15].color != turn)     { mp++; } //\/
if (t[i].fila == 3 && t[i + 17].color != turn)     { mp++; } //\/
if (t[i].fila == 4 && t[i - 10].color != turn)     { mp++; } //\/
if (t[i].fila == 4 && t[i - 15].color != turn)     { mp++; } //\/
if (t[i].fila == 4 && t[i - 17].color != turn)     { mp++; } //\/
if (t[i].fila == 4 && t[i + 6].color != turn)      { mp++; } //\/
if (t[i].fila == 4 && t[i + 15].color != turn)     { mp++; } //\/
if (t[i].fila == 4 && t[i + 17].color != turn)     { mp++; } //\/
if (t[i].fila == 5 && t[i - 10].color != turn)     { mp++; } //\/
if (t[i].fila == 5 && t[i - 15].color != turn)     { mp++; } //\/
if (t[i].fila == 5 && t[i - 17].color != turn)     { mp++; } //\/
if (t[i].fila == 5 && t[i + 6].color != turn)      { mp++; } //\/
if (t[i].fila == 5 && t[i + 15].color != turn)     { mp++; } //\/
if (t[i].fila == 5 && t[i + 17].color != turn)     { mp++; } //\/
if (t[i].fila == 6 && t[i - 10].color != turn)     { mp++; } //\/
if (t[i].fila == 6 && t[i - 15].color != turn)     { mp++; } //\/
if (t[i].fila == 6 && t[i - 17].color != turn)     { mp++; } //\/
if (t[i].fila == 6 && t[i + 6].color != turn)      { mp++; } //\/
if (t[i].fila == 6 && t[i + 15].color != turn)     { mp++; } //\/
if (t[i].fila == 6 && t[i + 17].color != turn)     { mp++; } //\/
if (t[i].fila == 7 && t[i + 6].color != turn)      { mp++; } //\/
if (t[i].fila == 7 && t[i + 15].color != turn)     { mp++; } //\/
if (t[i].fila == 7 && t[i + 17].color != turn)     { mp++; } //\/
if (t[i].fila == 7 && t[i - 10].color != turn)     { mp++; } //\/
if (t[i].fila == 8 && t[i + 15].color != turn)     { mp++; } //\/
if (t[i].fila == 8 && t[i + 17].color != turn)     { mp++; } //\/
if (t[i].fila == 8 && t[i + 6].color != turn)      { mp++; } //\/
break;
case 8:
if (t[i].fila == 1 && t[i - 10].color != turn)     { mp++; } //\/
if (t[i].fila == 1 && t[i - 17].color != turn)     { mp++; } //\/
if (t[i].fila == 2 && t[i - 10].color != turn)     { mp++; } //\/
if (t[i].fila == 2 && t[i - 17].color != turn)     { mp++; } //\/
if (t[i].fila == 2 && t[i + 6].color != turn)      { mp++; } //\/
if (t[i].fila == 3 && t[i - 10].color != turn)     { mp++; } //\/
if (t[i].fila == 3 && t[i - 17].color != turn)     { mp++; } //\/
if (t[i].fila == 3 && t[i + 6].color != turn)      { mp++; } //\/
if (t[i].fila == 3 && t[i + 15].color != turn)     { mp++; } //\/
if (t[i].fila == 4 && t[i - 10].color != turn)     { mp++; } //\/
if (t[i].fila == 4 && t[i - 17].color != turn)     { mp++; } //\/
if (t[i].fila == 4 && t[i + 6].color != turn)      { mp++; } //\/
if (t[i].fila == 4 && t[i + 15].color != turn)     { mp++; } //\/
if (t[i].fila == 5 && t[i - 10].color != turn)     { mp++; } //\/
if (t[i].fila == 5 && t[i - 17].color != turn)     { mp++; } //\/
if (t[i].fila == 5 && t[i + 6].color != turn)      { mp++; } //\/
if (t[i].fila == 5 && t[i + 15].color != turn)     { mp++; } //\/
if (t[i].fila == 6 && t[i - 10].color != turn)     { mp++; } //\/
if (t[i].fila == 6 && t[i - 17].color != turn)     { mp++; } //\/
if (t[i].fila == 6 && t[i + 6].color != turn)      { mp++; } //\/
if (t[i].fila == 6 && t[i + 15].color != turn)     { mp++; } //\/
if (t[i].fila == 7 && t[i - 10].color != turn)     { mp++; } //\/
if (t[i].fila == 7 && t[i + 15].color != turn)     { mp++; } //\/
if (t[i].fila == 7 && t[i + 6].color != turn)      { mp++; } //\/
if (t[i].fila == 8 && t[i + 15].color != turn)     { mp++; } //\/
if (t[i].fila == 8 && t[i + 6].color != turn)        { mp++; } //\/

break;
}
}

/****************************************************/
void pruebemovertorre() {
if (i >= 9 && t[i - 8].color != turn ) {mp++;decir "torre avanza una casilla "<<endl;}
if (i >= 17 && t[i - 8].color == 0 && t[i - 16].color != turn ) {mp++; decir "torre avanza dos casillas"<<endl;}
if (i >= 25 && t[i - 8].color == 0 && t[i - 16].color == 0 && t[i - 24].color != turn ) {mp++;decir "y avanza tres casillas"<<endl;}
if (i >= 33 && t[i - 8].color == 0 && t[i - 16].color == 0 && t[i - 24].color == 0 && t[i - 32].color != turn) {mp++;decir "torre avanza cuatro casilla"<<endl;}
if (i >= 41 && t[i - 8].color == 0 && t[i - 16].color == 0 && t[i - 24].color == 0 && t[i - 32].color == 0 && t[i - 40].color != turn ){mp++;decir "torre avanza la quinta casilla"<<endl;}
if (i >= 49 && t[i - 8].color == 0 && t[i - 16].color == 0 && t[i - 24].color == 0 && t[i - 32].color == 0 && t[i - 40].color == 0 && t[i - 48].color != turn ){mp++; decir " avanza seicasilla"<<endl;}
if (i >= 57 && t[i - 8].color == 0 && t[i - 16].color == 0 && t[i - 24].color == 0 && t[i - 32].color == 0 && t[i - 40].color == 0 && t[i - 48].color == 0 && t[i - 56].color != turn ){mp++; decir " y sietcasil"<<endl;}

if (i <= 56 && t[i + 8].color != turn ) {mp++; decir "y una patrás"<<endl;}
if (i <= 48 && t[i + 8].color == 0 && t[i + 16].color != turn ){mp++; decir "y dos patrás"<<endl;}
if (i <= 40 && t[i + 8].color == 0 && t[i + 16].color == 0 && t[i + 24].color != turn ){mp++; decir "tre patrá"<<endl;}
if (i <= 32 && t[i + 8].color == 0 && t[i + 16].color == 0 && t[i + 24].color == 0 && t[i + 32].color != turn ) {mp++;decir "atrasa cuatro"<< endl;}
if (i <= 24 && t[i + 8].color == 0 && t[i + 16].color == 0 && t[i + 24].color == 0 && t[i + 32].color == 0 && t[i + 40].color != turn ){mp++; decir "atrasinco"<< endl;}
if (i <= 16 && t[i + 8].color == 0 && t[i + 16].color == 0 && t[i + 24].color == 0 && t[i + 32].color == 0 && t[i + 40].color == 0 && t[i + 48].color != turn ){mp++; decir "atra sei"<< endl;}
if (i <= 8 && t[i + 8].color == 0 && t[i + 16].color == 0 && t[i + 24].color == 0 && t[i + 32].color == 0 && t[i + 40].color == 0 && t[i + 48].color == 0 && t[i + 56].color != turn ){mp++; decir "too pa trá 7"<< endl;}

if (t[i + 1].color != turn && t[i].columna <= 7) {mp++; decir "der 1"<<endl;}
if (t[i + 1].color == 0 && t[i + 2].color != turn && t[i].columna <= 6){mp++; decir "der 2"<<endl;}
if (t[i + 1].color == 0 && t[i + 2].color == 0 && t[i + 3].color != turn && t[i].columna <= 5){mp++; decir "der 3"<<endl;}
if (t[i + 1].color == 0 && t[i + 2].color == 0 && t[i + 3].color == 0 && t[i + 4].color != turn && t[i].columna <= 4){mp++; decir "der 4"<<endl;}
if (t[i + 1].color == 0 && t[i + 2].color == 0 && t[i + 3].color == 0 && t[i + 4].color == 0 && t[i + 5].color != turn && t[i].columna <= 3){mp++; decir "der 5"<<endl;}
if (t[i + 1].color == 0 && t[i + 2].color == 0 && t[i + 3].color == 0 && t[i + 4].color == 0 && t[i + 5].color == 0 && t[i + 6].color != turn && t[i].columna <= 2){mp++; decir "der 6"<<endl;}
if (t[i + 1].color == 0 && t[i + 2].color == 0 && t[i + 3].color == 0 && t[i + 4].color == 0 && t[i + 5].color == 0 && t[i + 6].color == 0 && t[i + 7].color != turn && t[i].columna <= 1){mp++; decir "der 7"<<endl;}

if (t[i - 1].color != turn && t[i].columna >= 2){mp++; decir "izq 1"<<endl;}
if (t[i - 1].color == 0 && t[i - 2].color != turn && t[i].columna >= 3){mp++; decir "izq 2"<<endl;}
if (t[i - 1].color == 0 && t[i - 2].color == 0 && t[i - 3].color != turn && t[i].columna >= 4){mp++; decir "izq 3"<<endl;}
if (t[i - 1].color == 0 && t[i - 2].color == 0 && t[i - 3].color == 0 && t[i - 4].color != turn && t[i].columna >= 5){mp++; decir "izq 4"<<endl;}
if (t[i - 1].color == 0 && t[i - 2].color == 0 && t[i - 3].color == 0 && t[i - 4].color == 0 && t[i - 5].color != turn && t[i].columna >= 6){mp++; decir "izq 5"<<endl;}
if (t[i - 1].color == 0 && t[i - 2].color == 0 && t[i - 3].color == 0 && t[i - 4].color == 0 && t[i - 5].color == 0 && t[i - 6].color != turn && t[i].columna >= 7){mp++; decir "izq 6"<<endl;}
if (t[i - 1].color == 0 && t[i - 2].color == 0 && t[i - 3].color == 0 && t[i - 4].color == 0 && t[i - 5].color == 0 && t[i - 6].color == 0 && t[i - 7].color != turn && t[i].columna >= 8){mp++; decir "izq 7"<<endl;}
}
/***************************************************/
void pruebemoveralfil() {
if (t[i - 7].color != turn && t[i].columna <= 7 && t[i].fila <= 7) {mp++; decir "diag arr der 1"<<endl;}
if (t[i - 7].color == 0 && t[i - 14].color != turn && t[i].columna <= 6 && t[i].fila <= 6){mp++; decir "diag arr der 2"<<endl;}
if (t[i - 7].color == 0 && t[i - 14].color == 0 && t[i - 21].color != turn && t[i].columna <= 5 && t[i].fila <= 5){mp++; decir "diag arr der 3"<<endl;}
if (t[i - 7].color == 0 && t[i - 14].color == 0 && t[i - 21].color == 0 && t[i - 28].color != turn && t[i].columna <= 4 && t[i].fila <= 4){mp++; decir "diag arr der 4"<<endl;}
if (t[i - 7].color == 0 && t[i - 14].color == 0 && t[i - 21].color == 0 && t[i - 28].color == 0 && t[i - 35].color != turn && t[i].columna <= 3 && t[i].fila <= 3){mp++; decir "diag arr der 5"<<endl;}
if (t[i - 7].color == 0 && t[i - 14].color == 0 && t[i - 21].color == 0 && t[i - 28].color == 0 && t[i - 35].color == 0 && t[i - 42].color != turn && t[i].columna <= 2 && t[i].fila <= 2){mp++; decir "diag arr der 6"<<endl;}
if (t[i - 7].color == 0 && t[i - 14].color == 0 && t[i - 21].color == 0 && t[i - 28].color == 0 && t[i - 35].color == 0 && t[i - 42].color == 0 && t[i - 49].color != turn && t[i].columna == 1 && t[i].fila == 1){mp++; decir "diag arr der 7"<<endl;}
if (t[i - 9].color != turn && t[i].columna >= 2 && t[i].fila <= 7) {mp++; decir "diag arr izq 1"<<endl;}
if (t[i - 9].color == 0 && t[i - 18].color != turn && t[i].columna >= 3 && t[i].fila <= 6){mp++; decir "diag arr izq 2"<<endl;}
if (t[i - 9].color == 0 && t[i - 18].color == 0 && t[i - 27].color != turn && t[i].columna >= 4 && t[i].fila <= 5){mp++; decir "diag arr izq 3"<<endl;}
if (t[i - 9].color == 0 && t[i - 18].color == 0 && t[i - 27].color == 0 && t[i - 36].color != turn && t[i].columna >= 5 && t[i].fila <= 4){mp++; decir "diag arr izq 4"<<endl;}
if (t[i - 9].color == 0 && t[i - 18].color == 0 && t[i - 27].color == 0 && t[i - 36].color == 0 && t[i - 45].color != turn && t[i].columna >= 6 && t[i].fila <= 3){mp++; decir "diag arr izq 5"<<endl;}
if (t[i - 9].color == 0 && t[i - 18].color == 0 && t[i - 27].color == 0 && t[i - 36].color == 0 && t[i - 45].color == 0 && t[i - 54].color != turn && t[i].columna >= 7 && t[i].fila <= 2){mp++; decir "diag arr izq 6"<<endl;}
if (t[i - 9].color == 0 && t[i - 18].color == 0 && t[i - 27].color == 0 && t[i - 36].color == 0 && t[i - 45].color == 0 && t[i - 54].color == 0 && t[i - 63].color != turn && t[i].columna >= 8 && t[i].fila <= 1){mp++; decir "diag arr izq 7"<<endl;}
if (t[i + 7].color != turn && t[i].columna >= 2 && t[i].fila >= 2) {mp++; decir "diag ab izq 1"<<endl;}
if (t[i + 7].color == 0 && t[i + 14].color != turn && t[i].columna >= 3 && t[i].fila >= 3){mp++; decir "diag ab izq 2"<<endl;}
if (t[i + 7].color == 0 && t[i + 14].color == 0 && t[i + 21].color != turn && t[i].columna >= 4 && t[i].fila >= 4){mp++; decir "diag ab izq 3"<<endl;}
if (t[i + 7].color == 0 && t[i + 14].color == 0 && t[i + 21].color == 0 && t[i + 28].color != turn && t[i].columna >= 5 && t[i].fila >= 5){mp++; decir "diag ab izq 4"<<endl;}
if (t[i + 7].color == 0 && t[i + 14].color == 0 && t[i + 21].color == 0 && t[i + 28].color == 0 && t[i + 35].color != turn && t[i].columna >= 6 && t[i].fila >= 6){mp++; decir "diag ab izq 5"<<endl;}
if (t[i + 7].color == 0 && t[i + 14].color == 0 && t[i + 21].color == 0 && t[i + 28].color == 0 && t[i + 35].color == 0 && t[i + 42].color != turn && t[i].columna >= 7 && t[i].fila >= 7){mp++; decir "diag ab izq 6"<<endl;}
if (t[i + 7].color == 0 && t[i + 14].color == 0 && t[i + 21].color == 0 && t[i + 28].color == 0 && t[i + 35].color == 0 && t[i + 42].color == 0 && t[i + 49].color != turn && t[i].columna >= 8 && t[i].fila >= 8){mp++; decir "diag ab izq 7"<<endl;}
if (t[i + 9].color != turn && t[i].fila >= 2 && t[i].columna <= 7) {mp++; decir "diag ab der 1"<<endl;}
if (t[i + 9].color == 0 && t[i + 18].color != turn && t[i].fila >= 3 && t[i].columna <= 6){mp++; decir "diag ab der 2"<<endl;}
if (t[i + 9].color == 0 && t[i + 18].color == 0 && t[i + 27].color != turn && t[i].fila >= 4 && t[i].columna <= 5){mp++; decir "diag ab der 3"<<endl;}
if (t[i + 9].color == 0 && t[i + 18].color == 0 && t[i + 27].color == 0 && t[i + 36].color != turn && t[i].fila >= 5 && t[i].columna <= 4) {mp++; decir "diag ab der 4"<<endl;}
if (t[i + 9].color == 0 && t[i + 18].color == 0 && t[i + 27].color == 0 && t[i + 36].color == 0 && t[i + 45].color != turn && t[i].fila >= 6 && t[i].columna <= 3){mp++; decir "diag ab der 5"<<endl;}
if (t[i + 9].color == 0 && t[i + 18].color == 0 && t[i + 27].color == 0 && t[i + 36].color == 0 && t[i + 45].color == 0 && t[i + 54].color != turn && t[i].fila >= 7 && t[i].columna <= 2){mp++; decir "diag ab der 6"<<endl;}
if (t[i + 9].color == 0 && t[i + 18].color == 0 && t[i + 27].color == 0 && t[i + 36].color == 0 && t[i + 45].color == 0 && t[i + 54].color == 0 && t[i + 63].color != turn && t[i].fila >= 8 && t[i].columna <= 1){mp++; decir "diag ab der 7"<<endl;}
}

