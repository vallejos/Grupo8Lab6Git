#include "DataCarrera.h"

DataCarrera::DataCarrera()
{
//HOLADS
}

DataCarrera::DataCarrera(int codigo, string nombre)
{
    this->codigo=codigo;
    this->nombre=nombre;
}

DataCarrera::DataCarrera(const DataCarrera &a)
{

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
