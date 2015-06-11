#include "EstudianteController.h"

EstudianteController::EstudianteController()
{
 //constructor
}

EstudianteController* EstudianteController::instance = NULL;

EstudianteController* EstudianteController::getInstance()
{
    if (instance=NULL)
        instance = new EstudianteController;
    return instance;
}

ICollection *ListarEstudiantesNoInscriptos()
{
	ManejadorEstudiante *me = ManejadorEstudiante::getInstance();
	return (me->getEstNoInscriptos);
}

void SeleccionarEstudiante(string cedula)
{
	ManejadorEstudiante *me = ManejadorEstudiante::getInstance();
	this->estudiante = me->SeleccionarEstudiante(cedula);
}

DataDatosEstudiante *ConsultarDatosEstudiante(string cedula)
{
	ManejadorEstudiante *me = ManejadorEstudiante::getInstance();
    Estudiante *e = me->SeleccionarEstudiante(cedula);
    return (e->getDataDatosEstudiante());
}

ICollection *ListarEstudiantesRegistrados()
{
	ManejadorEstudiante *me = ManejadorEstudiante::getInstance();
	return (me->getEstudiante);
}

Estudiante* EstudianteController::getEstudiante()
{
    return this->estudiante;
}


EstudianteController::~EstudianteController()
{
    //dtor
    delete instance;
    instance = NULL;
}
