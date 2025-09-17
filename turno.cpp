#include "turno.h"
#include "misc/adornos.h"
int turn = 1;        // Definición real
int cont = 0;
int m = 0;
static int num_jugada;

int turno(){
    cont++;     // Incrementamos el contador de turnos
        turn = (cont % 2 == 1) ? 1 : 2; // corregido Qwen
	switch (turn) {
        case 1: beep_pieza();
            num_jugada++;
            decir "Jugada " << num_jugada << ". Es el turno de las blancas.\n";
            break;
        case 2: Beep(400, 100);
            decir "Jugada " << num_jugada << "... Es el turno de las negras.\n";
            break;
    }
return turn;
}
