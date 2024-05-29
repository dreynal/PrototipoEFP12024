#ifndef MATRICULA_H
#define MATRICULA_H
#include<iostream>

using namespace std;

class matricula
{
    private:
		//int choice;
		//string facultad, nombre, apellido1, apellido2, fechaNacimiento, direccion, fecha, telefono, DPI, correo, numeroBoleta;
		//double monto;
		struct Matricula {
        char carnet [20];
        char sede [20];
        char facultad [40];
        char plan [20];
        char jornada[15];
        char nombre[50];
        char email[40];
        char direccion[100];
        char telefono[15];
        };
	public:
	    char x;
	    int choice;
	    //string carnet;
	    string numeroBoleta;
		string numTarjeta, fExpiracion, codSeguridad;
		void menu();
		void insertar();
		void desplegar();
		void borrar();

		int generarNumeroAleatorio();
		string generarNumeroBoleta();
		void pagarEnLinea();

		struct Alumno {
		    char id[20];          // Almacena la id de los alumnos ingresados
		    char nombre[50];      // Almacena el nombre  del alumno ingresado
		    char DPI[40];         // Almacena el DPI del alumno ingresado
		    char direccion[100];  // Almacena la dirección del alumno ingresado
		    char nacionalidad[50];// Almacena la nacionalidad del alumno ingresado
		    char telefono[15];    // Almacena el número de teléfono del alumno ingresado
		};

};

#endif // MATRICULA_H
