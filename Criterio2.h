#ifndef CRITERIO2_H
#define CRITERIO2_H

#include "DataAsignatura.h"
#include "interfaces/ICollection.h"

class Criterio2
{
    public:
        Criterio2();
        ~Criterio2();
        ICollection *devolverListaAsignatura(ICollection *asignaturas);
};

#endif // CRITERIO2_H
