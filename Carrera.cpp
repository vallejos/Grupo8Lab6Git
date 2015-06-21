#include "Carrera.h"
#include "collections/OrderedDictionary.h"

Carrera::Carrera()
{
    //ctor
    this->codigo = 0;
    this->nombreCarrera = '\0';
    this->asignaturas = new OrderedDictionary();
}

Carrera::Carrera(const Carrera &c)
{
    this->codigo = c.codigo;
    this->nombreCarrera = c.nombreCarrera;
    // asignaturas?
}

Carrera::Carrera(int codigo, string nombreCarrera)
{
    this->codigo = codigo;
    this->nombreCarrera = nombreCarrera;
    this->asignaturas = new OrderedDictionary();
}

int Carrera::getCodigo()
{
    return this->codigo;
}

string Carrera::getNombreCarrera()
{
    return this->nombreCarrera;
}

DataCarrera* Carrera::getDataCarrera()
{
    try {
        DataCarrera* dataC = new DataCarrera(this->codigo, this->nombreCarrera);
        return dataC;
    } catch (exception &e) {
        throw;
    }
}

IDictionary* Carrera::getAsignaturas()
{
    return this->asignaturas;
}

void Carrera::setAsignaturas(IDictionary* asignaturas)
{
    this->asignaturas = asignaturas;
}

void Carrera::setCodigo(int codigo)
{
    this->codigo = codigo;
}

void Carrera::setNombreCarrera(string nombreCarrera)
{
    this->nombreCarrera = nombreCarrera;
}

Carrera::~Carrera()
{
    //dtor
    delete this->asignaturas;
}
