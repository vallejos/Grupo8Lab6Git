#include "DataSeccion.h"

DataSeccion::DataSeccion()
{

}

DataSeccion::DataSeccion(string nombre, string interno, DataEncargado *encargado, Sucursal *sucursal,
        ICollection *observers, IDictionary *ofertas)
{
    this->nombre = nombre;
    this->interno = interno;
    this->encargado = encargado;
    this->sucursal = sucursal;
    this->ofertas = ofertas;
    this->observers = observers;
}

DataSeccion::DataSeccion(const DataSeccion &ds)
{
    this->nombre = ds.nombre;
    this->interno = ds.interno;
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

DataEncargado *DataSeccion::getEncargado()
{
	return this->encargado;
}

DataSeccion::~DataSeccion()
{

}
