#include "Estudiante.h"

Estudiante::Estudiante()
{
    //ctor
    this->cedula = '\0';
    this->nombre = '\0';
    this->apellido = '\0';
    this->telefono = '\0';
    this->fechaNacimiento = NULL;
    this->creditos = 0;
    this->email = '\0';
    this->carreras = new OrderedDictionary();
    this->aprobadas= new List();
    this->inscripciones = new List();
    this->entrevistas = new List();
    this->notificaciones = new List();

}

Estudiante::Estudiante(string cedula,string nombre,string apellido, string telefono, Date* fechaNacimiento, int creditos,
                        string email, IDictionary* carreras, ICollection* aprobadas, ICollection* inscripciones, ICollection* entrevistas,
                        ICollection* notificaciones)
{
    this->cedula = cedula;
    this->nombre = nombre;
    this->apellido = apellido;
    this->telefono = telefono;
    this->fechaNacimiento = fechaNacimiento;
    this->creditos = creditos;
    this->email = email;

    if (carreras != NULL) {
        this->carreras = carreras;
    } else {
        this->carreras = new OrderedDictionary();
    }

    if (aprobadas != NULL) {
        this->aprobadas = aprobadas;
    } else {
        this->aprobadas = new List();
    }

    if (inscripciones != NULL) {
        this->inscripciones = inscripciones;
    } else {
        this->inscripciones = new List();
    }

    if (entrevistas != NULL) {
        this->entrevistas = entrevistas;
    } else {
        this->entrevistas = new List();
    }

    if (notificaciones != NULL) {
        this->notificaciones = notificaciones;
    } else {
        this->notificaciones = new List();
    }
}

Estudiante::Estudiante(const Estudiante &e)
{
    this->cedula = e.cedula;
    this->nombre = e.nombre;
    this->apellido = e.apellido;
    this->telefono = e.telefono;
    this->fechaNacimiento = e.fechaNacimiento;
    this->creditos = e.creditos;
    this->email = e.email;
    this->carreras = e.carreras;
    this->aprobadas = e.aprobadas;
    this->inscripciones = e.inscripciones;
    this->entrevistas = e.entrevistas;
    this->notificaciones = e.notificaciones;
}

string Estudiante::getCedula()
{
    return this->cedula;
}

string Estudiante::getNombre()
{
    return this->nombre;
}

string Estudiante::getApellido()
{
    return this->apellido;
}

string Estudiante::getTelefono()
{
    return this->telefono;
}

Date* Estudiante::getFechaNacimiento()
{
    return this->fechaNacimiento;
}

int Estudiante::getCreditos()
{
    return this->creditos;
}

string Estudiante::getEmail()
{
    return this->email;
}

IDictionary* Estudiante::getCarreras()
{
    return this->carreras;
}

ICollection* Estudiante::getAprobadas()
{
    return this->aprobadas;
}

ICollection* Estudiante::getInscripciones()
{
    return this->inscripciones;
}

ICollection* Estudiante::getEntrevistas()
{
    return this->entrevistas;
}

ICollection* Estudiante::getNotificaciones()
{
    return this->notificaciones;
}

void Estudiante::setCedula(string cedula)
{
    this->cedula = cedula;
}

void Estudiante::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Estudiante::setApellido(string apellido)
{
    this->apellido = apellido;
}

void Estudiante::setTelefono(string telefono)
{
    this->telefono = telefono;
}

void Estudiante::setFechaNacimiento(Date* fechaNacimiento)
{
    this->fechaNacimiento = fechaNacimiento;
}

void Estudiante::setCreditos(int creditos)
{
    this->creditos = creditos;
}

void Estudiante::setEmail(string email)
{
    this->email = email;
}

DataEstudiante* Estudiante::getDataEstudiante()
{
    try
    {
        //Se obtiene la coleccion de DataAsignatura
        /*ICollection* dataAsignaturas = new List();
        IIterator * lIt = this->aprobadas->getIterator();
        while(lIt->hasCurrent())
        {
            Aprobacion *apro;
            if( (apro = dynamic_cast<Aprobacion*> (lIt->getCurrent())) != NULL )
            {
                dataAsignaturas->add(apro->getDataAsignatura());
            } else
            {
                throw "Estudiante -> El objeto no es de la clase Aprobacion.";
            }

            lIt->next();
        }
        delete lIt;

        //Se obtiene la coleccion de DataCarrera
        IDictionary* dataCarreras = new OrderedDictionary();
        IIterator * It = this->carreras->getIterator();
        while(It->hasCurrent())
        {
            Carrera *carr;
            if( (carr = dynamic_cast<Carrera*> (It->getCurrent())) != NULL )
            {
                Integer* cod = new Integer (carr->getCodigo());
                dataCarreras->add(cod, carr->getDataCarrera());
            } else
            {
                throw "Estudiante -> El objeto no es de la clase Carrera.";
            }

            It->next();
        }
        delete It;*/

        DataEstudiante* dataEstudiante = new DataEstudiante(this->cedula, this->nombre, this->apellido, this->telefono,
                                             this->fechaNacimiento, this->creditos, this->email, this->carreras, this->aprobadas, this->inscripciones , this->entrevistas);
        return dataEstudiante;
    }
    catch (const char* e)
    {
    	throw;
    }

}

bool Estudiante::EstNoInscripto(string numExpediente)
{
    try
    {
        bool res;
        bool noEstaInscripto = true;
        IIterator * lIt = this->inscripciones->getIterator();
        while(lIt->hasCurrent() && (noEstaInscripto))
        {
            Inscripcion *insc;
            if( (insc = dynamic_cast<Inscripcion*> (lIt->getCurrent())) != NULL )
            {
                res = insc->EstInscripto(numExpediente);
                if (res)
                {
                    noEstaInscripto = false;
                }
            } else
            {
                throw "Estudiante -> El objeto no es de la clase Inscripcion.";
            }

            lIt->next();
        }
        delete lIt;

        return noEstaInscripto;
    }
    catch (const char* e)
    {
    	throw;
    }
}

bool Estudiante::EstInscripto(string numExpediente)
{
    try
    {
        bool res;
        bool estaInscripto = true;
        IIterator * lIt = this->inscripciones->getIterator();
        while(lIt->hasCurrent() && (estaInscripto))
        {
            Inscripcion *insc;
            if( (insc = dynamic_cast<Inscripcion*> (lIt->getCurrent())) != NULL )
            {
                res = insc->EstInscripto(numExpediente);
                if (!res)
                {
                    estaInscripto = false;
                }
            } else
            {
                throw "Estudiante -> El objeto no es de la clase Inscripcion.";
            }

            lIt->next();
        }
        delete lIt;

        return estaInscripto;
    }
    catch (const char* e)
    {
    	throw;
    }
}


void Estudiante::AsociarInscripcion (Inscripcion *insc)
{
    this->inscripciones->add(insc);
}

void Estudiante::AsociarEntrevista (Entrevista *ent)
{
    this->entrevistas->add(ent);
}

DataDatosEstudiante* Estudiante::getDataDatosEstudiante()
{
    try
    {
        //Se obtiene la coleccion de DataAprobada
        List* dataAprobadas = new List();
        IIterator * lIt = this->aprobadas->getIterator();
        while(lIt->hasCurrent())
        {
            Aprobacion *apro;
            if( (apro = dynamic_cast<Aprobacion*> (lIt->getCurrent())) != NULL )
            {
                dataAprobadas->add(apro->getDataAprobada());
            } else
            {
                throw "Estudiante -> El objeto no es de la clase Aprobacion.";
            }

            lIt->next();
        }
        delete lIt;

        List* dataOfertasEmpresas = new List();
        IIterator * lIt2 = this->inscripciones->getIterator();
        while(lIt2->hasCurrent())
        {
            Inscripcion *insc;
            if( (insc = dynamic_cast<Inscripcion*> (lIt2->getCurrent())) != NULL )
            {
                dataOfertasEmpresas->add(insc->getDataOfertaLaboral());
            } else
            {
                throw "Estudiante -> El objeto no es de la clase Inscripcion.";
            }
            lIt2->next();
        }

        delete lIt2;

        DataDatosEstudiante* datosEstudiante = new DataDatosEstudiante(dataAprobadas, dataOfertasEmpresas);

        return datosEstudiante;
    }
    catch (const char* e)
    {
    	throw;
    }
}

void Estudiante::enviarMail(string numExpediente)
{
    String* nExp = new String(numExpediente.c_str());
    this->notificaciones->add(nExp);
}

Estudiante::~Estudiante()
{
    //dtor
    if (this->fechaNacimiento != NULL)
        delete this->fechaNacimiento;
    delete this->carreras;
    delete this->aprobadas;
    delete this->inscripciones;
    delete this->entrevistas;
    delete this->notificaciones;
}
