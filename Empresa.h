#ifndef EMPRESA_H
#define EMPRESA_H

#include <string>
#include "DataSucursal.h"
#include "interfaces/ICollectible.h"
#include "interfaces/ICollection.h"

class Sucursal;

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

#include "Sucursal.h"

#endif // EMPRESA_H

