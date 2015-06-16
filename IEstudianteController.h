#ifndef IESTUDIANTECONTROLLER_H
#define IESTUDIANTECONTROLLER_H

#include <string>
#include "DataEstudiante.h"
#include "DataDatosEstudiante.h"
#include "ICollection.h"

class IEstudianteController {
    public:
        IEstudianteController() = 0;
        ~IEstudianteController() = 0;
        ICollection *ListarEstudiantesNoInscriptos() = 0;
        void SeleccionarEstudiante(string cedula) = 0;
        void ModificarEstudiante(string cedula, DataEstudiante* nuevosDatos) = 0;
        DataDatosEstudiante *ConsultarDatosEstudiante(string cedula) = 0;
        ICollection *ListarEstudiantesRegistrados() = 0;
        ICollection *ListarEstudiantesInscriptosEnOferta() = 0;
    protected:
    private:
};

#endif // IESTUDIANTECONTROLLER_H
