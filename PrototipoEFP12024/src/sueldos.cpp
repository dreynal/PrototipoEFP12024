
#include <iostream>
#include <fstream>
#include <iomanip>
#include "sueldos.h"
#include "Bitacora.h"
#include <cstdlib> // Para la funci�n rand()
#include <ctime> // Para la funci�n time()

using namespace std;

void sueldos::menu() {
    int choice;
    string codigoPrograma = "6650"; // C�digo del programa
    Bitacora Auditoria; // Objeto para gestionar la bit�cora de auditor�a
    string user = "admin"; // Usuario actual del sistema

    do {
        system("cls");
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t|    MENU DE SUELDOS          |" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t 1. Base de datos de empleados" << endl;
        cout << "\t\t\t 2. Generaci�n de n�minas" << endl;
        cout << "\t\t\t 3. Proceso de asignaci�n " << endl;
        cout << "\t\t\t 4. Ver informaci�n  " << endl;
        cout << "\t\t\t 5. Retorno" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\tOpci�n a escoger:[1/2/3/4/5]" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opci�n: ";
        cin >> choice;

        switch (choice) {
            case 1:
                menuEmpleados(); // Llama a la funci�n para el men� de empleados
                Auditoria.ingresoBitacora(user, codigoPrograma, "MEN"); // Registra en la bit�cora la acci�n de mostrar el men� de empleados
                break;
            case 2:
                generacionNomina(); // Llama a la funci�n para la generaci�n de n�mina
                break;
            case 3:
                procesoAsignacionMaestros(); // Llama a la funci�n para el proceso de asignaci�n de maestros
                break;
            case 4:
                verMaestros(); // Llama a la funci�n para ver la informaci�n de los maestros
                break;
            case 5:
                // Implementa la funcionalidad para "Retorno" aqu� si es necesario
                break;
            default:
                cout << "\n\t\t\t Opci�n inv�lida... Por favor prueba otra vez..";
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
        cout << "\t\t\t 3. Ver informaci�n de los empleados" << endl;
        cout << "\t\t\t 4. Retroceder" << endl;
        cout << "\t\t\t-----------------------------------" << endl;
        cout << "\t\t\tOpci�n a escoger:[1/2/3/4]" << endl;
        cout << "\t\t\t-----------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opci�n: ";
        cin >> choice;

        switch (choice) {
            case 1:
                agregarEmpleado(); // Llama a la funci�n para agregar un empleado
                break;
            case 2:
                eliminarEmpleado(); // Llama a la funci�n para eliminar un empleado
                break;
            case 3:
                verEmpleados(); // Llama a la funci�n para ver la informaci�n de los empleados
                break;
            case 4:
                // Salir del men� de empleados
                break;
            default:
                cout << "\n\t\t\t Opci�n inv�lida... Por favor prueba otra vez..";
                cin.ignore();
                cin.get();
        }
    } while (choice != 4);
}

void sueldos::agregarEmpleado() {
    Empleado empleado;
    srand(time(0)); // Inicializar el generador de n�meros aleatorios

    cout << "\n\tIngrese el nombre del empleado: ";
    cin.ignore();
    getline(cin, empleado.nombre);

    cout << "\tIngrese el puesto del empleado: ";
    getline(cin, empleado.puesto);

    cout << "\tIngrese el salario del empleado: ";
    cin >> empleado.salario;

    // Generar un c�digo �nico para el empleado
    int codigoEmpleado = rand() % 10000; // Generar un n�mero aleatorio entre 0 y 9999

    // Guardar la informaci�n en un archivo binario
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

    cout << "\n\t�El empleado ha sido agregado con �xito!\n";
    system("pause");
}

void sueldos::eliminarEmpleado() {
    int codigoEmpleado;
    cout << "\n\tIngrese el c�digo del empleado que desea eliminar: ";
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
        cout << "\n\t�El empleado ha sido eliminado con �xito!\n";
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

    cout << "\n-----------------Informaci�n de los empleados---------------------" << endl;
    cout << "C�digo" << setw(10) << "Nombre" << setw(22) << "Puesto" << setw(12) << "Salario\n\n";

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
    cout << "\tIngrese su especializaci�n (Ingenier�a o Licenciatura): ";
    getline(cin, especializacion);
    cout << "\tIngrese donde quiere impartir clases (Ingenier�a o Licenciatura): ";
    getline(cin, lugarImpartirClases);

    // Guardar la informaci�n en un archivo binario
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

    cout << "\n\t�La informaci�n ha sido guardada con �xito!\n";
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

    cout << "\n-----------------Informaci�n de los maestros---------------------" << endl;
    cout << setw(20) << "Nombre" << setw(25) << "Especializaci�n" << setw(30) << "Lugar para impartir clases\n\n";

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
    cout << fixed << setprecision(2); // Establecer la precisi�n a dos decimales
    cout << "\n-------------------Detalle de N�mina-------------------\n";
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
    cout << "Bonificaci�n Incentivo: Q" << bonificacionIncentivo << endl;
    if (bonificacionExtra > 0) {
        cout << "Bonificaci�n Extra: Q" << bonificacionExtra << " (" << (mesPago == "julio" ? "Bono 14" : "Aguinaldo") << ")" << endl;
    }
    cout << "--------------------------------------------------------\n";
    cout << "Sueldo Neto: Q" << salarioNeto << endl;
    cout << "--------------------------------------------------------\n";

    cout << "\n\t�La n�mina ha sido generada con �xito!\n";
    system("pause");
}

