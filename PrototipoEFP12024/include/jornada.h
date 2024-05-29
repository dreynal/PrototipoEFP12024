#ifndef JORNADA_H
#define JORNADA_H
//blibliotecas
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;

struct Jornada{
    int codigo;
    char nombre[50];
};
class JornadaCRUD {
public:
    void Ingresar();
    void Modificar();
    void Borrar();
    void Desplegar();
    void CrudJornada();

};

#endif // JORNADA_H
