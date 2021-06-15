#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <stdlib.h>
//#include <windows.h>

/*  
  Error cuando ponen tipos de datos diferentes en condiciones de los intentos de numeros
*/

using namespace std;

int main()
{
  string dificultad;
  string repetirJuego;
  bool validar;
  cout << endl;
  cout << "Juego de Adivina el numero secreto ver. Alpha 5.6" << endl;
  cout << endl;
  cout << "Instrucciones: El usuario (usted) debe intentar adivinar el numero que estoy pensando" << endl;
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
  do
  {
    cout << "Elija la dificultad del juego\n Presione 1 para dificultad Facil (numeros entre 1 y 10) \n Presione 2 para dificultad Media (numeros entre 1 y 25) \n Presione 3 para dificultad Dificil (numeros entre 1 y 50)" << endl;
    cout << endl;
    cout << "NOTA: Para las dificultades media y dificil, habra una pista del tipo frio, tibio y caliente" << endl;
    cout << "--------> ";
    cin >> dificultad;

    while (dificultad != "1" && dificultad != "2" && dificultad != "3")
    {
      system("clear"); //Linux
      //system("cls"); //Windows
      cout << endl;
      cout << "Ingresa un valor valido" << endl;
      cout << endl;
      cout << "Elija la dificultad del juego\n Presione 1 para dificultad Facil (numeros entre 1 y 10) \n Presione 2 para dificultad Media (numeros entre 1 y 25) \n Presione 3 para dificultad Dificil (numeros entre 1 y 50)" << endl;
      cout << endl;
      cout << "NOTA: Para las dificultades media y dificil, habra una pista del tipo frio, tibio y caliente" << endl;
      cout << "--------> ";
      cin >> dificultad;
    }
    if (dificultad == "1")
    {
      int rangoAzar = 10;
      //***********************************************
      //Variables to the hints
      int frio = round(rangoAzar / 2);
      int tibio = round((rangoAzar / 2) / 2);
      int caliente = round(((rangoAzar / 2) / 2) /2);
      //***********************************************
      int numero_al_azar = 0, numero_del_usuario = 0, puntuacionSuma = 0, puntuacion = 0, vidas = 0;
      string letras_del_usuario;
      int puntuaciontotal = (rangoAzar - 1) * 30;
      int puntuacionMaxima = puntuaciontotal;
      bool victoria = false;
      bool validarEntradas;

      srand(time(0));
      numero_al_azar = rand()% rangoAzar + 1;

      cout << endl;
      //Limit of numbers to choose
      cout << endl;
      cout << "*******************************************" <<endl;
      cout << "|        Comienzas con "<< puntuacionMaxima <<" puntos         |" << endl;
      cout << "*******************************************" <<endl;
      cout << endl;
      cout << "Elige un numero entre el 1 y el " << rangoAzar << endl;
      cout << endl;

      for(
        vidas = 3; 
        vidas >= 1 && victoria == false; 
        vidas--)
      {
        //system("Color 70");
        do
        {
          cout << "+--------------------------+" << endl;
          cout << "| " << "tienes "<<vidas<<" oportunidad(es)" <<" |" << endl;
          cout << "+--------------------------+" << endl;
          cout << "--------> ";
          
          do //Loop to check if the value is valid (numbers) 
          {
            try 
            {
              cin>>letras_del_usuario;
              numero_del_usuario = stoi(letras_del_usuario);
              if (numero_del_usuario == false)
              {
                cout << endl;
                cout << "Ingrese numeros validos" << endl;
                validarEntradas = false;
              }
              else
              {
                if (numero_del_usuario < 1 || numero_del_usuario > rangoAzar)
                {
                  cout << endl;
                  cout << "Ingrese numeros validos" << endl;
                  cout << endl;
                }
                validarEntradas = true;
              }
            }
            catch (exception e)
            {
              cout << endl;
              cout << "Ingrese numeros validos" << endl;
              cout << endl;
              validarEntradas = true;
            } 
          } while (validarEntradas == false);
        } while (numero_del_usuario < 1 || numero_del_usuario > rangoAzar);
        
        //Conditions for correct user data inputs
        if(numero_al_azar == numero_del_usuario && vidas == 3)
        {
            //system("Color 27");
            system("clear"); //Linux
            //system("cls"); //Windows
            cout << endl;
            cout << endl;
            cout << "**************************************************" <<endl;
            cout << "| FELICIDADES, adivinaste el numero A LA PRIMERA |" << endl;
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
            system("clear"); //Linux
            //system("cls"); //Windows
            cout << endl;
            cout << endl;
            //Calculate puntuation if user fails their try
            puntuacion = abs(numero_del_usuario - numero_al_azar) * 10;
            puntuacionSuma += puntuacion;
            puntuaciontotal = (puntuaciontotal - puntuacionSuma);
            //Calculate Puntuation if the user wins
            cout << "*************************************" <<endl;
            cout << "| FELICIDADES, adivinaste el numero |" << endl;
            cout << "*************************************" <<endl;
            cout << endl;
            cout << "+-------------------------------------------------+" << endl;
            cout << "| " << "Puntuacion Final = " << puntuaciontotal <<"                          |" << endl;
            cout << "| " << "Puntuacion Maxima = " << puntuacionMaxima << "                         |" << endl;
            cout << "|                                                 |" << endl;
            cout << "| " << "Puntos Faltantes para Puntuacion Maxima = " << puntuacionMaxima - puntuaciontotal << "    |" << endl;
            cout << "+-------------------------------------------------+" << endl;
            cout << endl;
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
            cout << "No adivinaste, intenta con otro numero" << endl;
            //hints only for medium and hard difficulties
            int pista = abs(numero_del_usuario - numero_al_azar);
            if (dificultad == "2" || dificultad == "3")
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
                cout << "AAAY!!!, TE ESTAS QUEMANDOOOO!!!" << endl;
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
          cout << "************************************" <<endl;
          cout << "| Lastima, no adivinaste el numero |" << endl;
          cout << "************************************" <<endl;
          cout << endl;
          cout << "+-------------------------------------------------+" << endl;
          cout << "| " << "Puntuacion Final = " << puntuaciontotal <<"                          |" << endl;
          cout << "| " << "Puntuacion Maxima = " << puntuacionMaxima << "                         |" << endl;
          cout << "|                                                 |" << endl;
          cout << "| " << "Puntos Faltantes para Puntuacion Maxima = " << puntuacionMaxima - puntuaciontotal << "    |" << endl;
          cout << "+-------------------------------------------------+" << endl;
          cout << endl;
          cout << "***************************************************" <<endl;
          cout << endl;
          cout << "+----------------------------+" << endl;
          cout << "| " << "El numero secreto era: "<<numero_al_azar <<"   |" << endl;
          cout << "+----------------------------+" << endl;
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
      cout << "Desea jugar una vez mas?\n Presione 1 para: Jugar otra vez\n Presione cualquier otra tecla para: Salir del juego" << endl;
      cout << "--------> ";
      cin >> repetirJuego;
      system("clr");
      cout << endl;
      //system("Color 60");
    }
    
    else if (dificultad == "2")
    {
      int rangoAzar = 25;
      //***********************************************
      //Variables to the hints
      int frio = round(rangoAzar / 2);
      int tibio = round((rangoAzar / 2) / 2);
      int caliente = round(((rangoAzar / 2) / 2) /2);
      //***********************************************
      int numero_al_azar = 0, numero_del_usuario = 0, puntuacionSuma = 0, puntuacion = 0, vidas = 0;
      string letras_del_usuario;
      int puntuaciontotal = (rangoAzar - 1) * 30;
      int puntuacionMaxima = puntuaciontotal;
      bool victoria = false;
      bool validarEntradas;

      srand(time(0));
      numero_al_azar = rand()% rangoAzar + 1;

      cout << endl;
      //Limit of numbers to choose
      cout << endl;
      cout << "*******************************************" <<endl;
      cout << "|        Comienzas con "<< puntuacionMaxima <<" puntos         |" << endl;
      cout << "*******************************************" <<endl;
      cout << endl;
      cout << "Elige un numero entre el 1 y el " << rangoAzar << endl;
      cout << endl;

      for(
        vidas = 3; 
        vidas >= 1 && victoria == false; 
        vidas--)
      {
        //system("Color 70");
        do
        {
          cout << "+--------------------------+" << endl;
          cout << "| " << "tienes "<<vidas<<" oportunidad(es)" <<" |" << endl;
          cout << "+--------------------------+" << endl;
          cout << "--------> ";
          
          do //Loop to check if the value is valid (numbers) 
          {
            try 
            {
              cin>>letras_del_usuario;
              numero_del_usuario = stoi(letras_del_usuario);
              if (numero_del_usuario == false)
              {
                cout << endl;
                cout << "Ingrese numeros validos" << endl;
                validarEntradas = false;
              }
              else
              {
                if (numero_del_usuario < 1 || numero_del_usuario > rangoAzar)
                {
                  cout << endl;
                  cout << "Ingrese numeros validos" << endl;
                  cout << endl;
                }
                validarEntradas = true;
              }
            }
            catch (exception e)
            {
              cout << endl;
              cout << "Ingrese numeros validos" << endl;
              cout << endl;
              validarEntradas = true;
            } 
          } while (validarEntradas == false);
        } while (numero_del_usuario < 1 || numero_del_usuario > rangoAzar);
        
        //Conditions for correct user data inputs
        if(numero_al_azar == numero_del_usuario && vidas == 3)
        {
            //system("Color 27");
            system("clear"); //Linux
            //system("cls"); //Windows
            cout << endl;
            cout << endl;
            cout << "**************************************************" <<endl;
            cout << "| FELICIDADES, adivinaste el numero A LA PRIMERA |" << endl;
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
            system("clear"); //Linux
            //system("cls"); //Windows
            cout << endl;
            cout << endl;
            //Calculate puntuation if user fails their try
            puntuacion = abs(numero_del_usuario - numero_al_azar) * 10;
            puntuacionSuma += puntuacion;
            puntuaciontotal = (puntuaciontotal - puntuacionSuma);
            //Calculate Puntuation if the user wins
            cout << "*************************************" <<endl;
            cout << "| FELICIDADES, adivinaste el numero |" << endl;
            cout << "*************************************" <<endl;
            cout << endl;
            cout << "+-------------------------------------------------+" << endl;
            cout << "| " << "Puntuacion Final = " << puntuaciontotal <<"                          |" << endl;
            cout << "| " << "Puntuacion Maxima = " << puntuacionMaxima << "                         |" << endl;
            cout << "|                                                 |" << endl;
            cout << "| " << "Puntos Faltantes para Puntuacion Maxima = " << puntuacionMaxima - puntuaciontotal << "    |" << endl;
            cout << "+-------------------------------------------------+" << endl;
            cout << endl;
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
            cout << "No adivinaste, intenta con otro numero" << endl;
            //hints only for medium and hard difficulties
            int pista = abs(numero_del_usuario - numero_al_azar);
            if (dificultad == "2" || dificultad == "3")
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
                cout << "AAAY!!!, TE ESTAS QUEMANDOOOO!!!" << endl;
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
          cout << "Lastima, no adivinaste el numero" << endl;
          cout << "+-------------------------------------------------+" << endl;
          cout << "| " << "Puntuacion Final = " << puntuaciontotal <<"                          |" << endl;
          cout << "| " << "Puntuacion Maxima = " << puntuacionMaxima << "                         |" << endl;
          cout << "|                                                 |" << endl;
          cout << "| " << "Puntos Faltantes para Puntuacion Maxima = " << puntuacionMaxima - puntuaciontotal << "    |" << endl;
          cout << "+-------------------------------------------------+" << endl;
          cout << endl;
          cout << "***************************************************" <<endl;
          cout << endl;
          cout << "+----------------------------+" << endl;
          cout << "| " << "El numero secreto era: "<<numero_al_azar <<"   |" << endl;
          cout << "+----------------------------+" << endl;
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
      cout << "Desea jugar una vez mas?\n Presione 1 para: Jugar otra vez\n Presione cualquier otra tecla para: Salir del juego" << endl;
      cout << "--------> ";
      cin >> repetirJuego;
      system("clr");
      cout << endl;
      //system("Color 60");
    }

    else if (dificultad == "3")
    {
      int rangoAzar = 50;
      //***********************************************
      //Variables to the hints
      int frio = round(rangoAzar / 2);
      int tibio = round((rangoAzar / 2) / 2);
      int caliente = round(((rangoAzar / 2) / 2) /2);
      //***********************************************
      int numero_al_azar = 0, numero_del_usuario = 0, puntuacionSuma = 0, puntuacion = 0, vidas = 0;
      string letras_del_usuario;
      int puntuaciontotal = (rangoAzar - 1) * 30;
      int puntuacionMaxima = puntuaciontotal;
      bool victoria = false;
      bool validarEntradas;

      srand(time(0));
      numero_al_azar = rand()% rangoAzar + 1;

      cout << endl;
      //Limit of numbers to choose
      cout << endl;
      cout << "*******************************************" <<endl;
      cout << "|        Comienzas con "<< puntuacionMaxima <<" puntos         |" << endl;
      cout << "*******************************************" <<endl;
      cout << endl;
      cout << "Elige un numero entre el 1 y el " << rangoAzar << endl;
      cout << endl;

      for(
        vidas = 3; 
        vidas >= 1 && victoria == false; 
        vidas--)
      {
        //system("Color 70");
        do
        {
          cout << "+--------------------------+" << endl;
          cout << "| " << "tienes "<<vidas<<" oportunidad(es)" <<" |" << endl;
          cout << "+--------------------------+" << endl;
          cout << "--------> ";
          
          do //Loop to check if the value is valid (numbers) 
          {
            try 
            {
              cin>>letras_del_usuario;
              numero_del_usuario = stoi(letras_del_usuario);
              if (numero_del_usuario == false)
              {
                cout << endl;
                cout << "Ingrese numeros validos" << endl;
                validarEntradas = false;
              }
              else
              {
                if (numero_del_usuario < 1 || numero_del_usuario > rangoAzar)
                {
                  cout << endl;
                  cout << "Ingrese numeros validos" << endl;
                  cout << endl;
                }
                validarEntradas = true;
              }
            }
            catch (exception e)
            {
              cout << endl;
              cout << "Ingrese numeros validos" << endl;
              cout << endl;
              validarEntradas = true;
            } 
          } while (validarEntradas == false);
        } while (numero_del_usuario < 1 || numero_del_usuario > rangoAzar);
        
        //Conditions for correct user data inputs
        if(numero_al_azar == numero_del_usuario && vidas == 3)
        {
            //system("Color 27");
            system("clear"); //Linux
            //system("cls"); //Windows
            cout << endl;
            cout << endl;
            cout << "**************************************************" <<endl;
            cout << "| FELICIDADES, adivinaste el numero A LA PRIMERA |" << endl;
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
            system("clear"); //Linux
            //system("cls"); //Windows
            cout << endl;
            cout << endl;
            //Calculate puntuation if user fails their try
            puntuacion = abs(numero_del_usuario - numero_al_azar) * 10;
            puntuacionSuma += puntuacion;
            puntuaciontotal = (puntuaciontotal - puntuacionSuma);
            //Calculate Puntuation if the user wins
            cout << "*************************************" <<endl;
            cout << "| FELICIDADES, adivinaste el numero |" << endl;
            cout << "*************************************" <<endl;
            cout << endl;
            cout << "+-------------------------------------------------+" << endl;
            cout << "| " << "Puntuacion Final = " << puntuaciontotal <<"                          |" << endl;
            cout << "| " << "Puntuacion Maxima = " << puntuacionMaxima << "                         |" << endl;
            cout << "|                                                 |" << endl;
            cout << "| " << "Puntos Faltantes para Puntuacion Maxima = " << puntuacionMaxima - puntuaciontotal << "    |" << endl;
            cout << "+-------------------------------------------------+" << endl;
            cout << endl;
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
            cout << "No adivinaste, intenta con otro numero" << endl;
            //hints only for medium and hard difficulties
            int pista = abs(numero_del_usuario - numero_al_azar);
            if (dificultad == "2" || dificultad == "3")
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
                cout << "AAAY!!!, TE ESTAS QUEMANDOOOO!!!" << endl;
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
          cout << "Lastima, no adivinaste el numero" << endl;
          cout << "+-------------------------------------------------+" << endl;
          cout << "| " << "Puntuacion Final = " << puntuaciontotal <<"                          |" << endl;
          cout << "| " << "Puntuacion Maxima = " << puntuacionMaxima << "                         |" << endl;
          cout << "|                                                 |" << endl;
          cout << "| " << "Puntos Faltantes para Puntuacion Maxima = " << puntuacionMaxima - puntuaciontotal << "    |" << endl;
          cout << "+-------------------------------------------------+" << endl;
          cout << endl;
          cout << "***************************************************" <<endl;
          cout << endl;
          cout << "+----------------------------+" << endl;
          cout << "| " << "El numero secreto era: "<<numero_al_azar <<"   |" << endl;
          cout << "+----------------------------+" << endl;
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
      cout << "Desea jugar una vez mas?\n Presione 1 para: Jugar otra vez\n Presione cualquier otra tecla para: Salir del juego" << endl;
      cout << "--------> ";
      cin >> repetirJuego;
      system("clr");
      cout << endl;
      //system("Color 60");
    }
    system("clear"); //Linux
    //system("cls"); //Windows
  }
  while (repetirJuego == "1");
  cout << endl;
  cout << "╔═╗┬─┐┌─┐┌─┐┬┌─┐┌─┐  ┌─┐┌─┐┬─┐   ╦┬ ┬┌─┐┌─┐┬─┐" << endl;
  cout << "║ ╦├┬┘├─┤│  │├─┤└─┐  ├─┘│ │├┬┘   ║│ ││ ┬├─┤├┬┘" << endl;
  cout << "╚═╝┴└─┴ ┴└─┘┴┴ ┴└─┘  ┴  └─┘┴└─  ╚╝└─┘└─┘┴ ┴┴└─" << endl;
  cout << endl;
  return 0;
}
