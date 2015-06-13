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
        ~EstudianteController();
    public:
        static EstudianteController* getInstance();
        ICollection *ListarEstudiantesNoInscriptos();
        ICollection *ListarEstudiantesInscriptosEnOferta();
        void SeleccionarEstudiante(String cedula);
        DataDatosEstudiante *ConsultarDatosEstudiante(String cedula);
        ICollection *ListarEstudiantesRegistrados();
        Estudiante* getEstudiante();
        void destroyEstudianteController();
};

#endif // ESTUDIANTECONTROLLER_H
