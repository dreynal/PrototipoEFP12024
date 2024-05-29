//Creado por Diana Mishel Loeiza Ramírez 9959-23-3457
//proceso notas
// implementacion de bitacora
#include "notas.h" // Inclusión del archivo de cabecera para las definiciones relacionadas con las notas
#include "Bitacora.h" // Inclusión del archivo de cabecera para las definiciones relacionadas con la bitácora
#include <fstream> // Inclusión de la biblioteca estándar de manejo de archivos
#include <iostream> // Inclusión de la biblioteca estándar de entrada/salida
#include <cstdlib> // Inclusión de la biblioteca estándar para funciones de utilidad
#include <conio.h> // Inclusión de la biblioteca para funciones de entrada y salida en consola

using namespace std; // Uso del espacio de nombres estándar

// Definición de la función para realizar operaciones CRUD en las notas

void NotaCrud::CrudNota() {
    string codigoPrograma = "5020"; // Código del programa
    Bitacora Auditoria; // Objeto para gestionar la bitácora de auditoría
    string user = "admin"; // Usuario actual del sistema

    int opcion; // Variable para almacenar la opción seleccionada por el usuario

    // Menú principal de operaciones CRUD
//bucle do-while de ejecucion
    do {
        system("cls"); // Limpia la pantalla
        // Mostrar opciones disponibles
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t|     SISTEMA DE GESTION UMG - Notas       |" << endl;
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t 1. Ingresar Nota" << endl;
        cout << "\t\t\t 2. Modificar Nota" << endl;
        cout << "\t\t\t 3. Borrar Nota" << endl;
        cout << "\t\t\t 4. Desplegar Notas" << endl;
        cout << "\t\t\t 5. Regresar al Menú Anterior" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\t |   Opción a escoger:[1|2|3|4|5|]           |" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\tIngrese tu Opción: ";

        cin >> opcion; // Leer la opción seleccionada por el usuario

        // Realizar la operación correspondiente según la opción seleccionada
//lee opcion del usuario desde consola
        switch (opcion) {
            case 1:
                IngresarNota(); // Llama a la función para ingresar una nota
                Auditoria.ingresoBitacora(user, codigoPrograma, "CNO"); // Registra en la bitácora la acción de creación de nota
                break;
            case 2:
                ModificarNota(); // Llama a la función para modificar una nota
                Auditoria.ingresoBitacora(user, codigoPrograma, "UNO"); // Registra en la bitácora la acción de modificación de nota
                break;
            case 3:
                BorrarNota(); // Llama a la función para borrar una nota
                Auditoria.ingresoBitacora(user, codigoPrograma, "DNO"); // Registra en la bitácora la acción de eliminación de nota
                break;
            case 4:
                DesplegarNotas(); // Llama a la función para desplegar todas las notas
                Auditoria.ingresoBitacora(user, codigoPrograma, "RNO"); // Registra en la bitácora la acción de lectura de notas
                break;
            case 5:
                break; // Salir del bucle y regresar al menú anterior
            default:
                cout << "\n\t\t\tOpción inválida. Por favor, prueba otra vez." << endl; // Mensaje de opción inválida
                cin.ignore(); // Ignorar cualquier entrada no válida
                cin.get(); // Esperar a que el usuario presione Enter para continuar
        }
    } while (opcion != 5); // Repetir el bucle hasta que el usuario elija salir
}

// Función para ingresar una nueva nota al sistema
void NotaCrud::IngresarNota() {

    system("cls"); // Limpiar la pantalla
    // imprime
    cout << "\n------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\n-------------------------------------------------Agregar Nota--------------------------------------------" << endl;
    notas nota; // Declarar una variable para almacenar la nueva nota
    cout << "Ingrese el código del estudiante: ";
    cin >> nota.codigoEstudiante; // Leer el código del estudiante
    cin.ignore(); // Ignorar el carácter de nueva línea en el buffer de entrada

    cout << "Ingrese el nombre del estudiante: ";
    getline(cin, nota.nombreEstudiante); // Leer el nombre del estudiante

    cout << "Ingrese el nombre del curso: ";
    getline(cin, nota.nombreCurso); // Leer el nombre del curso

    cout << "Ingrese la nota: ";
    cin >> nota.nota; // Leer la nota

    ofstream archivo("notas.dat", ios::binary | ios::app); // Abrir el archivo para escribir en modo binario, en modo de añadir al final
    archivo.write(reinterpret_cast<const char*>(&nota), sizeof(notas)); // Escribir la nota en el archivo
    archivo.close(); // Cerrar el archivo


    cout << "Nota agregada exitosamente!" << endl; // Mensaje de éxito
}

// Función para modificar la nota de un estudiante
void NotaCrud::ModificarNota() {
    int codigo;
    cout << "Ingrese el código del estudiante cuya nota desea modificar: ";
    cin >> codigo; // Leer el código del estudiante
//abre el archivo
    fstream archivo("notas.dat", ios::binary | ios::in | ios::out); // Abrir el archivo para lectura y escritura en modo binario
    if (!archivo) { // Si no se pudo abrir el archivo
        cout << "No hay notas registradas." << endl; // Mensaje de error
        return; // Salir de la función
    }
//crea objeto "nota"
    notas nota; // Declarar una variable para almacenar la nota actual
    bool encontrada = false; // Bandera para indicar si se encontró la nota
    while (archivo.read(reinterpret_cast<char*>(&nota), sizeof(notas))) { // Leer cada registro de nota del archivo
        if (nota.codigoEstudiante == codigo) { // Si se encuentra la nota con el código ingresado
            cout << "Ingrese la nueva nota para el estudiante: ";
            cin >> nota.nota; // Leer la nueva nota
//puntero
            archivo.seekp(-static_cast<int>(sizeof(notas)), ios::cur); // Mover el puntero de escritura una posición antes del registro actual
            archivo.write(reinterpret_cast<const char*>(&nota), sizeof(notas)); // Sobrescribir el registro actual con la nueva nota

            encontrada = true; // Actualizar la bandera indicando que se encontró la nota
            break; // Salir del bucle
        }
    }

    archivo.close(); // Cerrar el archivo

    if (!encontrada) { // Si la nota no se encontró
        cout << "No se encontró la nota del estudiante con el código ingresado." << endl; // Mensaje de error
    } else {
        //si la nota fue encontrada ingresa mensaje
        cout << "Nota modificada exitosamente!" << endl; // Mensaje de éxito
    }
}

// Función para borrar la nota de un estudiante
void NotaCrud::BorrarNota() {
    int codigo; // Variable para almacenar el código del estudiante cuya nota se desea eliminar
    cout << "Ingrese el código del estudiante cuya nota desea eliminar: ";
    cin >> codigo; // Leer el código del estudiante

    ifstream archivo("notas.dat", ios::binary); // Abrir el archivo para lectura en modo binario
    if (!archivo) { // Si no se pudo abrir el archivo
        cout << "No hay notas registradas." << endl; // Mensaje de error
    }


    ofstream archivoTmp("notas_tmp.dat", ios::binary); // Abrir un archivo temporal para escribir en modo binario
    notas nota; // Declarar una variable para almacenar la nota actual

    bool eliminada = false; // Bandera para indicar si se eliminó la nota

    while (archivo.read(reinterpret_cast<char*>(&nota), sizeof(notas))) { // Leer cada registro de nota del archivo
        if (nota.codigoEstudiante != codigo) { // Si el código del estudiante no coincide con el código ingresado
            archivoTmp.write(reinterpret_cast<const char*>(&nota), sizeof(notas)); // Escribir la nota en el archivo temporal
        } else {
            eliminada = true; // Actualizar la bandera indicando que se eliminó la nota
        }
    }
//
    archivo.close(); // Cerrar el archivo original
    archivoTmp.close(); // Cerrar el archivo temporal

    remove("notas.dat"); // Eliminar el archivo original
    rename("notas_tmp.dat", "notas.dat"); // Renombrar el archivo temporal como el archivo original

    if (eliminada) { // Si la nota fue eliminada

        cout << "Nota eliminada exitosamente!" << endl; // Mensaje de éxito
    } else {
        cout << "No se encontró la nota del estudiante con el código ingresado." << endl; // Mensaje de error
    }
}

// Función para desplegar todas las notas registradas en el sistema
void NotaCrud::DesplegarNotas() {
    system("cls"); // Limpiar la pantalla
    cout << "-----------------Despliegue de notas registradas---------------------" << endl; // Encabezado
    ifstream archivo("notas.dat", ios::binary); // Abrir el archivo para lectura en modo binario
    if (!archivo) { // Si no se pudo abrir el archivo
        cout << "No hay notas registradas." << endl; // Mensaje de error
        return; // Salir de la función
    }

    notas nota; // Declarar una variable para almacenar la nota actual
    while (archivo.read(reinterpret_cast<char*>(&nota), sizeof(notas))) { // Leer cada registro de nota del archivo
        // Mostrar los detalles de la nota
        cout << "Código del estudiante: " << nota.codigoEstudiante << endl;
        cout << "Nombre del estudiante: " << nota.nombreEstudiante << endl;
        cout << "Nombre del curso: " << nota.nombreCurso << endl;
        cout << "Nota: " << nota.nota << endl;
        cout << "-----------------------------" << endl; // Separador entre notas
    }

    archivo.close(); // Cerrar el archivo

    cout << "Presione Enter para continuar..."; // Mensaje para el usuario
    cin.ignore(); // Ignorar cualquier entrada adicional
    cin.get(); // Esperar a que el usuario presione Enter para continuar
}

