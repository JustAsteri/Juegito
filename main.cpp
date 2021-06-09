#include <iostream>
#include <cstdlib>
//#include <windows.h>
#include <ctime>

using namespace std;

int main()
{
    int numero_al_azar, numero_del_usuario;

    srand(time(0));
    numero_al_azar=rand()%10+1;

    for(int vidas=3; vidas>=1; vidas--)
    {
        //system("Color 70");
        cout << "Juego de Adivina el numero secreto ver. Alpha 0.1" << endl;
        cout << endl;
        cout << "tienes "<<vidas<<" oportunidades" << endl;
        cout << "porfavor esciba un numero entre el 1 y el 10" << endl;
        cin>>numero_del_usuario;

        if(numero_al_azar==numero_del_usuario)
        {
            //system("Color 27");
            cout << "Felicidades, adivinaste el numero" << endl;
            cout << "winner winner chicken dinner" << endl;
            //system("Pause");
        }
        else
        {
            //system("Color 47");
            cout << endl;
            cout << "no adivinaste, intenta otravez con otro numero" << endl;
            cout << endl;
            //system("Pause");
        }
    }
    //system("Color 60");
    cout << "GAME OVER" << endl;
    cout << endl;
    cout << "el numero secreto era: "<<numero_al_azar<< endl;

    return 0;
}
