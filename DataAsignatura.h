#ifndef DATAASIGNATURA_H
#define DATAASIGNATURA_H

#include <string>

using namespace std;

class DataAsignatura
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
