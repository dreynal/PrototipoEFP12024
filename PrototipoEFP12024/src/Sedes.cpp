//Creado por Anderson Rodriguez 9959-23-495
//Programa que permite insertar, desplegar, modificar y borrar Sedes
//
#include "Sedes.h" // Incluye el archivo de cabecera Sedes.h que contiene la declaración de la clase Sedes
#include "usuarios.h"
#include<iostream> // Incluye la biblioteca estándar para entrada y salida
#include<fstream> // Incluye la biblioteca para manejo de archivos
#include<stdlib.h> // Incluye la biblioteca estándar para funciones de utilidad
#include<cstdlib> // Incluye la biblioteca estándar para funciones de utilidad
#include<iomanip> // Incluye la biblioteca para manipulación de la salida
#include <sstream> // Incluye la biblioteca para operaciones de flujo de cadena
#include <cstring> // Incluye la biblioteca para operaciones de cadena
#include"Bitacora.h"

using namespace std; // Usa el espacio de nombres estándar

// Definición de la estructura Sede que contiene los datos de una sede
struct Sede {
    char id[10];
    char nombre[50];
    char telefono[20];
};


// Definición de las funciones miembro de la clase Sedes
void Sedes::menu()
{
    //implementacion de variables para bitacora
    //string codigoPrograma = "6100";
    //Bitacora Auditoria;
    //string user = "admin";
    int choice; // Variable para almacenar la opción seleccionada por el usuario
    char x; // Variable para almacenar la respuesta de agregar otra sede

    // Ciclo para mostrar el menú y procesar las opciones del usuario
    do
    {
        system("cls"); // Limpia la pantalla

        // Imprime el encabezado del menú
        cout<<"\t\t\t-----------------------------------------"<<endl;
        cout<<"\t\t\t|   SISTEMA DE GESTION SEDES -  6100  |"<<endl;
        cout<<"\t\t\t-----------------------------------------"<<endl;
        cout<<"\t\t\t 1. Ingreso Sedes"<<endl;
        cout<<"\t\t\t 2. Despliegue Sedes"<<endl;
        cout<<"\t\t\t 3. Modifica Sedes"<<endl;
        cout<<"\t\t\t 4. Borra Sedes"<<endl;
        cout<<"\t\t\t 5. Retornar menu anterior"<<endl;
        cout<<"\t\t\t-----------------------------------------"<<endl;
        cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5]"<<endl;
        cout<<"\t\t\t-----------------------------------------"<<endl;
        cout<<"\t\t\tIngresa tu Opcion: ";
        cin>>choice; // Lee la opción del usuario

        switch(choice) // Evalúa la opción seleccionada por el usuario
        {
        case 1:
            // Agregar sede
            do
            {
                insertar(); // Llama a la función para agregar una sede
                cout<<"\n\t\t\t Agrega otra Sede(Y,N): ";
                cin>>x; // Pregunta al usuario si quiere agregar otra sede
            } while(x=='y'||x=='Y'); // Repite el proceso si el usuario responde 'y' o 'Y'
            break;
        case 2:
            desplegar(); // Llama a la función para mostrar las sedes
            break;
        case 3:
            modificar(); // Llama a la función para modificar una sede
            break;
        case 4:
            borrar(); // Llama a la función para borrar una sede
            break;
        case 5:
            break; // Salir del menú
        default:
            cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.get(); // Espera a que el usuario presione Enter
        }
    } while(choice!= 5); // Repite el menú hasta que el usuario seleccione la opción 5
}

// Función para agregar una sede
void Sedes::insertar() {
    system("cls"); // Limpia la pantalla
    Sede sede; // Crea una instancia de la estructura Sede para almacenar los datos de la sede
    ofstream file("Sedes.dat", ios::binary | ios::app); // Abre el archivo "Sedes.dat" en modo de escritura binaria, append

    // Verifica si el archivo se abrió correctamente
    if (!file) {
        cerr << "No se pudo abrir el archivo." << endl; // Muestra un mensaje de error si no se puede abrir el archivo
        return; // Retorna
    }

    // Solicita al usuario ingresar los datos de la sede
    cout << "\n--------------------------------------------------------------------------------------------------------------------";
    cout << "\n-------------------------------------------------Agregar Sede-------------------------------------------------------" << endl;
    cout << "\t\t\tIngrese id de Sede       : ";
    cin.ignore();
    cin.getline(sede.id, sizeof(sede.id));
    cout << "\t\t\tIngrese nombre de Sede   : ";
    cin.getline(sede.nombre, sizeof(sede.nombre));
    cout << "\t\t\tIngrese Telefono de Sede : ";
    cin.getline(sede.telefono, sizeof(sede.telefono));
    // Escribe los datos de la sede en el archivo
    file.write(reinterpret_cast<const char*>(&sede), sizeof(Sede));
    file.close(); // Cierra el archivo
    string codigoPrograma="6100";
    Bitacora Auditoria;
    string user;
    Auditoria.ingresoBitacora(user,codigoPrograma,"INS");
}

// Función para mostrar todas las sedes
void Sedes::desplegar(){
    system("cls"); // Limpia la pantalla
    ifstream file("Sedes.dat", ios::binary); // Abre el archivo "Sedes.dat" en modo de lectura binaria

    // Verifica si el archivo se abrió correctamente
    if (!file) {
        cerr << "No se pudo abrir el archivo." << endl; // Muestra un mensaje de error si no se puede abrir el archivo
        return; // Retorna
    }

    int total = 0; // Contador para el total de sedes

    // Muestra la tabla de detalles de sedes
    cout << "\n-----------------------------------------Tabla Detalles de Sedes ----------------------------------------------" << endl;
    Sede sede; // Crea una instancia de la estructura Sede para almacenar los datos de cada sede
    while (file.read(reinterpret_cast<char*>(&sede), sizeof(Sede))) { // Lee los datos de las sedes del archivo
        cout << "\t\t\t ID Sede      : " << sede.id << endl;
        cout << "\t\t\t Nombre Sede  : " << sede.nombre << endl;
        cout << "\t\t\t Telefono Sede: " << sede.telefono << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
        total++; // Incrementa el contador de sedes
    }

    if (total == 0) { // Verifica si no hay sedes en el archivo
        cout << "\n\t\t\tNo hay informacion..." << endl; // Muestra un mensaje indicando que no hay información
    }

    file.close(); // Cierra el archivo
    cin.ignore(); // Limpia el buffer de entrada
    system("pause"); // Pausa el sistema para que el usuario pueda ver la información
    string codigoPrograma="6100";
    Bitacora Auditoria;
    string user;
    Auditoria.ingresoBitacora(user,codigoPrograma,"CON");
}

// Función para modificar los detalles de una sede
void Sedes::modificar() {
    system("cls"); // Limpia la pantalla
    fstream file("Sedes.dat", ios::in | ios::out | ios::binary); // Abre el archivo "Sedes.dat" en modo de lectura/escritura binaria

    // Verifica si el archivo se abrió correctamente
    if (!file) {
        cout << "\n\t\t\tNo hay información..."; // Muestra un mensaje de error si no se puede abrir el archivo
        return; // Retorna
    }

    string id_modificar; // Variable para almacenar el ID de la sede que se desea modificar
    int found = 0; // Variable para indicar si se encontró la sede a modificar

    cout << "\n-------------------------------------Modificar Detalles de Sedes----------------------------------------------" << endl;
    cout << "\t\t\tIngrese ID de la Sede que desea modificar: ";
    cin >> id_modificar; // Lee el ID de la sede que se desea modificar

    Sede sede; // Crea una instancia de la estructura Sede para almacenar los datos de la sede
    ofstream file1("temporal.dat", ios::binary); // Abre un archivo temporal en modo de escritura binaria

    // Verifica si el archivo temporal se abrió correctamente
    if (!file1) {
        cout << "\n\t\t\tError al abrir el archivo temporal..."; // Muestra un mensaje de error si no se puede abrir el archivo temporal
        return; // Retorna
    }

    // Lee las sedes del archivo y modifica los detalles de la sede con el ID proporcionado
    while (file.read(reinterpret_cast<char*>(&sede), sizeof(Sede))) {
        if (strcmp(sede.id, id_modificar.c_str()) == 0) { // Compara el ID de la sede actual con el ID proporcionado
            cout << "\t\t\tIngrese nuevo ID de Sede: ";
            cin >> sede.id; // Solicita al usuario ingresar el nuevo ID de la sede
            cout << "\t\t\tIngrese nuevo nombre de Sede: ";
            cin.ignore();
            cin.getline(sede.nombre, sizeof(sede.nombre)); // Solicita al usuario ingresar el nuevo nombre de la sede
            cout << "\t\t\tIngrese nuevo telefono de Sede: ";
            cin.getline(sede.telefono, sizeof(sede.telefono)); // Solicita al usuario ingresar el nuevo teléfono de la sede

            file1.write(reinterpret_cast<const char*>(&sede), sizeof(Sede)); // Escribe los datos de la sede modificada en el archivo temporal

            cout << "\n\t\t\tSede modificada correctamente!!!" << endl; // Muestra un mensaje indicando que la sede se modificó correctamente
            found++; // Incrementa el contador de sedes encontradas
        } else {
            file1.write(reinterpret_cast<const char*>(&sede), sizeof(Sede)); // Escribe los datos de la sede sin modificar en el archivo temporal
        }
    }

    if (!found) { // Verifica si no se encontró la sede con el ID proporcionado
        cout << "\n\t\t\tNo se encontro la Sede con el ID proporcionado." << endl; // Muestra un mensaje indicando que no se encontró la sede
    }

    file.close(); // Cierra el archivo original
    file1.close(); // Cierra el archivo temporal
    remove("Sedes.dat"); // Elimina el archivo original
    rename("temporal.dat", "Sedes.dat"); // Renombra el archivo temporal como "Sedes.dat"
    cin.ignore(); // Limpia el buffer de entrada
    system("pause"); // Pausa el sistema para que el usuario pueda ver el mensaje
    string codigoPrograma="6100";
    Bitacora Auditoria;
    string user;
    Auditoria.ingresoBitacora(user,codigoPrograma,"ACT");
}

// Función para borrar una sede
void Sedes::borrar() {
    system("cls"); // Limpia la pantalla
    string id_borrar; // Variable para almacenar el ID de la sede que se desea borrar
    int found = 0; // Variable para indicar si se encontró la sede a borrar

    cout << "\n------------------------------------------Detalles Sede a Borrar-----------------------------------------------" << endl;

    ifstream file("Sedes.dat", ios::binary); // Abre el archivo "Sedes.dat" en modo de lectura binaria

    // Verifica si el archivo se abrió correctamente
    if (!file) {
        cout << "\n\t\t\tNo hay informacion..."; // Muestra un mensaje de error si no se puede abrir el archivo
        return; // Retorna
    }

    ofstream file1("temporal.dat", ios::binary); // Abre un archivo temporal en modo de escritura binaria

    // Verifica si el archivo temporal se abrió correctamente
    if (!file1) {
        cout << "\n\t\t\tError al abrir el archivo temporal..."; // Muestra un mensaje de error si no se puede abrir el archivo temporal
        return; // Retorna
    }

    cout << "\n-----------------------------------------Sistema Busqueda de Sedes---------------------------------------------" << endl;
    cout << "\n\t\t Ingrese Id de la Sede que quiere Borrar: ";
    cin >> id_borrar; // Lee el ID de la sede que se desea borrar

    Sede sede; // Crea una instancia de la estructura Sede para almacenar los datos de la sede
    while (file.read(reinterpret_cast<char*>(&sede), sizeof(Sede))) { // Lee las sedes del archivo
        if (strcmp(sede.id, id_borrar.c_str()) == 0) { // Compara el ID de la sede actual con el ID proporcionado
            cout << "\n\t\t\tBorrado de informacion exitoso!!!!" << "\n" << endl; // Muestra un mensaje indicando que la sede se borró exitosamente
            found++; // Incrementa el contador de sedes encontradas
        } else {
            file1.write(reinterpret_cast<const char*>(&sede), sizeof(Sede)); // Escribe los datos de la sede sin borrar en el archivo temporal
        }
    }

    if (found == 0) { // Verifica si no se encontró la sede con el ID proporcionado
        cout << "\n\t\t\tId de Sede no encontrado...." << "\n" << endl; // Muestra un mensaje indicando que no se encontró la sede
    }

    file1.close(); // Cierra el archivo temporal
    file.close(); // Cierra el archivo original

    remove("Sedes.dat"); // Elimina el archivo original
    rename("temporal.dat", "Sedes.dat"); // Renombra el archivo temporal como "Sedes.dat"

    cin.ignore(); // Limpia el buffer de entrada
    system("pause"); // Pausa el sistema para que el usuario pueda ver el mensaje
    string codigoPrograma="6100";
    Bitacora Auditoria;
    string user;
    Auditoria.ingresoBitacora(user,codigoPrograma,"DEL");
}
