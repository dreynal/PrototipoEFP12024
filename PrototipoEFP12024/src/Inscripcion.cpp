//Creado por Daniel Reyna Lopez 9959-23-5291

#include "Inscripcion.h"  // Incluye el archivo de cabecera "Inscripcion.h"
#include <fstream>        // Biblioteca para manejo de archivos
#include <iomanip>        // Biblioteca para manipulación de entrada/salida
#include <ctime>          // Biblioteca para funciones de fecha y hora
#include <cstdlib>        // Biblioteca para funciones generales de propósito
#include <sstream>        // Biblioteca para manejo de cadenas y flujos

using namespace std;

// Función que valida si un ID de estudiante existe en el archivo "Alumnos.dat"
bool Inscripcion::validarID(const std::string& idEstudiante) {
    ifstream archivo("Alumnos.dat", ios::binary);  // Abre el archivo en modo binario
    if (!archivo) {  // Verifica si el archivo se abrió correctamente
        cerr << "Error al abrir el archivo de alumnos." << endl;
        return false;
    }

    Alumno alumno;  // Variable para almacenar los datos del alumno
    bool encontrado = false;  // Bandera para indicar si se encontró el ID

    // Lee cada registro del archivo hasta encontrar el ID o llegar al final del archivo
    while (archivo.read(reinterpret_cast<char*>(&alumno), sizeof(Alumno))) {
        if (alumno.id == idEstudiante) {  // Compara el ID leído con el ID ingresado
            encontrado = true;  // Marca como encontrado
            break;  // Sale del bucle
        }
    }

    archivo.close();  // Cierra el archivo
    return encontrado;  // Devuelve true si se encontró, false en caso contrario
}

// Función que lee los datos del estudiante y procesa la Inscripcion
string Inscripcion::leerDatos() {
    string idIngresado;  // Variable para almacenar el ID ingresado

    // Bucle para pedir el ID del estudiante hasta que sea válido
    while (true) {
        cout << "Ingrese el carnet del estudiante: ";
        cin >> idIngresado;

        if (validarID(idIngresado)) {  // Verifica si el ID es válido
            cout << "ID válido." << endl;
            break;  // Sale del bucle si el ID es válido
        } else {
            cout << "carnet inválido." << endl;
            char opcion;
            cout << "Desea volver a intentar? (S/N): ";
            cin >> opcion;
            if (opcion == 'N' || opcion == 'n') {  // Si el usuario elige no reintentar, devuelve una cadena vacía
                return "";
            }
        }
    }

    // Muestra opciones al usuario
    cout << "\n1. Pago de Inscripcion" << endl;
    cout << "2. Regresar al menu principal" << endl;
    cout << "Opciones a escoger: [1/2]" << endl;
    cout << "Seleccione: ";
    int opcionPago;
    cin >> opcionPago;

    // Llama a la función correspondiente según la opción seleccionada
    if (opcionPago == 1) {
        procesarInscripcion(idIngresado);  // Procesa el pago de Inscripcion
    } else {
        cout << "Error. Por favor, intente de nuevo." << endl;  // Mensaje para opción no implementada
    }

    return "";  // Devuelve una cadena vacía
}

// Función que procesa la colegiatura de los cursos
void Inscripcion::procesarInscripcion(const string& idIngresado) {
    string fechaHoy, semestre, mes, anio;

    // Pide al usuario que ingrese los detalles necesarios para el pago
    cout << "Ingrese la fecha de hoy (dd/mm/yyyy): ";
    cin >> fechaHoy;
    cout << "Ingrese el semestre que desea inscribirse (1-10): ";
    cin >> semestre;
    cout << "Ingrese el mes de inscriccion(enero-diciembre): ";
    cin >> mes;
    cout << "Ingrese el año (2023-2024): ";
    cin >> anio;

    // Muestra el monto de la Inscripcion
    cout << "\n\t--------- Monto de Inscripcion: Q745 ---------\n" << endl;
    cout << "Presione una tecla para continuar..." << endl;
    cin.ignore();  // Limpia el buffer de entrada
    cin.get();  // Espera a que el usuario presione una tecla

    // Llama a la función para realizar el pago en línea
    pagarEnLinea(745, fechaHoy, semestre, mes, anio, idIngresado);
}

// Función que procesa el pago en línea
void Inscripcion::pagarEnLinea(int monto, const string& fechaHoy, const string& semestre, const string& mes, const string& anio, const string& idIngresado) {
    // Limpia la pantalla
    system("cls");

    // Pide al usuario los datos de la tarjeta de crédito
    cout << "\n----------------------------------------------------------------------------------------------------------";
    cout << "\n-------------------------------------------DATOS DE LA TARJETA--------------------------------------------" << endl;
    cout << "Ingrese los datos de su tarjeta de crédito para realizar el pago en línea:" << endl;
    string numTarjeta, fExpiracion, codSeguridad;
    cout << "Número de tarjeta: ";
    cin.ignore();  // Limpia el buffer de entrada antes de capturar los datos de la tarjeta
    getline(cin, numTarjeta);
    cout << "Fecha de expiración (MM/AA): ";
    getline(cin, fExpiracion);
    cout << "Código de seguridad: ";
    getline(cin, codSeguridad);

    // Abre el archivo que contiene los datos de la tarjeta
    ifstream archivo("tarjeta.txt");
    if (!archivo.is_open()) {  // Verifica si el archivo se abrió correctamente
        cout << "Error: No se pudo abrir el archivo tarjeta.txt." << endl;
        return;
    }

    // Lee los datos de la tarjeta desde el archivo
    string numeroTarjeta, fechaExpiracion, codigoSeguridad;
    int saldo;
    getline(archivo, numeroTarjeta);
    getline(archivo, fechaExpiracion);
    getline(archivo, codigoSeguridad);
    archivo >> saldo;
    archivo.close();

    // Función lambda para eliminar espacios en blanco al principio y al final de las cadenas
    auto trim = [](string& str) {
        str.erase(0, str.find_first_not_of(' '));  // Quita espacios al inicio
        str.erase(str.find_last_not_of(' ') + 1);  // Quita espacios al final
    };
    trim(numTarjeta);
    trim(fExpiracion);
    trim(codSeguridad);
    trim(numeroTarjeta);
    trim(fechaExpiracion);
    trim(codigoSeguridad);

    // Compara los datos ingresados con los datos leídos del archivo
    if (numTarjeta != numeroTarjeta || fExpiracion != fechaExpiracion || codSeguridad != codigoSeguridad) {
        cout << "Datos de la tarjeta incorrectos." << endl;
        char opcion;
        cout << "Desea volver a intentar? (S/N): ";
        cin >> opcion;
        if (opcion == 'S' || opcion == 's') {  // Si el usuario elige reintentar, llama a la función de nuevo
            pagarEnLinea(monto, fechaHoy, semestre, mes, anio, idIngresado);
        }
        return;  // Sale de la función si los datos son incorrectos
    }

    // Verifica si hay saldo suficiente en la tarjeta
    if (saldo >= monto) {
        cout << "\n¡Pago realizado en línea con éxito!" << endl;
        cout << "Monto pagado: Q" << monto << endl;
        cout << "Saldo disponible en la tarjeta: Q" << saldo - monto << endl;

        // Actualiza el saldo en el archivo de la tarjeta
        ofstream archivoSalida("tarjeta.txt");
        if (!archivoSalida.is_open()) {  // Verifica si el archivo se abrió correctamente para escribir
            cout << "Error: No se pudo abrir el archivo tarjeta.txt para escribir." << endl;
            return;
        }

        archivoSalida << numeroTarjeta << endl;
        archivoSalida << fechaExpiracion << endl;
        archivoSalida << codigoSeguridad << endl;
        archivoSalida << saldo - monto << endl;
        archivoSalida.close();

        // Muestra el comprobante de pago
        string numeroBoleta = generarNumeroBoleta();  // Genera un número de boleta
        string nombreEstudiante;
        obtenerDatosEstudiante(idIngresado, nombreEstudiante);  // Obtiene los datos del estudiante

        cout << "\n----------------------------------------------------------------------------------------------------------";
        cout << "\n-------------------------------------------COMPROBANTE DE PAGO--------------------------------------------" << endl;
        cout << "Número de boleta: " << numeroBoleta << endl;
        cout << "Fecha: " << fechaHoy << endl;
        cout << "Semestre: " << semestre << endl;
        cout << "Mes: " << mes << endl;
        cout << "Año: " << anio << endl;
        cout << "Monto pagado: Q" << monto << endl;
        cout << "Carnet del estudiante: " << idIngresado << endl;
        cout << "Nombre del estudiante: " << nombreEstudiante << endl;
        cout << "----------------------------------------------------------------------------------------------------------" << endl;
    } else {
        // Mensaje si no hay fondos suficientes en la tarjeta
        cout << "\n¡No hay fondos suficientes en la tarjeta para realizar el pago!" << endl;
        cout << "Saldo disponible en la tarjeta: Q" << saldo << endl;
    }
    system("pause");  // Pausa el sistema para esperar que el usuario presione una tecla
}

// Función que genera un número de boleta aleatorio
string Inscripcion::generarNumeroBoleta() {
    srand(time(0));  // Inicializa la semilla para números aleatorios
    stringstream ss;
    for (int i = 0; i < 12; ++i) {
        if (i > 0 && i % 4 == 0) {
            ss << '-';  // Añade un guión cada 4 dígitos
        }
        ss << rand() % 10;  // Añade un dígito aleatorio
    }
    return ss.str();  // Devuelve el número de boleta generado
}

// Función que obtiene los datos del estudiante desde el archivo "Alumnos.dat"
void Inscripcion::obtenerDatosEstudiante(const string& idEstudiante, string& nombreEstudiante) {
    ifstream archivo("Alumnos.dat", ios::binary);  // Abre el archivo en modo binario
    if (!archivo) {  // Verifica si el archivo se abrió correctamente
        cerr << "Error al abrir el archivo de alumnos." << endl;
        return;
    }
    Alumno alumno;  // Variable para almacenar los datos del alumno
    bool encontrado = false;  // Bandera para indicar si se encontró el ID

    // Lee cada registro del archivo hasta encontrar el ID o llegar al final del archivo
    while (archivo.read(reinterpret_cast<char*>(&alumno), sizeof(Alumno))) {
        if (alumno.id == idEstudiante) {  // Compara el ID leído con el ID ingresado
            nombreEstudiante = alumno.nombre;  // Almacena el nombre del estudiante
            encontrado = true;  // Marca como encontrado
            break;  // Sale del bucle
        }
    }

    archivo.close();  // Cierra el archivo

    if (!encontrado) {
        cerr << "No se encontró al estudiante con el ID proporcionado." << endl;  // Mensaje si no se encuentra el estudiante
    }
}
