#ifndef EMPRESA_H
#define EMPRESA_H

#include <string>
#include "DataSucursal.h"
#include "Sucursal.h"
#include "interfaces/ICollectible.h"
#include "interfaces/ICollection.h"

class Empresa: public ICollectible {
    public:
        Empresa();
        Empresa(string rut, string nombre);
        ~Empresa();
        string getRut();
        string getNombre();
        ICollection *getDataSucursales(); // DataSucursal
        Sucursal *getSucursal(string nombre);

    private:
        string rut;
        string nombre;
        ICollection *sucursales;
};

#endif // EMPRESA_H
