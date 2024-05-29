
//creado por Oscar Morales 9959-23-3070

//Incluyendo las librerias a utilizar
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<string>

//incluyendo el encabezado alumnos
#include "alumnos.h"
//Incluyendo el encabezado de bitacora
#include "Bitacora.h"

using namespace std;


//Constructor alumnos y sus parametros
alumnos::alumnos(string id, string nombre, string telefono, string DPI, string direccion, string Genero, string nacionalidad, string civil, string fechanaci, string anoingre)
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

//Estableciendo la id del alumno
string alumnos::setid(string id)
{
    this->id = id;
    return id;
}

//Obteniendo la id del alumno
string alumnos::getid()
{
    return id;
}

//Estableciendo el nombre del alumno
string alumnos::setnombre(string nombre)
{
    this->nombre = nombre;
    return nombre;
}

//Obteniendo el nombre del alumno
string alumnos::getnombre()
{
    return nombre;
}

//Estableciendo el telefono del alumno
string alumnos::setTelefono(string telefono)
{
    this->telefono = telefono;
    return telefono;
}

//Obteniendo el telefono del alumno
string alumnos::getTelefono()
{
    return telefono;
}

//Estableciento el DPI del alumno
string alumnos::setDPI(string DPI)
{
    this->DPI = DPI;
    return DPI;
}

//Obteniendo el DPI del alumno
string alumnos::getDPI()
{
    return DPI;
}

//Estableciendo la direccion del alumno
string alumnos::setdireccion(string direccion)
{
    this->direccion = direccion;
    return direccion;
}


//Obteniendo la direccion del alumno
string alumnos::getdireccion()
{
    return direccion;
}

//Estableciendo el genero del alumno
string alumnos::setGenero(string Genero)
{
    this->Genero = Genero;
    return Genero;
}

//Obteniendo el genero del alumno
string alumnos::getGenero()
{
    return Genero;
}


//Estableciendo la nacionalidad del alumno
string alumnos::setnacionalidad(string nacionalidad)
{
    this->nacionalidad = nacionalidad;
    return nacionalidad;
}

//Obteniendo la nacionalidad del alumno
string alumnos::getnacionalidad()
{
    return nacionalidad;
}

//Estableciendo el estado civil del alumno
string alumnos::setcivil(string civil)
{
    this->civil = civil;
    return civil;
}

//Obteniendo  el estado civil del alumno
string alumnos::getcivil()
{
    return civil;
}

//Estableciendo la fecha de nacimiento del alumno
string alumnos::setfechanaci(string fechanaci)
{
    this->fechanaci = fechanaci;
    return fechanaci;
}

//Obteniendo la fecha de nacimiento del alumno
string alumnos::getfechanaci()
{
    return fechanaci;
}

//Estableciendo el año de ingreso del alumno
string alumnos::setanoingre(string anoingre)
{
    this->anoingre = anoingre;
    return anoingre;
}

//Obteniendo el año de ingreso del alumno
string alumnos::getanoingre()
{
    return anoingre;
}

//Funcion menu donde muestra el sistema de gestion de alumnos
void alumnos::menu()
{

//Implementando la bitacora
//Declarando variable string con el codigo programa
string codigoPrograma="2322";
Bitacora Auditoria;
//Declarando 2 variables string con el codigo programa
string user, contrasena;
Auditoria.ingresoBitacora(user,codigoPrograma,"ALM");


    //Definiendo Variable int
    int opcion;
    //Definiendo Variable char
	char continuar;

	do
    {
        //Limpiando pantalla
		system("cls");

		//Se muestra el diseño del sistema de gestion de alumnos
		cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|  BIENVENIDO AL SISTEMA DE GESTION DE ALUMNOS  |"<<endl;
		cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|            1. Agregar Estudiante              |"<<endl;
		cout<<"|            2. Mostrar Estudiante              |"<<endl;
		cout<<"|            3. Modificar Estudiante            |"<<endl;
		cout<<"|            4. Borrar Estudiante               |"<<endl;
		cout<<"|            5. Salir del programa              |"<<endl;
		cout<<"|            6. Regresar al menu                |"<<endl;
		cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|        Ingrese su opcion [1/2/3/4/5/6]        |"<<endl;
		cout<<"+-----------------------------------------------+"<<endl;
		cin>>opcion;

        //Permitiendo que el usuario eliga una opcion
		switch(opcion)
		{
		    //Opcion 1
			case 1:
				do
				{
				    //Funcion para insertar un alumno
					insertar();
					//Luego de ingresar un alumno mostrara el mensaje
					cout<<" -> ¿Deseas ingresar a otro estudiante? (S/N): ";
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
            case 6:
				break;
				//Si no elige una de las 5 opciones, mostrara el siguiente mensaje
			default:
				cout<<"ERROR, OPCION NO VALIDA, INTENTELO DE NUEVO PORFAVOR";
		}
		getch();
    //Indica que si el usuario elige 6 finaliza el ciclo
    }while(opcion != 6);
}

//Funcion para insertar un estudiando
void alumnos::insertar()
{

//Implementando la bitacora
//Declarando variable string con el codigo programa
string codigoPrograma="2350";
Bitacora Auditoria;
//Declarando 2 variables string con el codigo programa
string user, contrasena;
Auditoria.ingresoBitacora(user,codigoPrograma,"ALMI");


    //Limpiando pantalla
    system("cls");

    //Encabezado del diseño insertar estudiante
    cout<<"+---------------------------------------------------------+"<< endl;
    cout<<"|                Agregar detalles del Estudiante          |"<< endl;
    cout<<"+---------------------------------------------------------+"<< endl;

    //Inicializando un generador de numeros aleatorios
    srand(time(NULL));

    //Constructor
    Alumno alumno;

    //Estableciendo variable int dando valor de "24"
    int year = 24;
    //Generando un numero aleatorio
    int numAleatorio = (rand() % 9998) + 1;

    //Agregando un id aleatorio para cada alumno
    string idString = "9959-" + to_string(year) + "-" + to_string(numAleatorio);

    for (int i = 0; i < idString.length(); ++i) {
        alumno.id[i] = idString[i];
    }
    alumno.id[idString.length()] = '\0';

    //Mensaje generando carnet
    cout<<"       -> Generando carnet del estudiante: " << alumno.id<<endl;
    cin.ignore();

    //Mensaje para ingresar el nombre del alumno
    cout<<"       -> Ingrese el nombre del estudiante:  ";
    cin.getline(alumno.nombre, 50);

    //Mensaje para ingresar el DPI del alumno
    cout<<"       -> Ingrese el email del estudiante: ";
    cin.getline(alumno.DPI, 40);


    //Mensaje para ingresar la nacionalidad del alumno
    cout<<"       -> Ingrese la estatus del estudiante: ";
    cin.getline(alumno.nacionalidad, 100);


    //Mensaje para ingresar la direccion del alumno
    cout<<"       -> Ingrese la direccion del estudiante: ";
    cin.getline(alumno.direccion, 50);


    //Mensaje para ingresar el telefono del alumno
    cout<<"       -> Ingrese el telefono del estudiante: ";
    cin.getline(alumno.telefono, 15);

    cout<<"+---------------------------------------------------------+"<< endl;

    //Escribiendo los datos del obteto alumno en un archivo binario llamado en modo de escritura binaria, agregando los datos al final del archivo si ya existe.
    ofstream archivo("Alumnos.dat", ios::binary | ios::app);
    archivo.write(reinterpret_cast<const char*>(&alumno), sizeof(alumno));
    archivo.close();
}

//Funcion para desplegar los alumnos ya registrados
void alumnos::desplegar()
{
string codigoPrograma="2370";
Bitacora Auditoria;
string user, contrasena;
Auditoria.ingresoBitacora(user,codigoPrograma,"ALMD");

    //Limpiando pantalla
    system("cls");


    //Mostrando el encabezado de la tabla de detalles del estudiante
    cout << "+---------------------------------------------------------------------------------+" << endl;
    cout << "+                            Tabla de Detalles del Estudiante                     +" << endl;
    cout << "+---------------------------------------------------------------------------------+" << endl;

    //Abriendo un archivo binario llamado en modo de lectura binaria y se comprueba si la apertura fue exitosa
    ifstream archivo("Alumnos.dat", ios::binary | ios::app);
    if (!archivo) {

        //Si no encuentra informacion muestra el siguiente mensaje
        cout << "Error, no se encuentra informacion...";
        return;
    }


    Alumno alumno;

    //Ciclo while para leer los datos del archivo binario  y los almacenan en un objeto alumno llamado alumno y repite este procedimiento hasta que se acaben los datos por leer
    while (archivo.read(reinterpret_cast<char*>(&alumno), sizeof(Alumno))) {

        //Se muestra los detalles del estudiante
        cout << "                        Mostrando -> ID del estudiante: " << alumno.id << endl;
        cout << "                        Mostrando -> Nombre del estudiante: " << alumno.nombre << endl;
        cout << "                        Mostrando -> email del estudiante : " << alumno.DPI << endl;
        cout << "                        Mostrando -> Estatus del estudiante: " << alumno.nacionalidad << endl;
        cout << "                        Mostrando -> Direccion: " << alumno.direccion << endl;
        cout << "                        Mostrando -> Telefono: " << alumno.telefono << endl;
        cout << "+---------------------------------------------------------------------------------+" << endl;
    }
    archivo.close(); //cierra el archivo

    //Mensaje al usuario
    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}

//Funcion para modificar los alumnos ya registrados
void alumnos::modificar()
{
//Declarando 2 variables string con el codigo programa
string codigoPrograma="2380";
Bitacora Auditoria;
string user, contrasena;
Auditoria.ingresoBitacora(user,codigoPrograma,"ALMM");

    //Limpiando pantalla
	system("cls");
	//Declarando variables tipo fstream y string
    fstream archivo;
    string idPersona;

    //Variable bool con valor false
    bool encontrado = false;

    cout << "+---------------------------------------------------------------------------------+" << endl;
    cout << "+                       Modificar Detalles del estudiante                         +" << endl;
    cout << "+---------------------------------------------------------------------------------+" << endl;

    //abre un archivo binario en modo de lectura y escritura
    archivo.open("Alumnos.dat", ios::binary | ios::in | ios::out);
    //verificacion si se abre el archivo
    if (!archivo) {
        //si no se pudo muestra el siguiente mensaje
        cout << "Error, no se encuentra informacion...";
        return;
    }
    //si se pudo abrir correctament pide la id de la persona
    cout << "Ingrese el ID de la persona que desea modificar: ";
    cin >> idPersona;

    Alumno alumno;
    // Lee cada registro del archivo y busca el ID proporcionado por el usuario
    while (archivo.read(reinterpret_cast<char*>(&alumno), sizeof(Alumno))) {
        if (alumno.id == idPersona) {
            // Establece el indicador como verdadero si se encuentra el estudiante
            encontrado = true;

            //Muestra mensajes para poder ingresar los detalles para poder modificar del alumnno
            cout << "Ingrese el nuevo ID del estudiante: ";
            cin >> alumno.id;
            cout << "Ingrese el nuevo nombre del estudiante: ";
            cin >> alumno.nombre;
            cout << "Ingrese el nuevo email del estudiante: ";
            cin >> alumno.DPI;
            cout << "Ingrese el nuevo estatus del estudiante: ";
            cin >> alumno.nacionalidad;
            cout << "Ingrese la nueva direccion del estudiante: ";
            cin >> alumno.direccion;
            cout << "Ingrese el nuevo Telefono del estuantes: ";
            cin >> alumno.telefono;


            // Posiciona el puntero de escritura al inicio del registro que se está modificando
            archivo.seekp(-static_cast<int>(sizeof(Alumno)), ios::cur);

            // Escribe  nuevos detalles del estudiante en el archivo
            archivo.write(reinterpret_cast<char*>(&alumno), sizeof(Alumno));
            break;
        }
    }

    archivo.close(); // Cierra el archivo

    //si no lo encuentra mostrara el siguiente mensaje
    if (!encontrado) {
        cout << "No se encontró un estudiante con el ID proporcionado." << endl;
    }

    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}

//funcion para borrarr a las alumnos registradas
void alumnos::borrar()
{
string codigoPrograma="2400";
Bitacora Auditoria;
string user, contrasena;
Auditoria.ingresoBitacora(user,codigoPrograma,"ALMB");

    //Limpia pantalla
	system("cls");
	//declara una variable string
	string idPersona;

	//Muestra el encabezado de la tabla para eliminar un estudiante
    cout<<"+---------------------------------------------------------------------------------+"<<endl;
	cout<<"+                             Eliminar estudiante                                 +"<<endl;
    cout<<"+---------------------------------------------------------------------------------+"<<endl;


    // Abre el archivo binario alumnos.dat en modo de lectura
    ifstream archivo("Alumnos.dat", ios::binary);

    //verifica si se abrio el archivo
	if(!archivo)
	{
        //si no se abrio imprime el siguiente mensaje
		cout<<"Error, no se encuentra informacion...";
		return;
	}
    // Crea un nuevo archivo binario en modo de escritura
	ofstream archivo2("Alumnos2.dat", ios::binary);
	Alumno alumno;

    //Muestra el mensaje para poder borrar el alumno
    cout<<"-> Ingrese el ID de la persona que desea eliminar: ";
    cin>>idPersona;

    // Crea un nuevo archivo binario en modo de escritura
    bool resta = false;

        // Lee cada registro del archivo y busca el usuario proporcionado por el usuario
		while(archivo.read(reinterpret_cast<char*>(&alumno), sizeof(Alumno)))
		{
		    // Si el nombre del usuario no coincide con el proporcionado, se escribe en el nuevo archivo
			if(alumno.id != idPersona)
			{
				archivo2.write(reinterpret_cast<const char*>(&alumno), sizeof(Alumno));
			}
			else
			{
			    resta = true;
			}

		}
        //cierra ambos archivos
		archivo.close();
		archivo2.close();

        //remueve el Alumnos.dat
		remove("Alumnos.dat");

        //y renombra el Alumnos2.dat a alumnos.dat
		rename("Alumnos2.dat","Alumnos.dat");

		if (resta)
        {
        //Si se encuentra el alumno muestra el mensaje
        cout << "Alumno eliminado con exito." << endl;
        }
        else
        {
        //Si no se encuentra el alumno muestra el mensaje
        cout << "No se a podido encontrar el codigo del alumno" << endl;
        }
}
