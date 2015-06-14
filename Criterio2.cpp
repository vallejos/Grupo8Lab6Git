#include "Criterio2.h"
#include "IDictionary.h"

// constructor
Criterio2::Criterio2()
{

}

// destructor
Criterio2::~Criterio2()
{

}

// Sugiere una materia de las asignaturas seleccionadas tal que algun Estudiante haya aprobada.
// En caso que no exista se retorna NULL.
ICollection *Criterio1::devolverListaAsignatura(ICollection *asignaturas)
{
	// pedimos los estudiantes al manejador y vamos recorriendo uno a uno hasta encontrar alguno que tenga materias
	// aprobadas, en ese caso retornamos esa lista
    ManejadorEstudiante *eMgr = ManejadorEstudiante::getInstance();
    IDictionary *e = eMgr->getEstudiantes();

    bool found = false;

    List *result = new List();
    IIterator *it = asignaturas->getIterator();
    while(it.hasCurrent() && !found)
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
