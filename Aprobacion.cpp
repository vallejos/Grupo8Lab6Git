#include "Aprobacion.h"

Aprobacion::Aprobacion()
{
    //ctor
    this->nota = 0;
    this->fecha = NULL;
    this->asig = NULL;
}

Aprobacion::Aprobacion(Date* fecha, int nota, Asignatura* asig)
{
    this->fecha = fecha;
    this->nota = nota;
    this->asig = asig;
}

Aprobacion::Aprobacion(const Aprobacion &a)
{
    this->fecha = a.fecha;
    this->nota = a.nota;
    this->asig = a.asig;
}

Date* Aprobacion::getFecha()
{
    return this->fecha;
}

int Aprobacion::getNota()
{
    return this->nota;
}

Asignatura* Aprobacion::getAsignatura()
{
    return this->asig;
}

DataAprobada* Aprobacion::getDataAprobada()
{
    DataAsignatura* dAs = new DataAsignatura(this->asig->getCodigo(), this->asig->getNombre(), this->asig->getCreditos(), this->asig->getCarreras());
    DataAprobada* dAp = new DataAprobada(this->nota, this->fecha, dAs);

    return dAp;
}

DataAsignatura* Aprobacion::getDataAsignatura()
{
    DataAsignatura* dAs = new DataAsignatura(this->asig->getCodigo(), this->asig->getNombre(), this->asig->getCreditos(), this->asig->getCarreras());
    return dAs;
}

void Aprobacion::setFecha(Date* fecha)
{
    this->fecha = fecha;
}

void Aprobacion::setNota(int nota)
{
    this->nota = nota;
}

void Aprobacion::setAsignatura(Asignatura* a)
{
    this->asig = a;
}

Aprobacion::~Aprobacion()
{
    //dtor
    if (this->asig != NULL)
        delete this->asig;
    if (this->fecha != NULL)
        delete this->fecha;
}
