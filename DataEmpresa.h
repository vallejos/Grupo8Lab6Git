#ifndef DTEMPRESA_H
#define DTEMPRESA_H
#include "DataSucursal.h"
#include <string>
#include "interfaces/ICollectible.h"
#include "interfaces/IDictionary.h"

using namespace std;

class DataEmpresa: public ICollectible
{
    public:
	DataEmpresa();
        DataEmpresa(string rut, string nombre, IDictionary* sucursales);
        DataEmpresa(const DataEmpresa &e);
        ~DataEmpresa();
        string getRut();
        string getNombre();
        IDictionary* getSucursal();

    private:
        string rut;
        string nombre;
        IDictionary* sucursales;
};

#endif // DTEMPRESA_H
