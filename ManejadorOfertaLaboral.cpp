#include "ManejadorOfertaLaboral.h"

ManejadorOfertaLaboral* ManejadorOfertaLaboral::instance = NULL;

ManejadorOfertaLaboral::ManejadorOfertaLaboral()
{
    this->ofertasLaborales = NULL;
}

ManejadorOfertaLaboral *ManejadorOfertaLaboral::getInstance()
{
    //Se crea una instancia de ManejadorOfertaLaboral.
    if(instance == NULL)
        instance = new ManejadorOfertaLaboral();
    return instance;
}

ICollection *ManejadorOfertaLaboral::getDataOfertaLaboral()
{
    List* result = new List();
    IIterator * it = this->ofertasLaborales->getElemIterator();
    while(it.hasCurrent())
    {
        if(it.current()->EsActiva())
            result->add(it.current()->getDataOfertaLaboral());
        it.next();
    }
    delete it;
    return result;
    //Se rotorna un set de DataOfertaLaboral con las ofertas del sistema.
    //Va a recorrer la coleccion que tiene como pseudoatributo de Ofertas e ir creando DataOfertas para luego retornar un set de las mismas.
}

ICollection *ManejadorOfertaLaboral::getAllDataOfertaLaboral()
{
    List* result = new List();
    IIterator * it = this->ofertasLaborales->getElemIterator();
    while(it.hasCurrent())
    {
        result->add(it.current()->getDataOfertaLaboral());
        it.next();
    }
    delete it;
    return result;
    //Se rotorna un set de DataOfertaLaboral con las ofertas del sistema.
    //Va a recorrer la coleccion que tiene como pseudoatributo de Ofertas e ir creando DataOfertas para luego retornar un set de las mismas.
}


void ManejadorOfertaLaboral::SeleccionarOferta(string numExpediente)
{
    //Va a buscar en la coleccion que tiene de ofertas como pseudoatributo la oferta con numero de expediente numExpediente.
    return this->ofertasLaborales->find(numExpediente);// si es void no habria que retornar una oferta laboral //creo que lo que no va es el return
}

void ManejadorOfertaLaboral::addOfertaManejador(OfertaLaboral ol)
{
    //Se agrega a la coleccion de ofertas del manejador una oferta que fue dada de alta y que conoce seccion.
    //obtener numexpediente y hacer add (ikey, objeto)
}

void ManejadorOfertaLaboral::AltaAsignacionCargo()
{
    // con el estudiante y la oferta recordadas en memoria
    // accedo a la inscripcion y le setteo la efectivizacion (de la inscripcion)
    // no se con que fecha ni con que sueldo :/
}


void ManejadorOfertaLaboral::DarDeBajaLlamado()
{
   //buscar oferta
   // recorrer inscripciones y borrar link con estudiantes
   //borrar coleccion inscripciones
   //borrar oferta de IDictionary
    //Va a dar de baja una oferta que el manejador recuerda de alguna manera.
}

ManejadorOfertaLaboral::~ManejadorOfertaLaboral()
{

}
