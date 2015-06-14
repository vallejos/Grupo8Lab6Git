#ifndef CRITERIO2_H
#define CRITERIO2_H

#include "DataAsignatura.h"
#include "ICollection.h"

class Criterio2
{
    public:
        Criterio2();
        ~Criterio2();
        ICollection *devolverListaAsignatura(ICollection *asignaturas);
    protected:
    private:
};

#endif // CRITERIO2_H