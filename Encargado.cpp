#include "Encargado.h"

Encargado::Encargado()
{
    this->cedula = '\0';
    this->nombre = '\0';
    this->apellido = '\0';
    this->fechaNacimiento = NULL;
}

Encargado::Encargado(string cedula, string nombre, string apellido, Date* fechaNacimiento)
{
    this->cedula = cedula;
    this->nombre = nombre;
    this->apellido = apellido;
    this->fechaNacimiento = fechaNacimiento;
}

Encargado::Encargado(const Encargado &e)
{
    this->cedula = e.cedula;
    this->nombre= e.nombre;
    this->apellido= e.apellido;
    this->fechaNacimiento= e.fechaNacimiento;
}

DataEncargado *Encargado::getDataEncargado()
{
    return new DataEncargado(this->cedula, this->nombre, this->apellido, this->fechaNacimiento);
}

string Encargado::getCedula()
{
    return this->cedula;
}

string Encargado::getNombre()
{
    return this->nombre;
}

string Encargado::getApellido()
{
    return this->apellido;
}

void Encargado::setCedula(string cedula)
{
    this->cedula = cedula;
}

void Encargado::setNombre(string nombre)
{
    this->nombre = nombre;
}


void Encargado::setApellido(string apellido)
{
    this->apellido = apellido;
}

Date* Encargado::getFechaNacimiento()
{
    return this->fechaNacimiento;
}

void Encargado::setFechaNacimiento(Date* fechaNacimiento)
{
    this->fechaNacimiento= fechaNacimiento;
}

Encargado::~Encargado()
{
    //dtor
    if ((this->fechaNacimiento)!= NULL)
    {
        delete ((this->fechaNacimiento));
    }
}
