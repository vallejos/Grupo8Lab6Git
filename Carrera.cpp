#include "Carrera.h"

Carrera::Carrera()
{
    //ctor
    this->codigo = 0;
    this->nombreCarrera = "";
}

Carrera::Carrera(const Carrera &c)
{
    this->codigo = c.codigo;
    this->nombreCarrera = c.nombreCarrera;
}

Carrera::Carrera(int codigo, string nombreCarrera)
{
    this->codigo = codigo;
    this->nombreCarrera = nombreCarrera;
}

int Carrera::getCodigo()
{
    return this->codigo;
}

string Carrera::getNombreCarrera()
{
    return this->nombreCarrera:
}

DataCarrera* Carrera::getDataCarrera()
{
    DataCarrera* dataC = new DataCarrera(this->codigo, this->nombreCarrera);
    return dataC;
}

void Carrera::setCodigo(int codigo)
{
    this->codigo = codigo;
}

void Carrera::setNombreCarrera(string nombreCarrera)
{
    this->nombreCarrera = nombreCarrera;
}

Carrera::~Carrera()
{
    //dtor
}