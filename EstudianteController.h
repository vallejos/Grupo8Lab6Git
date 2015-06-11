#ifndef ESTUDIANTECONTROLLER_H
#define ESTUDIANTECONTROLLER_H

#include <string>
#include "ICollection.h"

using namespace std;

//Singleton
class EstudianteController
{
    private:
        EstudianteController();
        Estudiante *estudiante; // el estudiante que se recuerda
        static EstudianteController* instance;
    public:
        static EstudianteController* getInstance();
        ICollection *ListarEstudiantesNoInscriptos();
        void SeleccionarEstudiante(String cedula);
        DataDatosEstudiante *ConsultarDatosEstudiante(String cedula);
        ICollection *ListarEstudiantesRegistrados();
        Estudiante* getEstudiante();
        ~EstudianteController();
};

#endif // ESTUDIANTECONTROLLER_H
