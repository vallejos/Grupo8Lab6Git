#include "EstudianteController.h"
#include "OfertaLaboralController.h"
#include "OfertaLaboral.h"

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
    OfertaLaboralController *olc = OfertaLaboralController::getInstance();
    string numExpe = olc->getOfertaLaboral()->getNumExpediente();
	ManejadorEstudiante *me = ManejadorEstudiante::getInstance();
	return (me->getEstNoInscriptos(numExpe));
}

ICollection* EstudianteController::ListarEstudiantesInscriptosEnOferta()
{
    OfertaLaboralController *olc = OfertaLaboralController::getInstance();
    string numExpe = olc->getOfertaLaboral()->getNumExpediente();
	ManejadorEstudiante *me = ManejadorEstudiante::getInstance();
	return (me->getEstInscriptosEnOferta(numExpe));
}

void EstudianteController::SeleccionarEstudiante(string cedula)
{
	ManejadorEstudiante *me = ManejadorEstudiante::getInstance();
	this->estudiante = me->SeleccionarEstudiante(cedula);
}

DataDatosEstudiante* EstudianteController::ConsultarDatosEstudiante(string cedula)
{
    try
    {
        ManejadorEstudiante *me = ManejadorEstudiante::getInstance();
        Estudiante *e = me->SeleccionarEstudiante(cedula);
        return (e->getDataDatosEstudiante());
    }
    catch(const std::invalid_argument &e)
    {
    	throw std::invalid_argument(e.what());
    }
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

void EstudianteController::ModificarEstudiante(string cedula, DataEstudiante* nuevosDatos)
{
    ManejadorEstudiante *me = ManejadorEstudiante::getInstance();
    me->ModificarEstudiante(cedula, nuevosDatos);
}

IDictionary* EstudianteController::getAsignaturas()
{
    ManejadorEstudiante *me = ManejadorEstudiante::getInstance();
    return me->getAsignaturas();
}

IDictionary* EstudianteController::getCarreras()
{
    ManejadorEstudiante *me = ManejadorEstudiante::getInstance();
    return me->getCarreras();
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
