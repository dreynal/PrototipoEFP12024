#ifndef BITACORA_H
#define BITACORA_H
#include <iostream>


using namespace std;
class Bitacora
{
    public:
        void ingresoBitacora(string nombre, string aplicacion, string accion);
        void visualizarBitacora();

    private:
        string nombre, accion, aplicacion;
		char* date_time;
};

#endif // BITACORA_H
