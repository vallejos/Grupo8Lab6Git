#ifndef DATAOFERTAEMPRESA_H
#define DATAOFERTAEMPRESA_H

#include "DataEmpresa.h"
#include "interfaces/ICollectible.h"

class DataOfertaLaboral;

class DataOfertaEmpresa: public ICollectible {
    public:
        DataOfertaEmpresa();
        DataOfertaEmpresa(DataEmpresa *dataEmpresa, DataOfertaLaboral *dataOferta);
        DataEmpresa* getDataEmpresa();
        DataOfertaLaboral* getDataOfertaLaboral();
        ~DataOfertaEmpresa();
        DataOfertaEmpresa(const DataOfertaEmpresa &doe);

    private:
        DataEmpresa *dataEmpresa;
        DataOfertaLaboral *dataOferta;
};

#include "DataOfertaLaboral.h"

#endif // DATAOFERTAEMPRESA_H
