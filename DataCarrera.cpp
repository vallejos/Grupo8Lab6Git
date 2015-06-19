#include "DataCarrera.h"

DataCarrera::DataCarrera()
{

}

DataCarrera::DataCarrera(int codigo, string nombre)
{
    this->codigo=codigo;
    this->nombre=nombre;
}

DataCarrera::DataCarrera(const DataCarrera &a)
{
    this->codigo = a.codigo;
    this->nombre = a.nombre;
}

int DataCarrera::getCodigo()
{
	return this->codigo;
}

string DataCarrera::getNombre()
{
	return this->nombre;
}


DataCarrera::~DataCarrera()
{

}
