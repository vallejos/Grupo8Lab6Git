#include "ManejadorEstudiante.h"
#include "collections/OrderedDictionary.h"

ManejadorEstudiante *ManejadorEstudiante::instance = NULL;

ManejadorEstudiante::ManejadorEstudiante()
{
    this->estudiantes = new OrderedDictionary();
    this->asignaturas = new OrderedDictionary();
    this->carreras = new OrderedDictionary();
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
    OrderedDictionary* result = new OrderedDictionary();
    IIterator * it = this->estudiantes->getIterator();
    while(it->hasCurrent())
    {
        Estudiante *de = dynamic_cast<Estudiante*> (it->getCurrent());
        if (de->EstNoInscripto(numExpediente))
        {
            String *cedula = new String(de->getDataEstudiante()->getCedula().c_str());
            result->add(cedula, de->getDataEstudiante());
        }
        it->next();
    }
    delete it;
    return result;
}

IDictionary* ManejadorEstudiante::getEstInscriptosEnOferta(string numExpediente)
{
    OrderedDictionary* result = new OrderedDictionary();
    IIterator * it = this->estudiantes->getIterator();
    while(it->hasCurrent())
    {
        Estudiante *de = dynamic_cast<Estudiante*> (it->getCurrent());
        if (de->EstInscripto(numExpediente))
        {
            String *cedula = new String(de->getDataEstudiante()->getCedula().c_str());
            result->add(cedula, de->getDataEstudiante());
        }
        it->next();
    }
    delete it;
    return result;
}

void ManejadorEstudiante::ModificarEstudiante(string cedula, string nombre, string apellido, string telefono, Date *fechaNacimiento, int creditos, string email, ICollection *aprobacionesAAgregar, IDictionary *asignaturasAEliminar, IDictionary *carrerasAAgregar, IDictionary *carrerasAEliminar)
{
    String *ced = new String(cedula.c_str());
    Estudiante* e = dynamic_cast<Estudiante*> (this->estudiantes->find(ced));
    if(nombre != "")
        e->setNombre(nombre);
    if(apellido != "")
        e->setApellido(apellido);
    if(telefono != "")
        e->setTelefono(telefono);
    if(fechaNacimiento != NULL)
        e->setFechaNacimiento(fechaNacimiento);
    if(creditos != 0)
        e->setCreditos(creditos);
    if(email != "")
        e->setEmail(email);

    IDictionary *carreras = e->getCarreras();

    // Elimino las carreras que el usuario ingreso del estudiante.
    IIterator * it = this->carreras->getIterator();
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
     IIterator * it2 = this->carreras->getIterator();
     while(it2->hasCurrent())
    {
        Carrera *carrera;
        if( (carrera = dynamic_cast<Carrera*> (it2->getCurrent())) != NULL )
        {
            int cod = carrera->getCodigo();
            Integer *codigo = new Integer(cod);
            if (!carreras->member(codigo))
            {
                Carrera *c = dynamic_cast<Carrera*> (carreras->find(codigo));
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
    IIterator * it3 = this->asignaturas->getIterator();
    while(it3->hasCurrent())
    {
        Asignatura *asig;
        if( (asig = dynamic_cast<Asignatura*> (it3->getCurrent())) != NULL )
        {
            int cod = asig->getCodigo();
            int creditosAsig = asig->getCreditos();
            int creditosEst = e->getCreditos();
            int restaCreditos = creditosEst - creditosAsig;
            e->setCreditos(restaCreditos);
            IIterator * it4 = aprobadas->getIterator();
            bool encontro = false;
            while (it4->hasCurrent() && !encontro)
            {
                Aprobacion *aprobacion;
                if( (aprobacion = dynamic_cast<Aprobacion*> (it4->getCurrent())) != NULL )
                {
                    int codAsigEst = aprobacion->getAsignatura()->getCodigo();
                    if (cod == codAsigEst)
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
    if (this->PerteneceAsigACarrerasDeEst(carreras, aprobacionesAAgregar))
    {
        IIterator * it5 = aprobacionesAAgregar->getIterator();
        while(it5->hasCurrent())
        {
            Aprobacion *aprob;
            if( (aprob = dynamic_cast<Aprobacion*> (it5->getCurrent())) != NULL )
            {
                int cod = aprob->getAsignatura()->getCodigo();
                int creditosAsig = aprob->getAsignatura()->getCreditos();
                int creditosEst = e->getCreditos();
                int sumaCreditos = creditosEst + creditosAsig;
                e->setCreditos(sumaCreditos);
                IIterator * it6 = aprobadas->getIterator();
                while (it6->hasCurrent())
                {
                    Aprobacion *aprobacion;
                    if( (aprobacion = dynamic_cast<Aprobacion*> (it6->getCurrent())) != NULL )
                    {
                        int codAsigEst = aprobacion->getAsignatura()->getCodigo();
                        if (cod == codAsigEst)
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
    }else
    {
        throw "ManejadorEstudiante -> Alguna de las asignaturas a agregar no perteneces a las carreras que el estudiante cursa.";
    }

}

Estudiante *ManejadorEstudiante::SeleccionarEstudiante(string cedula)
{
    //Va a buscar en la coleccion de estudiantes del manejador,
    //y va a buscar el estudiante con cedula "cedula".
    String* ci = new String(cedula.c_str());
    if(! (this->estudiantes->member(ci)))
        throw "El Estudiante con C.I. " + cedula + " no existe en el Sistema.";
    return dynamic_cast<Estudiante*> (this->estudiantes->find(ci));
}

IDictionary *ManejadorEstudiante::getEstudiante()
{
//Va a recorrer los estudiantes del sistema y por cada estudiante crea un DataEstudiante para luego retornar un set.
    OrderedDictionary* result = new OrderedDictionary();
    IIterator * it = this->estudiantes->getIterator();
    while(it->hasCurrent())
    {
        Estudiante *e = dynamic_cast<Estudiante*> (it->getCurrent());
        String *cedula = new String(e->getDataEstudiante()->getCedula().c_str());
        result->add(cedula, e->getDataEstudiante());
        it->next();
    }
    delete it;
    return result;
}

IDictionary *ManejadorEstudiante::getEstudiantes()
{
    if (this->estudiantes == NULL)
        throw "No hay ningun estudiante dado de alta en el Sistema";
    return this->estudiantes;
}

IDictionary* ManejadorEstudiante::getAsignaturas()
{
    if (this->asignaturas == NULL)
        throw "No hay ninguna asignatura dado de alta en el Sistema";
    return this->asignaturas;
}

IDictionary* ManejadorEstudiante::getCarreras()
{
    if (this->carreras== NULL)
        throw "No hay ninguna carrera dada de alta en el Sistema";
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
            throw "ManejadorEstudiante -> El objeto no es de la clase Asignatura.";
        }
        it->next();
    }
    delete it;

    return true;
}

bool ManejadorEstudiante::PerteneceAsigACarrerasDeEst (IDictionary *carrerasDeEst, ICollection *aprobacionesAAgregar)
{
    IIterator * it = aprobacionesAAgregar->getIterator();
    while(it->hasCurrent())
    {
        Aprobacion *aprob;
        if( (aprob = dynamic_cast<Aprobacion*> (it->getCurrent())) != NULL )
        {
            IDictionary *carreras = aprob->getAsignatura()->getCarreras();
            IIterator * it2 = carreras->getIterator();
            bool NoPertenece = false;
            while (it2->hasCurrent() && !NoPertenece)
            {
                Carrera *carreraDeAsig;
                if( (carreraDeAsig = dynamic_cast<Carrera*> (it2->getCurrent())) != NULL )
                {
                    int codAsigEst = carreraDeAsig->getCodigo();
                    Integer *cod = new Integer(codAsigEst);
                    if (!carrerasDeEst->member(cod))
                    {
                        NoPertenece = true;
                    }
                }else
                {
                     throw "ManejadorEstudiante -> El objeto no es de la clase Carrera.";
                }
                it2->next();
            }
            return NoPertenece;

            delete it2;
        }else
        {
            throw "ManejadorEstudiante -> El objeto no es de la clase Aprobacion.";
        }
        it->next();
    }
    delete it;
    return false;
}

void ManejadorEstudiante::destroyManejadorEstudiante()
{
     if (instance != NULL)
     {
        this->~ManejadorEstudiante();
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
