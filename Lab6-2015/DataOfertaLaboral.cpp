#include "DataOfertaLaboral.h"
#include "collections/List.h"
#include "collections/OrderedDictionary.h"

DataOfertaLaboral::DataOfertaLaboral()
{

}

DataOfertaLaboral::DataOfertaLaboral(string numExpediente, string titulo, string descripcion, int cantidadHorasSemanales,
                        Rango *rangoSalarial, Date *fechaComienzo, Date *fechaFin, int cantidadPuestosNecesarios, 
                        IDictionary *asignaturas, Seccion* seccion, ICollection *inscripciones, ICollection *entrevistas)
{
    this->numExpediente = numExpediente;
    this->titulo = titulo;
    this->descripcion = descripcion;
    this->cantidadHorasSemanales = cantidadHorasSemanales;
    this->rangoSalarial = rangoSalarial;
    this->fechaComienzo = fechaComienzo;
    this->fechaFin = fechaFin;
    this->cantidadPuestosNecesarios = cantidadPuestosNecesarios;
    this->seccion = seccion;
    this->inscripciones = inscripciones;
    this->entrevistas = entrevistas;
    this->asignaturas = asignaturas;
}

DataOfertaLaboral::DataOfertaLaboral(const DataOfertaLaboral &dol)
{
    this->numExpediente = dol.numExpediente;
    this->titulo = dol.titulo;
    this->descripcion = dol.descripcion;
    this->cantidadHorasSemanales = dol.cantidadHorasSemanales;
    this->rangoSalarial = dol.rangoSalarial;
    this->fechaComienzo = dol.fechaComienzo;
    this->fechaFin = dol.fechaFin;
    this->cantidadPuestosNecesarios = dol.cantidadPuestosNecesarios;
    this->asignaturas = dol.asignaturas;
    this->seccion = dol.seccion;
    this->inscripciones = dol.inscripciones;
    this->entrevistas = dol.entrevistas;
}

string DataOfertaLaboral::getNumExpediente()
{
	return this->numExpediente;
}

string DataOfertaLaboral::getTitulo()
{
	return this->titulo;
}

string DataOfertaLaboral::getDescripcion()
{
	return this->descripcion;
}

int DataOfertaLaboral::getCantidadHorasSemanales()
{
	return this->cantidadHorasSemanales;
}

Rango *DataOfertaLaboral::getRangoSalarial()
{
	return this->rangoSalarial;
}

Date *DataOfertaLaboral::getFechaComienzo()
{
	return this->fechaComienzo;
}

Date *DataOfertaLaboral::getFechaFin()
{
	return this->fechaFin;
}

int DataOfertaLaboral::getCantidadPuestosNecesarios()
{
	return this->cantidadPuestosNecesarios;
}

Seccion* DataOfertaLaboral::getSeccion()
{
    return this->seccion;
}

ICollection* DataOfertaLaboral::getInscripciones()
{
    return this->inscripciones;
}

ICollection* DataOfertaLaboral::getEntrevistas()
{
    return this->entrevistas;
}

IDictionary* DataOfertaLaboral::getAsignaturas()
{
    return this->asignaturas;
}

DataOfertaLaboral::~DataOfertaLaboral()
{

}
