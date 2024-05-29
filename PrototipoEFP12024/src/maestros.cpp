
//creado por Victor Samayoa 9959-23-3424

//Incluyendo las librerias a utilizar
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<string>

//incluyendo el encabezado maestros
#include "maestros.h"
#include "Bitacora.h"
using namespace std;
//Constructor maestros y sus parametros

maestros::maestros(string id, string nombre, string telefono, string DPI, string direccion, string Genero, string nacionalidad, string civil, string fechanaci, string anoingre)
{
    // Asignando los valores de los parámetros a los atributos del objeto
    this->id = id;
    this->nombre = nombre;
    this->telefono = telefono;
    this->DPI = DPI;
    this->direccion = direccion;
    this->Genero = Genero;
    this->nacionalidad = nacionalidad;
    this->civil = civil;
    this->fechanaci = fechanaci;
    this->anoingre = anoingre;
}

//Estableciendo la id del maestro
string maestros::setid(string id)
{
    this->id = id;
    return id;
}

//Obteniendo la id del maestro
string maestros::getid()
{
    return id;
}


//Estableciendo el nombre del maestro
string maestros::setnombre(string nombre)
{
    this->nombre = nombre;
    return nombre;
}

//Obteniendo el nombre del maestro
string maestros::getnombre()
{
    return nombre;
}

//Estableciendo el telefono del maestro
string maestros::setTelefono(string telefono)
{
    this->telefono = telefono;
    return telefono;
}

//Obteniendo el telefono del maestro
string maestros::getTelefono()
{
    return telefono;
}

//Estableciento el DPI del maestro
string maestros::setDPI(string DPI)
{
    this->DPI = DPI;
    return DPI;
}

//Obteniendo el DPI del maestro
string maestros::getDPI()
{
    return DPI;
}

//Estableciendo la direccion del maestro
string maestros::setdireccion(string direccion)
{
    this->direccion = direccion;
    return direccion;
}


//Estableciendo la direccion del maestro
string maestros::getdireccion()
{
    return direccion;
}


//Obteniendo la direccion del maestro
string maestros::setGenero(string Genero)
{
    this->Genero = Genero;
    return Genero;
}

//Obteniendo el genero del maestro
string maestros::getGenero()
{
    return Genero;
}

//Estableciendo la nacionalidad del maestro
string maestros::setnacionalidad(string nacionalidad)
{
    this->nacionalidad = nacionalidad;
    return nacionalidad;
}

//Obteniendo la nacionalidad del maestro
string maestros::getnacionalidad()
{
    return nacionalidad;
}

//Estableciendo el estado civil del maestro
string maestros::setcivil(string civil)
{
    this->civil = civil;
    return civil;
}

//Obteniendo el estado civil del maestro
string maestros::getcivil()
{
    return civil;
}

//Estableciendo la fecha de nacimiento del maestro
string maestros::setfechanaci(string fechanaci)
{
    this->fechanaci = fechanaci;
    return fechanaci;
}

//Obteniendo la fecha de nacimiento del maestro
string maestros::getfechanaci()
{
    return fechanaci;
}


//Estableciendo el año de ingreso del alumno
string maestros::setanoingre(string anoingre)
{
    this->anoingre = anoingre;
    return anoingre;
}

//Obteniendo el año de ingreso del alumno
string maestros::getanoingre()
{
    return anoingre;
}

//Funcion menu donde muestra el sistema de gestion de alumnos
void maestros::menu()
{
//Implementando la bitacora
string codigoPrograma="2533";

Bitacora Auditoria;
//Declarando variable string con el codigo programa
string user, contrasena;
            Auditoria.ingresoBitacora(user,codigoPrograma,"MST");

    //Definiendo Variable int
    int opcion;
    //Definiendo Variable char
	char continuar;
	do
    {
        //Limpiando pantalla
		system("cls");

		//Se muestra el diseño del sistema de gestion de maestros
		cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|  BIENVENIDO AL SISTEMA DE GESTION DE MAESTROS |"<<endl;
		cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|            1. Agregar Maestro                 |"<<endl;
		cout<<"|            2. Mostrar Maestro                 |"<<endl;
		cout<<"|            3. Modificar Maestro               |"<<endl;
		cout<<"|            4. Borrar Maestro                  |"<<endl;
		cout<<"|            5. Salir del programa              |"<<endl;
		cout<<"|            6. Regresar al menu                |"<<endl;
		cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|        Ingrese su opcion [1/2/3/4/5/6]        |"<<endl;
		cout<<"+-----------------------------------------------+"<<endl;
		cin>>opcion;

        // Inicializando el generador de números aleatorios
		srand(getpid());

		//declarando variable int con su valor 24
        int year = 24;
        //declarando variable int con su funcion para generar numeros aleatorios
        int numAleatorio = rand() % 10000;

        //Permitiendo que el usuario eliga una opcion
		switch(opcion)
		{
            //Opcion 1
			case 1:
				do
				{
				    //Funcion para insertar un maestro
					insertar();

                    //Luego de ingresar un maestro mostrara el mensaje
					cout<<" -> ¿Deseas ingresar a otro Maestros? (S/N): ";
					cin>>continuar;

                //Si la respuesta es s o S, insertara otro estudiante
				}while(continuar=='S' || continuar=='s');
				break;


            //Opcion 2
			case 2:
                //Funcion para poder desplegar los alumnos registrados
				desplegar();
				break;

            //Opcion 3
			case 3:
			    //Funcion para modificar un alumno registrado
                modificar();
                break;

            //Opcion 4
			case 4:
			    //Funcion para borrar un alumno registrado
                borrar();
                break;

            //Opcion 5
			case 5:
            //Funcion para salir del sistema
				exit(0);
				break;

            //Si no elige una de las 5 opciones, mostrara el siguiente mensaje
            case 6:
				break;
			default:
				cout<<"ERROR, OPCION NO VALIDA, INTENTELO DE NUEVO PORFAVOR";
		}
		getch();
    //Indica que si el usuario elige 6 finaliza el ciclo
    }while(opcion != 6);
}

//Funcion para insertar un maestro
void maestros::insertar()
{
string codigoPrograma="2534";
Bitacora Auditoria;
string user, contrasena;
Auditoria.ingresoBitacora(user,codigoPrograma,"MSTI");
    //Limpiando pantalla
    system("cls");

    //Encabezado del diseño insertar estudiante
    cout<<"+---------------------------------------------------------+"<< endl;
    cout<<"|                Agregar detalles del Maestro          |"<< endl;
    cout<<"+---------------------------------------------------------+"<< endl;

    //Encabezado del diseño insertar estudiante
    srand(time(NULL));

    //Constructor
    Maestro maestro;

    //Estableciendo variable int dando valor de "24"
    int year = 24;
    //Generando un numero aleatorio
    int numAleatorio = (rand() % 9998) + 1;

    //Agregando un id aleatorio para cada alumno
    string idString = "9959-" + to_string(year) + "-" + to_string(numAleatorio);

    for (int i = 0; i < idString.length(); ++i) {
        maestro.id[i] = idString[i];
    }
    maestro.id[idString.length()] = '\0';

    //Mensaje generando codigo
    cout<<"       -> Generando codigo del maestro: " << maestro.id<<endl;
    cin.ignore();

    //Mensaje para ingresar el nombre del maestro
    cout<<"       -> Ingrese el nombre del maestro:  ";
    cin.getline(maestro.nombre, 50);

    //Mensaje para ingresar el email del maestro
    cout<<"       -> Ingrese el email del maestro: ";
    cin.getline(maestro.DPI, 20);

    //Mensaje para ingresar la estatus del maestro
    cout<<"       -> Ingrese la estatus del maestro: ";
    cin.getline(maestro.nacionalidad, 100);

    //Mensaje para ingresar la direccion del maestro
    cout<<"       -> Ingrese la direccion del maestro: ";
    cin.getline(maestro.direccion, 50);

    //Mensaje para ingresar el telefono del maestro
    cout<<"       -> Ingrese el telefono del maestro: ";
    cin.getline(maestro.telefono, 15);

    cout<<"+---------------------------------------------------------+"<< endl;

    //Escribiendo los datos del obteto alumno en un archivo binario llamado en modo de escritura binaria, agregando los datos al final del archivo si ya existe.
    ofstream archivo("Maestros.dat", ios::binary | ios::app);
    archivo.write(reinterpret_cast<const char*>(&maestro), sizeof(maestro));
    archivo.close();

}
//Funcion para desplegar los alumnos ya registrados
void maestros::desplegar()
{
    string codigoPrograma="2612";
 Bitacora Auditoria;
string user, contrasena;
            Auditoria.ingresoBitacora(user,codigoPrograma,"MSTD");
    //Limpiando pantalla
	system("cls");

    //Mostrando el encabezado de la tabla de detalles del estudiante
    cout << "+---------------------------------------------------------------------------------+" << endl;
    cout << "+                            Tabla de Detalles del Estudiante                     +" << endl;
    cout << "+---------------------------------------------------------------------------------+" << endl;

    //Mostrando el encabezado de la tabla de detalles del estudiante
    ifstream archivo("Maestros.dat", ios::binary | ios::app);
    if (!archivo) {
            //Si no encuentra informacion muestra el siguiente mensaje
        cout << "Error, no se encuentra informacion...";
        return;
    }
    Maestro maestro;

    //Ciclo while para leer los datos del archivo binario  y los almacenan en un objeto alumno llamado alumno y repite este procedimiento hasta que se acaben los datos por leer
    while (archivo.read(reinterpret_cast<char*>(&maestro), sizeof(Maestro))) {
        //Se muestra los detalles del estudiante
        cout << "                        Mostrando -> Codigo del Maestro: " << maestro.id << endl;
        cout << "                        Mostrando -> Nombre del Maestro: " << maestro.nombre << endl;
        cout << "                        Mostrando -> Email del maestro : " << maestro.DPI << endl;
        cout << "                        Mostrando -> Estatus del maestro: " << maestro.nacionalidad << endl;
        cout << "                        Mostrando -> Direccion: " << maestro.direccion << endl;
        cout << "                        Mostrando -> Telefono: " << maestro.telefono << endl;
        cout << "+---------------------------------------------------------------------------------+" << endl;
    }
    archivo.close(); //cierra el archivo

    //Mensaje al usuario
    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}

//Funcion para modificar los maestros ya registrados
void maestros::modificar()
{
    string codigoPrograma="2789";
 Bitacora Auditoria;
string user, contrasena;
            Auditoria.ingresoBitacora(user,codigoPrograma,"MSTM");
    //Limpiando pantalla
	system("cls");
	//Declarando variables tipo fstream y string
    fstream archivo;
    string idPersona;
    //Variable bool con valor false
    bool encontrado = false;


    cout << "+---------------------------------------------------------------------------------+" << endl;
    cout << "+                       Modificar Detalles del maestros                           +" << endl;
    cout << "+---------------------------------------------------------------------------------+" << endl;

    //abre un archivo binario en modo de lectura y escritura
    archivo.open("Maestros.dat", ios::binary | ios::in | ios::out);

    //verificacion si se abre el archivo
    if (!archivo) {
        //si no se pudo muestra el siguiente mensaje

        cout << "Error, no se encuentra informacion...";
        return;
    }
    //si se pudo abrir correctament pide la id de la persona
    cout << "Ingrese el ID de la persona que desea modificar: ";
    cin >> idPersona;

    Maestro maestro;
    // Lee cada registro del archivo y busca el ID proporcionado por el usuario

    while (archivo.read(reinterpret_cast<char*>(&maestro), sizeof(Maestro))) {

        // Establece el indicador como verdadero si se encuentra el estudiante
        if (maestro.id == idPersona) {

            // Establece el indicador como verdadero si se encuentra el estudiante
            encontrado = true;

            //Muestra mensajes para poder ingresar los detalles para poder modificar del alumnno
            cout << "Ingrese el nuevo codigo del Maestro: ";
            cin >> maestro.id;
            cout << "Ingrese el nuevo nombre del Maestro: ";
            cin >> maestro.nombre;
            cout << "Ingrese el nuevo email del Maestro: ";
            cin >> maestro.DPI;
            cout << "Ingrese el nuevo estatus del Maestro: ";
            cin >> maestro.nacionalidad;
            cout << "Ingrese la nueva direccion del Maestro: ";
            cin >> maestro.direccion;
            cout << "Ingrese el nuevo Telefono del Maestro: ";
            cin >> maestro.telefono;

            //Muestra mensajes para poder ingresar los detalles para poder modificar del alumnno
            archivo.seekp(-static_cast<int>(sizeof(Maestro)), ios::cur);

            // Escribe  nuevos detalles del estudiante en el archivo
            archivo.write(reinterpret_cast<char*>(&maestro), sizeof(Maestro));
            break;
        }
    }

    archivo.close();  // Cierra el archivo

    //si no lo encuentra mostrara el siguiente mensaje
    if (!encontrado) {
        cout << "No se encontró un maestro con el ID proporcionado." << endl;
    }

    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}

//funcion para borrarr a las maestros registradas
void maestros::borrar()
{
    string codigoPrograma="2802";
 Bitacora Auditoria;
string user, contrasena;
            Auditoria.ingresoBitacora(user,codigoPrograma,"MSTB");
    //Limpia pantalla
    system("cls");

	//declara una variable string
    string idPersona;

    //Muestra el encabezado de la tabla para eliminar un estudiante
    cout<<"+---------------------------------------------------------------------------------+"<<endl;
    cout<<"+                             Eliminar Maestros                                   +"<<endl;
    cout<<"+---------------------------------------------------------------------------------+"<<endl;

    // Abre el archivo binario alumnos.dat en modo de lectura
    ifstream archivo("Maestros.dat", ios::binary);

    //verifica si se abrio el archivo
    if(!archivo)
    {
        //verifica si se abrio el archivo
        cout<<"Error, no se encuentra informacion...";
        return;
    }
    // Crea un nuevo archivo binario en modo de escritura
    ofstream archivo2("Maestros2.dat", ios::binary);
    Maestro maestro;

    //Muestra el mensaje para poder borrar el alumno
    cout<<"-> Ingrese el ID de la persona que desea eliminar: ";
    cin>>idPersona;

    // Crea un nuevo archivo binario en modo de escritura
    bool resta = false;

        // Lee cada registro del archivo y busca el usuario proporcionado por el usuario
        while(archivo.read(reinterpret_cast<char*>(&maestro), sizeof(Maestro)))
        {
            // Lee cada registro del archivo y busca el usuario proporcionado por el usuario
            if(maestro.id != idPersona)
            {
                archivo2.write(reinterpret_cast<const char*>(&maestro), sizeof(Maestro));
            }
            else
            {
                resta = true;
            }

        }
        //cierra ambos archivos
        archivo.close();
        archivo2.close();

        //remueve Maestros.dat
        remove("Maestros.dat");

        //y renombra el Maestros.dat a Maestros.dat
        rename("Maestros2.dat","Maestros.dat");

        if (resta)
        {
        //Si se encuentra el alumno muestra el mensaje
        cout << "Maestro eliminado con exito." << endl;
        }
        else
        {
        //Si no se encuentra el alumno muestra el mensaje
        cout << "No se a podido encontrar el codigo del Maestro" << endl;
        }
}
