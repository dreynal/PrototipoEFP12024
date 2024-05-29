
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "usuarios.h"
#include "Login.h"
#include "Bitacora.h"

#include "alumnos.h"
#include "maestros.h"
#include "Carrera.h"
#include "Facultad.h"
#include "Cursoss.h"
#include "jornada.h"
#include "aulas.h"
#include "secciones.h"
#include "Sedes.h"
#include "Horarios.h"

#include "matricula.h"
#include "Inscripcion.h"
#include "colegiatura.h"
#include "sueldos.h"

using namespace std;

void menuGeneral();
void catalogos();
void reportes();
void procesos();
void ayuda();
void seguridad();
string codigoPrograma="1";
Bitacora Auditoria;
string user, contrasena;

int main()
{
        // Llamamos al objeto e ingresamos los parametros
    Login ingreso(user, contrasena);

    // Creamos un bool que verifique y despliegue el metodo VerificarUsuario
    bool UsuarioCorrecto = ingreso.VerificarUsuario();

    // Luego de ingresar con usuario y contraseña se nos despliega otro menu
    if (UsuarioCorrecto)
    {
        menuGeneral();
    }

    return 0;
}

void menuGeneral()
{
    int choice;


    do
    {
        system("cls");
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t|   SISTEMA DE GESTION UMG     |" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t 1. Catalogos" << endl;
        cout << "\t\t\t 2. Procesos" << endl;
        cout << "\t\t\t 3. Reportes" << endl;
        cout << "\t\t\t 4. Seguridad" << endl;
        cout << "\t\t\t 5. Ayuda" << endl;
        cout << "\t\t\t 6. Salir del Sistema" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t|Opcion a escoger:[1/2/3/4/5/6]  |" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opcion: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            catalogos();
            break;
        case 2:
            procesos();
            break;
        case 3:
            reportes();
            break;
        case 4:
            seguridad();
            break;
        case 5:
            ayuda();
            break;
        case 6:
                    Auditoria.ingresoBitacora(user,codigoPrograma,"LGO"); //llamada para registrar la bitacora de seguridad
            exit(0);
        default:
            cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
        }
    } while (choice != 6);
}

void catalogos()
{
    int choice;

    do
    {
        system("cls");
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t|   SISTEMA DE GESTION UMG - CATALOGOS      |" << endl;
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t 1. Usuarios del sistema" << endl;
        cout << "\t\t\t 2. Jornadas" << endl;
        cout << "\t\t\t 3. Horarios" << endl;
        cout << "\t\t\t 4. Retornar menu anterior" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\t | Opcion a escoger:[1-12]|" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opcion: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            usuarios usuario;
            usuario.menuUsuarios();
            break;
        }
        case 2:
        {
            JornadaCRUD jornada;
            jornada.CrudJornada();
        }
            break;
        case 3:
        {
            Horarios horarios;
            horarios.menu();
        }
            break;
        case 4:
            menuGeneral();
            break;
        default:
            cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
        }
    } while (choice != 12);
}

void procesos()
{
    // Implementación de procesos
    int choice;

    do
    {
        system("cls");
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t|   SISTEMA DE GESTION UMG - PROCESOS      |" << endl;
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t 1. Sueldos" << endl;
        cout << "\t\t\t 2. Retornar menu anterior" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\t | Opcion a escoger:[1-5]|" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opcion: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            sueldos sueldos;
            sueldos.menu();
        }
            break;
        case 2:
            menuGeneral();
            break;
        default:
            cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
        }
    } while (choice != 2);
}

void reportes()
{
    // Implementación de reportes
}

void ayuda()
{
    // Implementación de ayuda
}

void seguridad()
{
    // Implementación de seguridad
    Bitacora Auditoria;
    Auditoria.visualizarBitacora();
}
