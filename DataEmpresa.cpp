#include "DataEmpresa.h"

DataEmpresa::DataEmpresa()
{

}

DataEmpresa::DataEmpresa(string rut, string nombre)
{

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

DataSucursal ** DataEmpresa::getSucursal()
{
	return this->sucursales;
}

DataEmpresa::~DataEmpresa()
{

}
