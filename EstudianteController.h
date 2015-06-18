#ifndef ESTUDIANTECONTROLLER_H
#define ESTUDIANTECONTROLLER_H

#include <string>
#include "ICollection.h"
#include "DataEstudiante.h"
#include "DataDatosEstudiante.h"
#include "Estudiante.h"

using namespace std;

//Singleton
class EstudianteController : public IEstudianteController
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
        void SeleccionarEstudiante(string cedula);
        void ModificarEstudiante(string cedula, DataEstudiante* nuevosDatos);
        DataDatosEstudiante *ConsultarDatosEstudiante(string cedula);
        ICollection *ListarEstudiantesRegistrados();
        Estudiante* getEstudiante();
        IDictionary* getAsignaturas();
        IDictionary* getCarreras();
        void destroyEstudianteController();
};

#endif // ESTUDIANTECONTROLLER_H
