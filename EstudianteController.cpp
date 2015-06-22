#include "EstudianteController.h"
#include "OfertaLaboralController.h"
#include "IOfertaLaboralController.h"
#include "OfertaLaboral.h"
#include "ManejadorEstudiante.h"

EstudianteController* EstudianteController::instance = NULL;

EstudianteController::EstudianteController()
{
 //constructor
}

EstudianteController* EstudianteController::getInstance()
{
    if (instance==NULL)
        instance = new EstudianteController;
    return instance;
}

IDictionary* EstudianteController::ListarEstudiantesNoInscriptos()
{
    OfertaLaboralController* olc = OfertaLaboralController::getInstance();
    string numExpe = olc->getOfertaLaboral()->getNumExpediente();
    ManejadorEstudiante *me = ManejadorEstudiante::getInstance();
    IDictionary *estNoInsc = me->getEstNoInscriptos(numExpe);
    if (estNoInsc == NULL)
        throw "No existe un Estudiante no Inscripto a la Oferta Seleccionada";
    return estNoInsc;
}

IDictionary* EstudianteController::ListarEstudiantesInscriptosEnOferta()
{
    OfertaLaboralController* olc = OfertaLaboralController::getInstance();
    string numExpe = olc->getOfertaLaboral()->getNumExpediente();
    ManejadorEstudiante *me = ManejadorEstudiante::getInstance();
    IDictionary* studentsInsc = me->getEstInscriptosEnOferta(numExpe);
    return studentsInsc;
}

void EstudianteController::SeleccionarEstudiante(string cedula, IDictionary *estudiantesValidos)
{
    ManejadorEstudiante *me = ManejadorEstudiante::getInstance();
    String* ci = new String(cedula.c_str());
    if(! (estudiantesValidos->member(ci)))
        throw "La cedula " + cedula + " es invalida.";
    this->estudiante = me->SeleccionarEstudiante(cedula);
}

DataDatosEstudiante* EstudianteController::ConsultarDatosEstudiante(string cedula)
{
    ManejadorEstudiante *me = ManejadorEstudiante::getInstance();
    Estudiante *e = me->SeleccionarEstudiante(cedula);
    return (e->getDataDatosEstudiante());
}

IDictionary* EstudianteController::ListarEstudiantesRegistrados()
{
    ManejadorEstudiante *me = ManejadorEstudiante::getInstance();
    IDictionary *estudiantes = me->getEstudiantes();
    if (estudiantes == NULL)
        throw "No hay estudiantes registrados en el Sistema.";
    return estudiantes;
}

Estudiante* EstudianteController::getEstudiante()
{
    if (this->estudiante == NULL)
        throw "No hay ningun estudiante recordado en el sistema";
    return this->estudiante;
}

void EstudianteController::ModificarEstudiante(string cedula, string nombre, string apellido, string telefono, Date *fechaNacimiento, int creditos, string email, ICollection *aprobacionesAAgregar, IDictionary *asignaturasAEliminar, IDictionary *carrerasAAgregar, IDictionary *carrerasAEliminar)
{

    ManejadorEstudiante *me = ManejadorEstudiante::getInstance();
    me->ModificarEstudiante(cedula, nombre, apellido, telefono, fechaNacimiento, creditos, email, aprobacionesAAgregar, asignaturasAEliminar, carrerasAAgregar, carrerasAEliminar);
}

IDictionary* EstudianteController::getAsignaturas()
{
    ManejadorEstudiante *me = ManejadorEstudiante::getInstance();
    IDictionary* asigs = me->getAsignaturas();
    if (asigs == NULL)
        throw "No hay asignaturas registradas en el Sistema.";
    return asigs;
}

IDictionary* EstudianteController::getCarreras()
{
    ManejadorEstudiante *me = ManejadorEstudiante::getInstance();
    IDictionary* carrs = me->getCarreras();
    if (carrs == NULL)
        throw "No hay carreras registradas en el Sistema.";
    return carrs;
}

IDictionary* EstudianteController::getEstudiantes()
{
    ManejadorEstudiante* me = ManejadorEstudiante::getInstance();
    IDictionary* students = me->getEstudiantes();
    if (students == NULL)
        throw "No hay estudiantes registrados en el Sistema.";
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
        delete instance;
     }
}

EstudianteController::~EstudianteController()
{
    //dtor
    delete instance;
    instance = NULL;
}
