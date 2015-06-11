#include "DataCarrera.h"

DataCarrera::DataCarrera()
{
//HOLADS
}

DataCarrera::DataCarrera(int codigo, string nombre)
{

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
