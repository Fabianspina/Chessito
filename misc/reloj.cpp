#include "reloj.h"
#include <chrono>
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

    Reloj::Reloj()
        : corriendo(false), tiempoInicialMS(0), tiempoTranscurridoMS(0) {}

    Reloj::Reloj(int segundosIniciales)
        : corriendo(false),
      tiempoInicialMS(segundosIniciales * 1000),
      tiempoActualMS(segundosIniciales * 1000),
      tiempoTranscurridoMS(segundosIniciales * 1000) {}

void Reloj::iniciar() {
    if (!corriendo) {
        inicio = std::chrono::steady_clock::now();
        corriendo = true;
    }
}

void Reloj::detener() {
    if (corriendo) {
        auto fin = std::chrono::steady_clock::now();
        tiempoTranscurridoMS += std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio).count();
        corriendo = false;
    }
}

void Reloj::reiniciar() {
    tiempoTranscurridoMS = tiempoInicialMS;
    corriendo = false;
}

void Reloj::agregarTiempo(int ms) {
    tiempoTranscurridoMS += ms;
}

void Reloj::quitarTiempo(int ms) {
    tiempoTranscurridoMS -= ms;
    if (tiempoTranscurridoMS < 0)
        tiempoTranscurridoMS = 0;
}

int Reloj::obtenerSegundos() const {
    return static_cast<int>(tiempoTranscurridoMS / 1000);
}

std::string Reloj::formatoHHMMSS() const {
    long long totalSegundos = tiempoTranscurridoMS / 1000;
    int horas = static_cast<int>(totalSegundos / 3600);
    int minutos = static_cast<int>((totalSegundos % 3600) / 60);
    int segundos = static_cast<int>(totalSegundos % 60);

    char buffer[9];
    sprintf(buffer, "%02d:%02d:%02d", horas, minutos, segundos);
    return std::string(buffer);
}
