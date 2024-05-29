//Creado por Anderson Rodriguez 9959-23-495
#ifndef SEDES_H
#define SEDES_H
#include <iostream>

using namespace std;

class Sedes
{
    private:

	public:
	    char id[10];
        char nombre[50];
        char telefono[20];
		void menu();
		void insertar();
		void desplegar();
		void modificar();
		void borrar();
};

#endif // SEDES_H
