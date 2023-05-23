#include <iostream>
#include "Personaje.h"
#include "EnemigoFinal.h"

    //Constructor
EnemigoFinal::EnemigoFinal(int vida, int ataque, std::string nombre, int posicionX, int posicionY,
    int psuperAtaque1, int psuperAtaque2)
    : Personaje(vida,
        ataque,
        nombre,
        posicionX,
        posicionY) {
    superAtaque1 = psuperAtaque1;
    superAtaque2 = psuperAtaque2;
};

    // Getters
    int EnemigoFinal::getSuperAtaque1()  {
        return superAtaque1; 
    }
    int EnemigoFinal::getSuperAtaque2()  {
        return superAtaque2; 
    }

    // Setters
    void EnemigoFinal::setSuperAtaque1(int psuperAtaque1) {
        superAtaque1 = psuperAtaque1;
    }
    void EnemigoFinal::setSuperAtaque2(int psuperAtaque2) {
        superAtaque2 = psuperAtaque2;
    }

    // Método para realizar el ataque superAtaque1
    void EnemigoFinal::atacarSuperAtaque1(Personaje& jugador) {
        jugador.setVida(jugador.getVida() - superAtaque1);
    }

    // Método para realizar el ataque superAtaque2
    void EnemigoFinal::atacarSuperAtaque2(Personaje& objetivo) {
        objetivo.setVida(objetivo.getVida() - superAtaque2);
    }
