//Creado por Rocio Guisell Lopez espinoza 9959-23-740
#include "secciones.h"

#include <fstream>
#include <iostream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

//implementacion de bitacora

#include "Bitacora.h"
using namespace std;
// Definici�n de la funci�n CrudSeccion de la clase SeccionesCrud
void SeccionesCrud::CrudSeccion()
{

 //implementacion de variables para bitacora
    string codigoPrograma= "5000";
    Bitacora Auditoria;
    string user ="admin";

    // Declaraci�n de la variable 'opcion' que almacenar� la opci�n del usuario
    int opcion;

    // Bucle do-while que se ejecutar� hasta que el usuario elija la opci�n 5 (Regresar al men� anterior)
    do{

    // Limpia la consola
	system("cls");
	// Imprime el men� de opciones en la consola
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t|     SISTEMA DE GESTION UMG - Secciones       |"<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingresar Seccion"<<endl;
	cout<<"\t\t\t 2. Modificar Seccion"<<endl;
	cout<<"\t\t\t 3. Borrar Seccion"<<endl;
	cout<<"\t\t\t 4. Desplegar Seccion"<<endl;
	cout<<"\t\t\t 5. Regresar Menu Anterior"<<endl;
    cout<<"\t\t\t --------------------------------------------"<<endl;
	cout<<"\t\t\t |   Opcion a escoger:[1|2|3|4|5|]           |"<<endl;
	cout<<"\t\t\t --------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    // Lee la opci�n del usuario desde la consola
    cin>>opcion;

    // Estructura switch que ejecuta una acci�n dependiendo de la opci�n elegida por el usuario
    switch (opcion)
    {
    case 1:
        // Si la opci�n es 1, llama a la funci�n IngresarSeccion
        IngresarSeccion();
        //registro de bitacora ingreso
        Auditoria.ingresoBitacora(user,codigoPrograma,"CSE");//CSE = Create Secciones

		break;
    case 2:
        // Si la opci�n es 2, llama a la funci�n ModificarSeccion
        ModificarSeccion();
        //registro de bitacora Modificar
        Auditoria.ingresoBitacora(user,codigoPrograma,"USE");//USE = Update Secciones

        break;
    case 3:
        // Si la opci�n es 3, llama a la funci�n BorrarSeccion
        BorrarSeccion();
        //registro de bitacora borrar
        Auditoria.ingresoBitacora(user,codigoPrograma,"DSE");//DSE = Delete Secciones

		break;
    case 4:
        // Si la opci�n es 4, llama a la funci�n DesplegarSeccion
        DesplegarSeccion();
        //registro de bitacora despliegle
        Auditoria.ingresoBitacora(user,codigoPrograma,"RSE");//RSE = Read Secciones
        break;
    case 5:
        // Si la opci�n es 5, sale del bucle
        break;
    default:
        // Si la opci�n no es ninguna de las anteriores, imprime un mensaje de error y espera una entrada del usuario
        cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		cin.get();
    }
    // El bucle se ejecuta mientras la opci�n no sea 5
    }while(opcion!= 5);
}

// Definici�n de la funci�n IngresarSeccion de la clase SeccionesCrud
void SeccionesCrud::IngresarSeccion()
{
    // Limpia la consola
    system("cls");
    // Imprime el t�tulo de la secci�n en la consola
    cout<<"\n------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n-------------------------------------------------Agregar Seccion--------------------------------------------"<<endl;
    // Crea un objeto 'seccion' de la clase 'secciones'
    secciones seccion;
    // Solicita al usuario que ingrese el c�digo de la secci�n
    cout << "Ingrese el codigo del Seccion: ";
    cin >> seccion.codigo;
    cin.ignore();

    // Solicita al usuario que ingrese el nombre de la secci�n
    cout << "Ingrese el nombre del Seccion: ";
    cin.getline(seccion.nombre, 50);

    // Solicita al usuario que ingrese el estatus de la secci�n
    cout << "Ingrese la estatus de la Seccion: ";
    cin.getline(seccion.estatus, 50);

    // Abre el archivo 'seccion.dat' en modo binario y de escritura al final del archivo
    ofstream archivo("seccion.dat", ios::binary | ios::app);
    // Escribe el objeto 'seccion' en el archivo
    archivo.write(reinterpret_cast<const char*>(&seccion), sizeof(secciones));
    // Cierra el archivo
    archivo.close();

    // Imprime un mensaje de �xito en la consola
    cout << "Seccion agregada exitosamente!" << endl;

}


// Definici�n de la funci�n ModificarSeccion de la clase SeccionesCrud
void SeccionesCrud::ModificarSeccion()
{
    // Declaraci�n de la variable 'codigo' que almacenar� el c�digo de la secci�n a modificar
    int codigo;
    // Solicita al usuario que ingrese el c�digo de la secci�n a modificar
    cout << "Ingrese el codigo de la Seccion a modificar: ";
    cin >> codigo;

    // Abre el archivo 'seccion.dat' en modo binario para lectura y escritura
    fstream archivo("seccion.dat", ios::binary | ios::in | ios::out);
    // Si el archivo no se pudo abrir, imprime un mensaje de error y termina la funci�n
    if (!archivo) {
        cout << "No hay Seccion registradas." << endl;
        return;
    }

    // Crea un objeto 'seccion' de la clase 'secciones'
    secciones seccion;
    // Declaraci�n de la variable booleana 'encontrada' que indicar� si se encontr� la secci�n a modificar
    bool encontrada = false;
    // Mientras se pueda leer un objeto 'seccion' del archivo...
    while (archivo.read(reinterpret_cast<char*>(&seccion), sizeof(secciones))) {
        // Si el c�digo de la secci�n le�da es igual al c�digo ingresado por el usuario...
        if (seccion.codigo == codigo) {
            // Solicita al usuario que ingrese el nuevo nombre de la secci�n
            cout << "Ingrese el nuevo nombre de la Seccion: ";
            cin.ignore();
            cin.getline(seccion.nombre, 50);

            // Solicita al usuario que ingrese el nuevo estatus de la secci�n
            cout << "Ingrese el nuevo estatus de la Seccion: ";
            cin.getline(seccion.estatus, 50);

            // Mueve el puntero de escritura del archivo a la posici�n de la secci�n a modificar
            archivo.seekp(-static_cast<int>(sizeof(seccion)), ios::cur);
            // Escribe el objeto 'seccion' modificado en el archivo
            archivo.write(reinterpret_cast<const char*>(&seccion), sizeof(secciones));

            // Cambia el valor de 'encontrada' a true
            encontrada = true;
            // Termina el bucle
            break;
        }
    }


    archivo.close();

     // Si 'encontrada' es false, es decir, si no se encontr� la secci�n a modificar...
    if (!encontrada) {
        // Imprime un mensaje de error en la consola
        cout << "No se encontr� la Seccion con el codigo ingresado." << endl;
    } else {
        // Si 'encontrada' es true, es decir, si se encontr� y modific� la secci�n...
        // Imprime un mensaje de �xito en la consola
        cout << "Seccion modificada exitosamente!" << endl;
    }
}




void SeccionesCrud::BorrarSeccion()
{
    // Declaraci�n de la variable 'codigo' que almacenar� el c�digo de la secci�n a eliminar
    int codigo;
    // Solicita al usuario que ingrese el c�digo de la secci�n a eliminar
    cout << "Ingrese el codigo de la Seccion a eliminar: ";
    cin >> codigo;

    // Abre el archivo 'seccion.dat' en modo binario para lectura
    ifstream archivo("seccion.dat", ios::binary);
    // Si el archivo no se pudo abrir, imprime un mensaje de error y termina la funci�n
    if (!archivo) {
        cout << "No hay seccion registradas." << endl;
    }



     // Crea un archivo temporal 'seccion_tmp.dat' en modo binario para escritura
    ofstream archivoTmp("seccion_tmp.dat", ios::binary);
    // Crea un objeto 'seccion' de la clase 'secciones'
    secciones seccion;
    // Declaraci�n de la variable booleana 'eliminada' que indicar� si se elimin� la secci�n
    bool eliminada = false;
    // Mientras se pueda leer un objeto 'seccion' del archivo...
    while (archivo.read(reinterpret_cast<char*>(&seccion), sizeof(secciones))) {
        // Si el c�digo de la secci�n le�da es diferente al c�digo ingresado por el usuario...
        if (seccion.codigo != codigo) {
            // Escribe el objeto 'seccion' en el archivo temporal
            archivoTmp.write(reinterpret_cast<const char*>(&seccion), sizeof(secciones));
        } else {
            // Si el c�digo de la secci�n le�da es igual al c�digo ingresado por el usuario, cambia el valor de 'eliminada' a true
            eliminada = true;
        }
    }

    // Cierra los archivos
    archivo.close();
    archivoTmp.close();
    // Aqu� deber�a continuar el c�digo para eliminar el archivo original y renombrar el archivo temporal



       // Elimina el archivo original 'seccion.dat'
    remove("seccion.dat");
    // Renombra el archivo temporal 'seccion_tmp.dat' a 'seccion.dat'
    rename("seccion_tmp.dat", "seccion.dat");

    // Si 'eliminada' es true, es decir, si se encontr� y elimin� la secci�n...
    if (eliminada) {
        // Imprime un mensaje de �xito en la consola
        cout << "seccion eliminada exitosamente!" << endl;
    } else {
        // Si 'eliminada' es false, es decir, si no se encontr� la secci�n a eliminar, imprime un mensaje de error en la consola
        cout << "No se encontr� la seccion con el codigo ingresado." << endl;
    }


}
// Definici�n de la funci�n DesplegarSeccion de la clase SeccionesCrud
void SeccionesCrud::DesplegarSeccion()
{
    // Limpia la consola
    system("cls");
    // Imprime el t�tulo de la secci�n en la consola
    cout<<"-----------------Despliegue de seccion registradas---------------------"<<endl;
    // Abre el archivo 'seccion.dat' en modo binario para lectura
    ifstream archivo("seccion.dat", ios::binary);
    // Si el archivo no se pudo abrir, imprime un mensaje de error y termina la funci�n
    if (!archivo) {
        cout << "No hay seccion registradas." << endl;
        return;
    }

      // Crea un objeto 'seccion' de la clase 'secciones'
    secciones seccion;
    // Mientras se pueda leer un objeto 'seccion' del archivo...
    while (archivo.read(reinterpret_cast<char*>(&seccion), sizeof(secciones))) {
        // Imprime los datos de la secci�n en la consola
        cout << "Codigo: " << seccion.codigo << endl;
        cout << "Nombre: " << seccion.nombre << endl;
        cout << "Estatus: " << seccion.estatus << endl;
        cout << "-----------------------------" << endl;
    }

    // Cierra el archivo
    archivo.close();

    // Imprime un mensaje indicando al usuario que presione Enter para continuar
    cout << "Presione Enter para continuar...";
    // Ignora el siguiente car�cter de entrada (generalmente el salto de l�nea despu�s de la �ltima entrada)
    cin.ignore();
    // Espera a que el usuario presione Enter
    cin.get();

}

