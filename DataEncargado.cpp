#include "DataEncargado.h"

DataEncargado::DataEncargado()
{

}

DataEncargado::DataEncargado(string cedula, string nombre, string apellido, Date *fechaNacimiento)
{
    this->cedula=cedula;
    this->nombre=nombre;
    this->apellido=apellido;
    this->fechaNacimiento=fechaNacimiento;
}

DataEncargado::DataEncargado(const DataEncargado &e)
{

}

string DataEncargado::getCedula()
{
	return this->cedula;
}

string DataEncargado::getNombre()
{
	return this->nombre;
}

string DataEncargado::getApellido()
{
	return this->apellido;
}

Date *DataEncargado::getFechaNacimiento()
{
	return this->fechaNacimiento;
}

DataEncargado::~DataEncargado()
{

}
