#ifndef ASIGNATURA_H
#define ASIGNATURA_H

#include <string>
#include "DataAsignatura.h"
#include "interfaces/ICollectible.h"

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
        void setCodigo(int codigo);
        void setNombre(string nombre);
        void setCreditos(int creditos);
        DataAsignatura *getDataAsignatura();

    private:
        int codigo;
        string nombre;
        int creditos;
};

#endif // ASIGNATURA_H
