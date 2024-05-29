#ifndef SUELDOS_H
#define SUELDOS_H

#include <string>
using namespace std;

// Definici�n de la estructura para almacenar los datos de los empleados
struct Empleado {
    string nombre;
    string puesto;
    float salario;
};

// Definici�n de la clase sueldos con sus m�todos
class sueldos {
public:
    void menu();
    void menuEmpleados();
    void agregarEmpleado();
    void eliminarEmpleado();
    void verEmpleados();
    void procesoAsignacionMaestros();
    void verMaestros(); // Nuevo m�todo para ver la informaci�n de los maestros
    void generacionNomina(); // M�todo para la generaci�n de n�mina
};

#endif // SUELDOS_H
