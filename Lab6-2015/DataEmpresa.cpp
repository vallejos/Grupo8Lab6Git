#include "DataEmpresa.h"

DataEmpresa::DataEmpresa()
{

}

DataEmpresa::DataEmpresa(string rut, string nombre, IDictionary* sucursales)
{
    this->rut=rut;
    this->nombre=nombre;
    this->sucursales=sucursales;
}

DataEmpresa::DataEmpresa(const DataEmpresa &e)
{
    this->rut = e.rut;
    this->nombre = e.nombre;
}

string DataEmpresa::getRut()
{
	return this->rut;
}

string DataEmpresa::getNombre()
{
	return this->nombre;
}

IDictionary* DataEmpresa::getSucursal()
{
	return this->sucursales;
}

DataEmpresa::~DataEmpresa()
{

}
