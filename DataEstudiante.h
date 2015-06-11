#ifndef DTESTUDIANTE_H
#define DTESTUDIANTE_H

#include "DataAsignatura.h"
#include "DataCarrera.h"
#include "Date.h"
#include <string>

using namespace std;

class DataEstudiante
{
    public:
		DataEstudiante();
        DataEstudiante(string cedula, string nombre, string apellido, string telefono, Date *fechaNacimiento, int creditos);
        DataEstudiante(const DataEstudiante &e);
        ~DataEstudiante();
        string getCedula();
        string getNombre();
        string getApellido();
        string getTelefono();
        Date *getFechaNacimiento();
        int getCreditos();
        DataAsignatura ** getAsignaturas();
        DataCarrera ** getCarreras();
    private:
        string cedula;
        string nombre;
        string apellido;
        string telefono;
        Date *fechaNacimiento;
        int creditos;
        DataAsignatura ** asignaturas;
        DataCarrera ** carreras;
};

#endif // DTESTUDIANTE_H
