#include "Seccion.h"

Seccion::Seccion()
{
    this->nombre = '\0';
    this->interno = '\0';
}

Seccion::Seccion(string nombre, string interno)
{
    this->nombre = nombre;
    this->interno = interno;
}

Seccion::Seccion(const Seccion &s)
{
    this->nombre = s.nombre;
    this->interno = s.interno;
}

string Seccion::getNombre()
{
	return this->nombre;
}

string Seccion::getInterno()
{
	return this->interno;
}

void Seccion::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Seccion::setInterno(string interno)
{
    this->interno = interno;
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

OfertaLaboral *Seccion::addOferta(string numExpediente, string titulo, string descripcion, int cantidadHorasSemanales, Rango *rangoSalarial, Date *fechaComienzo, Date *fechaFin, int cantidadPuestosNecesarios, Set(DataAsignatura) asignaturas)
{
    //Debo llamar al constructor de OfertaLaboral
    //con los datos de la oferta pasados como parametros
    //y de alguna manera asociar esta nueva oferta a las asignaturas pasadas en el set.
    OfertaLaboral * dataOferta = OfertaLaboral(numExpediente, titulo, descripcion, cantidadHorasSemanales, rangoSalarial, fechaComienzo, fechaFin, cantidadPuestosNecesarios);
    this->ofertasLaborales->add(dataOferta);// creo que hay que pasarle la clave y un Icollectible
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

}
