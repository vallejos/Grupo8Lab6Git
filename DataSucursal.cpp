#include "DataSucursal.h"

DataSucursal::DataSucursal()
{
	this->nombre = '\0';
	this->direccion = '\0';
	this->telefono = '\0';
	this->secciones = NULL;
}

DataSucursal::DataSucursal(string nombre, string direccion, string telefono, ICollection *secciones)
{
	this->nombre = nombre;
	this->direccion = direccion;
	this->telefono = telefono;
	this->secciones = secciones;
}

DataSucursal::DataSucursal(const DataSucursal &s)
{

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

ICollection *DataSucursal::getSecciones()
{
	return this->secciones;
}


DataSucursal::~DataSucursal()
{

}
