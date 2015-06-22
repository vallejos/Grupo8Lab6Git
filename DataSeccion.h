#ifndef DATASECCION_H
#define DATASECCION_H

#include "DataEncargado.h"
#include "interfaces/ICollectible.h"
#include <string>
#include "Sucursal.h"
#include "interfaces/ICollection.h"
#include "interfaces/IDictionary.h"

using namespace std;

class DataSeccion : public ICollectible
{
    public:
        DataSeccion();
        DataSeccion(string nombre, string interno, DataEncargado *encargado, Sucursal *sucursal, ICollection *observers, IDictionary *ofertas);
        DataSeccion(const DataSeccion &ds);
        ~DataSeccion();
        string getNombre();
        string getInterno();
        DataEncargado *getEncargado();
    private:
        string nombre;
        string interno;
        DataEncargado *encargado;
        Sucursal *sucursal;
        IDictionary *ofertas;
        ICollection *observers;
};

#endif // DATASECCION_H
