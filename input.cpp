#include <algorithm>
#include <iostream>
using namespace std;
#include "convierte.h"
#include "input.h"
#include "turno.h"

bool mover(string& origen, string& destino) {
    string linea;
    decir "Tu jugada: ";
    getline(cin, linea);
    if (linea.empty()) return false;
    // Eliminar espacios extra
    linea.erase(remove_if(linea.begin(), linea.end(), ::isspace), linea.end());
    if (linea.length() < 4) {
    decir "Formato invalido. Debe ser algo como 'e2e4' o 'e2 e4'\n";
    return false;
}
    origin = linea.substr(0, 2);
    destiny = linea.substr(2, 2);
 return true;
}

void eligepieza(){
	decirnt "Su jugada che: ";
	b = &cas[0];
	cin >> b;
	d = &casdes[0];
	cin >> d;
    convierteorigen();
    conviertedestino();
    origen();
}

bool origen(){
        if ((turn == 1 && t[ori].color == 1) || (turn == 2 && t[ori].color == 2)) {
        destino();
	}
	else {
    decir "devolviendo false ori= " << ori; pausa;
 	return false;
	}
    return true;
};

void destino() {
	switch (t[dest].color) {
	case 0: {
             break;}
	case 1: if (turn == 1) { decirnt "destino incorrecto\n"; pausa; eligepieza(); }
			break;
	case 2: if (turn == 2) { decirnt "destino incorrecto\n"; pausa; eligepieza(); }
			break;
	}
	switch (t[ori].pieza) {
	case 1: validarey(); break;
	case 2: validadama();break;
	case 3: validatorre(); break;
	case 4: validaalfil(); break;
	case 5: validacaballo();break;
	case 6: validapeon();break;
	}
	beep();   //sonido ficha aj break;
if (jaque()){
resolverjaque();
}
//else actualiza();
//else {eligepieza();}
}

void actualiza(){
	if (turn == 1) {
		t[dest].pieza = t[ori].pieza; t[dest].color = t[ori].color;
		t[ori].pieza = 0; t[ori].color = 0;
//		borrapeon2();
	}
	else if (turn == 2) {
		t[dest].pieza = t[ori].pieza; t[dest].color = t[ori].color;
		t[ori].pieza = 0; t[ori].color = 0;
//		borrapeon2();
	}
//	else eligepieza();
}


