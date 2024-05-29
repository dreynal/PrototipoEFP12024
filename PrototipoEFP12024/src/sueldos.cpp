
#include <iostream>
#include <fstream>
#include <iomanip>
#include "sueldos.h"
#include "Bitacora.h"
#include <cstdlib> // Para la función rand()
#include <ctime> // Para la función time()

using namespace std;

void sueldos::menu() {
    int choice;
    string codigoPrograma = "6650"; // Código del programa
    Bitacora Auditoria; // Objeto para gestionar la bitácora de auditoría
    string user = "admin"; // Usuario actual del sistema

    do {
        system("cls");
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t|    MENU DE SUELDOS          |" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t 1. Base de datos de empleados" << endl;
        cout << "\t\t\t 2. Generación de nóminas" << endl;
        cout << "\t\t\t 3. Proceso de asignación " << endl;
        cout << "\t\t\t 4. Ver información  " << endl;
        cout << "\t\t\t 5. Retorno" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\tOpción a escoger:[1/2/3/4/5]" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opción: ";
        cin >> choice;

        switch (choice) {
            case 1:
                menuEmpleados(); // Llama a la función para el menú de empleados
                Auditoria.ingresoBitacora(user, codigoPrograma, "MEN"); // Registra en la bitácora la acción de mostrar el menú de empleados
                break;
            case 2:
                generacionNomina(); // Llama a la función para la generación de nómina
                break;
            case 3:
                procesoAsignacionMaestros(); // Llama a la función para el proceso de asignación de maestros
                break;
            case 4:
                verMaestros(); // Llama a la función para ver la información de los maestros
                break;
            case 5:
                // Implementa la funcionalidad para "Retorno" aquí si es necesario
                break;
            default:
                cout << "\n\t\t\t Opción inválida... Por favor prueba otra vez..";
                cin.ignore();
                cin.get();
        }
    } while (choice != 5);
}

void sueldos::menuEmpleados() {
    int choice;
    do {
        system("cls");
        cout << "\t\t\t-----------------------------------" << endl;
        cout << "\t\t\t|    BASE DE DATOS DE EMPLEADOS   |" << endl;
        cout << "\t\t\t-----------------------------------" << endl;
        cout << "\t\t\t 1. Agregar empleado" << endl;
        cout << "\t\t\t 2. Eliminar empleado" << endl;
        cout << "\t\t\t 3. Ver información de los empleados" << endl;
        cout << "\t\t\t 4. Retroceder" << endl;
        cout << "\t\t\t-----------------------------------" << endl;
        cout << "\t\t\tOpción a escoger:[1/2/3/4]" << endl;
        cout << "\t\t\t-----------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opción: ";
        cin >> choice;

        switch (choice) {
            case 1:
                agregarEmpleado(); // Llama a la función para agregar un empleado
                break;
            case 2:
                eliminarEmpleado(); // Llama a la función para eliminar un empleado
                break;
            case 3:
                verEmpleados(); // Llama a la función para ver la información de los empleados
                break;
            case 4:
                // Salir del menú de empleados
                break;
            default:
                cout << "\n\t\t\t Opción inválida... Por favor prueba otra vez..";
                cin.ignore();
                cin.get();
        }
    } while (choice != 4);
}

void sueldos::agregarEmpleado() {
    Empleado empleado;
    srand(time(0)); // Inicializar el generador de números aleatorios

    cout << "\n\tIngrese el nombre del empleado: ";
    cin.ignore();
    getline(cin, empleado.nombre);

    cout << "\tIngrese el puesto del empleado: ";
    getline(cin, empleado.puesto);

    cout << "\tIngrese el salario del empleado: ";
    cin >> empleado.salario;

    // Generar un código único para el empleado
    int codigoEmpleado = rand() % 10000; // Generar un número aleatorio entre 0 y 9999

    // Guardar la información en un archivo binario
    ofstream file("empleados.dat", ios::binary | ios::app);
    size_t nombreSize = empleado.nombre.size();
    size_t puestoSize = empleado.puesto.size();
    file.write(reinterpret_cast<const char*>(&codigoEmpleado), sizeof(codigoEmpleado));
    file.write(reinterpret_cast<const char*>(&nombreSize), sizeof(nombreSize));
    file.write(empleado.nombre.c_str(), nombreSize);
    file.write(reinterpret_cast<const char*>(&puestoSize), sizeof(puestoSize));
    file.write(empleado.puesto.c_str(), puestoSize);
    file.write(reinterpret_cast<const char*>(&empleado.salario), sizeof(empleado.salario));
    file.close();

    cout << "\n\t¡El empleado ha sido agregado con éxito!\n";
    system("pause");
}

void sueldos::eliminarEmpleado() {
    int codigoEmpleado;
    cout << "\n\tIngrese el código del empleado que desea eliminar: ";
    cin >> codigoEmpleado;

    ifstream archivo("empleados.dat", ios::binary);
    ofstream archivoTmp("empleados_tmp.dat", ios::binary);

    size_t nombreSize, puestoSize;
    Empleado empleado;
    int codigo;
    bool eliminado = false;

    while (archivo.read(reinterpret_cast<char*>(&codigo), sizeof(codigo))) {
        archivo.read(reinterpret_cast<char*>(&nombreSize), sizeof(nombreSize));
        empleado.nombre.resize(nombreSize);
        archivo.read(&empleado.nombre[0], nombreSize);
        archivo.read(reinterpret_cast<char*>(&puestoSize), sizeof(puestoSize));
        empleado.puesto.resize(puestoSize);
        archivo.read(&empleado.puesto[0], puestoSize);
        archivo.read(reinterpret_cast<char*>(&empleado.salario), sizeof(empleado.salario));

        if (codigo == codigoEmpleado) {
            eliminado = true;
        } else {
            archivoTmp.write(reinterpret_cast<const char*>(&codigo), sizeof(codigo));
            archivoTmp.write(reinterpret_cast<const char*>(&nombreSize), sizeof(nombreSize));
            archivoTmp.write(empleado.nombre.c_str(), nombreSize);
            archivoTmp.write(reinterpret_cast<const char*>(&puestoSize), sizeof(puestoSize));
            archivoTmp.write(empleado.puesto.c_str(), puestoSize);
            archivoTmp.write(reinterpret_cast<const char*>(&empleado.salario), sizeof(empleado.salario));
        }
    }

    archivo.close();
    archivoTmp.close();

    remove("empleados.dat");
    rename("empleados_tmp.dat", "empleados.dat");

    if (eliminado) {
        cout << "\n\t¡El empleado ha sido eliminado con éxito!\n";
    } else {
        cout << "\n\tEste empleado no existe en la base de datos.\n";
    }

    system("pause");
}

void sueldos::verEmpleados() {
    ifstream archivo("empleados.dat", ios::binary);
    if (!archivo) {
        cout << "No hay empleados registrados." << endl;
        return;
    }

    Empleado empleado;
    int codigo;

    cout << "\n-----------------Información de los empleados---------------------" << endl;
    cout << "Código" << setw(10) << "Nombre" << setw(22) << "Puesto" << setw(12) << "Salario\n\n";

    size_t nombreSize, puestoSize;
    while (archivo.read(reinterpret_cast<char*>(&codigo), sizeof(codigo))) {
        archivo.read(reinterpret_cast<char*>(&nombreSize), sizeof(nombreSize));
        empleado.nombre.resize(nombreSize);
        archivo.read(&empleado.nombre[0], nombreSize);
        archivo.read(reinterpret_cast<char*>(&puestoSize), sizeof(puestoSize));
        empleado.puesto.resize(puestoSize);
        archivo.read(&empleado.puesto[0], puestoSize);
        archivo.read(reinterpret_cast<char*>(&empleado.salario), sizeof(empleado.salario));

        cout << codigo << setw(10) << empleado.nombre << setw(22) << empleado.puesto << setw(12) << empleado.salario << endl;
    }

    archivo.close();

    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}

void sueldos::procesoAsignacionMaestros() {
    string nombre, especializacion, lugarImpartirClases;
    cout << "\n\tIngrese su nombre: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "\tIngrese su especialización (Ingeniería o Licenciatura): ";
    getline(cin, especializacion);
    cout << "\tIngrese donde quiere impartir clases (Ingeniería o Licenciatura): ";
    getline(cin, lugarImpartirClases);

    // Guardar la información en un archivo binario
    ofstream file("Maestros.dat", ios::binary | ios::app);
    size_t nombreSize = nombre.size();
    size_t especializacionSize = especializacion.size();
    size_t lugarImpartirClasesSize = lugarImpartirClases.size();
    file.write(reinterpret_cast<const char*>(&nombreSize), sizeof(nombreSize));
    file.write(nombre.c_str(), nombreSize);
    file.write(reinterpret_cast<const char*>(&especializacionSize), sizeof(especializacionSize));
    file.write(especializacion.c_str(), especializacionSize);
    file.write(reinterpret_cast<const char*>(&lugarImpartirClasesSize), sizeof(lugarImpartirClasesSize));
    file.write(lugarImpartirClases.c_str(), lugarImpartirClasesSize);
    file.close();

    cout << "\n\t¡La información ha sido guardada con éxito!\n";
    system("pause");
}

void sueldos::verMaestros() {
    ifstream archivo("Maestros.dat", ios::binary);
    if (!archivo) {
        cout << "No hay maestros registrados." << endl;
        return;
    }

    string nombre, especializacion, lugarImpartirClases;
    size_t nombreSize, especializacionSize, lugarImpartirClasesSize;

    cout << "\n-----------------Información de los maestros---------------------" << endl;
    cout << setw(20) << "Nombre" << setw(25) << "Especialización" << setw(30) << "Lugar para impartir clases\n\n";

    while (archivo.read(reinterpret_cast<char*>(&nombreSize), sizeof(nombreSize))) {
        nombre.resize(nombreSize);
        archivo.read(&nombre[0], nombreSize);
        archivo.read(reinterpret_cast<char*>(&especializacionSize), sizeof(especializacionSize));
        especializacion.resize(especializacionSize);
        archivo.read(&especializacion[0], especializacionSize);
        archivo.read(reinterpret_cast<char*>(&lugarImpartirClasesSize), sizeof(lugarImpartirClasesSize));
        lugarImpartirClases.resize(lugarImpartirClasesSize);
        archivo.read(&lugarImpartirClases[0], lugarImpartirClasesSize);

        cout << setw(20) << nombre << setw(25) << especializacion << setw(30) << lugarImpartirClases << endl;
    }

    archivo.close();

    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}

void sueldos::generacionNomina() {
    string nombre, mesPago;
    double salario;

    cout << "\n\tIngrese el nombre del empleado: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "\tIngrese el sueldo del empleado: ";
    cin >> salario;

    cout << "\tIngrese el mes de pago del empleado: ";
    cin.ignore();
    getline(cin, mesPago);

    // Calcular las deducciones
    double deduccionIGGS = salario * 0.055;
    double deduccionISR = salario * 0.0483;
    double deduccionIRTRA = salario * 0.01;
    double totalDeducciones = deduccionIGGS + deduccionISR + deduccionIRTRA;

    // Calcular las bonificaciones
    double bonificacionIncentivo = 250.0;
    double bonificacionExtra = 0.0;

    if (mesPago == "julio") {
        bonificacionExtra = salario; // Bono 14
    } else if (mesPago == "diciembre") {
        bonificacionExtra = salario; // Aguinaldo
    }

    // Calcular el salario neto
    double salarioNeto = salario - totalDeducciones + bonificacionIncentivo + bonificacionExtra;

    // Mostrar los resultados en una tabla
    cout << fixed << setprecision(2); // Establecer la precisión a dos decimales
    cout << "\n-------------------Detalle de Nómina-------------------\n";
    cout << "Empleado: " << nombre << endl;
    cout << "Sueldo Bruto: Q" << salario << endl;
    cout << "--------------------------------------------------------\n";
    cout << "Deducciones:\n";
    cout << "IGSS (5.5%): Q" << deduccionIGGS << endl;
    cout << "ISR (4.83%): Q" << deduccionISR << endl;
    cout << "IRTRA (1%): Q" << deduccionIRTRA << endl;
    cout << "Total Deducciones: Q" << totalDeducciones << endl;
    cout << "--------------------------------------------------------\n";
    cout << "Bonificaciones:\n";
    cout << "Bonificación Incentivo: Q" << bonificacionIncentivo << endl;
    if (bonificacionExtra > 0) {
        cout << "Bonificación Extra: Q" << bonificacionExtra << " (" << (mesPago == "julio" ? "Bono 14" : "Aguinaldo") << ")" << endl;
    }
    cout << "--------------------------------------------------------\n";
    cout << "Sueldo Neto: Q" << salarioNeto << endl;
    cout << "--------------------------------------------------------\n";

    cout << "\n\t¡La nómina ha sido generada con éxito!\n";
    system("pause");
}

