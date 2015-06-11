#ifndef EMPRESA_H
#define EMPRESA_H

#include <string>
#include "DataSucursal.h"
#include "Sucursal.h"
#include "lab6-colecciones/interfaces/ICollectible.h"
#include "lab6-colecciones/interfaces/ICollection.h"

class Empresa: public ICollectible {
    public:
        Empresa();
        Empresa(string rut, string nombre);
        ~Empresa();
        string getRut();
        string getNombre();
        ICollection *getDataSucursales(); // DataSucursal
        Sucursal *getSucursal(string nombre);
    protected:
    private:
        string rut;
        string nombre;
        ICollection *sucursales;
};

#endif // EMPRESA_H