#include "Seccion.h"
#include "OfertaLaboral.h"
#include "String.h"
#include "ManejadorEstudiante.h"
#include "collections/List.h"
#include "collections/OrderedDictionary.h"

Seccion::Seccion()
{
    this->nombre = '\0';
    this->interno = '\0';
    this->sucursal = NULL;
    this->encargado = NULL;
    this->observers = new List();
    this->ofertasLaborales = new OrderedDictionary();
}

Seccion::Seccion(string nombre, string interno)
{
    this->nombre = nombre;
    this->interno = interno;
    this->sucursal = NULL;
    this->encargado = NULL;
    this->observers = new List();
    this->ofertasLaborales = new OrderedDictionary();
}

Seccion::Seccion(const Seccion &s)
{
    this->nombre = s.nombre;
    this->interno = s.interno;
    this->sucursal = s.sucursal;
    this->encargado = s.encargado;
    this->observers = s.observers;
    this->ofertasLaborales = s.ofertasLaborales;
}

string Seccion::getNombre()
{
	return this->nombre;
}

string Seccion::getInterno()
{
	return this->interno;
}

Sucursal* Seccion::getSucursal()
{
    return this->sucursal;
}

Encargado* Seccion::getEncargado()
{
    return this->encargado;
}

IDictionary *Seccion::getOfertasLaborales()
{
    return this->ofertasLaborales;
}

void Seccion::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Seccion::setInterno(string interno)
{
    this->interno = interno;
}

void Seccion::setEncargado(Encargado* encargado)
{
    this->encargado = encargado;
}

DataSeccion *Seccion::getDataSeccion()
{
    DataEncargado *de = this->encargado->getDataEncargado();
    return new DataSeccion(this->nombre, this->interno, de);
}

DataEmpresa *Seccion::getDataEmpresa()
{
    return this->sucursal->getDataEmpresa();

}

OfertaLaboral *Seccion::addOferta(string numExpediente, string titulo, string descripcion, int cantidadHorasSemanales, Rango *rangoSalarial, Date *fechaComienzo, Date *fechaFin, int cantidadPuestosNecesarios, IDictionary *asignaturas)
{
    //Debo llamar al constructor de OfertaLaboral
    //con los datos de la oferta pasados como parametros
    //y de alguna manera asociar esta nueva oferta a las asignaturas pasadas en el set.
    OfertaLaboral * dataOferta = new OfertaLaboral(numExpediente, titulo, descripcion, cantidadHorasSemanales, rangoSalarial, fechaComienzo, fechaFin, cantidadPuestosNecesarios, asignaturas);
    String *numExp = new String(numExpediente.c_str());
    this->ofertasLaborales->add(numExp,dataOferta);

    ManejadorEstudiante* mEstu = ManejadorEstudiante::getInstance();
    //Se notifica a los observadores
    IIterator * it = this->observers->getIterator();
    while(it->hasCurrent())
    {
        Estudiante *student;
        if( (student = dynamic_cast<Estudiante*> (it->getCurrent())) != NULL )
        {
            if(mEstu->EstudianteCumpleRequisitos(student, asignaturas))
            {
                student->enviarMail(numExpediente);
            }
        } else
        {
            throw "Seccion -> El objeto no es de la clase Estudiante.";
        }
    }
    delete it;

    return dataOferta;
}

void Seccion::addObserver(IObserver *obs)
{
   this->observers->add(obs);
}

void Seccion::removeObserver(IObserver *obs)
{
     this->observers->remove(obs);
}

Seccion::~Seccion()
{
    //Debo destruir la memoria de observers, ofertasLaborales, encargado y sucursal
    if (this->sucursal != NULL)
        delete this->sucursal;
    if (this->encargado != NULL)
        delete this->encargado;
    delete this->observers;
    delete this->ofertasLaborales;
}
