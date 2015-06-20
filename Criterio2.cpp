#include "Criterio2.h"
#include "interfaces/ICollection.h"
#include "interfaces/IIterator.h"
#include "ManejadorEstudiante.h"
#include "DataEstudiante.h"

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
ICollection *Criterio2::devolverListaAsignatura()
{
    ManejadorEstudiante *eMgr = ManejadorEstudiante::getInstance();
    IDictionary *e = eMgr->getEstudiantes();

    bool found = false;

    ICollection *result;
    IIterator * it = e->getIterator();
    DataEstudiante *da;
    ICollectible *col;
    while(it->hasCurrent() && !found)
    {
        col = it->getCurrent();
        if ((da = dynamic_cast<DataEstudiante*> (col)) != NULL)
        {
            if(da->getAprobadas() != NULL)
            {
                result = da->getAprobadas();
                found = true;
            }
        } else {
            throw "Criterio2: el parametro no es del tipo DataAprobadas";
        }
        it->next();
    }
    delete it;

    return result;

/*
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
*/
}
