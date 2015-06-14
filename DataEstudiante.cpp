#include "DataEstudiante.h"

DataEstudiante::DataEstudiante()
{

}

DataEstudiante::DataEstudiante(string cedula, string nombre, string apellido, string telefono, Date *fechaNacimiento,
                                int creditos, string email, IDictionary* carreras, ICollection* aprobadas,
                                ICollection* inscripciones, ICollection* entrevistas);
{
// FALTA HACER
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

string DataEstudiante::getEmail()
{
    return this->email;
}

IDictionary* DataEstudiante::getCarreras()
{
    return this->carreras;
}

ICollection* DataEstudiante::getAprobadas()
{
    return this->aprobadas;
}

ICollection* DataEstudiante::getInscripciones()
{
    return this->inscripciones;
}

ICollection* DataEstudiante::getEntrevistas()
{
    return this->inscripciones;
}

DataEstudiante::~DataEstudiante()
{

}
