#ifndef COLEGIATURA_H
#define COLEGIATURA_H

#include <iostream>
using namespace std;

class colegiatura
{
private:
    string carnet, trimestre, anio, mes, id, nombre, estatus;

public:
    bool validarID(const std::string &idEstudiante);
    string leerDatos();
    void procesarColegiaturaCursos(const string &idIngresado); // Modificado para incluir idIngresado
    void pagarEnLinea(int monto, const string &fechaHoy, const string &semestre, const string &mes, const string &anio, const string &idIngresado); // Modificado para incluir idIngresado
    string generarNumeroBoleta();
    void menu();
    void insertar();
    void modificar();
    void buscar();
    void borrar();

    void obtenerDatosEstudiante(const string &idEstudiante, string &nombreEstudiante);

    struct Alumno
    {
        char id[20];
        char nombre[50];
        char Genero[10];
        char DPI[20];
        char direccion[100];
        char nacionalidad[50];
        char telefono[15];
        char civil[20];
        char fechanaci[20];
        char anoingre[10];
    };
};

#endif // COLEGIATURA_H

