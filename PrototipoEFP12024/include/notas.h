//creado por Diana Mishel Loeiza Ramirez 9959-23-3457
#ifndef NOTAS_H
#define NOTAS_H

#include <fstream>
#include <iostream>


#include<stdlib.h>// Incluye funciones para el manejo de memoria dinamica, control de procesos y conversiones de cadena.
#include<cstdlib>// Incluye funciones para el control de procesos y conversiones de cadena.
#include<conio.h>// Incluye funciones para el manejo de la consola.
#include<iomanip>// Incluye funciones para formatear la salida.


using namespace std;// Se utiliza el espacio de nombres estandar.

// Definición de la estructura aulas que representa la información de un aula.
struct notas
{

    int codigoEstudiante; // Variable para almacenar el código del estudiante
    string nombreEstudiante; // Variable para almacenar el nombre del estudiante
    string nombreCurso; // Variable para almacenar el nombre del curso
    float nota; // Variable para almacenar la nota del estudiante


};

class NotaCrud {
public:
    //void CrudNota();
    void IngresarNota();
    void ModificarNota();
    void BorrarNota();
    void DesplegarNotas();
    void CrudNota();
    void RegistrarBitacora(string usuario, string accion);

};

#endif // NOTAS_H

