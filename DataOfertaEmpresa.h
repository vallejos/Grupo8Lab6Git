#ifndef DATAOFERTAEMPRESA_H
#define DATAOFERTAEMPRESA_H

#include "DataEmpresa.h"

class DataOfertaLaboral;

class DataOfertaEmpresa {
    public:
        DataOfertaEmpresa();
        DataOfertaEmpresa(DataEmpresa *dataEmpresa, DataOfertaLaboral *dataOferta);
        DataEmpresa* getDataEmpresa();
        DataOfertaLaboral* getDataOfertaLaboral();
        ~DataOfertaEmpresa();

    private:
        DataEmpresa *dataEmpresa;
        DataOfertaLaboral *dataOferta;
};

#include "DataOfertaLaboral.h"

#endif // DATAOFERTAEMPRESA_H
