#include "ManejadorEstudiante.h"

ManejadorEstudiante *ManejadorEstudiante::instance = NULL;

ManejadorEstudiante::ManejadorEstudiante()
{
    this->estudiantes=NULL;
}

ManejadorEstudiante *ManejadorEstudiante::getInstance()
{
    //Se crea una instancia de ManejadorEstudiante.
    if(instance == NULL)
        instance = new ManejadorEstudiante();
    return instance;
}

ICollection *ManejadorEstudiante::getEstNoInscriptos(string numExpediente)
{
    //Se va a mover por la coleccion de estudiantes que el manejador conoce
    //se invoca a EstNoInscripto para corroborar si el estudiante está inscripto a la oferta con numExpediente
    //por cada estudiante no inscripto se crea un DataEstudiante para luego retornar una coleccion de DataEstudiante.
    List* result = new List();
    IIterator * it = this->estudiantes->getElemIterator();
    while(it.hasCurrent())
    {
        if (it.current()->EstNoInscripto(numExpediente))
            result->add(it.current()->getDataEstudiante());
        it.next();
    }
    delete it;
    return result;
}

ICollection* ManejadorEstudiante::getEstInscriptosEnOferta(string numExpediente)
{
    List* result = new List();
    IIterator * it = this->estudiantes->getElemIterator();
    while(it.hasCurrent())
    {
        if (it.current()->EstInscripto(numExpediente))
            result->add(it.current()->getDataEstudiante());
        it.next();
    }
    delete it;
    return result;
}

void ManejadorEstudiante::ModificarEstudiante(string cedula, DataEstudiante* nuevosDatos)
{
//Pre: ningun dato del nuevosDatos es vacio.
//p.e si el usuario no modifica el apellido, el DataEstudiante debe contener el apellido del estudiante y no ser vacio
    Estudiante* e = this->estudiantes->find(cedula);
    e->setApellido(nuevosDatos->getApellido());
    e->setNombre(nuevosDatos->getNombre());
    e->setAprobadas(nuevosDatos->getAprobadas());
    e->setCarreras(nuevosDatos->getCarreras());
    e->setCreditos(nuevosDatos->getCreditos());
    e->setEmail(nuevosDatos->getEmail());
    e->setEntrevistas(nuevosDatos->getEntrevistas());
    e->setFechaNacimiento(nuevosDatos->getFechaNacimiento());
    e->setInscripciones(nuevosDatos->getInscripciones());
    e->setTelefono(nuevosDatos->getTelefono());
}

Estudiante *ManejadorEstudiante::SeleccionarEstudiante(string cedula)
{
    //Va a buscar en la coleccion de estudiantes del manejador,
    //y va a buscar el estudiante con cedula "cedula".
    try
    {
        String* ci = new String(cedula);
        if(this->estudiantes->member(ci))
        {
            return this->estudiantes->find(cedula);
        }
        else
        {
            throw std::invalid_argument("El Estudiante con C.I. " + cedula + " no existe en el Sistema.");
        }
    }
    catch(const std::invalid_argument &e)
    {
    	throw std::invalid_argument(e.what());
    }
}

ICollection *ManejadorEstudiante::getEstudiante()
{
    //Va a recorrer los estudiantes del sistema y por cada estudiante crea un DataEstudiante para luego retornar un set.
    List* result = new List();
    IIterator * it = this->estudiantes->getElemIterator();
    while(it.hasCurrent())
    {
        result->add(it.current()->getDataEstudiante());
        it.next();
    }
    delete it;
    return result;
}

IDictionary *ManejadorEstudiante::getEstudiantes()
{
    return this->estudiantes;
}

IDictionary* ManejadorEstudiante::getAsignaturas()
{
    return this->asignaturas;
}

IDictionary* ManejadorEstudiante::getCarreras()
{
    return this->carreras;
}

void ManejadorEstudiante::destroyManejadorEstudiante()
{
     if (instance != NULL)
     {
        delete ManejadorEstudiante;
     }
}

ManejadorEstudiante::~ManejadorEstudiante()
{
    //Debo liberar la meoria de el diccionario de estudiantes
    if (this->estudiantes != NULL)
        delete this->estudiantes;
    delete instance;
    instance = NULL;
}
