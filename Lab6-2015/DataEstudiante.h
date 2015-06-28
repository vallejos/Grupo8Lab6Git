#ifndef DTESTUDIANTE_H
#define DTESTUDIANTE_H

#include "DataAsignatura.h"
#include "DataCarrera.h"
#include "Date.h"
#include <string>
#include "interfaces/IDictionary.h"
#include "interfaces/ICollection.h"
#include "interfaces/ICollectible.h"

using namespace std;

class DataEstudiante: public ICollectible
{
    public:
        DataEstudiante(string cedula, string nombre, string apellido, string telefono, Date *fechaNacimiento, int creditos,
                    string email, IDictionary* carreras, ICollection* aprobadas, ICollection* inscripciones,ICollection* entrevistas);
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
