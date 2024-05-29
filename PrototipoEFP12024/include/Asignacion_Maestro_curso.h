//hecho por Victor Gómez 9959-23-10733
#ifndef ASIGNACION_MAESTRO_CURSO_H
#define ASIGNACION_MAESTRO_CURSO_H
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;

struct Asignacion{
    //hecho por Kathia Contreras 9959-23-8246
    int codigo_maestro;
    char nombre_maestro[50];
    char apellido_maestro[50];
    char sede[50];
    char aula[50];
    char seccion[50];
    char facultad[50];
    char carrera[50];
    char curso[50];
    char jornada[50];
    char horario[50];
};

class Asignacion_Maestro_curso
{
    public:
        Asignacion_Maestro_curso();

    void Menu_catedratico();
    void asignarse_curso();
    void actas();

    private:

};

#endif // ASIGNACION_MAESTRO_CURSO_H
