#include "Criterio2.h"
#include "interfaces/ICollection.h"
#include "interfaces/IIterator.h"
#include "ManejadorEstudiante.h"
#include "DataEstudiante.h"
#include "Integer.h"
#include "collections/OrderedDictionary.h"

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
IDictionary *Criterio2::devolverListaAsignatura(IDictionary* asigsUsuario)
{
    	// pedimos los estudiantes al manejador y vamos recorriendo uno a uno hasta encontrar alguno que tenga materias
	// aprobadas, en ese caso retornamos esa lista
    ManejadorEstudiante *eMgr = ManejadorEstudiante::getInstance();
    IDictionary *e = eMgr->getEstudiantes();

    bool found = false;

    ICollection *aprobadas;
    IDictionary *asignaturasNuevas = new OrderedDictionary();
    IIterator * it = e->getIterator();
    Estudiante *est;
    ICollectible *col;
    ICollectible *col2;
    ICollectible *col3;
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
                        
                        IIterator * it3 = asigsUsuario->getIterator();
                        while(it3->hasCurrent() && !found)
                        {
                            col3 = it3->getCurrent();
                            Asignatura* asigUsu;
                            if ((asigUsu = dynamic_cast<Asignatura*> (col3)) != NULL)
                            {                                
                                if(asig->getCodigo() == asigUsu->getCodigo())
                                {
                                    Integer* cod = new Integer(asig->getCodigo());
                                    asignaturasNuevas->add(cod, asigUsu);
                                    found = true;
                                }
                            } else {
                                throw "Criterio1: el parametro no es del tipo Asignatura";
                            }
                            it3->next();
                        }
                        delete it3;
                    } else {
                        throw "Criterio1: el parametro no es del tipo Aprobacion";
                    }
                    it2->next();
                }
                delete it2;
            }
        } else {
            throw "Criterio1: el parametro no es del tipo Estudiante";
        }
        it->next();
    }
    delete it;
    
    //if(!found)
        //asignaturas = new OrderedDictionary();
    
    return asignaturasNuevas;
}
