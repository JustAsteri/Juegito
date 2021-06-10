#include <iostream>
#include <cstdlib>
//#include <windows.h>
#include <ctime>
#include <cmath>

/*
  Add Restrictions to UserInput
  Add difficulties
    Easy: 1 - 10
    Medium: 1 - 25
    Hard: 1 - 50
  Add hint to the user in the last life
*/

using namespace std;

int main()
{
    int limiteNumero, numero_al_azar = 0, numero_del_usuario = 0, puntuacionSuma = 0, puntuacion = 0, vidas = 0;
    int rangoAzar = 10;
    int puntuaciontotal = rangoAzar * 10;
    bool victoria = false;

    srand(time(0));
    //numero_al_azar = rand()% rango + 1;
    numero_al_azar = 5;

        cout << endl;
        limiteNumero = 10;
        cout << "Juego de Adivina el numero secreto ver. Alpha 0.2" << endl;
        cout << "Elige un numero entre el 1 y el " << limiteNumero << endl;
        cout << endl;
        cout << "            __" << endl;
        cout << "           (  )" << endl;
        cout << "            ||" << endl;
        cout << "            ||" << endl;
        cout << "       ____|\"\"|__..__" << endl;
        cout << "      /______________\\ " << endl;
        cout << "      \\______________/~~~." << endl;
        cout << endl;
        cout << endl;
        cout << "******************************************" <<endl;
        cout << "|        Comienzas con 150 puntos        |" << endl;
        cout << "******************************************" <<endl;
        cout << endl;

    for(vidas=3; vidas>=1 && victoria == false; vidas--)
    {
        //system("Color 70");

        cout << "+--------------------------+" << endl;
        cout << "| " << "tienes "<<vidas<<" oportunidad(es)" <<" |" << endl;
        cout << "+--------------------------+" << endl;
        cout << "--------> ";

        cin>>numero_del_usuario;

        if(numero_al_azar==numero_del_usuario && vidas == 3)
        {
            //system("Color 27");
            cout << endl;
            cout << endl;
            cout << "**************************************************" <<endl;
            cout << "| Felicidades, adivinaste el numero A LA PRIMERA |" << endl;
            cout << "******************************************" <<endl;
            cout << endl;
            cout << "+------------------------+" << endl;
            cout << "| " << "Puntuacion Final: 9999" << " |" << endl;
            cout << "+------------------------+" << endl;
            //system("Pause");
            victoria = true;
        }
        else if(numero_al_azar==numero_del_usuario && vidas != 3)
        {
            //system("Color 27");
            cout << endl;
            cout << endl;
            puntuaciontotal = (puntuaciontotal - puntuacionSuma) * 2;
            cout << "*************************************" <<endl;
            cout << "| Felicidades, adivinaste el num            cout << puntuacionSuma << endl;ero |" << endl;
            cout << "*************************************" <<endl;
            cout << endl;
            cout << "+------------------------+" << endl;
            cout << "| " << "Puntuacion Final: " << puntuaciontotal << " |" << endl;
            cout << "+------------------------+" << endl;
            //system("Pause");
            victoria = true;
        }
        else
        {
            //system("Color 47");
            cout << endl;
            puntuacion = abs(numero_del_usuario - numero_al_azar) * 10;
            puntuacionSuma += puntuacion;
            if (vidas > 1)
            {
              cout << "No adivinaste, intenta otra vez con otro numero" << endl;
            }
            cout << endl;
            //system("Pause");
        }
    }
    //system("Color 60");

    cout << "╔═╗╔═╗╔╦╗╔═╗  ╔═╗╦  ╦╔═╗╦═╗" << endl;
    cout << "║ ╦╠═╣║║║║╣   ║ ║╚╗╔╝║╣ ╠╦╝" << endl;
    cout << "╚═╝╩ ╩╩ ╩╚═╝  ╚═╝ ╚╝ ╚═╝╩╚═" << endl;

    cout << endl;
    if (vidas == 0 && victoria == false)
    {
      puntuaciontotal = (puntuaciontotal - puntuacionSuma) + (puntuaciontotal / 2);

      cout << "+----------------------+" << endl;
      cout << "| " << "Puntuacion Final: " << puntuaciontotal <<" |" << endl;
      cout << "+----------------------+" << endl;
        
      cout << "+--------------------------+" << endl;
      cout << "| " << "El numero secreto era: "<<numero_al_azar <<" |" << endl;
      cout << "+--------------------------+" << endl;
    }

    return 0;
}
