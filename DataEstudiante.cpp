#include "DataEstudiante.h"

DataEstudiante::DataEstudiante()
{

}

DataEstudiante::DataEstudiante(string cedula, string nombre, string apellido, string telefono, Date *fechaNacimiento, int creditos)
{

}

DataEstudiante::DataEstudiante(const DataEstudiante &e)
{

}

string DataEstudiante::getCedula()
{
	return this->cedula;
}

string DataEstudiante::getNombre()
{
	return this->nombre;
}

string DataEstudiante::getApellido()
{
	return this->apellido;
}

string DataEstudiante::getTelefono()
{
	return this->telefono;
}

Date *DataEstudiante::getFechaNacimiento()
{
	return this->fechaNacimiento;
}

int DataEstudiante::getCreditos()
{
	return this->creditos;
}

DataCarrera ** DataEstudiante::getCarreras()
{
	return this->carreras;
}

DataAsignatura ** DataEstudiante::getAsignaturas()
{
	return this->asignaturas;
}

DataEstudiante::~DataEstudiante()
{

}
