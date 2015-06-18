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
    try {
        OfertaLaboralController *olc = OfertaLaboralController::getInstance();
        string numExpe = olc->getOfertaLaboral()->getNumExpediente();
    	ManejadorEstudiante *me = ManejadorEstudiante::getInstance();
    	return (me->getEstNoInscriptos(numExpe));
    } catch (e) {
        throw e;
    }
}

ICollection* EstudianteController::ListarEstudiantesInscriptosEnOferta()
{
    try {
        OfertaLaboralController *olc = OfertaLaboralController::getInstance();
        string numExpe = olc->getOfertaLaboral()->getNumExpediente();
    	ManejadorEstudiante *me = ManejadorEstudiante::getInstance();
    	return (me->getEstInscriptosEnOferta(numExpe));
    } catch (e) {
        throw e;
    }
}

void EstudianteController::SeleccionarEstudiante(string cedula)
{
    try {
    	ManejadorEstudiante *me = ManejadorEstudiante::getInstance();
    	this->estudiante = me->SeleccionarEstudiante(cedula);
    } catch (e) {
        throw e;
    }
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
    try {
    	ManejadorEstudiante *me = ManejadorEstudiante::getInstance();
    	return (me->getEstudiante);
    } catch (e) {
        throw e;
    }
}

Estudiante* EstudianteController::getEstudiante()
{
    return this->estudiante;
}

void EstudianteController::ModificarEstudiante(string cedula, string nombre, string apellido, string telefono, Date *fechaNacimiento, int creditos, string email, IDictionary *asignaturasAAgregar, IDictionary *asignaturasAEliminar, IDictionary *carrerasAAgregar, IDictionary *carrerasAEliminar)
{
    try {
        ManejadorEstudiante *me = ManejadorEstudiante::getInstance();
        me->ModificarEstudiante(cedula, nombre, apellido, telefono, fechaNacimiento, creditos, email, asignaturasAAgregar, asignaturasAEliminar, carrerasAAgregar, carrerasAEliminar);
    } catch (e) {
        throw e;
    }
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
