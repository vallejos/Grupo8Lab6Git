#ifndef ESTRATEGIAASIGNATURAS_H
#define ESTRATEGIAASIGNATURAS_H

#include <string>
#include "ICollection.h"

using namespace std;

class EstrategiaAsignaturas
{
    public:
        virtual ICollection *devolverListaAsignatura() = 0;
};

#endif // ESTRATEGIAASIGNATURAS_H
