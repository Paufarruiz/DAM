#include "Ship.h"
#include <iostream>

using namespace std;

//constructor

Ship::Ship(int pvelocidad, std::string pname, int pdistancia, int pnitro) {
	velocidad = pvelocidad;
	name = pname;
	distancia = pdistancia;
	nitro = pnitro;
}

//getters

int Ship::getVelocidad() {
	return velocidad;
}
int Ship::getDistancia() {
	return distancia;
}
std::string Ship::getName() {
	return name;
}
int Ship::getNitro() {
	return nitro;
}

//setters

void Ship::setVelocidad(int pvelocidad) {
	velocidad = pvelocidad;
}
void Ship::setDistancia(int pdistancia) {
	distancia = pdistancia;
}
void Ship::setName(std::string pname) {
	name = pname;
}
void Ship::getNitro(int pnitro) {
	nitro = pnitro;
}

//metodos propios

void Ship::movimiento() {
	std::cout << "El jugador " << getName() << " se a movido " << getDistancia() << std::endl;
}
