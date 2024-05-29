

#ifndef HORARIOS_H
#define HORARIOS_H

// La estructura Horario representa un horario con un identificador, nombre y descripción.
struct Horario {
        char id[11];       // Identificador del horario.
        char nombre[11];   // Nombre del horario.
        char Jornada [11];
        char Horario[11];  // Descripción del horario.
    };

// La clase Horarios maneja operaciones relacionadas con horarios.
class Horarios {
public:
    // Muestra el menú de opciones para el usuario.
    void menu();

    // Inserta un nuevo horario en la estructura.
    void insertar();

    // Despliega todos los horarios almacenados.
    void desplegar();

    // Modifica un horario existente.
    void modificar();

    // Borra un horario existente.
    void borrar();

    Horario horario;  // Instancia de la estructura Horario.
};

#endif // HORARIOS_H
