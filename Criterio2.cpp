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
ICollection *Criterio2::devolverListaAsignatura(ICollection *asignaturas)
{
    bool found = false;

    List *result = new List();
    IIterator *it = asignaturas->getIterator();
    while(it->hasCurrent() && !found)
    {
        if(it.current()->getAprobadas() != NULL)
        {
	        result->add(it.current()->getAprobadas());
	        found = true;
        }
        it.next();
    }
    delete it;

    return result;
}
