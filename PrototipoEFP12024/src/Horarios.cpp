


#include "Horarios.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <cstring>
#include "Bitacora.h"

using namespace std;

// Estructura para almacenar los datos de los horarios
struct horarios {
    char id[11];      // ID del horario, longitud máxima de 10 caracteres
    char Sede[11];    // Nombre de la sede, longitud máxima de 10 caracteres
    char Jornada [11];
    char Horario[11]; // Horario, longitud máxima de 10 caracteres

};

// Método para mostrar el menú principal del sistema de gestión de horarios
void Horarios::menu() {
    int choice;
    char x;

    do {
        system("cls"); // Limpia la pantalla (en sistemas Windows)
        cout << "\t\t\t-----------------------------------------"<<endl;
        cout << "\t\t\t|   SISTEMA DE GESTION HORARIOS -  6200  |"<<endl;
        cout << "\t\t\t-----------------------------------------"<<endl;
        cout << "\t\t\t 1. Agregar Horario"<<endl;
        cout << "\t\t\t 2. Despliegue Horarios"<<endl;
        cout << "\t\t\t 3. Modificar Horario"<<endl;
        cout << "\t\t\t 4. Borrar Horario"<<endl;
        cout << "\t\t\t 5. Retornar menu anterior"<<endl;
        cout << "\t\t\t-----------------------------------------"<<endl;
        cout << "\t\t\t Opcion a escoger:[1/2/3/4/5]"<<endl;
        cout << "\t\t\t-----------------------------------------"<<endl;
        cout << "\t\t\t Ingresa tu Opcion: ";
        cin >> choice;

        switch(choice) {
        case 1:
            do {
                insertar(); // Llama al método para agregar un nuevo horario
                cout << "\n\t\t\t Agregar otro Horario(Y,N): ";
                cin >> x;
            } while(x == 'y' || x == 'Y'); // Repite mientras el usuario ingrese 'Y' o 'y'
            break;
        case 2:
            desplegar(); // Llama al método para desplegar todos los horarios
            break;
        case 3:
            modificar(); // Llama al método para modificar un horario existente
            break;
        case 4:
            borrar(); // Llama al método para borrar un horario
            break;
        case 5:
            return; // Sale del menú
        default:
            cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.get();
        }
    } while(choice != 5);
}

// Método para insertar un nuevo horario
void Horarios::insertar() {
    system("cls"); // Limpia la pantalla
    Horarios horarios; // Crea una instancia de la estructura horarios
    ofstream file("Horarios.dat", ios::binary | ios::app); // Abre el archivo en modo binario y de adición

    if (!file) {
        cerr << "No se pudo abrir el archivo." << endl;
        return;
    }

    // Solicita los datos del nuevo horario al usuario
    cout << "\n--------------------------------------------------------------------------------------------------------------------";
    cout << "\n-------------------------------------------------Agregar Horario-------------------------------------------------------" << endl;
    cout << "\t\t\tIngrese id del Horario: ";
    cin.ignore();
    cin.getline(horario.id, sizeof(horario.id));
    cout << "\t\t\tIngrese nombre   : ";
    cin.getline(horario.nombre, sizeof(horario.nombre));
    cout << "\t\t\tElija la Jornada : ";
    cin.getline(horario.Jornada, sizeof(horario.Jornada));
    cout << "\t\t\tIngrese Horario : ";
    cin.getline(horario.Horario, sizeof(horario.Horario));
    file.write(reinterpret_cast<const char*>(&horario), sizeof(horario)); // Escribe los datos en el archivo
    file.close(); // Cierra el archivo
    string codigoPrograma = "6200";
    Bitacora Auditoria;
    string user;
    Auditoria.ingresoBitacora(user, codigoPrograma, "INS"); // Registra la acción en la bitácora
}

// Método para desplegar todos los horarios almacenados
void Horarios::desplegar() {
    system("cls"); // Limpia la pantalla
    ifstream file("Horarios.dat", ios::binary); // Abre el archivo en modo binario

    if (!file) {
        cerr << "No se pudo abrir el archivo." << endl;
        return;
    }

    int total = 0;

    cout << "\n-----------------------------------------Tabla Detalles de Horarios ----------------------------------------------" << endl;
    Horarios horarios;
    while (file.read(reinterpret_cast<char*>(&horario), sizeof(horario))) { // Lee los datos del archivo
        cout << "\t\t\t ID del Horario      : " << horario.id << endl;
        cout << "\t\t\t Nombre   : " << horario.nombre << endl;
        cout << "\t\t\t Jornada del Horario : " << horario.Jornada << endl;
        cout << "\t\t\t Horario de la Sede  : " << horario.Horario << endl;

        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
        total++;
    }

    if (total == 0) {
        cout << "\n\t\t\tNo hay informacion..." << endl;
    }

    file.close(); // Cierra el archivo
    cin.ignore();
    system("pause"); // Pausa la ejecución hasta que el usuario presione una tecla
    string codigoPrograma = "6200";
    Bitacora Auditoria;
    string user;
    Auditoria.ingresoBitacora(user, codigoPrograma, "CON"); // Registra la acción en la bitácora
}

// Método para modificar un horario existente
void Horarios::modificar() {
    system("cls"); // Limpia la pantalla
    fstream file("Horarios.dat", ios::in | ios::out | ios::binary); // Abre el archivo en modo binario para lectura y escritura

    if (!file) {
        cout << "\n\t\t\tNo hay información...";
        return;
    }

    string id_modificar;
    int found = 0;

    cout << "\n-------------------------------------Modificar Detalles del Horario----------------------------------------------" << endl;
    cout << "\t\t\tIngrese ID del Horario que desea modificar: ";
    cin >> id_modificar;

    Horarios horarios;
    ofstream file1("temporal.dat", ios::binary); // Abre un archivo temporal en modo binario

    if (!file1) {
        cout << "\n\t\t\tError al abrir el archivo temporal...";
        return;
    }

    while (file.read(reinterpret_cast<char*>(&horario), sizeof(Horario))) { // Lee los datos del archivo original
        if (strcmp(horario.id, id_modificar.c_str()) == 0) {
            // Solicita los nuevos datos al usuario
            cout << "\t\t\tIngrese nuevo ID del Horario: ";
            cin >> horario.id;
            cout << "\t\t\tIngrese nuevo nombre de la Sede: ";
            cin.ignore();
            cin.getline(horario.nombre, sizeof(horario.nombre));
            cout << "\t\t\t Elija la Jornada: ";
            cin.getline(horario.Jornada, sizeof(horario.Jornada));
            cout << "\t\t\tIngrese el nuevo Horario: ";
            cin.getline(horario.Horario, sizeof(horario.Horario));

            file1.write(reinterpret_cast<const char*>(&horario), sizeof(Horario)); // Escribe los datos modificados en el archivo temporal

            cout << "\n\t\t\t Horario modificad correctamente!!!" << endl;
            found++;
        } else {
            file1.write(reinterpret_cast<const char*>(&horario), sizeof(Horario)); // Escribe los datos no modificados en el archivo temporal
        }
    }

    if (!found) {
        cout << "\n\t\t\tNo se encontro algun Horario con el ID proporcionado." << endl;
    }

    file.close(); // Cierra el archivo original
    file1.close(); // Cierra el archivo temporal
    remove("Horarios.dat"); // Elimina el archivo original
    rename("temporal.dat", "Horarios.dat"); // Renombra el archivo temporal al nombre del archivo original
    cin.ignore();
    system("pause"); // Pausa la ejecución hasta que el usuario presione una tecla
    string codigoPrograma = "6200";
    Bitacora Auditoria;
    string user;
    Auditoria.ingresoBitacora(user, codigoPrograma, "ACT"); // Registra la acción en la bitácora
}

// Método para borrar un horario
void Horarios::borrar() {
    system("cls"); // Limpia la pantalla
    string id_borrar;
    int found = 0;

    cout << "\n------------------------------------------Detalles Horario a Borrar-----------------------------------------------" << endl;

    ifstream file("Horarios.dat", ios::binary); // Abre el archivo en modo binario

    if (!file) {
        cout << "\n\t\t\tNo hay informacion...";
        return;
    }

    ofstream file1("temporal.dat", ios::binary); // Abre un archivo temporal en modo binario

    if (!file1) {
        cout << "\n\t\t\tError al abrir el archivo temporal...";
        return;
    }

    cout << "\n-----------------------------------------Sistema Busqueda de Horarios---------------------------------------------" << endl;
    cout << "\n\t\t Ingrese Id del Horario que quiere Borrar: ";
    cin >> id_borrar;

    Horario horario;
    while (file.read(reinterpret_cast<char*>(&horario), sizeof(Horario))) { // Lee los datos del archivo original
        if (strcmp(horario.id, id_borrar.c_str()) == 0) {
            // Si se encuentra el ID, no se escribe en el archivo temporal
            cout << "\n\t\t\tBorrado de informacion exitoso!!!!" << "\n" << endl;
            found++;
        } else {
            file1.write(reinterpret_cast<const char*>(&horario), sizeof(Horario)); // Escribe los datos no borrados en el archivo temporal
        }
    }

    if (found == 0) {
        cout << "\n\t\t\tId de Horario no encontrado...." << "\n" << endl;
    }

    file1.close(); // Cierra el archivo temporal
    file.close(); // Cierra el archivo original

    remove("Horarios.dat"); // Elimina el archivo original
    rename("temporal.dat", "Horarios.dat"); // Renombra el archivo temporal al nombre del archivo original

    cin.ignore();
    system("pause"); // Pausa la ejecución hasta que el usuario presione una tecla
    string codigoPrograma = "6200";
    Bitacora Auditoria;
    string user;
    Auditoria.ingresoBitacora(user, codigoPrograma, "DEL"); // Registra la acción en la bitácora
}
