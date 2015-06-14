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
        DataEstudiante(string cedula, string nombre, string apellido, string telefono, Date *fechaNacimiento, int creditos,
                    string email, IDictionary* carreras, ICollection* aprobadas, ICollection* inscripciones,
                    ICollection* entrevistas);
        DataEstudiante(const DataEstudiante &e);
        ~DataEstudiante();
        string getCedula();
        string getNombre();
        string getApellido();
        string getTelefono();
        Date *getFechaNacimiento();
        int getCreditos();
        string getEmail();
        IDictionary* getCarreras();
        ICollection* getAprobadas();
        ICollection* getInscripciones();
        ICollection* getEntrevistas();
    private:
        string cedula;
        string nombre;
        string apellido;
        string telefono;
        Date *fechaNacimiento;
        int creditos;
        string email;
        IDictionary* carreras;
        ICollection* aprobadas;
        ICollection* inscripciones;
        ICollection* entrevistas;
};

#endif // DTESTUDIANTE_H
