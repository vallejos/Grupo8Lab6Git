#include "Criterio2.h"
#include "interfaces/IDictionary.h"

// constructor
Criterio2::Criterio2()
{

}

// destructor
Criterio2::~Criterio2()
{

}

// Sugiere una materia de las asignaturas seleccionadas tal que algun Estudiante haya aprobada.
// En caso que no exista se retorna un ICollection vacio (List).
IDictionary *Criterio2::devolverListaAsignatura(IDictionary *asignaturas)
{
    bool found = false;

    List *result = new List();
    IDictionary *it = asignaturas->getIterator();
    while(it->hasCurrent() && !found)
    {
        if(it->getCurrent()->getAprobadas() != NULL)
        {
	        result->add(it->getCurrent()->getAprobadas());
	        found = true;
        }
        it->next();
    }
    delete it;

    return result;
}
