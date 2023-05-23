#pragma once
#include <iostream>

class Personaje
{
protected:
    int vida;
    int ataque;
    std::string nombre;
    int posicionX;
    int posicionY;

public:
    //Constructor
    Personaje(int pvida, int pataque, std::string pnombre, int pposicionX, int pposicionY);

    // Getters
    int getVida();
    int getAtaque();
    std::string getNombre();
    int getPosicionX();
    int getPosicionY();

    // Setters
    void setVida(int pvida);
    void setAtaque(int pataque);
    void setNombre(std::string pnombre);
    void setPosicionX(int pposicionX);
    void setPosicionY(int pposicionY);

    // Método para mover el personaje
    void mover(int x, int y);
};