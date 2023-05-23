#include "Personaje.h"
#include <iostream>

    //Constructor
    Personaje::Personaje(int pvida, int pataque, std::string pnombre, int pposicionX, int pposicionY) {
        vida = pvida;
        ataque = pataque;
        nombre = pnombre;
        posicionX = pposicionX;
        posicionY = pposicionY;
    }        

    // Getters
    int Personaje::getVida() {
        return vida; 
    }
    int Personaje::getAtaque() {
        return ataque; 
    }
    std::string Personaje::getNombre() {
        return nombre; 
    }
    int Personaje::getPosicionX() {
        return posicionX; 
    }
    int Personaje::getPosicionY() {
        return posicionY; 
    }

    // Setters
    void Personaje::setVida(int pvida) {
        vida = pvida;
    }
    void Personaje::setAtaque(int pataque) {
        ataque = pataque;
    }
    void Personaje::setNombre(std::string pnombre) {
        nombre = pnombre;
    }
    void Personaje::setPosicionX(int pposicionX) {
        posicionX = pposicionX;
    }
    void Personaje::setPosicionY(int pposicionY) {
        posicionY = pposicionY;
    }

    // Método para mover el personaje
    void Personaje::mover(int x, int y) {
        posicionX = x;
        posicionY = y;
    }
