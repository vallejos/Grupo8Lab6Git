#ifndef DATAASIGNATURA_H
#define DATAASIGNATURA_H

#include <string>
#include "interfaces/ICollectible.h"
#include "interfaces/ICollection.h"
#include "interfaces/IDictionary.h"

using namespace std;

class DataAsignatura : public ICollectible
{
    public:
        DataAsignatura();
        DataAsignatura(int codigo, string nombre, int creditos, IDictionary *carreras);
        DataAsignatura(const DataAsignatura &da);
        ~DataAsignatura();
        int getCodigo();
        string getNombre();
        int getCreditos();
        IDictionary *getCarreras();

    private:
        int codigo;
        string nombre;
        int creditos;
        IDictionary *carreras;
};

#endif // DATAASIGNATURA_H
