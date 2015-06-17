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

DataEmpresa* DataOfertaEmpresa::getDataEmpresa()
{
    return this->dataEmpresa;
}

DataOfertaLaboral* DataOfertaEmpresa::getDataOfertaLaboral()
{
    return this->dataOferta;
}

// destructor
DataOfertaEmpresa::~DataOfertaEmpresa() {

}
