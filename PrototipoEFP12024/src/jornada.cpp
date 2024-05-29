
#include "jornada.h"
#include <fstream>
#include <iostream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

//Implementación de Bitácora hechar por: Pablo Romeo Palencia Rosales 9959-23-736
#include "Bitacora.h"

using namespace std;

void JornadaCRUD::CrudJornada() {
int choice;
//implementacion de variables para la bitacora
string codigoPrograma="4001";
Bitacora Auditoria;
string user="admin";

    do {
	//limpiar pantalla
	system("cls");
	//menu de opciones
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t|   SISTEMA DE GESTION UMG - Jornada        |"<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingresar Jornada"<<endl;
	cout<<"\t\t\t 2. Modificar Jornada"<<endl;
	cout<<"\t\t\t 3. Borrar Jornada"<<endl;
	cout<<"\t\t\t 4. Desplegar Jornada"<<endl;
	cout<<"\t\t\t 5. Regresar Menu Anterior"<<endl;
    cout<<"\t\t\t --------------------------------------------"<<endl;
	cout<<"\t\t\t |   Opcion a escoger:[1|2|3|4|5|]           |"<<endl;
	cout<<"\t\t\t --------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
	case 1:
        Ingresar();
        //Se ejecuta la accion y se registra en la bitacora
        Auditoria.ingresoBitacora(user,codigoPrograma,"CJO"); //CJO = Create Jornada
        system("pause");
		break;
    case 2:
        Modificar();
        //Se ejecuta la accion y se registra en la bitacora
        Auditoria.ingresoBitacora(user,codigoPrograma,"UJO"); //UJO = Update Jornada
        system("pause");
		break;
    case 3:
        Borrar();
        //Se ejecuta la accion y se registra en la bitacora
        Auditoria.ingresoBitacora(user,codigoPrograma,"DJO"); //DJO = Delete Jornada
        system("pause");
		break;
    case 4:
        Desplegar();
        //Se ejecuta la accion y se registra en la bitacora
        Auditoria.ingresoBitacora(user,codigoPrograma,"RJO"); //RJO = Read Jornada
        system("pause");
		break;
    case 5:
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		cin.get();
	}
    }while(choice!= 5);
}


//Funcion que nos permite ingresar nuevos datos
void JornadaCRUD::Ingresar() {

	//limpia la consola
   system("cls");
    cout<<"\n------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n-------------------------------------------------Agregar Jornada--------------------------------------------"<<endl;
    Jornada Jornada;
    //se ingresa los datos y se guardan en variables
    cout << "Ingrese el codigo de la Jornada: ";
    cin >> Jornada.codigo;
    cin.ignore();

    cout << "Ingrese el nombre de la Jornada: ";
    cin.getline(Jornada.nombre, 50);

	//Se crea el objeto archivo para abrir el archivo en binario
	//si el archivo no esta existe, se crea uno nuevo
    ofstream archivo("Jornadas.DAT", ios::binary | ios::app);
    archivo.write(reinterpret_cast<const char*>(&Jornada), sizeof(Jornada));
    archivo.close();

    cout << "Jornada agregada exitosamente!" << endl;
}

//Funcion que nos permite modificar registros
void JornadaCRUD::Modificar() {
    int codigo;

    //ingresar el codigo del dato a modificar
    cout << "Ingrese el codigo de la Jornada a modificar: ";
    cin >> codigo;
//abrir el archivo en modo lectura y escribir en binario
    fstream archivo("Jornadas.DAT", ios::binary | ios::in | ios::out);
//verificar si el archivo se pudo abrir correctamente
    if (!archivo) {
        cout << "No hay Jornadas registradas." << endl;
        return;
    }

    Jornada Jornada;
    //variable booleana que se usara para indicar si se encontro el codigo que se ingreso
    bool encontrada = false;
    //lee de forma repetida cada registro del archivo hasta que no haya mas registros
    while (archivo.read(reinterpret_cast<char*>(&Jornada), sizeof(Jornada))) {
		//compara el codigo del archivo con el ingresado para determinar si se ha encontrado o no
        if (Jornada.codigo == codigo) {
            cout << "Ingrese el nuevo nombre de la Jornada: ";
            cin.ignore();
            cin.getline(Jornada.nombre, 50);

            archivo.seekp(-static_cast<int>(sizeof(Jornada)), ios::cur);
            //modifica el archivo, sobreescribiendo el registro original
            archivo.write(reinterpret_cast<const char*>(&Jornada), sizeof(Jornada));
			//establece como verdadera la variable, para indicar que se ha encontrado la jornada que se desea modificar
            encontrada = true;
            break;
        }
    }
//se cierra el archivo
    archivo.close();
    if (!encontrada) {
        cout << "No se encontró la Jornada con el codigo ingresado." << endl;
    } else {
        cout << "Jornada modificada exitosamente!" << endl;
    }

}
//Funcion para borrar los registros
void JornadaCRUD::Borrar() {
    int codigo;
    //se ingresa el codigo del registro a eliminar
    cout << "Ingrese el codigo de la Jornada a eliminar: ";
    cin >> codigo;
//abre el archivo en modo de lectura binario y lee los datos del archivo
    ifstream archivo("Jornadas.DAT", ios::binary);
   //verifica si el archivo se pudo abrir correctamente
    if (!archivo) {
        cout << "No hay Jornadas registradas." << endl;

    }
//abre un nuevo archivo temporal en modo de escritura binaria
//el archivo temporal se utilizara para escribir los datos del archivo original exepto los que se desea eliminar

    ofstream archivoTmp("Jornadas_tmp.DAT", ios::binary);
    Jornada Jornada;
    bool eliminada = false;
    while (archivo.read(reinterpret_cast<char*>(&Jornada), sizeof(Jornada))) {
        if (Jornada.codigo != codigo) {
            archivoTmp.write(reinterpret_cast<const char*>(&Jornada), sizeof(Jornada));
        } else {
            eliminada = true;
        }
    }

    archivo.close();
    archivoTmp.close();
//elimina el archivo original y renombra el archivo temporal
//esto reemplaza el archivo origial con el archivo nuevo que no contiene el registro eliminado
    remove("Jornadas.DAT");
    rename("Jornadas_tmp.DAT", "Jornadas.DAT");

    if (eliminada) {
        cout << "Jornada eliminada exitosamente!" << endl;

    } else {
        cout << "No se encontró la Jornada con el codigo ingresado." << endl;
    }

}

//Funcion para desplegar todos los registros
void JornadaCRUD::Desplegar() {
    system("cls");

//Despliegue modificado por Alisson López 9959-23-7225

    cout<<"-------DESPLIEGUE JORNADAS REGISTRADAS----"<<endl;
    cout<<"           Codigo       Nombre             "<<endl;
    cout<<"------------------------------------------"<<endl;
      //abre el archivo en modo lectura binaria y lee los datos del archivo
    ifstream archivo("Jornadas.DAT", ios::binary);
    if (!archivo) {
        cout << "No hay Jornadas registradas." << endl;
        return;
    }

    Jornada Jornada;
        //lee de forma repetida cada registro del archivo hasta que no haya mas registros

    while (archivo.read(reinterpret_cast<char*>(&Jornada), sizeof(Jornada))) {
			//Imprime los registros leidos del archivo

        cout  << setw(14)<< Jornada.codigo ;
        cout << setw(18)<< Jornada.nombre ;
        cout<<" "<<endl;
    }

    archivo.close();

    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}

