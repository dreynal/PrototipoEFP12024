#ifndef SUELDOS_H
#define SUELDOS_H

#include <string>
using namespace std;

// Definición de la estructura para almacenar los datos de los empleados
struct Empleado {
    string nombre;
    string puesto;
    float salario;
};

// Definición de la clase sueldos con sus métodos
class sueldos {
public:
    void menu();
    void menuEmpleados();
    void agregarEmpleado();
    void eliminarEmpleado();
    void verEmpleados();
    void procesoAsignacionMaestros();
    void verMaestros(); // Nuevo método para ver la información de los maestros
    void generacionNomina(); // Método para la generación de nómina
};

#endif // SUELDOS_H
