#include "DataDatosEstudiante.h"

// constructor
DataDatosEstudiante::DataDatosEstudiante() {
    this->dataAprobadas = NULL;
    this->dataOfertasEmpresas = NULL;
}

DataDatosEstudiante::DataDatosEstudiante(ICollection* dataAprobadas, ICollection* dataOfertasEmpresas)
{
    this->dataAprobadas = dataAprobadas;
    this->dataOfertasEmpresas = dataOfertasEmpresas;
}

ICollection* DataDatosEstudiante::getDataAprobadas()
{
    return this->dataAprobadas:
}

ICollection* DataDatosEstudiante::getDataOfertasEmpresas()
{
    return this->dataOfertasEmpresas;
}

// destructor
DataDatosEstudiante::~DataDatosEstudiante() {

}
