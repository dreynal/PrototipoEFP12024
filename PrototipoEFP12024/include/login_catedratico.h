
#ifndef LOGIN_CATEDRATICO_H
#define LOGIN_CATEDRATICO_H
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;
class login_catedratico
{
public:
        login_catedratico(string usuarios,string contrasena);

        string setUser(string usuarios);
        string getUser();

        string setContrasena(string contrasena);
        string getContrasena();


        bool VerificarUsuario();


    private:
        string usuarios,contrasena;

};
#endif // LOGIN_CATEDRATICO_H

