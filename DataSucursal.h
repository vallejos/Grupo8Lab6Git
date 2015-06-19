#ifndef DATASUCURSAL_H
#define DATASUCURSAL_H

#include <string>
#include "interfaces/ICollection.h"

using namespace std;

class DataSucursal
{
    public:
		DataSucursal();
        DataSucursal(string nombre, string direccion, string telefono, ICollection *secciones);
        DataSucursal(const DataSucursal &s);
        ~DataSucursal();
        string getNombre();
        string getDireccion();
        string getTelefono();
        ICollection *getSecciones();

    private:
        string nombre;
        string direccion;
        string telefono;
        ICollection *secciones;
};

#endif // DATASUCURSAL_H
