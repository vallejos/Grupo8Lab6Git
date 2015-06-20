#ifndef CRITERIO1_H
#define CRITERIO1_H

#include "DataAsignatura.h"
#include "interfaces/IDictionary.h"

class Criterio1
{
    public:
        Criterio1();
        ~Criterio1();
        IDictionary *devolverListaAsignatura(IDictionary *asignaturas);
};

#endif // CRITERIO1_H
