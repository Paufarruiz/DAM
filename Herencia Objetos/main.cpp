#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Personaje.h"
#include "EnemigoFinal.h"
#include <conio.h>

const int FILAS = 10;
const int COLUMNAS = 22;

bool salaOcultaDetectet = true;

int TesoroX = rand() % (FILAS - 2) + 1;  // Generar coordenada X aleatoria
int TesoroY = rand() % (COLUMNAS - 2) + 1;     // Generar coordenada Y aleatoria

void mostrarPantallaInicio() {
    std::cout << "                           *******************************************************" << std::endl;
    std::cout << "                           *                                                     *" << std::endl;
    std::cout << "                           *                        DARK                         *" << std::endl;
    std::cout << "                           *          La Venganza en el Laberinto Oscuro         *" << std::endl;
    std::cout << "                           *                                                     *" << std::endl;
    std::cout << "                           *******************************************************" << std::endl;
    std::cout << std::endl;
    std::cout << "                                           Bienvenido/a a DARK" << std::endl;
    std::cout << "                                ¡Preparate para una aventura que cambiara" << std::endl;
    std::cout << "                                         tu insignificante vida!" << std::endl << std::endl << std::endl << std::endl << std::endl;
    std::cout << "La nueva producion de Kojima Productions" << std::endl << std::endl << std::endl;
    std::cout << std::endl;
    std::cout << "Presiona Enter para continuar..." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void dibujarMapa(char mapa[FILAS][COLUMNAS], Personaje& enemigo1, Personaje& enemigo2, Personaje& enemigo3, EnemigoFinal& enemigoFinal) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (i == enemigo1.getPosicionY() && j == enemigo1.getPosicionX()) {
                std::cout << "E";
            }
            else if (i == enemigo2.getPosicionY() && j == enemigo2.getPosicionX()) {
                std::cout << "E";
            }
            else if (i == enemigo3.getPosicionY() && j == enemigo3.getPosicionX()) {
                std::cout << "E";
            }
            else if (i == enemigoFinal.getPosicionY() && j == enemigoFinal.getPosicionX()) {
                std::cout << "O";
            }
            else if (i == TesoroX && j == TesoroY) {
                std::cout << "T";
            }
            else {
                std::cout << mapa[i][j];
            }
        }
        std::cout << std::endl;
    }
}

void iniciarBatalla(Personaje& jugador, Personaje& enemigo) {
    // Imprimir información de la batalla
    std::cout << "¡Ha comenzado una batalla contra " << enemigo.getNombre() << "!" << std::endl;
    std::cout << "Personaje principal: " << jugador.getNombre() << " - Vida: " << jugador.getVida() << std::endl;
    std::cout << enemigo.getNombre() << ": Vida: " << enemigo.getVida() << std::endl;
    std::cout << std::endl;

    // Bucle de combate
    while (jugador.getVida() > 0 && enemigo.getVida() > 0) {
        // Turno del personaje principal
        int damagePersonaje = jugador.getAtaque();
        enemigo.setVida(enemigo.getVida() - damagePersonaje);

        std::cout << jugador.getNombre() << " ataca a " << enemigo.getNombre() << " y causa " << damagePersonaje << " puntos de daño." << std::endl;

        // Verificar si el enemigo ha sido derrotado
        if (enemigo.getVida() <= 0) {
            std::cout << enemigo.getNombre() << " ha sido derrotado." << std::endl;
            break;  // Salir del bucle de combate
        }

        // Turno del enemigo
        int damageEnemigo = enemigo.getAtaque();
        jugador.setVida(jugador.getVida() - damageEnemigo);

        std::cout << enemigo.getNombre() << " ataca a " << jugador.getNombre() << " y causa " << damageEnemigo << " puntos de daño." << std::endl;

        // Verificar si el personaje principal ha sido derrotado
        if (jugador.getVida() <= 0) {
            std::cout << jugador.getNombre() << " ha sido derrotado." << std::endl;
            break;  // Salir del bucle de combate
        }

        std::cout << std::endl;
        std::cout << "Personaje principal: Vida: " << jugador.getVida() << std::endl;
        std::cout << enemigo.getNombre() << ": Vida: " << enemigo.getVida() << std::endl;
        std::cout << std::endl;

        // Pausa para mostrar la información y dar tiempo al jugador
        std::cout << "Presiona cualquier tecla para continuar..." << std::endl;
        _getch();  // Esperar a que se presione una tecla
    }
}

// Función para iniciar la batalla contra el enemigo final
void iniciarBatallaFinal(Personaje& jugador, EnemigoFinal& enemigoFinal) {
    std::cout << "¡Ha comenzado la batalla contra el Enemigo Final!" << std::endl;

   while (jugador.getVida() > 0 && enemigoFinal.getVida() > 0) {

        // Verificar si el enemigo final ha sido derrotado
        if (enemigoFinal.getVida() <= 0) {
           std::cout << "¡Has derrotado al Enemigo Final! ¡Has ganado el juego!" << std::endl;
           break;
        }

        // Verificar si el jugador ha sido derrotado
        if (jugador.getVida() <= 0) {
           std::cout << "Has sido derrotado por el Enemigo Final. ¡Has perdido el juego!" << std::endl;
           break;
        }

        // Esperar a que el usuario presione Enter
        std::cout << "Presione Enter para continuar..." << std::endl;
        getchar();

        // Turno del jugador
        int damagePersonaje = jugador.getAtaque();
        enemigoFinal.setVida(enemigoFinal.getVida() - damagePersonaje);

        std::cout << jugador.getNombre() << " ataca a " << enemigoFinal.getNombre() << " y causa " << damagePersonaje << " puntos de daño." << std::endl;


        // Turno del enemigo final
        int rattackFinal = rand() % 3 + 1;
        if (rattackFinal == 1)
        {
            int damageEnemigo = enemigoFinal.getAtaque();
            jugador.setVida(jugador.getVida() - damageEnemigo);

            std::cout << enemigoFinal.getNombre() << " ataca a " << jugador.getNombre() << " y causa " << damageEnemigo << " puntos de daño." << std::endl;
        }
        else  if (rattackFinal == 2)
        {
            enemigoFinal.atacarSuperAtaque1(jugador);
            int damageEnemigo = enemigoFinal.getSuperAtaque1();
            std::cout << enemigoFinal.getNombre() << " ataca a " << jugador.getNombre() << " y causa " << damageEnemigo << " puntos de daño." << std::endl;
        }
        else  if (rattackFinal == 3)
        {
            enemigoFinal.atacarSuperAtaque1(jugador);
            int damageEnemigo = enemigoFinal.getSuperAtaque2();
            std::cout << enemigoFinal.getNombre() << " ataca a " << jugador.getNombre() << " y causa " << damageEnemigo << " puntos de daño." << std::endl;
        }

        // Mostrar información de la batalla
        std::cout << "-------------------------" << std::endl;
        std::cout << "Vida del Jugador: " << jugador.getVida() << std::endl;
        std::cout << "Vida del Enemigo Final: " << enemigoFinal.getVida() << std::endl;
        std::cout << "-------------------------" << std::endl;
    }
}

void historiaDelPersonaje() {
    std::cout << "*****************************************************" << std::endl;
    std::cout << "           VENGANZA EN EL LABERINTO OSCURO           " << std::endl;
    std::cout << "*****************************************************" << std::endl;

    std::cout << R"(
Había una vez un valiente guerrero llamado Aragorn. Era un hombre noble y justo,
y amaba a su hija, Elena, con todo su corazón.

Un oscuro día, un monstruo maligno llamado Drakon acechó su hogar. En un acto de
crueldad, Drakon arrebató la vida de Elena delante de los ojos de Aragorn. Su
corazón lleno de dolor y sed de venganza, Aragorn juró encontrar al monstruo y
hacerlo pagar por su malvado acto.

                            ┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈
                            ┈┈┈┈┈▁▁▁▁▁▁▁▁┈┈
                            ┈┈┈┈╱╱╱╱╱╱╲┈┈┈☼
                            ┈┈┈╱╱╱╱╱╱┈┈╲┈┈┈
                            ┈╱╲┃▔▔▔▔▏┏┓▕┈┈┈
                            ╱┈┈┃┊┊┊┊▏┃┃▕┈╱╲
                            ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔

Aragorn se aventuró en el Laberinto Oscuro, un lugar lleno de peligros y misterios.
Su único objetivo era encontrar a Drakon y acabar con su reinado de terror. Con
su espada en mano y su determinación inquebrantable, Aragorn se adentró en la oscuridad.

El laberinto estaba lleno de trampas mortales, criaturas feroces y pasillos sin fin.
Pero nada detendría a Aragorn en su búsqueda de venganza. Cada paso que daba lo
acercaba más a su objetivo, y su sed de justicia crecía con cada desafío superado.

La batalla final se avecinaba. Aragorn podía sentir la presencia de Drakon en lo más
profundo del laberinto. Era el momento de enfrentarse a su enemigo y hacer justicia por
la vida perdida de su amada hija.

Con coraje y habilidad, Aragorn se enfrentó a Drakon en una batalla épica. El sonido
de las espadas chocando resonaba por todo el laberinto. Aragorn luchaba con todas sus
fuerzas, alimentado por su deseo de venganza.

Al final, con un golpe certero, Aragorn derrotó a Drakon. El monstruo yacía sin vida
a sus pies, y Aragorn sintió una mezcla de satisfacción y tristeza. Su misión estaba
cumplida, pero el vacío dejado por la pérdida de su hija nunca sería llenado.

Aragorn salió del Laberinto Oscuro, llevando consigo el recuerdo de su hija y la
certeza de que había hecho justicia. A partir de ese día, su nombre sería recordado
como un símbolo de valentía y venganza en el reino.

                            ┈┈┈┈▅┈┈▕▀┈┈┈┈┈┈┈
                            ┈┈┈▕┈┈┈╱╲▕▀┈┈┈┈┈
                            ┈┈┈╱╲┈┈▏▕╱╲┈┈┈┈
                            ┈┈┈▏▕╱╲▏▎▏▕╱╲┈▃
                            ┈╱╲▏▎▅▂▅▂▏▎▏▎▏▏
                            ▂▏▎▏▕╭┳┳╮▏┊▏▕╱╲
                            ▏▏┊▏▎┃┊┊┃▏▎▏▎▏▕
                            ▇▆▅▃▂┻┻┻┻▂▃▅▆▇▉

*****************************************************

¡Gracias por jugar a 'DARK Venganza en el Laberinto Oscuro'!

*****************************************************    
    )" << std::endl;
}

/*
void descubrirSalaOculta(Personaje& jugador, EnemigoFinal& enemigoFinal) {
    const int salaOcultaFILAS = 8;
    const int salaOcultaCOLUMNAS = 10;
    char salaOculta[salaOcultaFILAS][salaOcultaCOLUMNAS] = {
        {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
        {'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X'},
        {'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X'},
        {'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X'},
        {'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X'},
        {'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X'},
        {'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X'},
        {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'}
    };

    const int jefeFinalFILAS = 8;
    const int jefeFinalCOLUMNAS = 10;
    char jefeFinal[jefeFinalFILAS][jefeFinalCOLUMNAS] = {
        // Definir el tablero del jefe final según tus necesidades
    };

    // Verificar si el jugador choca con la sala oculta
    if (jugador.getPosicionX() == 5 && jugador.getPosicionY() == 4) {
        system("cls");
        std::cout << "¡Has descubierto una sala oculta! ¡Prepárate para la batalla final!" << std::endl;

        // Mostrar tablero del jefe final
        for (int i = 0; i < jefeFinalFILAS; i++) {
            for (int j = 0; j < jefeFinalCOLUMNAS; j++) {
                std::cout << jefeFinal[i][j];
            }
            std::cout << std::endl;
        }

        // Iniciar la batalla contra el jefe final
        iniciarBatalla(jugador, enemigoFinal);
    }

}
*/


int main() {

    mostrarPantallaInicio();

    // Inicializar la semilla aleatoria
    srand(time(NULL));

    // Jugador
    Personaje jugador(325, 10, "Jugador", 1, 1);

    // Salida
    //int salidaX = rand() % 4 + 1;
    //int salidaY = 5;

    // Enemigos normales
    Personaje enemigo1(50, 5, "Enemigo 1", rand() % (COLUMNAS - 2) + 1, rand() % (FILAS - 2) + 1);
    Personaje enemigo2(50, 5, "Enemigo 2", rand() % (COLUMNAS - 2) + 1, rand() % (FILAS - 2) + 1);
    Personaje enemigo3(50, 5, "Enemigo 3", rand() % (COLUMNAS - 2) + 1, rand() % (FILAS - 2) + 1);

    // Enemigo final
    EnemigoFinal enemigoFinal(150, 15, "Enemigo Final", rand() % (COLUMNAS - 2) + 1, rand() % (FILAS - 2) + 1, 20, 25);

    //Tablero
    char mapa[FILAS][COLUMNAS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#','#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', ' ', '#',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#','#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    int posX = jugador.getPosicionX();  // Posición inicial en x del personaje
    int posY = jugador.getPosicionY();  // Posición inicial en y del personaje
    char tecla;

    mapa[posY][posX] = 'P';  // Dibujar el personaje en la posición inicial

    if (salaOcultaDetectet == true)
    {
        while (true) {
            system("cls");  // Limpiar la consola
            dibujarMapa(mapa, enemigo1, enemigo2, enemigo3, enemigoFinal);

            tecla = _getch();  // Leer la tecla presionada

            // Borrar la posición anterior del personaje
            mapa[posY][posX] = ' ';

            // Actualizar la posición del personaje según la tecla presionada
            if (tecla == 'w' && mapa[posY - 1][posX] != '#') {
                posY--;
            }
            else if (tecla == 's' && mapa[posY + 1][posX] != '#') {
                posY++;
            }
            else if (tecla == 'a' && mapa[posY][posX - 1] != '#') {
                posX--;
            }
            else if (tecla == 'd' && mapa[posY][posX + 1] != '#') {
                posX++;
            }
            else if (tecla == 'q') {
                break;
            }



            mapa[posY][posX] = 'P'; // Dibujar el personaje en la nueva posición



            // Verificar si mataste al enemigo Final
            if (enemigoFinal.getVida() <= 0) {
                std::cout << "¡Has derrotado al Enemigo Final! ¡Has ganado el juego!" << std::endl << std::endl << std::endl << std::endl << std::endl;
                historiaDelPersonaje();
                break;  // Salir del Juego
            }

            // Verificar si el jugador ha sido derrotado
            if (jugador.getVida() <= 0) {
                std::cout << "Has sido derrotado. ¡Has perdido el juego!" << std::endl;
                std::cout << "¡Menudo Paquete eres!" << std::endl;
                break;
            }
           


            // Verificar si el personaje choca contra un enemigo
            bool choque = false;
            if (posX == enemigo1.getPosicionX() && posY == enemigo1.getPosicionY()) {
                choque = true;
                iniciarBatalla(jugador, enemigo1);
            }
            else if (posX == enemigo2.getPosicionX() && posY == enemigo2.getPosicionY()) {
                choque = true;
                iniciarBatalla(jugador, enemigo2);
            }
            else if (posX == enemigo3.getPosicionX() && posY == enemigo3.getPosicionY()) {
                choque = true;
                iniciarBatalla(jugador, enemigo3);
            }
            else if (posX == enemigoFinal.getPosicionX() && posY == enemigoFinal.getPosicionY()) {
                //salaOcultaDetectet = false; //Entrar a la sala oculta
                //break;
                choque = true;
                iniciarBatallaFinal(jugador, enemigoFinal);
            }
            else if (posX == TesoroX && posY == TesoroY) {
                std::cout << "Lo as encontrado. ¡El TESORO OCULTO!" << std::endl;
                std::cout << "¡Tu no seras el mas suertudo del mundo!" << std::endl;
                choque = true;
            }

            if (choque) {
                // Realizar acciones después de la batalla
                posX = rand() % (COLUMNAS - 2) + 1;
                posY = rand() % (FILAS - 2) + 1;
            }



            mapa[posY][posX] = 'P';  // Dibujar el personaje en la nueva posición
        }
    }
    else
    {
        //descubrirSalaOculta(jugador, enemigoFinal);

    }

}
