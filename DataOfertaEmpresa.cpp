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

// destructor
DataOfertaEmpresa::~DataOfertaEmpresa() {

}
