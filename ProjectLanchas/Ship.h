#pragma once
#include <iostream>
class Ship
{
private:

	std::string name;
	int velocidad;
	int distancia;
	int nitro;

public:
	//constructor

	Ship(int pvelocidad, std::string pname, int pdistancia, int pnitro);

	//getters

	int getVelocidad();
	int getDistancia();
	std::string getName();
	int getNitro();

	//setters

	void setVelocidad(int pvelocidad);
	void setDistancia(int pdistancia);
	void setName(std::string pname);
	void getNitro(int pnitro);

	//metodos propios

	void movimiento();
};

