#ifndef ESTRATEGIAASIGNATURAS_H
#define ESTRATEGIAASIGNATURAS_H

#include "interfaces/ICollection.h"
#include "interfaces/IDictionary.h"

class EstrategiaAsignaturas
{
    public:
        EstrategiaAsignaturas();
        virtual IDictionary *devolverListaAsignatura(IDictionary* asigsUsuario) = 0;
        virtual ~EstrategiaAsignaturas() = 0;
    protected:
    private:
};

#endif // ESTRATEGIAASIGNATURAS_H
