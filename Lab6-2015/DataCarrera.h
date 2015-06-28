#ifndef DTCARRERA_H
#define DTCARRERA_H

#include <string>
#include "interfaces/ICollectible.h"
#include "Asignatura.h"
#include "interfaces/IDictionary.h"

using namespace std;

class DataCarrera : public ICollectible
{
    public:
	DataCarrera();
        DataCarrera(int codigo, string nombre, IDictionary* asignaturas);
        DataCarrera(const DataCarrera &a);
        ~DataCarrera();
        int getCodigo();
        string getNombre();
        IDictionary* getAsignaturas();

    private:
        int codigo;
        string nombre;
        IDictionary* asignaturas;

};

#endif // DTCARRERA_H
