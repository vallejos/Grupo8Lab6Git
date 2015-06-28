#include "DataEstudiante.h"
#include "collections/OrderedDictionary.h"
#include "collections/List.h"

DataEstudiante::DataEstudiante(string cedula, string nombre, string apellido, string telefono, Date *fechaNacimiento,
                                int creditos, string email, IDictionary* carreras, ICollection* aprobadas, ICollection* inscripciones, ICollection* entrevistas)
{
    this->cedula = cedula;
    this->nombre = nombre;
    this->apellido = apellido;
    this->telefono = telefono;
    this->fechaNacimiento = fechaNacimiento;
    this->creditos = creditos;
    this->email = email;
    this->carreras = carreras;
    this->aprobadas = aprobadas;
    this->inscripciones = inscripciones;
    this->entrevistas = entrevistas;
}

DataEstudiante::DataEstudiante(const DataEstudiante &e)
{
    this->cedula = e.cedula;
    this->nombre = e.nombre;
    this->apellido = e.apellido;
    this->telefono = e.telefono;
    this->fechaNacimiento = e.fechaNacimiento;
    this->creditos = e.creditos;
    this->email = e.email;
    this->carreras = e.carreras;
    this->aprobadas = e.aprobadas;
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
    if (this->fechaNacimiento !=NULL)
        delete this->fechaNacimiento;
}
