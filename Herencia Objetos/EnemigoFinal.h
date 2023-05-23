#pragma once
#include <iostream>
#include "Personaje.h"

class EnemigoFinal : public Personaje {
private:
    int superAtaque1;
    int superAtaque2;

public:

    //Constructor
    EnemigoFinal(int vida, int ataque, std::string nombre, int posicionX, int posicionY,
        int psuperAtaque1, int psuperAtaque2);

    // Getters
    int getSuperAtaque1();
    int getSuperAtaque2();


    // Setters
    void setSuperAtaque1(int psuperAtaque1);
    void setSuperAtaque2(int psuperAtaque2);

    // Método para realizar el ataque superAtaque1
    void atacarSuperAtaque1(Personaje& objetivo);

    // Método para realizar el ataque superAtaque2
    void atacarSuperAtaque2(Personaje& objetivo);
};
