#include "Bitacora.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <ctime>
#include <stdlib.h>
#include <iomanip>

void Bitacora::ingresoBitacora(string nombre, string aplicacion, string accion)
//Parametros:  nombre: codigo de usuario autenticado.  aplicacion: codigo de aplicacion.  accion: puede ser INS->ingreso
//QRY->consulta UPD->actualizacion DEL->borrado de datos PRN->imprimir
{
	fstream file;
	file.open("Bitacora.dat", ios::binary | ios::app | ios::out );
    time_t now = time(0);
    date_time = ctime(&now);
    file<<std::left<<std::setw(20)<<nombre<<std::left<<std::setw(15)<<aplicacion<<std::left<<std::setw(15)<< accion <<std::left<<std::setw(15)<< date_time;
    file.close();
}
void Bitacora::visualizarBitacora()
{
    system("cls");
    cout<<"\n-------------------------Tabla de Detalles de Bitacora - 1000 -------------------------"<<endl;

	fstream file;
	string texto;
	int total=0;
	file.open("Bitacora.dat",ios::binary | ios::in);
	cout<<"\nNombre" <<setw(22)<< "Aplicacion" <<setw(12)<< "Accion" <<setw(20)<< "Fecha\n\n";
	file >> nombre >> aplicacion >> accion >> date_time;

    while(!file.eof())
    {
        total++;
        getline(file,texto);
        cout<<texto<<endl;
    }
    if(total==0)
    {
        cout<<"\n\t\t\tNo hay informacion...";
    }

    file.close();
    system("pause");
}
