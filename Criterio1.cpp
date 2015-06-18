#include "Criterio1.h"
#include "interfaces/IDictionary.h"

// constructor
Criterio1::Criterio1()
{

}

// destructor
Criterio1::~Criterio1()
{

}

// Sugiere las materias aprobadas de algun estudiante o NULL en caso de no encontrar estudiantes con materias aprobadas
// Nota: Para el Criterio1, no se necesita la lista de asignaturas
ICollection *Criterio1::devolverListaAsignatura(ICollection *asignaturas)
{
	// pedimos los estudiantes al manejador y vamos recorriendo uno a uno hasta encontrar alguno que tenga materias
	// aprobadas, en ese caso retornamos esa lista
    ManejadorEstudiante *eMgr = ManejadorEstudiante::getInstance();
    IDictionary *e = eMgr->getEstudiantes();

    bool found = false;

    ICollection result = NULL;
    IIterator * it = e->getElemIterator();
    while(it->hasCurrent() && !found)
    {
        if(it->current()->getAprobadas() != NULL)
        {
            result = it->current()->getAprobadas();
            found = true;
        }
        it->next();
    }
    delete it;

    return result;
}
