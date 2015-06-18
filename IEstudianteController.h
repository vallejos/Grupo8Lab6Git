#ifndef IESTUDIANTECONTROLLER_H
#define IESTUDIANTECONTROLLER_H

#include <string>
#include "DataEstudiante.h"
#include "DataDatosEstudiante.h"
#include "interfaces/ICollection.h"

class IEstudianteController {
    public:
        IEstudianteController() = 0;
        virtual ~IEstudianteController() = 0;
        void ModificarEstudiante(
        virtual ICollection *ListarEstudiantesNoInscriptos() = 0;
        virtual void SeleccionarEstudiante(string cedula) = 0;
        virtual void ModificarEstudiante(string cedula, string nombre, string apellido, string telefono,
                                        Date *fechaNacimiento, int creditos, string email, IDictionary *asignaturasAAgregar,
                                        IDictionary *asignaturasAEliminar, IDictionary *carrerasAAgregar, IDictionary *carrerasAEliminar) = 0;
        virtual DataDatosEstudiante *ConsultarDatosEstudiante(string cedula) = 0;
        virtual ICollection *ListarEstudiantesRegistrados() = 0;
        virtual ICollection *ListarEstudiantesInscriptosEnOferta() = 0;
        virtual IDictionary* getAsignaturas() = 0;
        virtual IDictionary* getCarreras() = 0;
};

#endif // IESTUDIANTECONTROLLER_H
