#ifndef DTENCARGADO_H
#define DTENCARGADO_H

#include "Date.h"
#include <string>

using namespace std;

class DataEncargado
{
    public:
		DataEncargado();
        DataEncargado(string cedula, string nombre, string apellido, Date *fechaNacimiento);
        DataEncargado(const DataEncargado &e);
        ~DataEncargado();
        string getCedula();
        string getNombre();
        string getApellido();
        Date *getFechaNacimiento();
    private:
        string cedula;
        string nombre;
        string apellido;
        Date *fechaNacimiento;
};

#endif // DTENCARGADO_H
