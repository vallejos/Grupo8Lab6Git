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

IDictionary *ManejadorEstudiante::getEstNoInscriptos(string numExpediente)
{
    //Se va a mover por la coleccion de estudiantes que el manejador conoce
    //se invoca a EstNoInscripto para corroborar si el estudiante está inscripto a la oferta con numExpediente
    //por cada estudiante no inscripto se crea un DataEstudiante para luego retornar una coleccion de DataEstudiante.
    List* result = new List();
    IIterator * it = this->estudiantes->getIterator();
    while(it->hasCurrent())
    {
        if (it->getCurrent()->EstNoInscripto(numExpediente))
            result->add(it->getCurrent()->getDataEstudiante());
        it->next();
    }
    delete it;
    return result;
}

IDictionary* ManejadorEstudiante::getEstInscriptosEnOferta(string numExpediente)
{
    List* result = new List();
    IIterator * it = this->estudiantes->getIterator();
    while(it->hasCurrent())
    {
        if (it->getCurrent()->EstInscripto(numExpediente))
            result->add(it->getCurrent()->getDataEstudiante());
        it->next();
    }
    delete it;
    return result;
}

void ManejadorEstudiante::ModificarEstudiante(string cedula, string nombre, string apellido, string telefono, Date *fechaNacimiento, int creditos, string email, IDictionary *asignaturasAAgregar, IDictionary *asignaturasAEliminar, IDictionary *carrerasAAgregar, IDictionary *carrerasAEliminar)
{
    //Arreglar esta operacion
    Estudiante* e = this->estudiantes->find(cedula);
    e->setNombre(nombre);
    e->setApellido(apellido);
    e->setTelefono(telefono);
    e->setFechaNacimiento(fechaNacimiento);
    e->setCreditos(creditos);
    e->setEmail(email);
    IDictionary *carreras = e->getCarreras();
    IIterator * it = this->carrerasAEliminar->getIterator();
    while(it->hasCurrent())
    {
        Carrera *carrera;
        if( (carrera = dynamic_cast<Carrera*> (it->current())) != NULL )
        {
            int cod = it->current()->getCodigo();
        }else
        {
            throw "ManejadorEstudiante -> El objeto no es de la clase Carrera.";
        }




        if (it->current()->EstInscripto(numExpediente))
            result->add(it->current()->getDataEstudiante());
        it->next();
    }
    delete it;

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

IDictionary *ManejadorEstudiante::getEstudiante()
//Va a recorrer los estudiantes del sistema y por cada estudiante crea un DataEstudiante para luego retornar un set.
    List* result = new List();
    IIterator * it = this->estudiantes->getIterator();
    while(it->hasCurrent())
    {
        result->add(it->getCurrent()->getDataEstudiante());
        it->next();
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

bool ManejadorEstudiante::EstudianteCumpleRequisitos(Estudiante* student, IDictionary* asignaturasOferta)
{
    ICollection *aprobadas = student->getAprobadas();
    IIterator * it = asignaturasOferta->getIterator();
    while(it->hasCurrent())
    {
        Asignatura *asig;
        if( (asig = dynamic_cast<Asignatura*> (it->getCurrent())) != NULL )
        {
            int cod = asig->getCodigo();
            IIterator * it2 = aprobadas->getIterator();
            bool encontro = false;
            while (it2->hasCurrent() && !encontro)
            {
                Aprobacion *aprobada;
                if( (aprobada = dynamic_cast<Aprobacion*> (it2->getCurrent())) != NULL )
                {
                    int codAsigEst = aprobada->getAsignatura()->getCodigo();
                    if (codAsigEst == cod)
                        encontro = true;
                }else
                {
                    throw "ManejadorEstudiante -> El objeto no es de la clase Aprobacion.";
                }
                it2->next();
            }
            delete it2;
            if (!encontro)
                 return false;
        }else
        {
            throw std::invalid_argument("ManejadorEstudiante -> El objeto no es de la clase Asignatura.");
        }
        it->next();
    }
    delete it;

    return true;
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
