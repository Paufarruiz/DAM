#include <iostream>
#include "Ship.h"

using namespace std;



int shipSelected;
string player1;
string player2 = "PEPO";
int numDado;
string nitro;
bool nitroSelect;
bool nitroSelect2;
int nitroMove;
int nitroMove2;
int distancia;
int distancia2;


void gameStart() {
    cout << "Inserta el nombre del piloto\n";
    cin >> player1;
}

int boatSelected() {
    int ships;
    while (!shipSelected) {
        cout << "Elige el tipo de barco que quieres utilizar\n";
        cout << "Barco 1\n";
        cout << "              __  " << endl;
        cout << "             |__/  "<< endl;
        cout << "            /|" << endl;
        cout << "           / |" << endl;
        cout << "          /  |" << endl;
        cout << "         /   |" << endl;
        cout << "        /    |" << endl;
        cout << "       /     |" << endl;
        cout << "      /      |" << endl;
        cout << "     /       |" << endl;
        cout << "    /________| " << endl;
        cout << "            _|_______  " << endl;
        cout << "    ______ / = = = = \______  " << endl;
        cout << "    /                      /    " << endl;
        cout << "    \_____________________/    " << endl;

        cout << "Barco 2\n";
        cout << "     __      _________ " << endl;
        cout << "     ||____ / = = = = \______  " << endl;
        cout << "    /                      /    " << endl;
        cout << "    \_____________________/    " << endl;

        cin >> ships;

        //IF PARA SELECTED  shipSelected
        if (ships == 1)
        {
            shipSelected = true;
        }
        else {
            shipSelected = true;
        }

    }
    shipSelected = false;

    return ships;
}
void dado() {
    numDado = rand() % 5 + 1;
    cout << "Tiras del dado y te a salido un " << numDado << endl;
}
void movimientoNitro() {
    while (!nitroSelect)
    {
        cout << "Quieres utilizar el nitro: " << endl;
        cout << "Si " << endl;
        cout << "No " << endl;
        cin >> nitro;

        if (nitro == "Si")
        {
            nitroMove = rand() % 2 ;
            if (nitroMove == 0)
            {
                cout << "GG que suerte con el nitro" << endl;
                distancia = distancia * 2;
                nitroSelect = true;
            }
            if (nitroMove == 1)
            {
                cout << "F en el chat XD, el nitro salio pocho" << endl;
                distancia = distancia / 2;
                nitroSelect = true;
            }
            
        }
        if (nitro == "No")
        {
            nitroMove = 3;
            nitroSelect = true;

        }
    }

}
void nitroMaquina() {
    
    while (!nitroSelect2)
    {
        int nitroM = rand() % 2;
        if (nitroM == 1)
        {
            nitroMove2 = rand() % 2;
            if (nitroMove2 == 0)
            {
                cout << "GG PEPO que suerte con el nitro" << endl << endl << endl;
                distancia = distancia * 2;
                nitroSelect2 = true;
            }
            if (nitroMove2 == 1)
            {
                cout << "F en el chat PEPO, el nitro salio pocho" << endl << endl << endl;
                distancia = distancia / 2;
                nitroSelect2 = true;
            }

        }
        if (nitroM == 2)
        {
            nitroMove2 = 3;
            nitroSelect2 = true;

        }
    }
    
}
void distanciaF(Ship& ship, Ship& ship2) {
    dado();
    distancia = distancia + numDado * 100;
    ship.setDistancia(distancia);
    ship.movimiento();

    dado();
    distancia2 = distancia2 + numDado * 100;
    ship2.setDistancia(distancia2);
    ship2.movimiento();
}


void movimientFinal() {
    if (nitroMove == 0)
    {
        distancia = distancia * 2;
    }
    if (nitroMove == 1)
    {
        distancia = distancia / 2;
    }
    if (nitroMove == 3)
    {
        distancia = distancia;
    }

    if (nitroMove2 == 0)
    {
        distancia2 = distancia2 * 2;
    }
    if (nitroMove2 == 1)
    {
        distancia2 = distancia2 / 2;
    }
    if (nitroMove2 == 3)
    {
        distancia2 = distancia2;
    }
    
    cout << "El jugador " << player1 << " se a movido en toda la partida un total de " << distancia << endl;
    cout << "El jugador " << player2 << " se a movido en toda la partida un total de " << distancia2 << endl;
}

void final(int pShips) {
    if (pShips == 1)
    {
        int n1 = distancia / 100;
        int n2 = distancia2 / 100;
        cout << string(n1, '   ') << "              __  " << endl;
        cout << string(n1, '   ') << "             |__/  " << endl;
        cout << string(n1, '   ') << "            /|" << endl;
        cout << string(n1, '   ') << "           / |" << endl;
        cout << string(n1, '   ') << "          /  |" << endl;
        cout << string(n1, '   ') << "         /   |" << endl;
        cout << string(n1, '   ') << "        /    |" << endl;
        cout << string(n1, '   ') << "       /     |" << endl;
        cout << string(n1, '   ') << "      /      |" << endl;
        cout << string(n1, '   ') << "     /       |" << endl;
        cout << string(n1, '   ') << "    /________| " << endl;
        cout << string(n1, '   ') << "            _|_______  " << endl;
        cout << string(n1, '   ') << "    ______ / = = = = \______  " << endl;
        cout << string(n1, '   ') << "    /                      /    " << endl;
        cout << string(n1, '-_-') << "    \_____________________/    " << endl;

        cout << string(n2, '   ') << "     __      _________ " << endl;
        cout << string(n2, '   ') << "     ||____ / = = = = \______  " << endl;
        cout << string(n2, '   ') << "    /                      /    " << endl;
        cout << string(n2, '-_-') << "    \_____________________/    " << endl;
    }
    else {
        int n1 = distancia / 100;
        int n2 = distancia2 / 100;
        cout << string(n2, '   ') << "              __  " << endl;
        cout << string(n2, '   ') << "             |__/  " << endl;
        cout << string(n2, '   ') << "            /|" << endl;
        cout << string(n2, '   ') << "           / |" << endl;
        cout << string(n2, '   ') << "          /  |" << endl;
        cout << string(n2, '   ') << "         /   |" << endl;
        cout << string(n2, '   ') << "        /    |" << endl;
        cout << string(n2, '   ') << "       /     |" << endl;
        cout << string(n2, '   ') << "      /      |" << endl;
        cout << string(n2, '   ') << "     /       |" << endl;
        cout << string(n2, '   ') << "    /________| " << endl;
        cout << string(n2, '   ') << "            _|_______  " << endl;
        cout << string(n2, '   ') << "    ______ / = = = = \______  " << endl;
        cout << string(n2, '   ') << "    /                      /    " << endl;
        cout << string(n2, '-_-') << "    \_____________________/    " << endl;

        cout << string(n1, '   ') << "     __      _________ " << endl;
        cout << string(n1, '   ') << "     ||____ / = = = = \______  " << endl;
        cout << string(n1, '   ') << "    /                      /    " << endl;
        cout << string(n1, '-_-') << "    \_____________________/    " << endl;
    }



}
void winner() {
    if (distancia > distancia2)
    {
        cout << player1 << " es el ganador" << endl;
    }
    else if (distancia < distancia2)
    {
        cout << player2 << " es el ganador" << endl;
    } else{
        cout << player1 << " empato contra " << player2 << endl;
    }
}
int main() {
    int ships = 0;
    srand(time(NULL));
    gameStart();
    ships =  boatSelected();
    Ship boat1(0, player1, 0, 1);
    Ship boat2(0, player2, 0, 1);
    for (size_t i = 1; i < 6; i++)
    {
        movimientoNitro();
        nitroMaquina(); 
        distanciaF(boat1, boat2);      
    }

    movimientFinal();
    final(ships);
    winner();

    //boat1.setName(player1);

}