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

void ManejadorEstudiante::ModificarEstudiante(string cedula, string nombre, string apellido, string telefono, Date *fechaNacimiento, int creditos, string email, ICollection *aprobacionesAAgregar, IDictionary *asignaturasAEliminar, IDictionary *carrerasAAgregar, IDictionary *carrerasAEliminar)
{
    Estudiante* e = this->estudiantes->find(cedula);
    if(nombre != NULL)
        e->setNombre(nombre);
    if(apellido != NULL)
        e->setApellido(apellido);
    if(telefono != NULL)
        e->setTelefono(telefono);
    if(fechaNacimiento != NULL)
        e->setFechaNacimiento(fechaNacimiento);
    if(creditos != NULL)
        e->setCreditos(creditos);
    if(email != NULL)
        e->setEmail(email);

    IDictionary *carreras = e->getCarreras();

    // Elimino las carreras que el usuario ingreso del estudiante.
    IIterator * it = this->carrerasAEliminar->getIterator();
    while(it->hasCurrent())
    {
        Carrera *carrera;
        if( (carrera = dynamic_cast<Carrera*> (it->getCurrent())) != NULL )
        {
            int cod = carrera->getCodigo();
            Integer *codigo = new Integer(cod);
            if (carreras->member(codigo))
            {
                carreras->remove(codigo);
            }else
            {
                throw "ManejadorEstudiante -> La Carrera a Eliminar no es una Carrera del Estudiate.";
            }
        }else
        {
            throw "ManejadorEstudiante -> El objeto no es de la clase Carrera.";
        }
        it->next();
    }
    delete it;

     // Agrego las carreras que el usuario ingreso al estudiante.
     IIterator * it2 = this->carrerasAAgregar->getIterator();
     while(it2->hasCurrent())
    {
        Carrera *carrera;
        if( (carrera = dynamic_cast<Carrera*> (it2->getCurrent())) != NULL )
        {
            int cod = carrera->getCodigo();
            Integer *codigo = new Integer(cod);
            if (!carreras->member(codigo))
            {
                Carrera *c = carreras->find(codigo);
                carreras->add(codigo,c);
            }else
            {
                throw "ManejadorEstudiante -> La Carrera a Agregar ya es una Carrera del Estudiante.";
            }
        }else
        {
            throw "ManejadorEstudiante -> El objeto no es de la clase Carrera.";
        }
        it2->next();
    }
    delete it2;

    ICollection *aprobadas = e->getAprobadas();

    // Elimino las asignaturas que el usuario ingreso del estudiante.
    IIterator * it3 = this->asignaturasAEliminar->getIterator();
    while(it3->hasCurrent())
    {
        Asignatura *asig;
        if( (asig = dynamic_cast<Asignatura*> (it3->getCurrent())) != NULL )
        {
            int cod = asig->getCodigo();
            IIterator * it4 = this->aprobadas->getIterator();
            bool encontro = false;
            while (it4->hasCurrent() && !encontro)
            {
                Aprobacion *aprobacion;
                if( (aprobacion = dynamic_cast<Aprobacion*> (it4->getCurrent())) != NULL )
                {
                    int codAsigEst = aprobacion->getAsignatura()->getCodigo();
                    if (codigo == codAsigEst)
                    {
                        aprobadas->remove(aprobacion);
                        encontro = true;
                    }
                }else
                {
                     throw "ManejadorEstudiante -> El objeto no es de la clase Aprobacion.";
                }
                it4->next();
            }
            if (!encontro)
            {
                throw "ManejadorEstudiante -> La Asignatura a Eliminar no es una Asignatura del Estudiate.";
            }
            delete it4;
        }else
        {
            throw "ManejadorEstudiante -> El objeto no es de la clase Asignatura.";
        }
        it3->next();
    }
    delete it3;

    // Agrego las asignaturas que el usuario ingreso al estudiante.
    IIterator * it5 = this->aprobacionesAAgregar->getIterator();
    while(it5->hasCurrent())
    {
        Aprobacion *aprob;
        if( (aprob = dynamic_cast<Aprobacion*> (it5->getCurrent())) != NULL )
        {
            int cod = aprob->getAsignatura()->getCodigo();
            IIterator * it6 = this->aprobadas->getIterator();
            while (it6->hasCurrent())
            {
                Aprobacion *aprobacion;
                if( (aprobacion = dynamic_cast<Aprobacion*> (it6->getCurrent())) != NULL )
                {
                    int codAsigEst = aprobacion->getAsignatura()->getCodigo();
                    if (codigo == codAsigEst)
                    {
                        throw "ManejadorEstudiante -> La Asignatura a Agregar ya es una Asignatura del Estudiate.";
                    }
                }else
                {
                     throw "ManejadorEstudiante -> El objeto no es de la clase Aprobacion.";
                }
                it6->next();
            }

            aprobadas->add(aprob);

            delete it6;
        }else
        {
            throw "ManejadorEstudiante -> El objeto no es de la clase Aprobacion.";
        }
        it5->next();
    }
    delete it5;


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
    IIterator * it = this->estudiantes->getElemIterator();
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
