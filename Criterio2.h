#ifndef CRITERIO2_H
#define CRITERIO2_H

#include "DataAsignatura.h"
#include "interfaces/IDictionary.h"

class Criterio2
{
    public:
        Criterio2();
        ~Criterio2();
        IDictionary *devolverListaAsignatura(IDictionary *asignaturas);
};

#endif // CRITERIO2_H
