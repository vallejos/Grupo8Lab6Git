#include "DataOfertaLaboral.h"

//No tengo claro si va creditosMinimos porque no estaba en el datatype original.
DataOfertaLaboral::DataOfertaLaboral()
{
    this->numExpediente = '\0';
    this->titulo = '\0';
    this->descripcion = '\0';
    this->cantidadHorasSemanales = 0;
    this->rangoSalarial = NULL;
    this->fechaComienzo = NULL;
    this->fechaFin = NULL;
    this->cantidadPuestosNecesarios = 0;
    this->creditosMinimos = 0;
}

DataOfertaLaboral::DataOfertaLaboral(string numExpediente, string titulo, string descripcion, int cantidadHorasSemanales, Rango *rangoSalarial, Date *fechaComienzo, Date *fechaFin, int cantidadPuestosNecesarios, int creditosMinimos)
{
    this->numExpediente = numExpediente;
    this->titulo = titulo;
    this->descripcion = descripcion;
    this->cantidadHorasSemanales = cantidadHorasSemanales;
    this->rangoSalarial = rangoSalarial;
    this->fechaComienzo = fechaComienzo;
    this->fechaFin = fechaFin;
    this->cantidadPuestosNecesarios = cantidadPuestosNecesarios;
    this->creditosMinimos = creditosMinimos;
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
    this->creditosMinimos = dol.creditosMinimos;
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

int DataOfertaLaboral::getCreditosMinimos()
{
	return this->creditosMinimos;
}

DataOfertaLaboral::~DataOfertaLaboral()
{

}
