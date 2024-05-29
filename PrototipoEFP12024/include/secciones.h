// Creado por Rocio Guisell Lopez espinoza 9959-23-740

// Comprueba si SECCIONES_H ya ha sido definido, si no, lo define
#ifndef SECCIONES_H
#define SECCIONES_H

// Incluye las bibliotecas est�ndar de C++ necesarias para el programa
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>


using namespace std;

// Define la estructura 'secciones' con los campos 'codigo', 'nombre' y 'estatus'
struct secciones
{
    int codigo;
    char nombre[45];
    char estatus[1];
};

// Define la clase 'SeccionesCrud' con los m�todos p�blicos 'IngresarSeccion', 'ModificarSeccion', 'BorrarSeccion', 'DesplegarSeccion' y 'CrudSeccion'
class SeccionesCrud
{
    public:
        void IngresarSeccion();
        void ModificarSeccion();
        void BorrarSeccion();
        void DesplegarSeccion();
        void CrudSeccion();

};//fin de la clase aula

// Fin de la comprobaci�n de la definici�n de SECCIONES_H
#endif // SECCIONES_H
