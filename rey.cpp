#include "rey.h"

int rodearey[8] = { -9, -8, -7, -1, +1, +7, +8, +9 };
reyes rey[3] = {
{ 0, 0, 0, 0, 0, 0, 0 },
{ 5, 1, 1, 0, 0, 0, 0 },
{ 5, 8, 2, 0, 0, 0, 0 }
};
int casilladelrey;
int ubicarey() {//decir "\nestoy en la funcion ubicarey()\n"; pausa;
for bucle{
if (t[i].pieza == 1 && t[i].color == 1) {
rey[1].col = t[i].columna;
rey[1].fil = t[i].fila;
rey[1].colr = t[i].color;
rey[1].an = t[i].tocan;
//decirnt "El rey blanco esta en la casilla: " << t[i].fila << t[i].columna << endl;
casilladelrey = i;
return casilladelrey;
}
if (t[i].pieza == 1 && t[i].color == 2) {
rey[2].col = t[i].columna;
rey[2].fil = t[i].fila;
rey[2].colr = t[i].color;
rey[2].ab = t[i].tocab;
//decirnt "El rey negro esta en la casilla: " << t[i].fila << t[i].columna << endl;
casilladelrey = i;
return casilladelrey;
}
}
}

int ambitorey(){
for bucle{
if (turn == 1 && ti.pieza == 1 && ti.color == 1) {
decir "el Rey blanco se encuentra en la casilla: " << i;
return i;}
if (turn == 2 && ti.pieza == 1 && ti.color == 2) {
decir "el Rey negro se encuentra en la casilla: " << i;
//decir rodearey[2];
//decir endl << t[i-1].tocab << endl << t[i-7].tocab << endl<< t[i-8].tocab << endl<< t[i-9].tocab<< endl;
//decir endl << t[i+1].tocab << endl<< t[i+7].tocab << endl<< t[i+8].tocab << endl<< t[i+9].tocab;
return i;}
}
}

bool jaque() {
	if (turn == 1) {
            vtaux();
            ubicarey();
		if (rey[1].an != 0){
            decir "\nJAaaaquee\n";
            vt();
			resolverjaque();
			return true;
		}
		else{
			decir rey[1].col <<" "<< rey[1].fil <<" "<< rey[1].an <<" ";
			//decir "\nNo hay jaque a las blancas\n";
			return false;
		}
	}
	else if (turn == 2) {
            vtaux();
            ubicarey();
            if (rey[2].ab != 0)
            {
            decir "\nJAaaaquee\n";
            vt();
			resolverjaque();
			return true;
		}
		else
		{
			//decir "\nNo hay jaque a las negras\n";
			return false;
		}
	}
}

void resolverjaque() {
// rojo;
decir "OH! Estoy en jaque";//extraído de eligepieza
jaquemate(casilladelrey);
	decirnt "Su jugada: ";
	b = &cas[0];
	cin >> b;
	d = &casdes[0];
	cin >> d;
    convierteorigen(); conviertedestino();

	if ((turn == 1 && t[ori].color == 1) || (turn == 2 && t[ori].color == 2)) {
	switch (t[ori].pieza) {
	case 1: validarey(); break;
	case 2: validadama();break;
	case 3: validatorre(); break;
	case 4: validaalfil(); break;
	case 5: validacaballo();break;
	case 6: validapeon();break;

	if (turn == 1) {
		t[dest].pieza = t[ori].pieza; t[dest].color = t[ori].color;
		t[ori].pieza = 0; t[ori].color = 0;
		borrapeon2();vt();
		return;
	}
	else if (turn == 2) {
		t[dest].pieza = t[ori].pieza; t[dest].color = t[ori].color;
		t[ori].pieza = 0; t[ori].color = 0;
		borrapeon2();vt();
        return;
	}
	else vtaux();
        if(jaque()){
        decir "lero lero";
        resolverjaque();}

}
}
}

bool jaquemate(int casilladelrey){//Se llama siempre
if (turn ==1 && jaque() && mp== 0)  { decir "jaque mate! Las negras ganan" <<endl; return true;}
return false;
}
void validarey() {
//decir "validando rey\n";pausa;
//decir turn << "\t" << t[dest].columna << "\t" << t[ori].columna + 1 << "\t" << t[dest].fila << "\t" << t[ori].fila - 1 << t[dest].tocan << "\n";pausa;
if (
//si juegan las negras y...
(turn == 2 && t[dest].columna == t[ori].columna + 1 && t[dest].fila == t[ori].fila + 1 && t[dest].tocab == 0 )||
(turn == 2 && t[dest].columna == t[ori].columna - 1 && t[dest].fila == t[ori].fila + 1 && t[dest].tocab == 0 )||
(turn == 2 && t[dest].columna == t[ori].columna + 1 && t[dest].fila == t[ori].fila - 1 && t[dest].tocab == 0 )||
(turn == 2 && t[dest].columna == t[ori].columna - 1 && t[dest].fila == t[ori].fila - 1 && t[dest].tocab == 0 )||
(turn == 2 && t[dest].columna == t[ori].columna + 1 && t[dest].fila == t[ori].fila && t[dest].tocab == 0 )|| // columna + 1la misma fila y amenaza = 0 o
(turn == 2 && t[dest].columna == t[ori].columna - 1 && t[dest].fila == t[ori].fila && t[dest].tocab == 0 )||
(turn == 2 && t[dest].columna == t[ori].columna && t[dest].fila == t[ori].fila + 1 && t[dest].tocab == 0 )||
(turn == 2 && t[dest].columna == t[ori].columna && t[dest].fila == t[ori].fila - 1 && t[dest].tocab == 0 )||
(turn == 1 && t[dest].columna == t[ori].columna + 1 && t[dest].fila == t[ori].fila + 1 && t[dest].tocan == 0 )||
(turn == 1 && t[dest].columna == t[ori].columna - 1 && t[dest].fila == t[ori].fila + 1 && t[dest].tocan == 0 )||
(turn == 1 && t[dest].columna == t[ori].columna + 1 && t[dest].fila == t[ori].fila - 1 && t[dest].tocan == 0 )||
(turn == 1 && t[dest].columna == t[ori].columna - 1 && t[dest].fila == t[ori].fila - 1 && t[dest].tocan == 0 )||
(turn == 1 && t[dest].columna == t[ori].columna + 1 && t[dest].fila == t[ori].fila && t[dest].tocan == 0 )||
(turn == 1 && t[dest].columna == t[ori].columna - 1 && t[dest].fila == t[ori].fila && t[dest].tocan == 0 )||
(turn == 1 && t[dest].columna == t[ori].columna && t[dest].fila == t[ori].fila + 1 && t[dest].tocan == 0 )||
(turn == 1 && t[dest].columna == t[ori].columna && t[dest].fila == t[ori].fila - 1 && t[dest].tocan == 0 )

)

{
if (turn == 1)rey[1].rmb++;
if (turn == 2)rey[1].rmn++;
actualiza();
}
else if
(
// validación de enroque corto
(turn == 1 && t[dest].columna == t[ori].columna + 2 && t[dest - 1].pieza == 0 && t[64].pieza == 3
&& rey[1].rmb == 0 && t[dest - 1].tocan == 0 && t[dest].tocan == 0 )||
(turn == 2 && t[dest].columna == t[ori].columna + 2 && t[dest - 1].pieza == 0 && t[8].pieza == 3
&& rey[1].rmn == 0 && t[dest - 1].tocab == 0 && t[dest].tocab == 0)
)
{
enroquecorto();
}

else if
(
// validación de enroque largo
(turn == 1 && t[dest].columna == t[ori].columna - 2 && t[dest + 1].pieza == 0 && t[dest].pieza == 0 && t[dest - 1].pieza == 0 && t[57].pieza == 3
&& rey[1].rmb == 0 && t[dest + 1].tocan == 0 && t[dest].tocan == 0 )||
(turn == 2 && t[dest].columna == t[ori].columna - 2 && t[dest + 1].pieza == 0 && t[dest].pieza == 0 && t[dest - 1].pieza == 0 && t[1].pieza == 3
&& rey[1].rmn == 0 && t[dest - 1].tocab == 0 && t[dest].tocab == 0)
)
{
enroquelargo();
}

else {
decir "movida incorrecta\n";
eligepieza();
}
}
void enroquecorto() {
	t[dest].pieza = t[ori].pieza;
	t[dest].color = t[ori].color;

	t[dest - 1].pieza = 3;
	t[dest - 1].color = turn;

	t[dest - 2].color = turn;
	t[dest + 1].pieza = 0;
	t[dest + 1].color = 0;

	t[ori].pieza = 0;
	t[ori].color = 0;

}

void enroquelargo() {
	t[dest].pieza = t[ori].pieza;
	t[dest].color = t[ori].color;

	t[dest + 1].pieza = 3;
	t[dest + 1].color = turn;

	t[dest - 2].color = turn;

	t[dest - 2].pieza = 0;
	t[dest - 2].color = 0;

	t[ori].pieza = 0;
	t[ori].color = 0;

}
