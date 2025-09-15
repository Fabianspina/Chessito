#ifndef RELOJ_H
#define RELOJ_H
#include <string>
#include <chrono>

class Reloj {
public:
    Reloj();                        //Constructores
    Reloj(int segundosIniciales);

    void iniciar();
    void detener();
    void reiniciar();

    void agregarTiempo(int ms);
    void quitarTiempo(int ms);
    int obtenerSegundos() const;
    std::string formatoHHMMSS() const;

private:
    bool corriendo;
    long long tiempoInicialMS;
    long long tiempoActualMS;
    long long tiempoTranscurridoMS;

    std::chrono::steady_clock::time_point inicio;
};

#endif // RELOJ_H
