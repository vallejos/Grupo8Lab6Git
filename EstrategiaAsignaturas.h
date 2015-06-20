#ifndef ESTRATEGIAASIGNATURAS_H
#define ESTRATEGIAASIGNATURAS_H

#include "interfaces/ICollection.h"

class EstrategiaAsignaturas
{
    public:
        EstrategiaAsignaturas();
        virtual ICollection *devolverListaAsignatura() = 0;
        virtual ~EstrategiaAsignaturas() = 0;
    protected:
    private:
};

#endif // ESTRATEGIAASIGNATURAS_H
