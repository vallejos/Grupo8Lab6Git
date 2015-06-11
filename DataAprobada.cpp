#include "DataAprobada.h"

DataAprobada::DataAprobada()
{
    //ctor
    this->nota = 0;
    this->fecha = NULL;
    this->asig = NULL;
}

DataAprobada::DataAprobada(int nota, Date* fecha, DataAsignatura* dAsig)
{
    this->nota = nota;
    this->fecha = fecha;
    this->asig = dAsig;
}

DataAprobada::DataAprobada(const DataAprobada &dAp)
{
    this->nota = dAp.nota;
    this->fecha = dAp.fecha;
    this->asig = dAp.asig;
}

int DataAprobada::getNota()
{
    return this->nota;
}

Date* DataAprobada::getFecha()
{
    return this->fecha;
}

DataAsignatura* DataAprobada::getDataAsignatura()
{
    return this->asig;
}

DataAprobada::~DataAprobada()
{
    //dtor
}