#include "Criterio1.h"
#include "interfaces/IDictionary.h"
#include "interfaces/IIterator.h"
#include "ManejadorEstudiante.h"
#include "DataEstudiante.h"

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
IDictionary *Criterio1::devolverListaAsignatura(IDictionary *asignaturas)
{
	// pedimos los estudiantes al manejador y vamos recorriendo uno a uno hasta encontrar alguno que tenga materias
	// aprobadas, en ese caso retornamos esa lista
    ManejadorEstudiante *eMgr = ManejadorEstudiante::getInstance();
    IDictionary *e = eMgr->getEstudiantes();

    bool found = false;

    IDictionary *result;
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
            throw "Criterio1: el parametro no es del tipo DataAprobadas";
        }
        it->next();
    }
    delete it;

    return result;
}
