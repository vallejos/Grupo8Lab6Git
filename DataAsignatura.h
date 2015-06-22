#ifndef DATAASIGNATURA_H
#define DATAASIGNATURA_H

#include <string>
#include "interfaces/ICollectible.h"
#include "interfaces/ICollection.h"

using namespace std;

class DataAsignatura : public ICollectible
{
    public:
		DataAsignatura();
        DataAsignatura(int codigo, string nombre, int creditos);
        DataAsignatura(const DataAsignatura &da);
        ~DataAsignatura();
        int getCodigo();
        string getNombre();
        int getCreditos();

    private:
        int codigo;
        string nombre;
        int creditos;
};

#endif // DATAASIGNATURA_H
