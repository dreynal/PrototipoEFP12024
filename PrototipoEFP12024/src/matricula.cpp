#include "matricula.h"
#include <iostream>
#include <fstream>
#include <string>
#include<stdlib.h>
#include<iomanip>
#include <cstring> // Incluye la biblioteca para strcmp
#include <cstdlib> // Para la generación de números aleatorios
#include <ctime>   // Para establecer la semilla del generador de números aleatorios
#include "alumnos.h"
#include "Sedes.h"
using namespace std;

// Definición de la estructura Sede que contiene los datos de una sede
struct Matricula {
    char carnet [20];
    char sede [20];
    char facultad [40];
    char plan [20];
    char jornada[15];
    char nombre[50];
    char email[40];
    char direccion[100];
    char telefono[15];

};
void matricula::menu(){
int choice;

	do
    {
	system("cls");

	cout<<"\t\t\t---------------------------------------"<<endl;
	cout<<"\t\t\t|SISTEMA DE PAGO DE MATRICULA EN LINEA|"<<endl;
	cout<<"\t\t\t---------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso Matricula"<<endl;
	cout<<"\t\t\t 2. Despliegue Matricula"<<endl;
    cout<<"\t\t\t 3. Borra Matricula"<<endl;
    cout<<"\t\t\t 4. Retornar menu anterior"<<endl;
    cout<<"\t\t\t-----------------------------------------"<<endl;
    cout<<"\t\t\tOpcion a escoger:[1/2/3/4]"<<endl;
    cout<<"\t\t\t-----------------------------------------"<<endl;
    cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice; // Lee la opción del usuario

    switch(choice)
    {
    case 1:
        do
        {
            insertar();
            cout<<"\n\t\t\t Desea agregar otra matricula (Y,N): ";
            cin>>x; // Pregunta al usuario si quiere agregar otra Matricula
        } while(x=='y'||x=='Y'); // Repite el proceso si el usuario responde 'y' o 'Y'
		break;
	case 2:
	    {
	        desplegar();
	    }
		break;
    case 3:
        {
            borrar();
        }
        break;
    case 4:
        {
            break;
        }
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		cin.get();
	}
  }while(choice!= 4);
}

// Función para generar un número de boleta aleatorio
string matricula::generarNumeroBoleta() {
    srand(time(0)); // Establecer la semilla para números aleatorios
    string numeroBoleta = "No.";
    for (int i = 0; i < 6; ++i) {
        numeroBoleta += to_string(rand() % 10); // Añadir dígitos aleatorios
    }
    return numeroBoleta;
}

void matricula::insertar() {
    system("cls");
    Matricula matricula;
    ofstream fileMat("Matricula.dat", ios::binary | ios::app); // Abre el archivo en modo binario y de adición

    if (!fileMat) {
        cerr << "No se pudo abrir el archivo 'Matricula.dat'." << endl;
        return;
    }
    else {
        Alumno alumno;
        bool encontrado = false;
        //string carnet;

        cout<<"\n-----------------------------------------------------------------------------------------------------------------";
        cout<<"\n-------------------------------------------Registro de Nuevos Estudiantes----------------------------------------"<<endl;

        cout << "\n\t\t\tIngrese su numero de carnet: ";
        cin.ignore();
        cin.getline(matricula.carnet, sizeof(matricula.carnet));

        // Verificación del carnet en el archivo de Alumnos.dat
        ifstream archivoAlumnos("Alumnos.dat", ios::binary);
        if (!archivoAlumnos.is_open()) {
            cerr << "Error: No se pudo abrir el archivo 'Alumnos.dat'." << endl;
            return;
        }
        else
        {
            while (archivoAlumnos.read(reinterpret_cast<char*>(&alumno), sizeof(Alumno)))
            {
                if (strcmp(alumno.id, matricula.carnet) == 0) {
                    encontrado = true;
                    break;
                }
            }
            archivoAlumnos.close();

            if (!encontrado) {
                cerr << "El carnet ingresado no coincide con el de ningun estudiante" << endl;
                return;
            }
            // Asignar los datos del alumno a la estructura Matricula
            strcpy(matricula.carnet, alumno.id);
            strcpy(matricula.nombre, alumno.nombre);
            strcpy(matricula.email, alumno.DPI);
            strcpy(matricula.direccion, alumno.direccion);
            strcpy(matricula.telefono, alumno.telefono);
        }

        cout << "Seleccione la Sede (Ej. Portales, Boca del monte, etc.): ";
        cin.getline(matricula.sede, sizeof(matricula.sede));
        cout << "Seleccione la Facultad (Ej. Ingenieria en sistemas, Ingenieria civil, etc.): ";
        cin.getline(matricula.facultad, sizeof(matricula.facultad));
        cout << "Seleccione el plan(Diario, Fin de semana): ";
        cin.getline(matricula.plan, sizeof(matricula.plan));
        cout << "Seleccione la Jornada(Matutino, Vespertina): ";
        cin.getline(matricula.jornada, sizeof(matricula.jornada));

        // Luego de ingresar los datos, se escriben en el archivo
        fileMat.write(reinterpret_cast<char*>(&matricula), sizeof(Matricula));

        cout << "\n\t\t--------- Monto de la matricula: Q10.00 ---------" << endl;
        system("pause");
    }

    fileMat.close();

    pagarEnLinea();
    system("cls");
    // Generar el número de boleta
    string numeroBoleta;
    numeroBoleta = generarNumeroBoleta();
    ifstream archivo("Alumnos.dat", ios::binary);
    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo" << endl;
        return;
    }
    else
    {
        Alumno alumno;
        while (archivo.read(reinterpret_cast<char*>(&alumno), sizeof(Alumno))) {
    }
    // Mostrar el comprobante de pago
    cout<<"\n----------------------------------------------------------------------------------------------------------";
    cout<<"\n-------------------------------------------Comprobante de pago -------------------------------------------"<<endl;
    cout << "\t\t\tNumero de boleta: " << numeroBoleta << endl;
    cout << "\t\t\tNumero de carnet: " << alumno.id << endl;
    cout << "\t\t\tNombre completo: " << alumno.nombre << endl;
    cout << "\t\t\tMonto de la matricula: Q10.00" <<"\n"<< endl;
    ofstream file2("Boleta_Pago.dat", ios::binary | ios::app);
    file2.write(reinterpret_cast<char*>(&numeroBoleta), sizeof(numeroBoleta));
    file2.write(reinterpret_cast<char*>(&alumno.id), sizeof(alumno.id));
    file2.write(reinterpret_cast<char*>(&alumno.nombre), sizeof(alumno.nombre));
    file2.close();
    }
    system("pause");
}

void matricula::desplegar() {
    system("cls"); // Limpia la pantalla
    ifstream fileMat("Matricula.dat", ios::binary); // Abre el archivo "Matricula.dat" en modo de lectura binaria

    // Verifica si el archivo se abrió correctamente
    if (!fileMat) {
        cerr << "No se pudo abrir el archivo 'Matricula.dat'." << endl; // Muestra un mensaje de error si no se puede abrir el archivo
        return; // Retorna
    }

    int total = 0; // Contador para el total de registros de matrícula

    cout << "\n-----------------------------------------------------------------------------------------------------------------";
    cout << "\n-------------------------------------------Datos de Matricula Registrados----------------------------------------" << endl;
    Matricula matricula;
    while (fileMat.read(reinterpret_cast<char*>(&matricula), sizeof(Matricula))) {
        cout << "\t\t\tNumero de carnet: " << matricula.carnet<< endl;
        cout << "\t\t\tNombre del alumno: " << matricula.nombre<< endl;
        cout << "\t\t\tEmail    : " << matricula.email<< endl;
        cout << "\t\t\tDireccion: " << matricula.direccion << endl;
        cout << "\t\t\tTelefono del alumno: " << matricula.telefono << endl;
        cout << "\t\t\tSede     : " << matricula.sede << endl;
        cout << "\t\t\tFacultad : " << matricula.facultad << endl;
        cout << "\t\t\tPlan     : " << matricula.plan << endl;
        cout << "\t\t\tJornada  : " << matricula.jornada << endl;
        cout << "+---------------------------------------------------------------------------------------------------------------+" << endl;
        total++; // Incrementa el contador de registros de matrícula
    }

    if (total == 0) { // Verifica si no hay registros de matrícula en el archivo
        cout << "\n\t\t\tNo hay informacion registrada." << endl; // Muestra un mensaje indicando que no hay información
    }

    fileMat.close(); // Cierra el archivo
    cin.ignore(); // Limpia el buffer de entrada
    system("pause"); // Pausa el sistema para que el usuario pueda ver la información
}

void matricula::borrar() {
    system("cls"); // Limpia la pantalla
    string id_borrar; // Variable para almacenar el ID de la matricula que se desea borrar
    int found = 0; // Variable para indicar si se encontró la matricula a borrar

    cout << "\n------------------------------------------Detalles Matricula a Borrar-----------------------------------------------" << endl;

    ifstream fileMat("Matricula.dat", ios::binary); // Abre el archivo "Matricula.dat" en modo de lectura binaria

    // Verifica si el archivo se abrió correctamente
    if (!fileMat) {
        cout << "\n\t\t\tNo hay informacion..."; // Muestra un mensaje de error si no se puede abrir el archivo
        return; // Retorna
    }

    ofstream file1("temporal.dat", ios::binary); // Abre un archivo temporal en modo de escritura binaria

    // Verifica si el archivo temporal se abrió correctamente
    if (!file1) {
        cout << "\n\t\t\tError al abrir el archivo temporal..."; // Muestra un mensaje de error si no se puede abrir el archivo temporal
        return; // Retorna
    }

    cout << "\n-----------------------------------------Sistema Busqueda de Matriculas---------------------------------------------" << endl;
    cout << "\n\t\t Ingrese el carnet de la Matricula que quiere Borrar: ";
    cin >> id_borrar; // Lee el ID de la matricula que se desea borrar

    Matricula matricula; // Crea una instancia de la estructura Matricula para almacenar los datos de la matricula
    while (fileMat.read(reinterpret_cast<char*>(&matricula), sizeof(Matricula))) { // Lee las matriculas del archivo
        if (strcmp(matricula.carnet, id_borrar.c_str()) == 0) { // Compara el carnet de la matricula actual con el ID proporcionado
            cout << "\n\t\t\tBorrado de informacion exitoso!!!!" << "\n" << endl; // Muestra un mensaje indicando que la sede se borró exitosamente
            found++; // Incrementa el contador de sedes encontradas
        } else {
            file1.write(reinterpret_cast<const char*>(&matricula), sizeof(Matricula)); // Escribe los datos de la matricula sin borrar en el archivo temporal
        }
    }

    if (found == 0) { // Verifica si no se encontró la matricula con el ID proporcionado
        cout << "\n\t\t\tId de matricula no encontrada...." << "\n" << endl; // Muestra un mensaje indicando que no se encontró la matricula
    }

    file1.close(); // Cierra el archivo temporal
    fileMat.close(); // Cierra el archivo original

    remove("Matricula.dat"); // Elimina el archivo original
    rename("temporal.dat", "Matricula.dat"); // Renombra el archivo temporal como "Sedes.dat"

    cin.ignore(); // Limpia el buffer de entrada
    system("pause"); // Pausa el sistema para que el usuario pueda ver el mensaje
    //string codigoPrograma="6100";
    //Bitacora Auditoria;

    //string user;
    //Auditoria.ingresoBitacora(user,codigoPrograma,"DEL");
}

void matricula::pagarEnLinea() {
    system("cls");
    cout<<"\n----------------------------------------------------------------------------------------------------------";
    cout<<"\n-------------------------------------------DATOS DE LA TARJETA--------------------------------------------"<<endl;
    cout << "Ingrese los datos de su tarjeta de credito para realizar el pago en linea:" << endl;
    string numTarjeta, fExpiracion, codSeguridad;
    cout << "Numero de tarjeta: ";
    //cin.ignore();
    getline(cin, numTarjeta);
    cout << "Fecha de expiracion (MM/AA): ";
    getline(cin, fExpiracion);
    cout << "Codigo de seguridad: ";
    getline(cin, codSeguridad);

    ifstream archivo("tarjeta.txt");
    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo tarjeta.txt." << endl;
        return;
    }
    else
    {
        string numeroTarjeta, fechaExpiracion, codigoSeguridad;
        int saldo;
        // Leer el número de tarjeta
        getline(archivo, numeroTarjeta);
        // Leer la fecha de expiración
        getline(archivo, fechaExpiracion);
        // Leer el código de seguridad
        getline(archivo, codigoSeguridad);
        // Leer el saldo disponible
        string saldoStr;
        getline(archivo, saldoStr);
        saldo = stoi(saldoStr);
        if (numTarjeta != numeroTarjeta || fExpiracion != fechaExpiracion || codSeguridad != codigoSeguridad)
        {
            cout << "Los datos de la tarjeta no coinciden." << endl;
        return;
        }
        // Si los datos coinciden, continuar con el proceso de pago
        // Verificar el saldo en la tarjeta
        if (saldo >= 10) { // Si hay suficiente saldo para el pago
            cout << "\n¡Su pago de matricula ha sido procesado con exito!" << endl;
            cout << "Monto pagado: Q10.00" << endl;
            cout << "Saldo disponible en la tarjeta: Q" << saldo - 10 << endl;
            cout<<"----------------------------------------------------------------------------------------------------------"<<endl;
            archivo.close(); // Cerrar el archivo antes de abrirlo en modo de escritura
            // Actualizar el saldo en el archivo después del pago
            ofstream archivoSalida("tarjeta.txt"); // Abrir el archivo en modo de escritura
            if (!archivoSalida.is_open()) {
                cout << "Error: No se pudo abrir el archivo tarjeta.txt para escribir." << endl;
            return;
            }
            // Escribir los datos actualizados en el archivo
            archivoSalida << numeroTarjeta << endl;
            archivoSalida << fechaExpiracion << endl;
            archivoSalida << codigoSeguridad << endl;
            archivoSalida << saldo - 10 << endl; // Actualizar el saldo restando 10
            archivoSalida.close(); // Cerrar el archivo después de escribir
            }
            else { // Si no hay suficiente saldo para el pago
                cout << "\n¡No hay fondos suficientes en la tarjeta para realizar el pago!" << endl;
                cout << "Saldo disponible en la tarjeta: Q" << saldo << endl;
            }
                system("pause");
        }
}
