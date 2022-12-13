#include <iostream>
#include<stdlib.h>
#include<time.h>
#include<string>

using namespace std;

string enemyName = "Manolo";
int enemyHP = 1000;
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
int heroHP = 50000;
bool heroIsAlive = true;
int herofocus;
int heromana = 200;
bool attackSelected;


void gameStart() {
    cout << "Los hermanos titiriteros te acaban de aparecer, " << enemyName << " acaba de aparecer con " << enemyHP << " de vida y su hermano " << enemyName2 << " con " << enemyHP2 << " de vida.\n";
    cout << "Inserta el nombre del heroe que lo va a derrotar\n";
    cin >> heroName;
    cout << "El nombre del heroe es " << heroName << " y tiene " << heroHP << " puntos de vida\n";
}

bool checkHeroStatus() {
    
    if (heroHP <= 0) {
        heroHP = 0;
        heroIsAlive = false;
        return false;
        
    }
}

void attackSelected2() {
    while (!attackSelected) {
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
}

int enemyAtack() {
    srand(time(NULL));
    if (enemyIsAlive)
    {
        enemyDamage = 250 + rand() % (1500 - 0);
        
    }
    else
    {
        enemyDamage = 0;
    }
    return enemyDamage;
}

int enemyAtack2() {
    if (enemyIsAlive2) {
        return 250 + rand() % (1500 - 0);
    }
    else {
        return 0;
    }
}


int heroFocus2() {
    cout << "A que enemigo quieres hacerle dps?\n"
        "1-Manolo\n"
        "2-Hermenegildo\n";
    cin >> herofocus;
    return herofocus;
}


int main()
{
    gameStart();

    while ((enemyIsAlive == true || enemyIsAlive2 == true) && heroIsAlive == true) {


        attackSelected2();
        
        heroFocus2();

        enemyDamage2 = enemyAtack2();

        enemyAtack();

        

        if (herofocus == 1)
        {
            enemyHP = enemyHP - heroDamage;
            cout << "Al enemigo le quedan " << enemyHP << " puntos de vida y a su hermano " << enemyHP2 << "puntos de vida\n";
        }
        if (herofocus == 2)
        {
            enemyHP2 = enemyHP2 - heroDamage;
            cout << "Al enemigo le quedan " << enemyHP << " puntos de vida y a su hermano " << enemyHP2 << "puntos de vida\n";
        }
        else {
            cout << "As fallado \n";
        }

        if ((herofocus == 1) && (enemyIsAlive == false) || (herofocus == 2) && (enemyIsAlive2 == false)) {
            cout << "\nDeja de abusar de el mama huevo, que ya esta muerto\n";
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

        

        if (enemyIsAlive == true || enemyIsAlive2 == true) {
            heroHP = heroHP - enemyDamage - enemyDamage2;
            cout << "El enemigo te ha hecho " << enemyDamage << " puntos de dps y su hermano te a hecho " << enemyDamage2 << " te quedan " << heroHP << " de vida\n";
        }

       // checkHeroStatus();

        if (!checkHeroStatus())
        {
            cout << "El heroe a muerto, la ultima esperanza de la humanidad se extingue\n";
        }

        if (enemyHP2 <= 0 && enemyHP <= 0)
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
