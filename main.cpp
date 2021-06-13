#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <stdlib.h>

/*
  Add Restrictions to UserInput - Completed

  Add difficulties - completed
    Easy: 1 - 10
    Medium: 1 - 25
    Hard: 1 - 50

  Add hint to the user in the last life (just in Medium and Hard) - completed
    Medium:
      Frio = Estas cerca por: 12 numeros;
      Tibio = Estas cerca por: 6 numeros;
      Caliente = Estas cerca por: 3 numeros;
    Hard:
      Frio = Estas cerca por: 25 numeros;
      Tibio = Estas cerca por: 12 numeros;
      Caliente = Estas cerca por: 6 numeros;

  Repeat the game if the user wants - Completed 
*/

using namespace std;

int main()
{
  int dificultad = 0;
  int repetirJuego = 1;
  cout << endl;
  cout << "Juego de Adivina el numero secreto ver. Alpha 5.1" << endl;
  cout << endl;
  cout << "            __" << endl;
  cout << "           (  )" << endl;
  cout << "            ||" << endl;
  cout << "            ||" << endl;
  cout << "       ____|\"\"|__..__" << endl;
  cout << "      /______________\\ " << endl;
  cout << "      \\______________/~~~." << endl;
  cout << endl;

  //Loop to reapeat the game if the user wants
  while (repetirJuego == 1)
  {
    cout << "Elija la dificultad del juego\n Presione 1 para dificultad: Facil (numeros entre 1 y 10) \n Presione 2 para dificultad: media (numeros entre 1 y 25) \n Presione 3 para dificultad: dificil (numeros entre 1 y 50)" << endl;
    cout << endl;
    cout << "NOTA: Para las dificultades media y dificil, habra una pista del tipo frio, tibio y caliente" << endl;
    cout << "--------> ";
    cin >> dificultad;

    if (dificultad == 1)
    {
      int rangoAzar = 10;
      //***********************************************
      //Variables to the hints
      int frio = round(rangoAzar / 2);
      int tibio = round((rangoAzar / 2) / 2);
      int caliente = round(((rangoAzar / 2) / 2) /2);
      //***********************************************
      int numero_al_azar = 0, numero_del_usuario = 0, puntuacionSuma = 0, puntuacion = 0, vidas = 0;
      int puntuaciontotal = (rangoAzar - 1) * 30;
      bool victoria = false;

      srand(time(0));
      numero_al_azar = rand()% rangoAzar + 1;

      cout << endl;
      //Limit of numbers to choose
      cout << endl;
      cout << "******************************************" <<endl;
      cout << "|        Comienzas con "<< puntuaciontotal <<" puntos        |" << endl;
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
            //Calculate puntuation if user fails their try
            puntuacion = abs(numero_del_usuario - numero_al_azar) * 10;
            puntuacionSuma += puntuacion;
            puntuaciontotal = (puntuaciontotal - puntuacionSuma);
            //Calculate Puntuation if the user wins
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
            //hints only for medium and hard difficulties
            int pista = abs(numero_del_usuario - numero_al_azar);
            if (dificultad == 2 || dificultad == 3)
            {
              if (pista >= frio)
              {
                cout << "Uy, estas frio" << endl;
                cout << endl;
              }
              else if (pista >= tibio && pista < frio)
              {
                cout << "Uy, estas tibio" << endl;
                cout << endl;
              }
              else if (pista >= caliente && pista < tibio)
              {
                cout << "AY!!!, TE ESTAS QUEMANDOOOO!!!" << endl;
                cout << endl;
              }
            }
          }
          cout << endl;
          //system("Pause");
        }

        //Condition if the user lost the game
        if (vidas == 1 && victoria == false)
        {
          puntuaciontotal = (puntuaciontotal - puntuacionSuma);

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
      cout << endl;
      //system("Color 60");
    }

    else if (dificultad == 2)
    {
      int rangoAzar = 25;
      //***********************************************
      //Variables to the hints
      int frio = round(rangoAzar / 2);
      int tibio = round((rangoAzar / 2) / 2);
      int caliente = round(((rangoAzar / 2) / 2) /2);
      //***********************************************
      int numero_al_azar = 0, numero_del_usuario = 0, puntuacionSuma = 0, puntuacion = 0, vidas = 0;
      int puntuaciontotal = (rangoAzar - 1) * 30;
      bool victoria = false;

      srand(time(0));
      numero_al_azar = rand()% rangoAzar + 1;

      cout << endl;
      //Limit of numbers to choose
      cout << endl;
      cout << "******************************************" <<endl;
      cout << "|        Comienzas con "<< puntuaciontotal <<" puntos        |" << endl;
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
            //Calculate puntuation if user fails their try
            puntuacion = abs(numero_del_usuario - numero_al_azar) * 10;
            puntuacionSuma += puntuacion;
            puntuaciontotal = (puntuaciontotal - puntuacionSuma);
            //Calculate Puntuation if the user wins
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
            //hints only for medium and hard difficulties
            int pista = abs(numero_del_usuario - numero_al_azar);
            if (dificultad == 2 || dificultad == 3)
            {
              if (pista >= frio)
              {
                cout << "Uy, estas frio" << endl;
                cout << endl;
              }
              else if (pista >= tibio && pista < frio)
              {
                cout << "Uy, estas tibio" << endl;
                cout << endl;
              }
              else if (pista >= caliente && pista < tibio)
              {
                cout << "AY!!!, TE ESTAS QUEMANDOOOO!!!" << endl;
                cout << endl;
              }
            }
          }
          cout << endl;
          //system("Pause");
        }

        //Condition if the user lost the game
        if (vidas == 1 && victoria == false)
        {
          puntuaciontotal = (puntuaciontotal - puntuacionSuma);

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
      cout << endl;
      //system("Color 60");
    }

    else if (dificultad == 3)
    {
      int rangoAzar = 50;
      //***********************************************
      //Variables to the hints
      int frio = round(rangoAzar / 2);
      int tibio = round((rangoAzar / 2) / 2);
      int caliente = round(((rangoAzar / 2) / 2) /2);
      //***********************************************
      int numero_al_azar = 0, numero_del_usuario = 0, puntuacionSuma = 0, puntuacion = 0, vidas = 0;
      int puntuaciontotal = (rangoAzar - 1) * 30;
      bool victoria = false;

      srand(time(0));
      numero_al_azar = rand()% rangoAzar + 1;

      cout << endl;
      //Limit of numbers to choose
      cout << endl;
      cout << "******************************************" <<endl;
      cout << "|        Comienzas con "<< puntuaciontotal <<" puntos        |" << endl;
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
            //Calculate puntuation if user fails their try
            puntuacion = abs(numero_del_usuario - numero_al_azar) * 10;
            puntuacionSuma += puntuacion;
            puntuaciontotal = (puntuaciontotal - puntuacionSuma);
            //Calculate Puntuation if the user wins
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
            //hints only for medium and hard difficulties
            int pista = abs(numero_del_usuario - numero_al_azar);
            if (dificultad == 2 || dificultad == 3)
            {
              if (pista >= frio)
              {
                cout << "Uy, estas frio" << endl;
                cout << endl;
              }
              else if (pista >= tibio && pista < frio)
              {
                cout << "Uy, estas tibio" << endl;
                cout << endl;
              }
              else if (pista >= caliente && pista < tibio)
              {
                cout << "AY!!!, TE ESTAS QUEMANDOOOO!!!" << endl;
                cout << endl;
              }
            }
          }
          cout << endl;
          //system("Pause");
        }

        //Condition if the user lost the game
        if (vidas == 1 && victoria == false)
        {
          puntuaciontotal = (puntuaciontotal - puntuacionSuma);

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
      cout << endl;
      //system("Color 60");
    }
  }
  return 0;
}
