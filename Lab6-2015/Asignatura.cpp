#include "Asignatura.h"
#include "collections/OrderedDictionary.h"

Asignatura::Asignatura()
{
    this->codigo = 0;
    this->nombre = '\0';
    this->creditos = 0;
    this->carreras = new OrderedDictionary();
}

Asignatura::Asignatura(int codigo, string nombre, int creditos)
{
    this->codigo = codigo;
    this->nombre = nombre;
    this->creditos = creditos;
    this->carreras = new OrderedDictionary();
}

Asignatura::Asignatura(const Asignatura &a)
{
    this->codigo = a.codigo;
    this->nombre = a.nombre;
    this->creditos = a.creditos;

}

int Asignatura::getCodigo()
{
	return this->codigo;
}

string Asignatura::getNombre()
{
	return this->nombre;
}

int Asignatura::getCreditos()
{
	return this->creditos;
}

IDictionary* Asignatura::getCarreras()
{
    return this->carreras;
}

void Asignatura::setCarreras(IDictionary* carreras)
{
    this->carreras = carreras;
}

void Asignatura::setCodigo(int codigo)
{

    this->codigo = codigo;
}

void Asignatura::setNombre(string nombre)
{

    this->nombre = nombre;
}

void Asignatura::setCreditos(int creditos)
{

    this->creditos = creditos;
}

DataAsignatura *Asignatura::getDataAsignatura()
{
    //Llama al constructor de DataAsignatura
    //con los datos codigo, nombre y creditos de asignatura y lo retorna.
    return new DataAsignatura(this->codigo, this->nombre, this->creditos, this->carreras);
}

Asignatura::~Asignatura()
{
    //dtor
    delete this->carreras;
}
