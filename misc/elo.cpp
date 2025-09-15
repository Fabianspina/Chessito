#include <iostream>
#include <cmath>
using namespace std;
#include "elo.h"
#define decir cout <<

// Función para calcular las probabilidades
int resultado;
float Probability(int rating1, int rating2)
{
    decir "ingrese elo jugador 1: ";
    cin >> rating1;
    decir endl << "ingrese elo jugador 2: ";
    cin >> rating2;
    // Calculate and return the expected score
    return 1.0 / (1 + pow(10, (rating1 - rating2) / 400.0));
}

// Function to calculate Elo rating
// K is a constant.
// resultado determines the resultado: 1 for Player A win, 0 for Player B win, 0.5 for draw.
void EloRating(float Ra, float Rb, int K, float resultado)
{
    // Calculate the Winning Probability of Player B
    float Pb = Probability(Ra, Rb);

    // Calculate the Winning Probability of Player A
    float Pa = Probability(Rb, Ra);

//    cin >> resultado >> "resultado: ";

    // Update the Elo Ratings
    Ra = Ra + K * (resultado - Pa);
    Rb = Rb + K * ((1 - resultado) - Pb);

    // Print updated ratings
    cout << "Updated Ratings:-\n";
    cout << "Ra = " << Ra << " Rb = " << Rb << endl;
}
