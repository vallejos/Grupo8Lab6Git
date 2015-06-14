#ifndef CRITERIO1_H
#define CRITERIO1_H

#include "DataAsignatura.h"
#include "ICollection.h"

class Criterio1
{
    public:
        Criterio1();
        ~Criterio1();
        ICollection *devolverListaAsignatura(ICollection *asignaturas);
    protected:
    private:
};

#endif // CRITERIO1_H