#include "DataDatosEstudiante.h"
#include "collections/List.h"

// constructor
DataDatosEstudiante::DataDatosEstudiante(ICollection* dataAprobadas, ICollection* dataOfertasEmpresas)
{
    this->dataAprobadas = dataAprobadas;
    this->dataOfertasEmpresas = dataOfertasEmpresas;
}

DataDatosEstudiante::DataDatosEstudiante(const DataDatosEstudiante &dde)
{
    this->dataAprobadas = dde.dataAprobadas;
    this->dataOfertasEmpresas = dde.dataOfertasEmpresas;
}

ICollection* DataDatosEstudiante::getDataAprobadas()
{
    return this->dataAprobadas;
}

ICollection* DataDatosEstudiante::getDataOfertasEmpresas()
{
    return this->dataOfertasEmpresas;
}

// destructor
DataDatosEstudiante::~DataDatosEstudiante()
{

}
