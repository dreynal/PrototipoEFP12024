#include "colegiatura.h"
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <sstream>

using namespace std;

bool colegiatura::validarID(const std::string& idEstudiante) {
    ifstream archivo("Alumnos.dat", ios::binary);
    if (!archivo) {
        cerr << "Error al abrir el archivo de alumnos." << endl;
        return false;
    }

    Alumno alumno;
    bool encontrado = false;

    while (archivo.read(reinterpret_cast<char*>(&alumno), sizeof(Alumno))) {
        if (alumno.id == idEstudiante) {
            encontrado = true;
            break;
        }
    }

    archivo.close();
    return encontrado;
}

string colegiatura::leerDatos() {
    string idIngresado;

    while (true) {
        cout << "Ingrese el carnet del estudiante: ";
        cin >> idIngresado;

        if (validarID(idIngresado)) {
            cout << "El ID ingresado es válido." << endl;
            break;
        } else {
            cout << "El carnet ingresado es inválido." << endl;
            char opcion;
            cout << "Desea volver a intentar? (S/N): ";
            cin >> opcion;
            if (opcion == 'N' || opcion == 'n') {
                return "";
            }
        }
    }

    cout << "\n1. Colegiatura cursos" << endl;
    cout << "2. Regresar al menu principal" << endl;
    cout << "Opciones a escoger: [1/2]" << endl;
    cout << "Seleccione: ";
    int opcionPago;
    cin >> opcionPago;

    if (opcionPago == 1) {
        procesarColegiaturaCursos(idIngresado);
    } else {
        cout << "Opción no implementada todavía." << endl;
    }

    return "";
}

void colegiatura::procesarColegiaturaCursos(const string& idIngresado) {
    string fechaHoy, semestre, mes, anio;

    cout << "Ingrese la fecha de hoy (dd/mm/yyyy): ";
    cin >> fechaHoy;
    cout << "Ingrese el semestre que cursa (1-10): ";
    cin >> semestre;
    cout << "Ingrese el mes de la colegiatura (enero-diciembre): ";
    cin >> mes;
    cout << "Ingrese el año (2023-2024): ";
    cin >> anio;

    cout << "\n\t--------- Monto de la colegiatura: Q825 ---------\n" << endl;
    cout << "Presione una tecla para continuar..." << endl;
    cin.ignore();  // Limpia el buffer de entrada
    cin.get();  // Espera a que el usuario presione una tecla

    pagarEnLinea(825, fechaHoy, semestre, mes, anio, idIngresado);
}

void colegiatura::pagarEnLinea(int monto, const string& fechaHoy, const string& semestre, const string& mes, const string& anio, const string& idIngresado) {
    // Limpiar la pantalla
    system("cls");

    // Captura de los datos de la tarjeta
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

    // Abrir el archivo de la tarjeta
    ifstream archivo("tarjeta.txt");
    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo tarjeta.txt." << endl;
        return;
    }

    // Leer los datos de la tarjeta desde el archivo
    string numeroTarjeta, fechaExpiracion, codigoSeguridad;
    int saldo;
    getline(archivo, numeroTarjeta);
    getline(archivo, fechaExpiracion);
    getline(archivo, codigoSeguridad);
    archivo >> saldo;
    archivo.close();

    // Eliminar espacios en blanco al principio y al final de las cadenas
    auto trim = [](string& str) {
        str.erase(0, str.find_first_not_of(' '));       // quitar espacios al inicio
        str.erase(str.find_last_not_of(' ') + 1);       // quitar espacios al final
    };
    trim(numTarjeta);
    trim(fExpiracion);
    trim(codSeguridad);
    trim(numeroTarjeta);
    trim(fechaExpiracion);
    trim(codigoSeguridad);

    // Comparar los datos ingresados con los del archivo
    if (numTarjeta != numeroTarjeta || fExpiracion != fechaExpiracion || codSeguridad != codigoSeguridad) {
        cout << "Datos de la tarjeta incorrectos." << endl;
        char opcion;
        cout << "Desea volver a intentar? (S/N): ";
        cin >> opcion;
        if (opcion == 'S' || opcion == 's') {
            pagarEnLinea(monto, fechaHoy, semestre, mes, anio, idIngresado);
        }
        return;
    }

    // Verificar si hay saldo suficiente
    if (saldo >= monto) {
        cout << "\n¡Pago realizado en línea con éxito!" << endl;
        cout << "Monto pagado: Q" << monto << endl;
        cout << "Saldo disponible en la tarjeta: Q" << saldo - monto << endl;

        // Actualizar el saldo en el archivo de la tarjeta
        ofstream archivoSalida("tarjeta.txt");
        if (!archivoSalida.is_open()) {
            cout << "Error: No se pudo abrir el archivo tarjeta.txt para escribir." << endl;
            return;
        }

        archivoSalida << numeroTarjeta << endl;
        archivoSalida << fechaExpiracion << endl;
        archivoSalida << codigoSeguridad << endl;
        archivoSalida << saldo - monto << endl;
        archivoSalida.close();

        // Mostrar comprobante de pago
        string numeroBoleta = generarNumeroBoleta();
        string nombreEstudiante;
        obtenerDatosEstudiante(idIngresado, nombreEstudiante);

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
        cout << "\n¡No hay fondos suficientes en la tarjeta para realizar el pago!" << endl;
        cout << "Saldo disponible en la tarjeta: Q" << saldo << endl;
    }
    system("pause");
}

string colegiatura::generarNumeroBoleta() {
    srand(time(0));
    stringstream ss;
    for (int i = 0; i < 12; ++i) {
        if (i > 0 && i % 4 == 0) {
            ss << '-';
        }
        ss << rand() % 10;
    }
    return ss.str();
}

void colegiatura::obtenerDatosEstudiante(const string& idEstudiante, string& nombreEstudiante) {
    ifstream archivo("Alumnos.dat", ios::binary);
    if (!archivo) {
        cerr << "Error al abrir el archivo de alumnos." << endl;
        return;
    }
    Alumno alumno;
    bool encontrado = false;

    while (archivo.read(reinterpret_cast<char*>(&alumno), sizeof(Alumno))) {
        if (alumno.id == idEstudiante) {
            nombreEstudiante = alumno.nombre;
            encontrado = true;
            break;
        }
    }

    archivo.close();

    if (!encontrado) {
        cerr << "No se encontró al estudiante con el ID proporcionado." << endl;
    }
}



/*
void colegiatura::menu(){
    string carnet, trimestre, anio, mes;
int choice;

	do
    {
	system("cls");

	cout<<"\t\t\t------------------------------------"<<endl;
	cout<<"\t\t\t|     201-Colegiatura Cursos       |"<<endl;
	cout<<"\t\t\t------------------------------------"<<endl;
	cout<<"\t\t\t No. de Carnet: "<<endl;
	cin >> carnet;
	cout<<"\t\t\t Semestre/Trimestre(1/2/3/4/5/6/7/8): "<<endl;
	cin >> trimestre;
	cout<<"\t\t\t Anio(2024/2023/2022/2021/2020): "<<endl;
	cin >> anio;
	cout<<"\t\t\t Mes(ene/feb/mar/abr/may/jun/jul/ago/sept/oct/nov/dic): "<<endl;
	cin >> mes;
	cout<<"\t\t\t 4. Exit"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    	{
    		//insertar();
    	}
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		cin.get();
	}
  }while(choice!= 4);
}
*/
