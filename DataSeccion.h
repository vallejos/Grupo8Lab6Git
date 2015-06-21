#ifndef DATASECCION_H
#define DATASECCION_H

#include "DataEncargado.h"
#include "interfaces/ICollectible.h"
#include <string>

using namespace std;

class DataSeccion : public ICollectible
{
    public:
		DataSeccion();
        DataSeccion(string nombre, string interno, DataEncargado *encargado);
        DataSeccion(const DataSeccion &ds);
        ~DataSeccion();
        string getNombre();
        string getInterno();
        DataEncargado *getEncargado();
    private:
        string nombre;
        string interno;
        DataEncargado *encargado;
};

#endif // DATASECCION_H
