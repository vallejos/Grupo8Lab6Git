#ifndef DATADATOSESTUDIANTE_H
#define DATADATOSESTUDIANTE_H

#include "DataAprobada.h"
#include "DataOfertaEmpresa.h"

class DataDatosEstudiante: public ICollectible {
    public:
        DataDatosEstudiante();
        DataDatosEstudiante(ICollection* dataAprobadas, ICollection* dataOfertasEmpresas);
        ICollection* getDataAprobadas();
        ICollection* getDataOfertasEmpresas();
        ~DataDatosEstudiante();
    protected:
    private:
        ICollection* dataAprobadas;
        ICollection* dataOfertasEmpresas;
};

#endif // DATADATOSESTUDIANTE_H
