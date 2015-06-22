#include "DataCarrera.h"

DataCarrera::DataCarrera()
{

}

DataCarrera::DataCarrera(int codigo, string nombre, IDictionary* asignaturas)
{
    this->codigo=codigo;
    this->nombre=nombre;
    this->asignaturas = asignaturas;
}

DataCarrera::DataCarrera(const DataCarrera &a)
{
    this->codigo = a.codigo;
    this->nombre = a.nombre;
    this->asignaturas = a.asignaturas;
}

int DataCarrera::getCodigo()
{
	return this->codigo;
}

string DataCarrera::getNombre()
{
	return this->nombre;
}

IDictionary* DataCarrera::getAsignaturas()
{
    return this->asignaturas;
}

DataCarrera::~DataCarrera()
{

}
