#ifndef CRITERIO1_H
#define CRITERIO1_H

#include "DataAsignatura.h"
#include "interfaces/ICollection.h"
#include "EstrategiaAsignaturas.h"

class Criterio1: public EstrategiaAsignaturas
{
    public:
        Criterio1();
        ~Criterio1();
        IDictionary *devolverListaAsignatura();
};

#endif // CRITERIO1_H
