//Archivo de implementacion de la clase FACULTAD que contiene el funcionamiento de la clase
#include "facultad.h"
#include "Login.h"
#include "Bitacora.h"
#include "usuarios.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
//Elaborado por: Lourdes Isabel Melendez Pineda 9959-23-1379
//Comentado, Depurado y revisado por: Josue Daniel Villagran Pinto 9490-11-17319
using namespace std;
// CRUD de la clase
void FacultadCRUD::Crudfacultad() {
    int choice;
    do {
        system("cls");
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t|   SISTEMA DE GESTION UMG - FACULTADES    |" << endl;
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t 1. Ingresar Facultad" << endl;
        cout << "\t\t\t 2. Modificar Facultad" << endl;
        cout << "\t\t\t 3. Borrar Facultad" << endl;
        cout << "\t\t\t 4. Desplegar Facultad" << endl;
        cout << "\t\t\t 5. Regresar Menu Anterior" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\t |   Opcion a escoger:[1|2|3|4|5|]           |" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opcion: ";
        cin >> choice;

        switch (choice) {
            case 1:
                IngresarFa();
                system("Pause");
                break;
            case 2:
                ModificarFa();
                system("Pause");
                break;
            case 3:
                BorrarFa();
                system("Pause");
                break;
            case 4:
                DesplegarFa();
                break;
            case 5:
                break;
            default:
                cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
                cin.get();
        }
    } while (choice != 5);
}
// en esta parte de codigo nos permite agregar Facultades
void FacultadCRUD::IngresarFa() {
    string codigoPrograma="3001";
    system("cls");
    cout << "\n------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\n-------------------------------------------------Agregar Facultad--------------------------------------------" << endl;
    Facultad facultad;
    cout << "Ingrese el codigo de la facultad: ";
    cin >> facultad.codigo;
    cin.ignore();

    cout << "Ingrese el nombre de la Facultad: ";
    cin.getline(facultad.nombre, 50);

    ofstream archivo("facultad.dat", ios::binary | ios::app);
    archivo.write(reinterpret_cast<const char*>(&facultad), sizeof(Facultad));
    archivo.close();
//------------------------------------------------------------------
    Bitacora Auditoria;
    string user,pass;

    Auditoria.ingresoBitacora(user,codigoPrograma,"ICA");//ICA = Insertar Carrera
//------------------------------------------------------------------------------------------
    cout << "Facultad agregada exitosamente!" << endl;
}
// modifica facultades regitradas
void FacultadCRUD::ModificarFa() {
    string codigoPrograma="3001";
    system("cls");
    cout << "\n-------------------------------------------------Modificar Facultad--------------------------------------------" << endl;
    int codigo;
    cout << "Ingrese el codigo de la facultad a modificar: ";
    cin >> codigo;

    fstream archivo("facultad.dat", ios::binary | ios::in | ios::out);
    if (!archivo) {
        cout << "No hay facultades registradas." << endl;
        return;
    }

    Facultad facultad;
    bool encontrada = false;
    while (archivo.read(reinterpret_cast<char*>(&facultad), sizeof(Facultad))) {
        if (facultad.codigo == codigo) {
            cout << "Ingrese el nuevo nombre de la facultad: ";
            cin.ignore();
            cin.getline(facultad.nombre, 50);

            archivo.seekp(-static_cast<int>(sizeof(Facultad)), ios::cur);
            archivo.write(reinterpret_cast<const char*>(&facultad), sizeof(Facultad));

            encontrada = true;
            break;
        }
    }

    archivo.close();
//------------------------------------------------------------------------------------
    Bitacora Auditoria;
    string user,pass;

    Auditoria.ingresoBitacora(user,codigoPrograma,"UCA");//UCA = Update Carrera
//-----------------------------------------------------------------------------------------
    // nos indica si no se encontro la facultad por si no esta registrada
    if (!encontrada) {
        cout << "No se encontró la facultad con el codigo ingresado." << endl;
    } else {
        cout << "Facultad modificada exitosamente!" << endl;
    }
}
// Borra facultades existentes
void FacultadCRUD::BorrarFa() {
    string codigoPrograma="3001";
    system("cls");
    cout << "\n-------------------------------------------------Borrar Facultad--------------------------------------------" << endl;
    int codigo;
    cout << "Ingrese el codigo de la facultad a eliminar: ";
    cin >> codigo;

    ifstream archivo("facultad.dat", ios::binary);
    if (!archivo) {
        cout << "No hay facultades registradas." << endl;
        return;
    }
// archivo temporal
    ofstream archivoTmp("facultad_tmp.dat", ios::binary);
    Facultad facultad;
    bool eliminada = false;
    while (archivo.read(reinterpret_cast<char*>(&facultad), sizeof(Facultad))) {
        if (facultad.codigo != codigo) {
            archivoTmp.write(reinterpret_cast<const char*>(&facultad), sizeof(Facultad));
        } else {
            eliminada = true;
        }
    }

    archivo.close();
    archivoTmp.close();

    remove("facultad.dat");
    rename("facultad_tmp.dat", "facultad.dat");
//---------------------------------------------------------------------------------------
    Bitacora Auditoria;
    string user,pass;

    Auditoria.ingresoBitacora(user,codigoPrograma,"DCA");//DCA = Delete Carrera
//----------------------------------------------------------------------------------------

    if (eliminada) {
        cout << "Facultad eliminada exitosamente!" << endl;
    } else {
        cout << "No se encontró la facultad con el codigo ingresado." << endl;
    }
}
// nos muestra un reporte de las facultades que estan registradas
void FacultadCRUD::DesplegarFa() {
    string codigoPrograma="3001";
    system("cls");
    cout << "-----------------Despliegue de facultades registradas---------------------" << endl;
    ifstream archivo("facultad.dat", ios::binary);
    if (!archivo) {
        cout << "No hay facultades registradas." << endl;
        return;
    }

    Facultad facultad;
    while (archivo.read(reinterpret_cast<char*>(&facultad), sizeof(Facultad))) {
        cout << "Codigo: " << facultad.codigo << endl;
        cout << "Nombre: " << facultad.nombre << endl;
        cout << "-----------------------------" << endl;
    }

    archivo.close();
//----------------------------------------------------------------------------------
    Bitacora Auditoria;
    string user,pass;

    Auditoria.ingresoBitacora(user,codigoPrograma,"RCA");// RCA = Read Carrera
//---------------------------------------------------------------------------------------
//para hacer otra operacion
    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}


