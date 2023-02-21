// BlackJack.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

//Variables de uso
int picas[13];
int diamantes[13];
int Corazones[13];
int Treboles[13];
int chooseAS;
bool gameOver = false;

//Variables Jugador 1
string player1;
int pointsPlayer1 = 0;
bool surrender1 = false;
bool winnerP1 = false;
bool loserP1 = false;

//Variables Jugador 2
string player2 = "Croupiere";
int pointsPlayer2 = 0;
bool surrender2 = false;
bool winnerP2 = false;
bool loserP2 = false;


//Funciones

//Inicializa cualquier array con sus 12 posiciones a 1
//de esta forma, indicamos que todas las cartas están disponibles  
//si una posición está a 0, esa carta ya está repartida y no se repite
void inicializaArray(int(&pArray)[13]) {
    for (int i = 0; i < 13; i++) {
        pArray[i] = 1;
    }
}

//Comprueba aleatoriamente si ha de dar picas o diamantes
//y busca una carta al azar. Hasta que no encuentre una posición
// a 1, no asigna esa carta, cuyo valor es el indiceCarta + 1
void chooseCards(int& totalPoints, string player) {
    bool choosed = false;
    int indiceCarta = 0;
    int indicePalo = 0;
    string tipoPalo;
    while (!choosed) {
        //Elije una carta del 1 al 12
        indiceCarta = rand() % 13;
        indicePalo = rand() % 4;
        //Comprueba las Copas
        if (indicePalo == 0) {
            if (picas[indiceCarta] == 1) {
                //devuelve la carta
                picas[indiceCarta] = 0;
                choosed = true;
                tipoPalo = "picas";
            }
            //Comprueba los diamantes
        }
        else if(indicePalo == 1) {
            if (diamantes[indiceCarta] == 1) {
                //devuelve la tarjeta
                diamantes[indiceCarta] = 0;
                choosed = true;
                tipoPalo = "diamantes";
            }
        }
        else if (indicePalo == 2) {
            if (Corazones[indiceCarta] == 1) {
                //devuelve la tarjeta
                Corazones[indiceCarta] = 0;
                choosed = true;
                tipoPalo = "Corazones";
            }
        }
        else if (indicePalo == 3) {
            if (Treboles[indiceCarta] == 1) {
                //devuelve la tarjeta
                Treboles[indiceCarta] = 0;
                choosed = true;
                tipoPalo = "Treboles";
            }
        }
        if (indiceCarta == 0){
            if (player == player1){
                cout << "\n Has sacado un AS, que valor quieres darle 1 o 11" << endl;
                cin >> chooseAS;

                //COMPROBAR SI HA ELEGIDO BIEN UN 1 U 11. SI NO, HAY QUE VOLVER A PREGUNTAR
                while (chooseAS == 1 || chooseAS == 11){
                    if (chooseAS == 1) {
                        totalPoints += 1;
                        cout << "El jugador " << player << " ha sacado un AS de " << tipoPalo << " y tiene un total de " << totalPoints << endl;

                    }
                    else if (chooseAS == 11) {
                        totalPoints += 11;
                        cout << "El jugador " << player << " ha sacado un AS de " << tipoPalo << " y tiene un total de " << totalPoints << endl;

                    }
                }
                
            }
            else if (player == player2){
                if (totalPoints + 11 <= 21) {
                    totalPoints += 11;
                    cout << "El jugador " << player << " ha sacado un AS de " << tipoPalo << " y tiene un total de " << totalPoints << endl;

                }
                else {
                    totalPoints += 1;
                    cout << "El jugador " << player << " ha sacado un AS de " << tipoPalo << " y tiene un total de " << totalPoints << endl;

                }
            }
        }else if (indiceCarta >= 10){
            totalPoints += 10;
            if (indiceCarta == 10) {
                //J
                cout << "El jugador " << player << " ha sacado una J de " << tipoPalo << " y tiene un total de " << totalPoints << endl;
            }
            else if (indiceCarta == 11) {
                //Q
                cout << "El jugador " << player << " ha sacado una Q de " << tipoPalo << " y tiene un total de " << totalPoints << endl;
            }
            else {
                //K
                cout << "El jugador " << player << " ha sacado un K de " << tipoPalo << " y tiene un total de " << totalPoints << endl;
            }
           
        }
        else {
            totalPoints += indiceCarta + 1;
            cout << "El jugador " << player << " ha sacado un " << indiceCarta + 1 << " de " << tipoPalo << " y tiene un total de " << totalPoints << endl;
        }
    }
   }

bool checkPoints(int& points, bool& winner, bool& loser) {
    if (points == 21) {
        winner = true;
        return true;
    }
    else if (points > 21) {
        loser = true;
        return true;
    }
    return false;
}

bool checkWhoWins(int points1, int points2, bool& winner2) {
    if (points2 > points1) {
        winner2 = true;
        return true;
    }
    else {
        return false;
    }
}

void pau() {
    if (player1 == "pau") {
        cout << "Biendenido BOSS\n";
        cout << "El jugador " << player1 << " ha sacado un 10 de diamantes y tiene un total de 10 \n";
        cout << "El jugador " << player1 << " ha sacado un AS de diamantes y tiene un total de 21 \n";
        cout << "Ganas por ser el mejor developer del mundo XD\n\n";
        cout << "JAVI: Metroid Prime BEST GAME EVER \n\n";
        cout << "    __  ___     __             _     __   ____       _               " << "\n";
        cout << "   /  |/  /__  / /__________  (_)___/ /  / __ \_____(_)___ ___  ___  " << "\n";
        cout << "  / /|_/ / _ \/ __/ ___/ __ \/ / __  /  / /_/ / ___/ / __ `__ \/ _ \ " << "\n";
        cout << " / /  / /  __/ /_/ /  / /_/ / / /_/ /  / ____/ /  / / / / / / /  __/ " << "\n";
        cout << "/_/  /_/\___/\__/_/   \____/_/\__,_/  /_/   /_/  /_/_/ /_/ /_/\___/  " << "\n";
        winnerP1 = true;
    }
}

void gameStart() {
    cout << "Inserta el nombre del Player 1:\n";
    cin >> player1;
    
}

int main()
{
    gameStart();
    
    if (player1 == "pau") {
        pau();
    }
    else {
        inicializaArray(picas);
        inicializaArray(diamantes);
        inicializaArray(Corazones);
        inicializaArray(Treboles);
        srand(time(NULL));
        //primer reparto de cartas
        chooseCards(pointsPlayer1, player1);

        chooseCards(pointsPlayer1, player1);

        //Puede pasar que ganemos o perdamos nada más comenzar
        surrender1 = checkPoints(pointsPlayer1, winnerP1, loserP1);

        chooseCards(pointsPlayer2, player2);

        while (!surrender1) {
            int choice = 0;
            //Comienza el juego con el jugador 1
            while (choice != 1 && choice != 2) {
                cout << "Tienes " << pointsPlayer1 << ".Quieres pedir carta?" << endl;
                cout << "1.- Sí" << endl;
                cout << "2.- No" << endl;
                cin >> choice;
                if (choice != 1 && choice != 2) {
                    cout << "Por favor, elije una opción válida." << endl;
                }
            }
            if (choice == 1) {
                chooseCards(pointsPlayer1, player1);
                surrender1 = checkPoints(pointsPlayer1, winnerP1, loserP1);
                //comprueba si se ha pasado o ha ganado la partida
            }
            else {
                //Si no quiere carta, es turno de la banca
                surrender1 = true;
            }
        }
    }
    //Termina el turno del jugador 1. Hay que comprobar si ha ganado (winnerP1) o perdido ya (loserP1), o si la banca tiene que tirar
    if (winnerP1) {
        cout << "El jugador " << player1 << " gana y la banca pierde" << endl;
    }
    else if (loserP1) {
        cout << "El jugador " << player1 << " pierde y la banca gana" << endl;
    }
    else {
        //turno de la banca
        while (!surrender2) {
            chooseCards(pointsPlayer2, player2);

            surrender2 = checkPoints(pointsPlayer2, winnerP2, loserP2);
            if (!surrender2) {
                //Comprueba si la banca ya gana por puntos
                surrender2 = checkWhoWins(pointsPlayer1, pointsPlayer2, winnerP2);
            }
        }
        if (winnerP2) {
            cout << "La banca gana y el jugador " << player1 << " pierde" << endl;
        }
        else if (loserP2) {
            cout << "La banca pierde y el jugador " << player1 << " gana" << endl;
        }
    }

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
