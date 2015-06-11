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
    //Debería llamar al constructor de DataSeccion
    //con los datos nombre e interno de seccion y retornarlo.
    DataEncargado *de = this->encargado->getDataEncargado();
    return new DataSeccion(this->nombre, this->interno, de);
}

DataEmpresa Seccion::getDataEmpresa()
{
    //Debería llamar al constructor de DataEmpresa.

}

OfertaLaboral Seccion::addOferta(string numExpediente, string titulo, string descripcion, int cantidadHorasSemanales, Rango *rangoSalarial, Date *fechaComienzo, Date *fechaFin, int cantidadPuestosNecesarios, int creditosMinimos, Set(DataAsignatura) asignaturas)
{
    //Debo llamar al constructor de DataOfertaLaboral
    //con los datos de la oferta pasados como parametros
    //y de alguna manera asociar esta nueva oferta a las asignaturas pasadas en el set.
}

void Seccion::addObserver(IObserver obs)
{
    //Debo llamar al constructor por copia de IObserver y pasarle como parametro obs.
}

void Seccion::removeObserver(IObserver obs)
{
    //Debo llamar al destructor de IObserver y pasarle como parametro obs.
}

Seccion::~Seccion()
{

}
