#include "Asignatura.h"

Asignatura::Asignatura()
{
    this->codigo = -1;
    this->nombre = '\0';
    this->creditos = 0;
}

Asignatura::Asignatura(int codigo, string nombre, int creditos)
{
    this->codigo = codigo;
    this->nombre = nombre;
    this->creditos = creditos;

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

void Asignatura::setCodigo(int codigo){

    this->codigo = codigo;
}

void Asignatura::setNombre(string nombre){

    this->nombre = nombre;
}

void Asignatura::setCreditos(int creditos){

    this->creditos = creditos;
}

//Que pasa con las operaciones que se repiten en distintas clases, como ésta que la implementa tambien aprobación
DataAsignatura Asignatura::getDataAsignatura(){
    //Debería llamar al constructor de DataAsignatura
    //con los datos codigo,nombre y creditos de asignatura y retornarlo.
}

Asignatura::~Asignatura()
{

}
