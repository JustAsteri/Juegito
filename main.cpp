#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <stdlib.h>

/*
  Add Restrictions to UserInput - Complete

  Add difficulties
    Easy: 1 - 10
    Medium: 1 - 25
    Hard: 1 - 50

  Add hint to the user in the last life

  Repeat the game if the user wants - Completed 
*/

using namespace std;

void Clear()
{
    cout << "\x1B[2J\x1B[H";
}

int main()
{
  int repetirJuego = 1;

  //Loop to reapeat the game if the user wants
  while (repetirJuego == 1)
  {
    int numero_al_azar = 0, numero_del_usuario = 0, puntuacionSuma = 0, puntuacion = 0, vidas = 0;
    int rangoAzar = 10;
    int puntuaciontotal = rangoAzar * 10;
    bool victoria = false;

    srand(time(0));
    //numero_al_azar = rand()% rango + 1;
    numero_al_azar = 5;

    cout << endl;
    //Limit of numbers to choose
    cout << "Juego de Adivina el numero secreto ver. Alpha 4.1" << endl;
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
    cout << "Elige un numero entre el 1 y el " << rangoAzar << endl;
    cout << endl;

    for(
      vidas = 3; 
      vidas >= 1 && victoria == false; 
      vidas--)
    {
      //system("Color 70");

      cout << "+--------------------------+" << endl;
      cout << "| " << "tienes "<<vidas<<" oportunidad(es)" <<" |" << endl;
      cout << "+--------------------------+" << endl;
      cout << "--------> ";
      
      //Number of the user in the first try
      cin>>numero_del_usuario;

      //Bucle for incorrect user data inputs
      while (numero_del_usuario < 1 || numero_del_usuario > rangoAzar)
      {
        cout << "Ingresa un valor entre el 1 y el 10" << endl;
        cout << "--------> ";
        cin>>numero_del_usuario;
      }
      
      //Conditions for correct user data inputs
      if(numero_al_azar == numero_del_usuario && vidas == 3)
      {
          //system("Color 27");
          cout << endl;
          cout << endl;
          cout << "**************************************************" <<endl;
          cout << "| Felicidades, adivinaste el numero A LA PRIMERA |" << endl;
          cout << "**************************************************" <<endl;
          cout << endl;
          cout << "+------------------------+" << endl;
          cout << "| " << "Puntuacion Final: 9999" << " |" << endl;
          cout << "+------------------------+" << endl;
          //system("Pause");
          victoria = true;
      }

      else if(numero_al_azar == numero_del_usuario && vidas != 3)
      {
          //system("Color 27");
          cout << endl;
          cout << endl;
          //Calculate Puntuation if the user wins
          puntuaciontotal = (puntuaciontotal - puntuacionSuma) * 2;
          cout << "*************************************" <<endl;
          cout << "| Felicidades, adivinaste el numero |" << endl;
          cout << "*************************************" <<endl;
          cout << endl;
          cout << "+-----------------------+" << endl;
          cout << "| " << "Puntuacion Final: " << puntuaciontotal << " |" << endl;
          cout << "+-----------------------+" << endl;
          //system("Pause");
          victoria = true;
      }
      
      else if (numero_al_azar != numero_del_usuario)
      {
        //system("Color 47");
        cout << endl;
        //Calculate puntuation if user fails their try
        puntuacion = abs(numero_del_usuario - numero_al_azar) * 10;
        puntuacionSuma += puntuacion;
        if (vidas > 1)
        {
          cout << "No adivinaste, intenta otra vez con otro numero" << endl;
        }
        cout << endl;
        //system("Pause");
      }

      //Condition if the user lost the game
      if (vidas == 1 && victoria == false)
      {
        puntuaciontotal = (puntuaciontotal - puntuacionSuma) + (puntuaciontotal / 2);

        cout << "+----------------------+" << endl;
        cout << "| " << "Puntuacion Final: " << puntuaciontotal <<" |" << endl;
        cout << "+----------------------+" << endl;
          
        cout << "+--------------------------+" << endl;
        cout << "| " << "El numero secreto era: "<<numero_al_azar <<" |" << endl;
        cout << "+--------------------------+" << endl;
      }

      if ((vidas == 1 && victoria == false) || victoria == true)
      {
        cout << endl;
        cout << "╔═╗╔═╗╔╦╗╔═╗  ╔═╗╦  ╦╔═╗╦═╗" << endl;
        cout << "║ ╦╠═╣║║║║╣   ║ ║╚╗╔╝║╣ ╠╦╝" << endl;
        cout << "╚═╝╩ ╩╩ ╩╚═╝  ╚═╝ ╚╝ ╚═╝╩╚═" << endl;
      }
    }

    cout << endl;
    cout << "Desea jugar una vez mas?\n Presione 1 para: Jugar otra vez\n Presione 0 para: Salir del juego" << endl;
    cout << "--------> ";
    cin >> repetirJuego;
    //Loop if the user gives an invalid value in the "Reapet game loop"
    while (repetirJuego != 0 && repetirJuego != 1)
    {
      cout << "Ingrese un valor valido: \nPresione 1 para: Jugar otra vez\n Presione 0 para: Salir del juego" << endl;
      cout << "--------> ";
      cin >> repetirJuego;
    }
    system("clear");
  }
  cout << endl;
  //system("Color 60");

  return 0;
}
