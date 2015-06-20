#include "EstudianteController.h"
#include "OfertaLaboralController.h"
#include "OfertaLaboral.h"

EstudianteController* EstudianteController::instance = NULL;

EstudianteController::EstudianteController()
{
 //constructor
}

EstudianteController* EstudianteController::getInstance()
{
    if (instance=NULL)
        instance = new EstudianteController;
    return instance;
}

IDictionary* EstudianteController::ListarEstudiantesNoInscriptos()
{
    try {
        OfertaLaboralController *olc = OfertaLaboralController::getInstance();
        string numExpe = olc->getOfertaLaboral()->getNumExpediente();
    	ManejadorEstudiante *me = ManejadorEstudiante::getInstance();
    	IDictionary *estNoInsc = me->getEstNoInscriptos(numExpe);
    	if (estudiantesNoInsc == NULL)
            throw std::invalid_argument("No existe un Estudiante no Inscripto a la Oferta Seleccionada");
    	return estNoInsc;
    } catch (e) {
        throw e;
    }
}

IDictionary* EstudianteController::ListarEstudiantesInscriptosEnOferta()
{
    try {
        OfertaLaboralController *olc = OfertaLaboralController::getInstance();
        string numExpe = olc->getOfertaLaboral()->getNumExpediente();
    	ManejadorEstudiante *me = ManejadorEstudiante::getInstance();
    	IDictionary* studentsInsc = me->getEstInscriptosEnOferta(numExpe);
    	return studentsInsc;
    } catch (e) {
        throw e;
    }
}

void EstudianteController::SeleccionarEstudiante(string cedula, IDictionary *estudiantesValidos)
{
    try {
        ManejadorEstudiante *me = ManejadorEstudiante::getInstance();
        String* ci = new String(cedula);
        if(estudiantesValidos->member(ci))
        {
            this->estudiante = me->SeleccionarEstudiante(cedula);
        }
        else
        {
            throw std::invalid_argument("La cédula " + cedula + " es inválida.");
        }


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

IDictionary* EstudianteController::ListarEstudiantesRegistrados()
{
    try {
    	ManejadorEstudiante *me = ManejadorEstudiante::getInstance();
    	IDictionary *estudiantes = me->getEstudiante;
    	if (estudiantes == NULL)
            throw "No existe ningún estudiante dado de alta en el Sistema";
    	return estudiantes;
    } catch (e) {
        throw e;
    }
}

Estudiante* EstudianteController::getEstudiante()
{
    return this->estudiante;
}

void EstudianteController::ModificarEstudiante(string cedula, string nombre, string apellido, string telefono, Date *fechaNacimiento, int creditos, string email, ICollection *aprobacionesAAgregar, IDictionary *asignaturasAEliminar, IDictionary *carrerasAAgregar, IDictionary *carrerasAEliminar)
{
    try {
        ManejadorEstudiante *me = ManejadorEstudiante::getInstance();
        me->ModificarEstudiante(cedula, nombre, apellido, telefono, fechaNacimiento, creditos, email, aprobacionesAAgregar, asignaturasAEliminar, carrerasAAgregar, carrerasAEliminar);
    } catch (e) {
        throw e;
    }
}

IDictionary* EstudianteController::getAsignaturas()
{
    ManejadorEstudiante *me = ManejadorEstudiante::getInstance();
    IDictionary* asigs = me->getAsignaturas();
    return asigs;
}

IDictionary* EstudianteController::getCarreras()
{
    ManejadorEstudiante *me = ManejadorEstudiante::getInstance();
    IDictionary* carrs = me->getCarreras();
    return carrs;
}

IDictionary* EstudianteController::getEstudiantes()
{
    ManejadorEstudiante* me = ManejadorEstudiante::getInstance();
    IDictionary students = me->getEstudiantes();
    return students;
}

bool EstudianteController::EstudianteCumpleRequisitos(Estudiante* student, IDictionary* asignaturasOferta)
{
    ManejadorEstudiante* me = ManejadorEstudiante::getInstance();
    bool cumple = me->EstudianteCumpleRequisitos(student, asignaturasOferta);
    return cumple;
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
