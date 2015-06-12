#ifndef DATAOFERTAEMPRESA_H
#define DATAOFERTAEMPRESA_H

#include "DataEmpresa.h"
#include "DataOfertaLaboral.h"

class DataOfertaEmpresa {
    public:
        DataOfertaEmpresa();
        DataOfertaEmpresa(DataEmpresa *dataEmpresa, DataOfertaLaboral *dataOferta);
        ~DataOfertaEmpresa();
    protected:
    private:
        DataEmpresa *dataEmpresa;
        DataOfertaLaboral *dataOferta;
};

#endif // DATAOFERTAEMPRESA_H
