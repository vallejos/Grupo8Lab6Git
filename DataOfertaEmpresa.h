#ifndef DATAOFERTAEMPRESA_H
#define DATAOFERTAEMPRESA_H

#include "DataEmpresa.h"
#include "DataOfertaLaboral.h"

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

#endif // DATAOFERTAEMPRESA_H
