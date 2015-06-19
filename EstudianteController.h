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
        ICollection *ListarEstudiantesNoInscriptos();
        ICollection *ListarEstudiantesInscriptosEnOferta();
        void SeleccionarEstudiante(string cedula, IDictionary *estudiantesValidos);
        void ModificarEstudiante(string cedula, string nombre, string apellido, string telefono, Date *fechaNacimiento, int creditos, string email, IDictionary *asignaturasAAgregar, IDictionary *asignaturasAEliminar, IDictionary *carrerasAAgregar, IDictionary *carrerasAEliminar);
        DataDatosEstudiante *ConsultarDatosEstudiante(string cedula);
        ICollection *ListarEstudiantesRegistrados();
        Estudiante* getEstudiante();
        IDictionary* getAsignaturas();
        IDictionary* getCarreras();
        void destroyEstudianteController();
};

#endif // ESTUDIANTECONTROLLER_H
