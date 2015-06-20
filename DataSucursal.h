#ifndef DATASUCURSAL_H
#define DATASUCURSAL_H

#include <string>
#include "interfaces/ICollection.h"
#include "interfaces/IDictionary.h"
#include "interfaces/ICollectible.h"

using namespace std;

class DataSucursal: public ICollectible
{
    public:
		DataSucursal();
        DataSucursal(string nombre, string direccion, string telefono, IDictionary *secciones);
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
