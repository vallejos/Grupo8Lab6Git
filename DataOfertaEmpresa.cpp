#include "DataOfertaEmpresa.h"

// constructor
DataOfertaEmpresa::DataOfertaEmpresa()
{

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

}
