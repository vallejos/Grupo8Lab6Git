#ifndef DTEMPRESA_H
#define DTEMPRESA_H
#include "DataSucursal.h"
#include <string>

using namespace std;

class DataEmpresa
{
    public:
		DataEmpresa();
        DataEmpresa(string rut, string nombre);
        DataEmpresa(const DataEmpresa &e);
        ~DataEmpresa();
        string getRut();
        string getNombre();
        ICollection* getSucursal();
    private:
        string rut;
        string nombre;
        ICollection* sucursales;
};

#endif // DTEMPRESA_H
