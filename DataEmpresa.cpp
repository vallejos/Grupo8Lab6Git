#include "DataEmpresa.h"

DataEmpresa::DataEmpresa()
{

}

DataEmpresa::DataEmpresa(string rut, string nombre)
{
    this->rut=rut;
    this->nombre=nombre;
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

ICollection* DataEmpresa::getSucursal()
{
	return this->sucursales;
}

DataEmpresa::~DataEmpresa()
{

}
