#include "adornos.h"
#define borrar system("cls")
#define pausa system ("pause >> null")
#define decir cout <<

void ayuda() {
borrar;
decir "\tAyuda para Chessito 16\n\n";
decir "\n\t\t< * > < * > < * > < * > < * > < * > < * > < * >\n\n\n\t\t";
decir "\n\t\t< A > < T > < E > < N > < C > < I > < O > < N >\n\n\n";
decir "\t4- No olvide agrandar la pantalla\n\n\n";
decir "\t6- haga sus movidas con la notacion pgn, es decir, por ejemplo:\n\n";
decir "\t\t e2 e4\n\n";
decir "\n\t\t< * > < * > < * > < * > < * > < * > < * > < * >\n\n\n\t\t";
pausa;
borrar;
}

void beep(){
Beep(350,35);
}

void beep_pieza(){
Beep(350,35);
}

void beep_cambio_pieza(){
Beep(400,100);
}
