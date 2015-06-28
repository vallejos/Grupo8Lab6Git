#ifndef ASIGNATURA_H
#define ASIGNATURA_H

#include <string>
#include "DataAsignatura.h"
#include "interfaces/ICollectible.h"
#include "interfaces/IDictionary.h"

using namespace std;

class Asignatura: public ICollectible
{
    public:
	Asignatura();
        Asignatura(int codigo, string nombre, int creditos);
        Asignatura(const Asignatura &a);
        ~Asignatura();
        int getCodigo();
        string getNombre();
        int getCreditos();
        IDictionary* getCarreras();
        void setCodigo(int codigo);
        void setNombre(string nombre);
        void setCreditos(int creditos);
        void setCarreras(IDictionary* carreras);
        DataAsignatura *getDataAsignatura();

    private:
        int codigo;
        string nombre;
        int creditos;
        IDictionary* carreras;
};

#endif // ASIGNATURA_H
