//Aqui se encuentra el archivos de implentación de la clase CARRERA que contiene todo el codigo fuente
//del funcionamiento del la clase
#include "Carrera.h"
#include "usuarios.h"
#include "Login.h"
#include "Bitacora.h"
#include <fstream>
#include <iostream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;
//Carlos David calderón Ramírez      9959-23-848
//Comentado revisado y depurado por:  Evelyn Sofía Andrade Luna   9959-23-1224
// menu CRUD de carreras



void CarrerasCRUD::Crudcarrera() {
int choice;
    //int x;
    do {
	system("cls");
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t|   SISTEMA DE GESTION UMG - CARRERAS      |"<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingresar Carrera"<<endl;
	cout<<"\t\t\t 2. Modificar Carrera"<<endl;
	cout<<"\t\t\t 3. Borrar Carrera"<<endl;
	cout<<"\t\t\t 4. Desplegar Carrera"<<endl;
	cout<<"\t\t\t 5. Regresar Menu Anterior"<<endl;
    cout<<"\t\t\t --------------------------------------------"<<endl;
	cout<<"\t\t\t |   Opcion a escoger:[1|2|3|4|5|]           |"<<endl;
	cout<<"\t\t\t --------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
	case 1:
        IngresarCa();
        system("Pause");
		break;
    case 2:
        system("Cls");
        ModificarCa();
		system("Pause");
		break;
    case 3:
        system("Cls");
        BorrarCa();
        system("Pause");
		break;
    case 4:
        DesplegarCa();
		break;
    case 5:
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		cin.get();
	}
    }while(choice!= 5);
}
// aqui se agregan carreras que son almacenadas
void CarrerasCRUD::IngresarCa() {
    string codigoPrograma="3000";
   system("cls");
    cout<<"\n------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n-------------------------------------------------Agregar Carrera--------------------------------------------"<<endl;
    Carrera carrera;
    cout << "Ingrese el codigo de la carrera: ";
    cin >> carrera.codigo;
    cin.ignore();

    cout << "Ingrese el nombre de la carrera: ";
    cin.getline(carrera.nombre, 50);

    cout << "Ingrese la facultad de la carrera: ";
    cin.getline(carrera.facultad, 50);

    ofstream archivo("carreras.dat", ios::binary | ios::app);
    archivo.write(reinterpret_cast<const char*>(&carrera), sizeof(Carrera));
    archivo.close();


    Bitacora Auditoria;
    string user,pass;

    Auditoria.ingresoBitacora(user,codigoPrograma,"ICA");//ICA = Insertar Carrera

    cout << "Carrera agregada exitosamente!" << endl;
}
// modificar carreras
void CarrerasCRUD::ModificarCa() {
    string codigoPrograma="3000";
    cout<<"\n------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n-------------------------------------------------Modificacion de Carreras--------------------------------------------"<<endl;
    int codigo;
    cout << "Ingrese el codigo de la carrera a modificar: ";
    cin >> codigo;

    fstream archivo("carreras.dat", ios::binary | ios::in | ios::out);
    if (!archivo) {
        cout << "No hay carreras registradas." << endl;
        return;
    }

    Carrera carrera;
    bool encontrada = false;
    while (archivo.read(reinterpret_cast<char*>(&carrera), sizeof(Carrera))) {
        if (carrera.codigo == codigo) {
            cout << "Ingrese el nuevo nombre de la carrera: ";
            cin.ignore();
            cin.getline(carrera.nombre, 50);

            cout << "Ingrese la nueva facultad de la carrera: ";
            cin.getline(carrera.facultad, 50);

            archivo.seekp(-static_cast<int>(sizeof(Carrera)), ios::cur);
            archivo.write(reinterpret_cast<const char*>(&carrera), sizeof(Carrera));

            encontrada = true;
            break;
        }
    }

    archivo.close();

    Bitacora Auditoria;
    string user,pass;

    Auditoria.ingresoBitacora(user,codigoPrograma,"UCA");//UCA = Update Carrera

    if (!encontrada) {
        cout << "No se encontró la carrera con el codigo ingresado." << endl;
    }
    else {
        cout << "Carrera modificada exitosamente!" << endl;
    }

}
// elimina carreras que ya no deseamos que estan registradas
void CarrerasCRUD::BorrarCa() {
    string codigoPrograma="3000";
    int codigo;
    cout<<"\n------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n-------------------------------------------------Eliminar Carreras--------------------------------------------"<<endl;
    cout << "Ingrese el codigo de la carrera a eliminar: ";
    cin >> codigo;

    ifstream archivo("carreras.dat", ios::binary);
    if (!archivo) {
        cout << "No hay carreras registradas." << endl;

    }

    ofstream archivoTmp("carreras_tmp.dat", ios::binary);
    Carrera carrera;
    bool eliminada = false;
    while (archivo.read(reinterpret_cast<char*>(&carrera), sizeof(Carrera))) {
        if (carrera.codigo != codigo) {
            archivoTmp.write(reinterpret_cast<const char*>(&carrera), sizeof(Carrera));
        } else {
            eliminada = true;
        }
    }

    archivo.close();
    archivoTmp.close();

    remove("carreras.dat");
    rename("carreras_tmp.dat", "carreras.dat");


    Bitacora Auditoria;
    string user,pass;

    Auditoria.ingresoBitacora(user,codigoPrograma,"DCA");//DCA = Delete Carrera

    if (eliminada) {
        cout << "Carrera eliminada exitosamente!" << endl;

    } else {
        cout << "No se encontró la carrera con el codigo ingresado." << endl;
    }

}
// Nos muestra las carreras registradas
void CarrerasCRUD::DesplegarCa() {
    system("cls");
    string codigoPrograma="3000";
    cout<<"-----------------Despliegue de carreras registradas---------------------"<<endl;
    ifstream archivo("carreras.dat", ios::binary);
    if (!archivo) {
        cout << "No hay carreras registradas." << endl;
        return;
    }

    Carrera carrera;
    while (archivo.read(reinterpret_cast<char*>(&carrera), sizeof(Carrera))) {
        cout << "Codigo: " << carrera.codigo << endl;
        cout << "Nombre: " << carrera.nombre << endl;
        cout << "Facultad: " << carrera.facultad << endl;
        cout << "-----------------------------" << endl;
    }

    archivo.close();


    Bitacora Auditoria;
    string user,pass;

    Auditoria.ingresoBitacora(user,codigoPrograma,"RCA");// RCA = Read Carrera

    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}
