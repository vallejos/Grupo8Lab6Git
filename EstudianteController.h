#ifndef ESTUDIANTECONTROLLER_H
#define ESTUDIANTECONTROLLER_H

#include <string>
#include "interfaces/ICollection.h"
#include "DataEstudiante.h"
#include "DataDatosEstudiante.h"
#include "Estudiante.h"
#include "IEstudianteController.h"
#include "IDictionary.h"

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
        IDictionary *ListarEstudiantesNoInscriptos();
        IDictionary *ListarEstudiantesInscriptosEnOferta();
        void SeleccionarEstudiante(string cedula, IDictionary *estudiantesValidos);
        void ModificarEstudiante(string cedula, string nombre, string apellido, string telefono, Date *fechaNacimiento, int creditos, string email, ICollection *aprobacionesAAgregar, IDictionary *asignaturasAEliminar, IDictionary *carrerasAAgregar, IDictionary *carrerasAEliminar);
        DataDatosEstudiante *ConsultarDatosEstudiante(string cedula);
        IDictionary *ListarEstudiantesRegistrados();
        Estudiante* getEstudiante();
        IDictionary* getAsignaturas();
        IDictionary* getCarreras();
        void destroyEstudianteController();
};

#endif // ESTUDIANTECONTROLLER_H
