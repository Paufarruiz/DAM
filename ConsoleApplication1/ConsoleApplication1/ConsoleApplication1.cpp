// ConsoleApplication1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include<stdlib.h>
#include<time.h>
#include<string>

using namespace std;

string enemyName = "Manolo";
int enemyHP=1000;
int enemyDamage;
bool enemyIsAlive = true;

string enemyName2 = "Hermenegildo";
int enemyHP2 = 1000;
int enemyDamage2;
bool enemyIsAlive2 = true;
int CordonesFin;

string heroName;
int heroDamage;
string heroDamage2;
int heroHP=5000;
bool heroIsAlive = true;
int herofocus;
int heromana = 200;
bool attackSelected;

int main()
{
    cout << "Los hermanos titiriteros te acaban de aparecer, " << enemyName << " acaba de aparecer con "<< enemyHP << " de vida y su hermano "<<enemyName2<< " con "<<enemyHP2<<" de vida.\n";
    cout << "Inserta el nombre del heroe que lo va a derrotar\n";
    cin >> heroName;
    cout << "El nombre del heroe es "<< heroName <<" y tiene "<<heroHP<<" puntos de vida\n";

    while ((enemyIsAlive == true || enemyIsAlive2==true) && heroIsAlive == true){

        

        while(!attackSelected){
            cout << "Que ataque quieres hacerle al enemigo con la vara del heroe?(espada,magia,punch o hero)\n";
            cin >> heroDamage2;
            if (heromana <= 0)
            {
                cout << "No tienes mana, no puedes utilizar MAGIA o HERO\n";
                attackSelected = false;
            }
            if (heroDamage2 == "espada")
            {
                heroDamage = 500;
                attackSelected = true;
            }
            if (heromana > 0)
            {
                if (heroDamage2 == "magia")
                {
                    heroDamage = 500;
                    heromana = heromana - 100;
                    attackSelected = true;
                }if (heroDamage2 == "hero")
                {
                    heroDamage = 2000;
                    heromana = heromana - 200;
                    attackSelected = true;
                }
            }
            if (heroDamage2 == "punch")
            {
                heroDamage = 250;
                attackSelected = true;
            }
        }
        attackSelected = false;

        cout << "A que enemigo quieres hacerle dps?\n"
                "1-Manolo\n"
                "2-Hermenegildo\n";
        cin >> herofocus;

        srand(time(NULL));
        if (enemyIsAlive)
        {
            enemyDamage = 250 + rand() % (1500 - 0);
        }
        else
        {
            enemyDamage = 0;
        }
        

        if (enemyIsAlive2){
        enemyDamage2 = 250 + rand() % (1500 - 0);
        }
        else {
            enemyDamage2 = 0;
        }

        if (herofocus == 1)
        {
            enemyHP = enemyHP - heroDamage;
            cout << "Al enemigo le quedan " << enemyHP << " puntos de vida y a su hermano " << enemyHP2 << "puntos de vida\n";
        }
        else
        {
            enemyHP2 = enemyHP2 - heroDamage;
            cout << "Al enemigo le quedan " << enemyHP << " puntos de vida y a su hermano " << enemyHP2 << "puntos de vida\n";
        }

         if (enemyHP <= 0) {
            enemyHP = 0;
            enemyIsAlive = false;
            cout << "Has derrotado al enemigo\n";
        }

         if (enemyHP2 <= 0)
         {
             enemyHP2 = 0;
             enemyIsAlive2 = false;
             cout << "Has derrotado al hermano del enemigo\n";
         }

        if (enemyIsAlive==true || enemyIsAlive2 == true) {
            heroHP = heroHP - enemyDamage - enemyDamage2;
            cout << "El enemigo te ha hecho " << enemyDamage << " puntos de dps y su hermano te a hecho "<<enemyDamage2<<" te quedan " << heroHP << " de vida\n";
        }

        if (heroHP <= 0) {
            heroHP = 0;
            heroIsAlive = false;
            cout << "El heroe a muerto, la ultima esperanza de la humanidad se extingue\n";
        }
        if (enemyHP2 <= 0 && enemyHP <=0)
        {
            cout << "As derrotado a los hermanos titiriteros, gracias a ello la humanidad ve una luz de esperanza, as optenido cordones del fin\n";
            cout << "Quieres saber que son los cordones del fin? Entonces pulsa 1\n";
            cin >> CordonesFin;
            if (CordonesFin == 1)
            {
                cout << "(una arma que son unos cordones tan finos que no se ven al ojo humano, creados por el lazo de fraternidad de los hermanos titiriteros)\n";
                cout << "Fin del Juego\n\n\n";
            }
            else
            {
                cout << "Fin del Juego";
            }
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
