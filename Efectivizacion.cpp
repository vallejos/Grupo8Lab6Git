#include "Efectivizacion.h"

Efectivizacion::Efectivizacion()
{
    //ctor
    this->fechaEfectivizacion = NULL;
}

Efectivizacion::Efectivizacion(int sueldo, Date* fechaEfectivizacion){
    this->sueldo = sueldo;
    this->fechaEfectivizacion = fechaEfectivizacion;
}

int Efectivizacion::getSueldo()
{
    return this->sueldo;
}

Date* Efectivizacion::getFechaEfectivizacion()
{
    return this->fechaEfectivizacion;
}

void Efectivizacion::setSueldo(int nuevoSueldo)
{
    this->sueldo = nuevoSueldo;
}

void Efectivizacion::setFechaEfectivizacion(Date* nuevaFechaEfectivizacion)
{
    this->fechaEfectivizacion = nuevaFechaEfectivizacion;
}

Efectivizacion::~Efectivizacion()
{
    //dtor
    if (this->fechaEfectivizacion != NULL)
    {
        delete this->fechaEfectivizacion;
    }
}
