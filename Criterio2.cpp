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
IDictionary *Criterio2::devolverListaAsignatura()
{
    	// pedimos los estudiantes al manejador y vamos recorriendo uno a uno hasta encontrar alguno que tenga materias
	// aprobadas, en ese caso retornamos esa lista
    ManejadorEstudiante *eMgr = ManejadorEstudiante::getInstance();
    IDictionary *e = eMgr->getEstudiantes();

    bool found = false;

    ICollection *aprobadas;
    IDictionary *asignaturas;
    IIterator * it = e->getIterator();
    Estudiante *est;
    ICollectible *col;
    ICollectible *col2;
    while(it->hasCurrent() && !found)
    {
        col = it->getCurrent();
        if ((est = dynamic_cast<Estudiante*> (col)) != NULL)
        {
            if(est->getAprobadas() != NULL)
            {
                aprobadas = est->getAprobadas();
                IIterator * it2 = aprobadas->getIterator();
                while(it2->hasCurrent() && !found)
                {
                    col2 = it2->getCurrent();
                    Aprobacion* apro;
                    if ((apro = dynamic_cast<Aprobacion*> (col2)) != NULL)
                    {
                        Asignatura* asig = apro->getAsignatura();
                        if(asig != NULL)
                        {
                            Integer* cod = new Integer(asig->getCodigo());
                            asignaturas->add(cod, asig);
                        }
                    } else {
                        throw "Criterio1: el parametro no es del tipo Aprobacion";
                    }
                    it2->next();
                }
                delete it2;
                found = true;
            }
        } else {
            throw "Criterio1: el parametro no es del tipo Estudiante";
        }
        it->next();
    }
    delete it;

    return asignaturas;

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
