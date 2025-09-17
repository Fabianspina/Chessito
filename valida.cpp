#include "valida.h"

void validacaballo() {
//	if( jaque()) resolverjaque();
if ((t[dest].columna == t[ori].columna + 1 && t[dest].fila == t[ori].fila + 2 && t[dest].color != turn ) || // si columna + 1 y fila + 2 y color de pieza no es igual a turno o
(t[dest].columna == t[ori].columna + 2 && t[dest].fila == t[ori].fila + 1 && t[dest].color != turn)  || // si columna + 2 y fila + 1 y color de pieza no es igual a turno o
(t[dest].columna == t[ori].columna - 1 && t[dest].fila == t[ori].fila + 2 && t[dest].color != turn)  || // si columna - 1 y fila + 2 y color de pieza no es igual a turno o
(t[dest].columna == t[ori].columna - 2 && t[dest].fila == t[ori].fila + 1 && t[dest].color != turn)  || // si columna - 2 y fila + 1 y color de pieza no es igual a turno o
(t[dest].columna == t[ori].columna + 1 && t[dest].fila == t[ori].fila - 2 && t[dest].color != turn)  || // si columna + 1 y fila - 2 y color de pieza no es igual a turno o
(t[dest].columna == t[ori].columna + 2 && t[dest].fila == t[ori].fila - 1 && t[dest].color != turn)  || // si columna + 2 y fila - 1 y color de pieza no es igual a turno o
(t[dest].columna == t[ori].columna - 1 && t[dest].fila == t[ori].fila - 2 && t[dest].color != turn)  || // si columna - 1 y fila - 2 y color de pieza no es igual a turno o
(t[dest].columna == t[ori].columna - 2 && t[dest].fila == t[ori].fila - 1 && t[dest].color != turn) )   // si columna - 2 y fila - 1 y color de pieza no es igual a turno o*/
	{
		actualiza();
	}
	else {
		decir "\tmovida incorrecta validando caballo\n";
		eligepieza();
	}
}

void validaalfil() {
	if (
(t[dest].columna == t[ori].columna + 1 && t[dest].fila == t[ori].fila + 1 && t[dest].color != 1 ) ||
(t[dest].columna == t[ori].columna + 2 && t[dest].fila == t[ori].fila + 2 && t[ori - 7].pieza == 0 && t[dest].color != 1 )||
(t[dest].columna == t[ori].columna + 3 && t[dest].fila == t[ori].fila + 3 && t[ori - 7].pieza == 0 && t[ori - 14].pieza == 0 && t[dest].color != 1) ||
(t[dest].columna == t[ori].columna + 4 && t[dest].fila == t[ori].fila + 4 && t[ori - 7].pieza == 0 && t[ori - 14].pieza == 0 && t[ori - 21].pieza == 0 && t[dest].color != 1) ||
(t[dest].columna == t[ori].columna + 5 && t[dest].fila == t[ori].fila + 5 && t[ori - 7].pieza == 0 && t[ori - 14].pieza == 0 && t[ori - 21].pieza == 0 && t[ori - 28].pieza == 0 && t[dest].color != 1) ||
(t[dest].columna == t[ori].columna + 6 && t[dest].fila == t[ori].fila + 6 && t[ori - 7].pieza == 0 && t[ori - 14].pieza == 0 && t[ori - 21].pieza == 0 && t[ori - 28].pieza == 0 && t[ori - 35].pieza == 0 && t[dest].color != 1) ||
(t[dest].columna == t[ori].columna + 7 && t[dest].fila == t[ori].fila + 7 && t[ori - 7].pieza == 0 && t[ori - 14].pieza == 0 && t[ori - 21].pieza == 0 && t[ori - 28].pieza == 0 && t[ori - 35].pieza == 0 && t[ori - 42].pieza == 0 && t[dest].color != 1) ||

(t[dest].columna == t[ori].columna - 1 && t[dest].fila == t[ori].fila + 1 && t[dest].color != 1) ||
(t[dest].columna == t[ori].columna - 2 && t[dest].fila == t[ori].fila + 2 && t[ori - 9].pieza == 0 && t[dest].color != 1) ||
(t[dest].columna == t[ori].columna - 3 && t[dest].fila == t[ori].fila + 3 && t[ori - 9].pieza == 0 && t[ori - 18].pieza == 0 && t[dest].color != 1) ||
(t[dest].columna == t[ori].columna - 4 && t[dest].fila == t[ori].fila + 4 && t[ori - 9].pieza == 0 && t[ori - 18].pieza == 0 && t[ori - 27].pieza == 0 && t[dest].color != 1) ||
(t[dest].columna == t[ori].columna - 5 && t[dest].fila == t[ori].fila + 5 && t[ori - 9].pieza == 0 && t[ori - 18].pieza == 0 && t[ori - 27].pieza == 0 && t[ori - 36].pieza == 0 && t[dest].color != 1) ||
(t[dest].columna == t[ori].columna - 6 && t[dest].fila == t[ori].fila + 6 && t[ori - 9].pieza == 0 && t[ori - 18].pieza == 0 && t[ori - 27].pieza == 0 && t[ori - 36].pieza == 0 && t[ori - 45].pieza == 0 && t[dest].color != 1) ||
(t[dest].columna == t[ori].columna - 7 && t[dest].fila == t[ori].fila + 7 && t[ori - 9].pieza == 0 && t[ori - 18].pieza == 0 && t[ori - 27].pieza == 0 && t[ori - 36].pieza == 0 && t[ori - 45].pieza == 0 && t[ori - 54].pieza == 0 && t[dest].color != 1 )||

(t[dest].columna == t[ori].columna + 1 && t[dest].fila == t[ori].fila - 1 && t[dest].color != 1) ||
(t[dest].columna == t[ori].columna + 2 && t[dest].fila == t[ori].fila - 2 && t[ori + 9].pieza == 0 && t[dest].color != 1) ||
(t[dest].columna == t[ori].columna + 3 && t[dest].fila == t[ori].fila - 3 && t[ori + 9].pieza == 0 && t[ori + 18].pieza == 0 && t[dest].color != 1) ||
(t[dest].columna == t[ori].columna + 4 && t[dest].fila == t[ori].fila - 4 && t[ori + 9].pieza == 0 && t[ori + 18].pieza == 0 && t[ori + 27].pieza == 0 && t[dest].color != 1) ||
(t[dest].columna == t[ori].columna + 5 && t[dest].fila == t[ori].fila - 5 && t[ori + 9].pieza == 0 && t[ori + 18].pieza == 0 && t[ori + 27].pieza == 0 && t[ori + 36].pieza == 0 && t[dest].color != 1) ||
(t[dest].columna == t[ori].columna + 6 && t[dest].fila == t[ori].fila - 6 && t[ori + 9].pieza == 0 && t[ori + 18].pieza == 0 && t[ori + 27].pieza == 0 && t[ori + 36].pieza == 0 && t[ori + 45].pieza == 0 && t[dest].color != 1) ||
(t[dest].columna == t[ori].columna + 7 && t[dest].fila == t[ori].fila - 7 && t[ori + 9].pieza == 0 && t[ori + 18].pieza == 0 && t[ori + 27].pieza == 0 && t[ori + 36].pieza == 0 && t[ori + 45].pieza == 0 && t[ori + 54].pieza == 0 && t[dest].color != 1) ||

(t[dest].columna == t[ori].columna - 1 && t[dest].fila == t[ori].fila - 1 && t[dest].color != 1) ||
(t[dest].columna == t[ori].columna - 2 && t[dest].fila == t[ori].fila - 2 && t[ori + 7].pieza == 0 && t[dest].color != 1) ||
(t[dest].columna == t[ori].columna - 3 && t[dest].fila == t[ori].fila - 3 && t[ori + 7].pieza == 0 && t[ori + 14].pieza == 0 && t[dest].color != 1) ||
(t[dest].columna == t[ori].columna - 4 && t[dest].fila == t[ori].fila - 4 && t[ori + 7].pieza == 0 && t[ori + 14].pieza == 0 && t[ori + 21].pieza == 0 && t[dest].color != 1) ||
(t[dest].columna == t[ori].columna - 5 && t[dest].fila == t[ori].fila - 5 && t[ori + 7].pieza == 0 && t[ori + 14].pieza == 0 && t[ori + 21].pieza == 0 && t[ori + 28].pieza == 0 && t[dest].color != 1) ||
(t[dest].columna == t[ori].columna - 6 && t[dest].fila == t[ori].fila - 6 && t[ori + 7].pieza == 0 && t[ori + 14].pieza == 0 && t[ori + 21].pieza == 0 && t[ori + 28].pieza == 0 && t[ori + 35].pieza == 0 && t[dest].color != 1) ||
(t[dest].columna == t[ori].columna - 7 && t[dest].fila == t[ori].fila - 7 && t[ori + 7].pieza == 0 && t[ori + 14].pieza == 0 && t[ori + 21].pieza == 0 && t[ori + 28].pieza == 0 && t[ori + 35].pieza == 0 && t[ori + 42].pieza == 0 && t[dest].color != 1) ||

(t[dest].columna == t[ori].columna + 1 && t[dest].fila == t[ori].fila + 1 && t[dest].color != 2) ||
(t[dest].columna == t[ori].columna + 2 && t[dest].fila == t[ori].fila + 2 && t[ori - 7].pieza == 0 && t[dest].color != 2) ||
(t[dest].columna == t[ori].columna + 3 && t[dest].fila == t[ori].fila + 3 && t[ori - 7].pieza == 0 && t[ori - 14].pieza == 0 && t[dest].color != 2) ||
(t[dest].columna == t[ori].columna + 4 && t[dest].fila == t[ori].fila + 4 && t[ori - 7].pieza == 0 && t[ori - 14].pieza == 0 && t[ori - 21].pieza == 0 && t[dest].color != 2 )||
(t[dest].columna == t[ori].columna + 5 && t[dest].fila == t[ori].fila + 5 && t[ori - 7].pieza == 0 && t[ori - 14].pieza == 0 && t[ori - 21].pieza == 0 && t[ori - 28].pieza == 0 && t[dest].color != 2) ||
(t[dest].columna == t[ori].columna + 6 && t[dest].fila == t[ori].fila + 6 && t[ori - 7].pieza == 0 && t[ori - 14].pieza == 0 && t[ori - 21].pieza == 0 && t[ori - 28].pieza == 0 && t[ori - 35].pieza == 0 && t[dest].color != 2) ||
(t[dest].columna == t[ori].columna + 7 && t[dest].fila == t[ori].fila + 7 && t[ori - 7].pieza == 0 && t[ori - 14].pieza == 0 && t[ori - 21].pieza == 0 && t[ori - 28].pieza == 0 && t[ori - 35].pieza == 0 && t[ori - 42].pieza == 0 && t[dest].color != 2) ||
(t[dest].columna == t[ori].columna - 1 && t[dest].fila == t[ori].fila + 1 && t[dest].color != 2) ||
(t[dest].columna == t[ori].columna - 2 && t[dest].fila == t[ori].fila + 2 && t[ori - 9].pieza == 0 && t[dest].color != 2) ||
(t[dest].columna == t[ori].columna - 3 && t[dest].fila == t[ori].fila + 3 && t[ori - 9].pieza == 0 && t[ori - 18].pieza == 0 && t[dest].color != 2) ||
(t[dest].columna == t[ori].columna - 4 && t[dest].fila == t[ori].fila + 4 && t[ori - 9].pieza == 0 && t[ori - 18].pieza == 0 && t[ori - 27].pieza == 0 && t[dest].color != 2) ||
(t[dest].columna == t[ori].columna - 5 && t[dest].fila == t[ori].fila + 5 && t[ori - 9].pieza == 0 && t[ori - 18].pieza == 0 && t[ori - 27].pieza == 0 && t[ori - 36].pieza == 0 && t[dest].color != 2 )||
(t[dest].columna == t[ori].columna - 6 && t[dest].fila == t[ori].fila + 6 && t[ori - 9].pieza == 0 && t[ori - 18].pieza == 0 && t[ori - 27].pieza == 0 && t[ori - 36].pieza == 0 && t[ori - 45].pieza == 0 && t[dest].color != 2) ||
(t[dest].columna == t[ori].columna - 7 && t[dest].fila == t[ori].fila + 7 && t[ori - 9].pieza == 0 && t[ori - 18].pieza == 0 && t[ori - 27].pieza == 0 && t[ori - 36].pieza == 0 && t[ori - 45].pieza == 0 && t[ori - 54].pieza == 0 && t[dest].color != 2) ||

(t[dest].columna == t[ori].columna + 1 && t[dest].fila == t[ori].fila - 1 && t[dest].color != 2 )||
(t[dest].columna == t[ori].columna + 2 && t[dest].fila == t[ori].fila - 2 && t[ori + 9].pieza == 0 && t[dest].color != 2) ||
(t[dest].columna == t[ori].columna + 3 && t[dest].fila == t[ori].fila - 3 && t[ori + 9].pieza == 0 && t[ori + 18].pieza == 0 && t[dest].color != 2 )||
(t[dest].columna == t[ori].columna + 4 && t[dest].fila == t[ori].fila - 4 && t[ori + 9].pieza == 0 && t[ori + 18].pieza == 0 && t[ori + 27].pieza == 0 && t[dest].color != 2) ||
(t[dest].columna == t[ori].columna + 5 && t[dest].fila == t[ori].fila - 5 && t[ori + 9].pieza == 0 && t[ori + 18].pieza == 0 && t[ori + 27].pieza == 0 && t[ori + 36].pieza == 0 && t[dest].color != 2) ||
(t[dest].columna == t[ori].columna + 6 && t[dest].fila == t[ori].fila - 6 && t[ori + 9].pieza == 0 && t[ori + 18].pieza == 0 && t[ori + 27].pieza == 0 && t[ori + 36].pieza == 0 && t[ori + 45].pieza == 0 && t[dest].color != 2) ||
(t[dest].columna == t[ori].columna + 7 && t[dest].fila == t[ori].fila - 7 && t[ori + 9].pieza == 0 && t[ori + 18].pieza == 0 && t[ori + 27].pieza == 0 && t[ori + 36].pieza == 0 && t[ori + 45].pieza == 0 && t[ori + 54].pieza == 0 && t[dest].color != 2) ||

(t[dest].columna == t[ori].columna - 1 && t[dest].fila == t[ori].fila - 1 && t[dest].color != 2) ||
(t[dest].columna == t[ori].columna - 2 && t[dest].fila == t[ori].fila - 2 && t[ori + 7].pieza == 0 && t[dest].color != 2) ||
(t[dest].columna == t[ori].columna - 3 && t[dest].fila == t[ori].fila - 3 && t[ori + 7].pieza == 0 && t[ori + 14].pieza == 0 && t[dest].color != 2) ||
(t[dest].columna == t[ori].columna - 4 && t[dest].fila == t[ori].fila - 4 && t[ori + 7].pieza == 0 && t[ori + 14].pieza == 0 && t[ori + 21].pieza == 0 && t[dest].color != 2) ||
(t[dest].columna == t[ori].columna - 5 && t[dest].fila == t[ori].fila - 5 && t[ori + 7].pieza == 0 && t[ori + 14].pieza == 0 && t[ori + 21].pieza == 0 && t[ori + 28].pieza == 0 && t[dest].color != 2) ||
(t[dest].columna == t[ori].columna - 6 && t[dest].fila == t[ori].fila - 6 && t[ori + 7].pieza == 0 && t[ori + 14].pieza == 0 && t[ori + 21].pieza == 0 && t[ori + 28].pieza == 0 && t[ori + 35].pieza == 0 && t[dest].color != 2) ||
(t[dest].columna == t[ori].columna - 7 && t[dest].fila == t[ori].fila - 7 && t[ori + 7].pieza == 0 && t[ori + 14].pieza == 0 && t[ori + 21].pieza == 0 && t[ori + 28].pieza == 0 && t[ori + 35].pieza == 0 && t[ori + 42].pieza == 0 && t[dest].color != 2)
			)
		{
			actualiza();
		}
	else {
		decir "\tmovida incorrecta validando alfil\n";
		eligepieza();
	}
}
void validapeon(){
/* 1 */
// si hay un peon en la fila 2
// puede avanzar dos casillas,
// mientras que la fila 3 está libre,
// manteniéndose por la misma columna
// si no hay jaque al rey, se valida la primer regla
// ejemplo: a2 a4

if (t[ori].fila == 2 && t[dest].fila == t[ori].fila + 2 && t[ori - 8].pieza == 0
    && t[dest].columna == t[ori].columna && t[dest].color == 0 && rey[1].an == 0){

            // Se quitó condición innecesaria para validar al paso.
            // En el caso de avanzar dos casillas el peón blanco deja una marca
            // (valor peon2 en 1) para que el negro decida si toma peón al paso

			{
				t[dest].peon2 = 1; actualiza(); //actualizapeonalp2();

                // Todavía hace falta que cuando juegue el negro, luego se borre ese valor
			}
		}
		/* 2 */
		else if (t[ori].fila == 5 && t[dest].fila == 6 && t[ori + 1].peon2 == 1 && rey[1].an == 0) //peón al paso tomando hacia la derecha
		{
			actualizapeonalp1();
			// y acá iría la actualización de t[dest].peon2 de las negras a 0 cuando pasó el turno
		}
		/* 3 */
		else if (t[ori].fila == 5 && t[dest].fila == t[ori].fila + 1 && t[ori - 1].pieza == 6 && t[ori - 1].peon2 == 1 && rey[1].an == 0) //peón al paso tomando hacia la izq
		{
			actualizapeonalp2();
			// y acá iría la actualización de t1[dest].peon2 de las negras a 0 cuando pasó el turno
		}
		/* 4 5 6 */
		else if (
			(t[dest].fila == t[ori].fila + 1 && t[ori].fila <= 6 && t[dest].columna == t[ori].columna && t[dest].color == 0 && rey[1].an == 0 )|| // peón avanza una casilla va bien
			(t[dest].fila == t[ori].fila + 1 && t[ori].fila <= 6 && t[dest].columna == t[ori].columna + 1 && t[dest].color == 2 && rey[1].an == 0) || // peón come a la derecha
			(t[dest].fila == t[ori].fila + 1 && t[ori].fila <= 6 && t[dest].columna == t[ori].columna - 1 && t[dest].color == 2 && rey[1].an == 0) )// peón come a la izquierda
		{
			actualiza();
		}
		/* 7 8 9 */
		else if ((t[ori].fila == 7 && t[dest].fila == 8 && t[dest].columna == t[ori].columna && t[dest].pieza == 0 && rey[1].an == 0) || // corona hacia adelante sin tomar
			(t[ori].fila == 7 && t[dest].fila == 8 && t[dest].columna == t[ori + 1].columna && t[dest].color == 2 && rey[1].an == 0) || // corona tomando hacia la derecha funciona
			(t[ori].fila == 7 && t[dest].fila == 8 && t[dest].columna == t[ori - 1].columna && t[dest].color == 2 && rey[1].an == 0) // corona tomando hacia la izquierda funciona
			)
		{
			coronar();
		}

	/*****************************************  Turno de las negras   ********************************************************************/
	/* 1 */
	else if (turn == 2) {
		if (t[ori].fila == 7 && t[dest].fila == t[ori].fila - 2 && t[ori + 8].pieza == 0 && t[dest].columna == t[ori].columna && t[dest].color == 0 && rey[1].ab == 0)
		{
			if ((t[dest + 1].pieza == 6 && t[dest + 1].color == 1 && t[dest].columna <= 7) || (t[dest - 1].pieza == 6 && t[dest - 1].color == 1 && t[dest].columna >= 2)) //Peón blanco avanza 2 casillas dejando tras de sí el valor peon2 en 1
			{
				decirn  "estoy aca";  t[dest].peon2 = 1; //actualizaconpeon();
			}
			else actualiza();
		} 		  /* 2 */
		else if (t[ori].fila == 4 && t[dest].fila == 3 && t[ori + 1].peon2 == 1 && rey[1].ab == 0) //peón al paso tomando hacia su derecha o izq desde el punto de vista blanco
		{
			actualizapeonalp3();
			// y acá iría la acutalización de t1[dest].peon2 de las negras a 0 cuando pasó el turno
		}
		/* 3 */
		else if (t[ori].fila == 4 && t[dest].fila == t[ori].fila - 1 && t[ori - 1].pieza == 6 && t[ori - 1].peon2 != 0 && rey[1].ab == 0)
			//peón al paso tomando hacia su der y funciona llama a actualizapeonalp4
		{
			actualizapeonalp4();
			// y acá iría la acutalización de t1[dest].peon2 de las negras a 0 cuando pasó el turno
		}
		/* 4 5 6 */
		else if ((t[dest].fila == t[ori].fila - 1 && t[ori].fila >= 3 && t[dest].columna == t[ori].columna && t[dest].color == 0 && rey[1].ab == 0) || // Avanza adelante
			(t[dest].fila == t[ori].fila - 1 && t[ori].fila >= 3 && t[dest].columna == t[ori].columna + 1 && t[dest].color == 1 && rey[1].ab == 0) || //come a la derecha de la pantalla
			(t[dest].fila == t[ori].fila - 1 && t[ori].fila >= 3 && t[dest].columna == t[ori].columna - 1 && t[dest].color == 1 && rey[1].ab == 0)  // come a la izq de la pantalla
			)
		{
			actualiza();
		}
		/*************************************** funciones de coronar *********************************/
		else if (
		(turn == 2 && t[ori].fila == 2 && t[dest].fila == 1 && t[dest].columna == t[ori].columna && t[dest].color == 0 && rey[1].ab == 0) ||
		(turn == 2 && t[ori].fila == 2 && t[dest].fila == 1 && t[dest].columna == t[ori].columna + 1 && t[dest].color == 1 && rey[1].ab == 0) ||
		(turn == 2 && t[ori].fila == 2 && t[dest].fila == 1 && t[dest].columna == t[ori].columna - 1 && t[dest].color == 1 && rey[1].ab == 0)
			)
		{
			coronar();
			actualiza();
		}
	}
	else {
		//decir "\n t1[ori].columna. fila y t1[dest].columna. fila " ; /* t[ori].columna << t[ori].fila << t[dest].columna << t[dest].fila*/ << "\n";
		pausa;
		decir "\tmovida incorrecta\n";
		eligepieza();
	}
}

void actualizaconpeon() {
t[dest].pieza = t[ori].pieza; t[dest].color = t[ori].color;
t[ori].pieza = 0; t[ori].color = 0;
vt();
}

void actualizapeonalp1() { //peón al paso blanco a la derecha.
	decir "\nestoy en la funcion actualizapeonalp1()\n"; pausa;
	t[dest].pieza = t[ori].pieza; t[dest].color = t[ori].color;
	t[ori + 1].pieza = 0; t[ori + 1].color = 0;
	t[ori].pieza = 0; t[ori].color = 0;
	vt();
}

void actualizapeonalp2() { //peón al paso blanco a la izq.
	decir "\nestoy en la funcion actualizapeonalp2()\n"; pausa;
	t[dest].pieza = t[ori].pieza; t[dest].color = t[ori].color;
	t[ori - 1].pieza = 0; t[ori - 1].color = 0;
	t[ori].pieza = 0; t[ori].color = 0;
//	vt();
}

void actualizapeonalp3() { //peón al paso negro a su derecha.
	decir "Me llamaron ? Soy actualizapeonalp3  "; pausa;
	t[dest].pieza = t[ori].pieza; t[dest].color = t[ori].color;
	t[ori + 1].pieza = 0; t[ori + 1].color = 0;
	t[ori].pieza = 0; t[ori].color = 0;
//	vt();
}

void actualizapeonalp4() { //peón al paso negro a su izq.
	decir "Me llamaron ? Soy actualizapeonalp4 "; pausa;
	t[dest].pieza = t[ori].pieza; t[dest].color = t[ori].color;
	t[ori - 1].pieza = 0; t[ori - 1].color = 0;
	t[ori].pieza = 0; t[ori].color = 0;
	vt();
}

void coronar() {
	/*
	Esta Función debería dar a elegir la pieza que se quiere coronar. Pero en esta etapa de la construcción la dejamos así.
	Igual es fácil. Es cargar un menu con las cuatro opciones posibles.
	*/
	if (turn == 1) {
		t[dest].pieza = 2;
		t[dest].color = 1;
		t[ori].pieza = 0;
		t[ori].color = 0;
	}
	if (turn == 2) {
		t[dest].pieza = 2;
		t[dest].color = 2;
		t[ori].pieza = 0;
		t[ori].color = 0;
	}
}

void validatorre() {
	if (
 (t[dest].columna == t[ori].columna && t[dest].fila == t[ori].fila + 1 && t[dest].color != 1) || //
 (t[dest].columna == t[ori].columna && t[dest].fila == t[ori].fila + 2 && t[ori - 8].pieza == 0 && t[dest].color != 1) || //
 (t[dest].columna == t[ori].columna && t[dest].fila == t[ori].fila + 3 && t[ori - 8].pieza == 0 && t[ori - 16].pieza == 0 && t[dest].color != 1) || //
 (t[dest].columna == t[ori].columna && t[dest].fila == t[ori].fila + 4 && t[ori - 8].pieza == 0 && t[ori - 16].pieza == 0 && t[ori - 24].pieza == 0 && t[dest].color != 1) || //
 (t[dest].columna == t[ori].columna && t[dest].fila == t[ori].fila + 5 && t[ori - 8].pieza == 0 && t[ori - 16].pieza == 0 && t[ori - 24].pieza == 0 && t[ori - 32].pieza == 0 && t[dest].color != 1) ||//
 (t[dest].columna == t[ori].columna && t[dest].fila == t[ori].fila + 6 && t[ori - 8].pieza == 0 && t[ori - 16].pieza == 0 && t[ori - 24].pieza == 0 && t[ori - 32].pieza == 0 && t[ori - 40].pieza == 0 && t[dest].color != 1) ||//
 (t[dest].columna == t[ori].columna && t[dest].fila == t[ori].fila + 7 && t[ori - 8].pieza == 0 && t[ori - 16].pieza == 0 && t[ori - 24].pieza == 0 && t[ori - 32].pieza == 0 && t[ori - 40].pieza == 0 && t[ori - 48].pieza == 0 && t[dest].color != 1) ||

 (t[dest].columna == t[ori].columna && t[dest].fila == t[ori].fila - 1 && t[dest].color != 1) ||
 (t[dest].columna == t[ori].columna && t[dest].fila == t[ori].fila - 2 && t[ori + 8].pieza == 0 && t[dest].color != 1) || //
 (t[dest].columna == t[ori].columna && t[dest].fila == t[ori].fila - 3 && t[ori + 8].pieza == 0 && t[ori + 16].pieza == 0 && t[dest].color != 1) ||//
 (t[dest].columna == t[ori].columna && t[dest].fila == t[ori].fila - 4 && t[ori + 8].pieza == 0 && t[ori + 16].pieza == 0 && t[ori + 24].pieza == 0 && t[dest].color != 1) ||
 (t[dest].columna == t[ori].columna && t[dest].fila == t[ori].fila - 5 && t[ori + 8].pieza == 0 && t[ori + 16].pieza == 0 && t[ori + 24].pieza == 0 && t[ori + 32].pieza == 0 && t[dest].color != 1) ||
 (t[dest].columna == t[ori].columna && t[dest].fila == t[ori].fila - 6 && t[ori + 8].pieza == 0 && t[ori + 16].pieza == 0 && t[ori + 24].pieza == 0 && t[ori + 32].pieza == 0 && t[ori + 40].pieza == 0 && t[dest].color != 1) || //
 (t[dest].columna == t[ori].columna && t[dest].fila == t[ori].fila - 7 && t[ori + 8].pieza == 0 && t[ori + 16].pieza == 0 && t[ori + 24].pieza == 0 && t[ori + 32].pieza == 0 && t[ori + 40].pieza == 0 && t[ori + 48].pieza == 0 && t[dest].color != 1) || //

 (t[dest].columna == t[ori].columna + 1 && t[dest].fila == t[ori].fila && t[dest].color != 1) ||
 (t[dest].columna == t[ori].columna + 2 && t[dest].fila == t[ori].fila  && t[ori + 1].pieza == 0 && t[dest].color != 1) ||
 (t[dest].columna == t[ori].columna + 3 && t[dest].fila == t[ori].fila  && t[ori + 1].pieza == 0 && t[ori + 2].pieza == 0 && t[dest].color != 1) ||
 (t[dest].columna == t[ori].columna + 4 && t[dest].fila == t[ori].fila  && t[ori + 1].pieza == 0 && t[ori + 2].pieza == 0 && t[ori + 3].pieza == 0 && t[dest].color != 1) ||
 (t[dest].columna == t[ori].columna + 5 && t[dest].fila == t[ori].fila  && t[ori + 1].pieza == 0 && t[ori + 2].pieza == 0 && t[ori + 3].pieza == 0 && t[ori + 4].pieza == 0 && t[dest].color != 1 ) ||
 (t[dest].columna == t[ori].columna + 6 && t[dest].fila == t[ori].fila  && t[ori + 1].pieza == 0 && t[ori + 2].pieza == 0 && t[ori + 3].pieza == 0 && t[ori + 4].pieza == 0 && t[ori + 5].pieza == 0 && t[dest].color != 1) ||
 (t[dest].columna == t[ori].columna + 7 && t[dest].fila == t[ori].fila  && t[ori + 1].pieza == 0 && t[ori + 2].pieza == 0 && t[ori + 3].pieza == 0 && t[ori + 4].pieza == 0 && t[ori + 5].pieza == 0 && t[ori + 6].pieza == 0 && t[dest].color != 1)  ||

 (t[dest].columna == t[ori].columna - 1 && t[dest].fila == t[ori].fila  && t[dest].color != 1) ||
 (t[dest].columna == t[ori].columna - 2 && t[dest].fila == t[ori].fila  && t[ori - 1].pieza == 0 && t[dest].color != 1) ||
 (t[dest].columna == t[ori].columna - 3 && t[dest].fila == t[ori].fila  && t[ori - 1].pieza == 0 && t[ori - 2].pieza == 0 && t[dest].color != 1) ||
 (t[dest].columna == t[ori].columna - 4 && t[dest].fila == t[ori].fila  && t[ori - 1].pieza == 0 && t[ori - 2].pieza == 0 && t[ori - 3].pieza == 0 && t[dest].color != 1) ||
 (t[dest].columna == t[ori].columna - 5 && t[dest].fila == t[ori].fila  && t[ori - 1].pieza == 0 && t[ori - 2].pieza == 0 && t[ori - 3].pieza == 0 && t[ori - 4].pieza == 0 && t[dest].color != 1) ||
 (t[dest].columna == t[ori].columna - 6 && t[dest].fila == t[ori].fila  && t[ori - 1].pieza == 0 && t[ori - 2].pieza == 0 && t[ori - 3].pieza == 0 && t[ori - 4].pieza == 0 && t[ori - 5].pieza == 0 && t[dest].color != 1) ||
 (t[dest].columna == t[ori].columna - 7 && t[dest].fila == t[ori].fila  && t[ori - 1].pieza == 0 && t[ori - 2].pieza == 0 && t[ori - 3].pieza == 0 && t[ori - 4].pieza == 0 && t[ori - 5].pieza == 0 && t[ori - 6].pieza == 0 && t[dest].color != 1)
		)
	{
		actualiza();
	}
	else
	{
		decir "\tmovida incorrecta vaalidando Torre\n";
		eligepieza();
	}
}
