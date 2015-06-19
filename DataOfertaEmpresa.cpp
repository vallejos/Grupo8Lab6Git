#include "DataOfertaEmpresa.h"

// constructor
DataOfertaEmpresa::DataOfertaEmpresa()
{
    this->dataEmpresa = NULL;
    this->dataOferta = NULL;

}

DataOfertaEmpresa::DataOfertaEmpresa(DataEmpresa *dataEmpresa, DataOfertaLaboral *dataOferta)
{
    this->dataEmpresa = dataEmpresa;
    this->dataOferta = dataOferta;
}

DataOfertaEmpresa::DataOfertaEmpresa(const DataOfertaEmpresa &doe)
{
    this->dataEmpresa= doe.dataEmpresa;
    this->dataOferta= doe.dataOferta;
}

DataEmpresa* DataOfertaEmpresa::getDataEmpresa()
{
    return this->dataEmpresa;
}

DataOfertaLaboral* DataOfertaEmpresa::getDataOfertaLaboral()
{
    return this->dataOferta;
}

// destructor
DataOfertaEmpresa::~DataOfertaEmpresa()
{
    if (this->dataEmpresa !=NULL)
        delete this->dataEmpresa;
    if (this->dataOferta !=NULL)
        delete this->dataOferta;
}
