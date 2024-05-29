//Elaborado por: Alisson Rocio Lopez Ortiz 9959 - 23 - 7225

#include "Cursoss.h"
#include <fstream>
#include <iostream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

//Implementación de Bitácora hechar por: Pablo Romeo Palencia Rosales 9959-23-736
#include "Bitacora.h"

using namespace std;

void CursosCRUD::CrudCursos() {
int choice;
//implementacion de variables para la bitacora
string codigoPrograma="4000";
Bitacora Auditoria;
string user="admin";

    do {
	//limpiar pantalla
	system("cls");
	//menu de opciones
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t|   SISTEMA DE GESTION UMG - Cursos      |"<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingresar Cursos"<<endl;
	cout<<"\t\t\t 2. Modificar Cursos"<<endl;
	cout<<"\t\t\t 3. Borrar Cursos"<<endl;
	cout<<"\t\t\t 4. Desplegar Cursos"<<endl;
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
        //Se ejecuta la accion y se registra en la bitacora
        Auditoria.ingresoBitacora(user,codigoPrograma,"CCU"); //CCU = Create Cursos
         system("pause");
		break;
    case 2:
        ModificarCa();
         //Se ejecuta la accion y se registra en la bitacora
        Auditoria.ingresoBitacora(user,codigoPrograma,"UCU"); //UCU = Update Cursos
         system("pause");
		break;
    case 3:
        BorrarCa();
        //Se ejecuta la accion y se registra en la bitacora
        Auditoria.ingresoBitacora(user,codigoPrograma,"DCU"); //DCU = Delete Cursos
         system("pause");
		break;
    case 4:
        DesplegarCa();
        //Se ejecuta la accion y se registra en la bitacora
        Auditoria.ingresoBitacora(user,codigoPrograma,"RCU"); //RCU = Read Cursos
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

void CursosCRUD::IngresarCa() {

   system("cls");
    cout<<"\n------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n-------------------------------------------------Agregar Cursos--------------------------------------------"<<endl;
    Curso Curso;

        //se ingresa los datos y se guardan en variables

    cout << "Ingrese el codigo de la Cursos: ";
    cin >> Curso.codigo;
    cin.ignore();

    cout << "Ingrese el nombre del Cursos: ";
    cin.getline(Curso.nombre, 50);

    cout << "Ingrese los Creditos del Curso: ";
    cin.getline(Curso.Creditos, 50);

    cout <<"Ingrese los Prerequisitos del Curso: ";
    cin.getline (Curso.requisitos,50);
	//Se crea el objeto archivo para abrir el archivo en binario
	//si el archivo no esta existe, se crea uno nuevo


    ofstream archivo("Cursoss.DAT", ios::binary | ios::app);
    archivo.write(reinterpret_cast<const char*>(&Curso), sizeof(Curso));
    archivo.close();

    cout << "Cursos agregada exitosamente!" << endl;
}
//Funcion que nos permite modificar registros

void CursosCRUD::ModificarCa() {
    int codigo;
    //ingresar el codigo del dato a modificar
    cout << "Ingrese el codigo del curso a modificar: ";
    cin >> codigo;
//abrir el archivo en modo lectura y escribir en binario

    fstream archivo("Cursoss.DAT", ios::binary | ios::in | ios::out);
    //verificar si el archivo se pudo abrir correctamente
    if (!archivo) {
        cout << "No hay Cursoss registradas." << endl;
        return;
    }

    Curso Curso;
    //variable booleana que se usara para indicar si se encontro el codigo que se ingreso
    bool encontrada = false;
    //lee de forma repetida cada registro del archivo hasta que no haya mas registros
    while (archivo.read(reinterpret_cast<char*>(&Curso), sizeof(Curso))) {
        //compara el codigo del archivo con el ingresado para determinar si se ha encontrado o no
        if (Curso.codigo == codigo) {
            cout << "Ingrese el nuevo nombre del Cursos: ";
            cin.ignore();
            cin.getline(Curso.nombre, 50);

            cout << "Ingrese los nuevos creditos del Cursos: ";
            cin.getline(Curso.Creditos, 50);

            cout <<"Ingrese los nuevos Prerequisitos del Curso";
            cin.getline(Curso.requisitos, 50);

            archivo.seekp(-static_cast<int>(sizeof(Curso)), ios::cur);
            //modifica el archivo, sobreescribiendo el registro original
            archivo.write(reinterpret_cast<const char*>(&Curso), sizeof(Curso));
			//establece como verdadera la variable, para indicar que se ha encontrado la jornada que se desea modificar
            encontrada = true;
            break;
        }
    }
//se cierra el archivo
    archivo.close();

    if (!encontrada) {
        cout << "No se encontró la Cursos con el codigo ingresado." << endl;
    } else {
        cout << "Cursos modificada exitosamente!" << endl;
    }

}
//funcion para borrar los resgistros
void CursosCRUD::BorrarCa() {
    int codigo;
    //se ingresa el codigo del registro a eliminar
    cout << "Ingrese el codigo de la Cursos a eliminar: ";
    cin >> codigo;
    //abre el archivo en modo de lectura binario y lee los datos del archivo

    ifstream archivo("Cursoss.DAT", ios::binary);
    //verifica si el archivo se pudo abrir correctamente
    if (!archivo) {
        cout << "No hay Cursoss registradas." << endl;

    }
//abre un nuevo archivo temporal en modo de escritura binaria
//el archivo temporal se utilizara para escribir los datos del archivo original exepto los que se desea eliminar
    ofstream archivoTmp("Cursoss_tmp.DAT", ios::binary);
    Curso Curso;
    bool eliminada = false;
    while (archivo.read(reinterpret_cast<char*>(&Curso), sizeof(Curso))) {
        if (Curso.codigo != codigo) {
            archivoTmp.write(reinterpret_cast<const char*>(&Curso), sizeof(Curso));
        } else {
            eliminada = true;
        }
    }

    archivo.close();
    archivoTmp.close();
//elimina el archivo original y renombra el archivo temporal
//esto reemplaza el archivo origial con el archivo nuevo que no contiene el registro eliminado
    remove("Cursoss.DAT");
    rename("Cursoss_tmp.DAT", "Cursoss.DAT");

    if (eliminada) {
        cout << "Cursos eliminada exitosamente!" << endl;

    } else {
        cout << "No se encontró la Cursos con el codigo ingresado." << endl;
    }

}
//Funcion para desplegar todos los registros

void CursosCRUD::DesplegarCa() {
    system("cls");

    cout<<"------------------------DESPLIEGUE DE CURSOS---------------------"<<endl;
    cout<<" Codigo      Nombre del Curso        Creditos         Requisitos "<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;


   //abre el archivo en modo lectura binaria y lee los datos del archivo
    ifstream archivo("Cursoss.DAT", ios::binary);
    if (!archivo) {
        cout << "No hay Cursoss registradas." << endl;
        return;
    }

    Curso Curso;
    //lee de forma repetida cada registro del archivo hasta que no haya mas registros
    while (archivo.read(reinterpret_cast<char*>(&Curso), sizeof(Curso))) {
		//Imprime los registros leidos del archivo

		cout << setw(5)<< Curso.codigo;
        cout << setw(20)<< Curso.nombre;
        cout  << setw(16)<< Curso.Creditos ;
        cout << setw(20)<< Curso.requisitos ;
        cout<<" "<<endl;
    }

    archivo.close();

    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}
