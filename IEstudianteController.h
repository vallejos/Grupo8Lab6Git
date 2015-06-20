#ifndef IESTUDIANTECONTROLLER_H
#define IESTUDIANTECONTROLLER_H

#include <string>
#include "DataEstudiante.h"
#include "DataDatosEstudiante.h"
#include "interfaces/ICollection.h"
#include "interfaces/IDictionary.h"
#include "Estudiante.h"

class IEstudianteController {
    public:
        IEstudianteController();
        virtual ~IEstudianteController() = 0;
        virtual IDictionary *ListarEstudiantesNoInscriptos() = 0;
        virtual void SeleccionarEstudiante(string cedula, IDictionary *estudiantesValidos) = 0;
        virtual void ModificarEstudiante(string cedula, string nombre, string apellido, string telefono,
                                        Date *fechaNacimiento, int creditos, string email, ICollection *aprobacionesAAgregar,
                                        IDictionary *asignaturasAEliminar, IDictionary *carrerasAAgregar, IDictionary *carrerasAEliminar) = 0;
        virtual DataDatosEstudiante *ConsultarDatosEstudiante(string cedula) = 0;
        virtual IDictionary *ListarEstudiantesRegistrados() = 0;
        virtual IDictionary *ListarEstudiantesInscriptosEnOferta() = 0;
        virtual IDictionary* EstudianteCumpleRequisitos(Estudiante* student, IDictionary* asignaturasOferta) = 0;
        virtual Estudiante *getEstudiante() = 0;
        virtual IDictionary *getEstudiantes() = 0;
};

#endif // IESTUDIANTECONTROLLER_H
