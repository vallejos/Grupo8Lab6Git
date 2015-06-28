#include "DataSucursal.h"
#include "collections/OrderedDictionary.h"

DataSucursal::DataSucursal(string nombre, string direccion, string telefono, IDictionary *secciones)
{
	this->nombre = nombre;
	this->direccion = direccion;
	this->telefono = telefono;
	this->secciones = secciones;
}

DataSucursal::DataSucursal(const DataSucursal &s)
{
    this->nombre = s.nombre;
	this->direccion = s.direccion;
	this->telefono = s.telefono;
	this->secciones = s.secciones;
}

string DataSucursal::getNombre()
{
	return this->nombre;
}

string DataSucursal::getDireccion()
{
	return this->direccion;
}

string DataSucursal::getTelefono()
{
	return this->telefono;
}

IDictionary *DataSucursal::getSecciones()
{
	return this->secciones;
}


DataSucursal::~DataSucursal()
{
    if (this->secciones != NULL)
        delete (this->secciones);
}
