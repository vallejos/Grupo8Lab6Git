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
