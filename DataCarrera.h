#ifndef DTCARRERA_H
#define DTCARRERA_H

#include <string>
#include "interfaces/ICollectible.h"

using namespace std;

class DataCarrera : public ICollectible
{
    public:
		DataCarrera();
        DataCarrera(int codigo, string nombre);
        DataCarrera(const DataCarrera &a);
        ~DataCarrera();
        int getCodigo();
        string getNombre();

    private:
        int codigo;
        string nombre;
};

#endif // DTCARRERA_H
