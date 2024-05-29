//Esqueleto proceso asignación realizado por Victor Gómez 9959-23-10733
#include "Asignacion_Maestro_curso.h"
#include "login_catedratico.h"
#include "aulas.h"
#include "secciones.h"
#include "Facultad.h"
#include "Carrera.h"
#include "Cursoss.h"
#include "jornada.h"
//#include "Horario.h"
//#include "Sedes.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;


void Asignacion_Maestro_curso::Menu_catedratico()
{

 //variables de user y contraseñan
    string user,contrasena;
    //llmamos al objeto e ingresamos los parametros
    login_catedratico ingreso(user,contrasena);


    //creamos un bool  que verifique y despliegue el metodo verificarUsuario
    bool UsuarioCorrecto=ingreso.VerificarUsuario();


    //luego de ingresar con usuario y contraseña se nos desplega otro menu
    if(UsuarioCorrecto)
    {
        int opcion;
        char  x;
        do
        {
        	system("cls");

    cout<<"\t\t\t+------------------------------------------+"<<endl;
    cout<<"\t\t\t|      BIENVENIDO AL MENU CATEDRATICO      |"<<endl;
    cout<<"\t\t\t+------------------------------------------+"<<endl;
	cout<<"\t\t\t|1. Asignacion De Cursos                   |"<<endl;
	cout<<"\t\t\t|2. Actas                                  |"<<endl;
	cout<<"\t\t\t|3. regresar al menu anterior              |"<<endl;
	cout<<"\t\t\t+------------------------------------------+"<<endl;
	cout<<"\t\t\t|Opcion a escoger:[1/2/3]              |"<<endl;
	cout<<"\t\t\t+------------------------------------------+"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>opcion;

    switch(opcion){
    case 1:

         {
          asignarse_curso();

            break;
        }


    case 2:

        break;
    case 3:

        break;

	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
        break;}
        }while(opcion!= 3);

    }

}
void Asignacion_Maestro_curso::asignarse_curso()
{
	system("cls");

//Proceso asignación maestro a curso realizado por Kathia Contreras 9959-23-8246

int num=1;
Asignacion Asigna;
cout<<"ingrese codigo maestro: ";
cin >> Asigna.codigo_maestro ;
cin.ignore();

cout <<"ingrese nombre catedratico: ";
cin.getline(Asigna.nombre_maestro,50);

cout <<"ingrese apellido catedratico: ";
cin.getline(Asigna.apellido_maestro,50);

system("cls");

//REVISAR QUE NOMBRE COLOCAN A CLASE Y ARCHIVO SEDE AL GRUPO ASIGNADO

/* **********   DESPLIEGUE SEDE.DAT   ********** */
    /*cout<<"---------------- Sedes existentes---------------------"<<endl;
    ifstream archivo7("sede.dat", ios::binary);
    // Verificar si el archivo se abrió correctamente
    if (!archivo7) {
        cout << "No hay aulas registradas." << endl;
        return;
    }
    Sedes sede1;
    // Recorrer el archivo y mostrar los datos de cada aula
    while (archivo7.read(reinterpret_cast<char*>(&sede1), sizeof(Sedes))) {

        cout << num<< ". " << sede1.nombre << endl;

        num++;
    }
    archivo7.close(); // Cerrar el archivo
    */

cout << "------------------------------------------------" << endl;
cout <<"ingrese la sede:";
cin.getline(Asigna.sede,50);


system("cls");

/* **********   DESPLIEGUE AULAS.DAT   ********** */

cout<<"-----------------Aulas Existentes---------------------"<<endl;
    // Abrir el archivo de aulas en modo lectura binaria
    ifstream archivo("aulas.dat", ios::binary);
    // Verificar si el archivo se abrió correctamente
    if (!archivo) {
        cout << "No hay aulas registradas." << endl;
        return;
    }

    // Declarar una variable para el aula
    aulas aula1;
    // Recorrer el archivo y mostrar los datos de cada aula
    while (archivo.read(reinterpret_cast<char*>(&aula1), sizeof(aulas))) {

        cout << num<< ". " << aula1.nombre << endl;

        num++;
    }

    archivo.close(); // Cerrar el archivo

cout << "------------------------------------------------" << endl;
cout <<"ingrese el aula:";
cin.getline(Asigna.aula,50);

system("cls");

/* **********   DESPLIEGUE SECCION.DAT   ********** */
    cout<<"-----------------Secciones Existentes---------------------"<<endl;
    // Abre el archivo 'seccion.dat' en modo binario para lectura
    ifstream archivo1("seccion.dat", ios::binary);
    // Si el archivo no se pudo abrir, imprime un mensaje de error y termina la funci�n
    if (!archivo1) {
        cout << "No hay seccion registradas." << endl;
        return;
    }
    secciones seccion1;
    // Mientras se pueda leer un objeto 'seccion1' del archivo...
    num=1;
    while (archivo1.read(reinterpret_cast<char*>(&seccion1), sizeof(secciones))) {
        // Imprime los datos de la seccion1 en la consola
        cout << num <<". " << seccion1.nombre << endl;
        num++;
    }
    archivo1.close();

cout << "------------------------------------------------" << endl;

cout <<"ingrese la seccion: ";
cin.getline(Asigna.seccion,50);


system("cls");
/* **********   DESPLIEGUE FACULTAD.DAT   ********** */
    num=1;
    cout << "-----------------Facultades Existentes---------------------" << endl;
    ifstream archivo2("facultad.dat", ios::binary);
    if (!archivo2) {
        cout << "No hay facultades registradas." << endl;
        return;
    }

    Facultad facultad1;
    while (archivo2.read(reinterpret_cast<char*>(&facultad1), sizeof(Facultad))) {

        cout << num <<". "<<"Nombre: " << facultad1.nombre << endl;
        num++;
    }

    archivo2.close();
cout << "------------------------------------------------" << endl;
    cout <<"ingrese la facultad: ";
    cin.getline(Asigna.facultad,50);


system("cls");
/* **********   DESPLIEGUE CARRERA.DAT   ********** */

    cout<<"-----------------Carreras Existentes---------------------"<<endl;
    ifstream archivo3("carreras.dat", ios::binary);
    if (!archivo3) {
        cout << "No hay carreras registradas." << endl;
        return;
    }
    Carrera carrera1;
    num=1;
    while (archivo3.read(reinterpret_cast<char*>(&carrera1), sizeof(Carrera))) {
        cout << num <<". " << carrera1.nombre << endl;
        num++;
    }
    archivo3.close();
cout << "------------------------------------------------" << endl;

    cout <<"ingrese la carrera: ";
    cin.getline(Asigna.carrera,50);


system("cls");
/* **********   DESPLIEGUE CURSO.DAT   ********** */
    cout<<"-----------------Cursos Existentes---------------------"<<endl;
   //abre el archivo en modo lectura binaria y lee los datos del archivo
    ifstream archivo4("Cursoss.DAT", ios::binary);
    if (!archivo4) {
        cout << "No hay Cursoss registradas." << endl;
        return;
    }
    Curso Curso1;
    num=1;
    //lee de forma repetida cada registro del archivo hasta que no haya mas registros
    while (archivo4.read(reinterpret_cast<char*>(&Curso1), sizeof(Curso))) {
		//Imprime los registros leidos del archivo
        cout << num <<". " << Curso1.nombre << endl;
        num++;
    }

    archivo4.close();

cout << "------------------------------------------------" << endl;

    cout <<"ingrese el curso: ";
    cin.getline(Asigna.curso,50);



system("cls");
/* **********   DESPLIEGUE JORNADAS.DAT   ********** */

    cout<<"-----------------Jornadas Existentes---------------------"<<endl;
      //abre el archivo en modo lectura binaria y lee los datos del archivo
    ifstream archivo5("Jornadas.DAT", ios::binary);
    if (!archivo5) {
        cout << "No hay Jornadas registradas." << endl;
        return;
    }
    Jornada Jornada1;
    num=1;
        //lee de forma repetida cada registro del archivo hasta que no haya mas registros

    while (archivo5.read(reinterpret_cast<char*>(&Jornada1), sizeof(Jornada))) {
			//Imprime los registros leidos del archivo
        cout << num <<". " << Jornada1.nombre << endl;
        num++;
    }
    archivo5.close();
cout << "------------------------------------------------" << endl;

    cout <<"ingrese la jornada: ";
    cin.getline(Asigna.jornada,50);


system("cls");
/* **********   DESPLIEGUE HORARIO.DAT   ********** */
   /* cout<<"-----------------Horarios Existentes---------------------"<<endl;
      //abre el archivo en modo lectura binaria y lee los datos del archivo
    ifstream archivo6("Horarios.DAT", ios::binary);
    if (!archivo6) {
        cout << "No hay Jornadas registradas." << endl;
        return;
    }

    Horario horario1;
    num=1;
        //lee de forma repetida cada registro del archivo hasta que no haya mas registros

    while (archivo6.read(reinterpret_cast<char*>(&horario1), sizeof(Horario))) {
			//Imprime los registros leidos del archivo
        cout << num <<". " << horario1.nombre << endl;
        num++;
    }
    archivo6.close();
*/
cout << "------------------------------------------------" << endl;

    cout <<"ingrese el horario;";
    cin.getline(Asigna.horario,50);



system("cls");
cout << "------------------------------------------------" << endl;

    ofstream archivo8("asignaciones.dat", ios::binary | ios::app);
    archivo8.write(reinterpret_cast<const char*>(&Asigna), sizeof(Asignacion));
    archivo8.close();
    cout << "Asignacion ingresada exitosamente!" << endl;
    cout << "------------------------------------------------" << endl;

system("pause");


}
void Asignacion_Maestro_curso::actas()
{
    //ACTAS HECHO POR KATHIA CONTRERAS 9959-23-8246
    system("cls");
    cout<<"--------------------------------------------------------------------ASIGNACIONES MAESTRO A CURSO-----------------------------------------------------------------------"<<endl;
    cout<<" Codigo      Nombre        Apellido         Sede           Aula      Seccion     Facultad              Carrera               Curso              Jornada        Horario"<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;

    // Abrir el archivo de aulas en modo lectura binaria
    ifstream archivo("asignaciones.dat", ios::binary);
    // Verificar si el archivo se abrió correctamente
    if (!archivo) {
        cout << "No hay asignaciones registradas." << endl;
        return;
    }

    // Declarar una variable para el aula
    Asignacion asign1;
    // Recorrer el archivo y mostrar los datos de cada aula
    while (archivo.read(reinterpret_cast<char*>(&asign1), sizeof(Asignacion))) {
        cout<<"|";
        cout << setw(5)<< asign1.codigo_maestro ;
        cout<<" |";
        cout << setw(12)<< asign1.nombre_maestro ;
        cout<<" |";
        cout  << setw(12)<< asign1.apellido_maestro ;
        cout<<" |";
        cout << setw(15)<< asign1.sede ;
        cout<<" |";
        cout << setw(10)<< asign1.aula;
        cout<<" |";
        cout << setw(10) << asign1.seccion;
        cout<<" |";
        cout << setw(15) << asign1.facultad ;
        cout<<"|";
        cout  << setw(25)<< asign1.carrera ;
        cout<<"|";
        cout << setw(18)<<  asign1.curso ;
        cout<<" |";
        cout << setw(15)<<   asign1.jornada;
        cout<<" |";
        cout << setw(10)<<   asign1.horario;
        cout<<" |"<<endl;
        cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    }

    archivo.close();
    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();

}

Asignacion_Maestro_curso:: Asignacion_Maestro_curso()
{

}
