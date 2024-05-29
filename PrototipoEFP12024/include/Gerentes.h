//victor omar gomez carrascosa 10733
#include "login_catedratico.h"

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;

login_catedratico::login_catedratico(string usuario, string contrasena)//parametros de la clase
{
    this -> usuarios=usuarios;
    this -> contrasena=contrasena;
}

string login_catedratico::setUser(string usuarios)
{
    this -> usuarios=usuarios;
}

string login_catedratico::getUser()
{
    return this->usuarios;
}

string login_catedratico::setContrasena(string contrasena)
{
    this -> contrasena=contrasena;
}

string login_catedratico::getContrasena()
{
    return this->contrasena;
}

//primer despliegue de pantalla
bool login_catedratico::VerificarUsuario()
{
    string usuario,contrasena;
    int contador= 0; // contador de intentos
    bool encontrado =false; // indica si encontro user y contra

    //el ciclo se repite mientras el numero de intentos sea menor a 3 o no se encuentre user valido
    while(contador<3 && !encontrado)
    {
         system("cls");
    cout <<"\t\t\t+-----------------------------------+"<<endl;
    cout <<"\t\t\t|       LONGIN CATEDRATICO          |"<<endl;
    cout <<"\t\t\t+-----------------------------------+"<<endl;
    cout <<"\t\t\t|Solo tienes permitido 3 intentos   |"<<endl;
    cout <<"\t\t\t+-----------------------------------+"<<endl;
    cout <<"\t\t\tIngrese el nombre del catedratico: ";
    cin >> usuario;
    cout <<"\t\t\tIngrese la contrasena: ";
    char caracter;
    caracter = getch();

    // ocultar a la hora de escribir la contraseña
    contrasena="";
        while (caracter!=13)//ascci enter
        {
        if(caracter !=8)//ascci backs pace
            {
                contrasena.push_back(caracter);
                cout<<"*";
            }
        else
            {
                if(contrasena.length()>0)
                {
                    cout<<"\b \b";
                    contrasena=contrasena.substr(0,contrasena.length()-1);
                }
            }
            caracter=getch();
        }

    //abrira el archivo de User y contraseñas--------------------------
    ifstream fileU_P;
    fileU_P.open("UsuariosMaestros.txt",ios::in);


    //verificar si se abrio el archivo---------------------------
    if (!fileU_P)
    {
        cout<<"\n\t\t\t No es posible abrir el archivo."<<endl;
        fileU_P.close();
        return false;
    }

    //busca el usuario en el archivo---------------------------------
    string user,pass;
    while (fileU_P>>user>>pass)
    {
        if (user==usuario && pass==contrasena)
        {
            encontrado=true;
            break;
        }
    }
     fileU_P.close();

    //si no encuentra user y pass , el contador incrementara------------------------
    if(!encontrado)
    {
        cout << "\n\n\t\t\tUSUARIO Y/O CONTRASEÑA INCORRECTOS" << endl;
        cout << "\n\n\t\t\tPerdio un intento, Intente de nuevo\n" << endl;
        contador++;
        system("pause");
    }
}

    //Si encuentra a user y pass , se retornara un true
   if (encontrado)
    {
    	         system("cls");

    cout << "\n\t----- Bienvenido " << usuario << " -----" << endl;
     system("pause");
    return true;
    }
   else
    {
	system("cls");
    cout << "\n\n\t\t\tPERDIO LOS 3 INTENTOS" << endl;
     system("pause");
     exit(0);

    return false;
    }





}
