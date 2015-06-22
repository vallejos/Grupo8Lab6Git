#ifndef CRITERIO2_H
#define CRITERIO2_H

#include "DataAsignatura.h"
#include "interfaces/ICollection.h"
#include "EstrategiaAsignaturas.h"

class Criterio2: public EstrategiaAsignaturas
{
    public:
        Criterio2();
        ~Criterio2();
        IDictionary *devolverListaAsignatura(IDictionary* asigsUsuario);
};

#endif // CRITERIO2_H
