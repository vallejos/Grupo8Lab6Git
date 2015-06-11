#include "DataSeccion.h"

DataSeccion::DataSeccion()
{
    this->nombre = '\0';
    this->interno = '\0';
    this->encargado = NULL;
}

DataSeccion::DataSeccion(string nombre, string interno, DataEncargado *encargado)
{
    this->nombre = nombre;
    this->interno = interno;
    this->encargado = encargado;
}

DataSeccion::DataSeccion(const DataSeccion &ds)
{
    this->nombre = ds.nombre;
    this->interno = ds.interno;
    // No se si no debería ser una copia limpia
    this->encargado = ds.encargado;
}

string DataSeccion::getNombre()
{
	return this->nombre;
}

string DataSeccion::getInterno()
{
	return this->interno;
}

DataEncargado DataSeccion::getEncargado()
{
	return this->encargado;
}

DataSeccion::~DataSeccion()
{

}
