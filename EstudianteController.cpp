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

ICollection* EstudianteController::ListarEstudiantesNoInscriptos()
{
	ManejadorEstudiante *me = ManejadorEstudiante::getInstance();
	return (me->getEstNoInscriptos);
}

ICollection* EstudianteController::ListarEstudiantesInscriptosEnOferta()
{
	ManejadorEstudiante *me = ManejadorEstudiante::getInstance();
	return (me->getEstInscriptosEnOferta);
}

void EstudianteController::SeleccionarEstudiante(string cedula)
{
	ManejadorEstudiante *me = ManejadorEstudiante::getInstance();
	this->estudiante = me->SeleccionarEstudiante(cedula);
}

DataDatosEstudiante* EstudianteController::ConsultarDatosEstudiante(string cedula)
{
	ManejadorEstudiante *me = ManejadorEstudiante::getInstance();
    Estudiante *e = me->SeleccionarEstudiante(cedula);
    return (e->getDataDatosEstudiante());
}

ICollection* EstudianteController::ListarEstudiantesRegistrados()
{
	ManejadorEstudiante *me = ManejadorEstudiante::getInstance();
	return (me->getEstudiante);
}

Estudiante* EstudianteController::getEstudiante()
{
    return this->estudiante;
}

void EstudianteController::destroyEstudianteController()
{
     if (instance != NULL)
     {
        delete EstudianteController;
     }
}

EstudianteController::~EstudianteController()
{
    //dtor
    delete instance;
    instance = NULL;
}
