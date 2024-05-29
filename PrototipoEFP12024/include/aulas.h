//Creado por Rocio Guisell Lopez espinoza 9959-23-740
#ifndef AULAS_H
#define AULAS_H

#include<stdlib.h>// Incluye funciones para el manejo de memoria dinamica, control de procesos y conversiones de cadena.
#include<cstdlib>// Incluye funciones para el control de procesos y conversiones de cadena.
#include<conio.h>// Incluye funciones para el manejo de la consola.
#include<iomanip>// Incluye funciones para formatear la salida.


using namespace std;// Se utiliza el espacio de nombres estandar.

// Definición de la estructura aulas que representa la información de un aula.
struct aulas
{
    int codigo;// Código del aula.
    char nombre [45];// Nombre del aula.
    char estatus [1];// Estatus del aula.
};
// Definición de la clase AulasCRUD que proporciona mótodos para realizar operaciones CRUD en aulas.
class AulasCRUD
{
    public:// Mótodos para realizar operaciones CRUD.
        void IngresarAula();
        void ModificarAula();
        void BorrarAula();
        void DesplegarAula();
        void CrudAula();
        void visualizarBitacora();

};//fin de la clase aula

#endif // AULAS_H

