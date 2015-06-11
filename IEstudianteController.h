#ifndef IESTUDIANTECONTROLLER_H
#define IESTUDIANTECONTROLLER_H

#include <string>
#include "DataEstudiante.h"
#include "DataDatosEstudiante.h"

class IEstudianteController {
    public:
        IEstudianteController();
        ~IEstudianteController();
        DataEstudiante **ListarEstudiantesNoInscriptos();
        void SeleccionarEstudiante(string cedula);
        DataDatosEstudiante **ConsultarDatosEstudiante(string cedula);
        DataEstudiante **ListarEstudiantesRegistrados();
    protected:
    private:
};

#endif // IESTUDIANTECONTROLLER_H