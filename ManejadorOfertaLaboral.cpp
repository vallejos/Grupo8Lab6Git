#include "ManejadorOfertaLaboral.h"
#include "String"

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
    //Se rotorna un set de DataOfertaLaboral con las ofertas activas del sistema.
    //Va a recorrer la coleccion que tiene como pseudoatributo de Ofertas e ir creando DataOfertas para luego retornar una coleccion de las mismas.
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

}

ICollection *ManejadorOfertaLaboral::getAllDataOfertaLaboral()
{
    //Se rotorna un set de DataOfertaLaboral con las ofertas del sistema.
    //Va a recorrer la coleccion que tiene como pseudoatributo de Ofertas e ir creando DataOfertas para luego retornar un una coleccion de las mismas.
    List* result = new List();
    IIterator * it = this->ofertasLaborales->getElemIterator();
    while(it.hasCurrent())
    {
        result->add(it.current()->getDataOfertaLaboral());
        it.next();
    }
    delete it;
    return result;

}


OfertaLaboral *ManejadorOfertaLaboral::SeleccionarOferta(string numExpediente)
{
    //Va a buscar en la coleccion que tiene de ofertas como pseudoatributo la oferta con numero de expediente numExpediente.
    String *numExp = String(numExpediente);
    return this->ofertasLaborales->find(numExp);
}

void ManejadorOfertaLaboral::addOfertaManejador(OfertaLaboral *ol)
{
    //Se agrega a la coleccion de ofertas del manejador una oferta que fue dada de alta por seccion.
    //obtener numexpediente y hacer add (ikey, objeto)
    string numExpediente = ol->getNumExpediente();
    String *numExp = String(numExpediente);
    this->ofertasLaborales->add(numExp,ol);
}

void ManejadorOfertaLaboral::DarDeBajaLlamado(OfertaLaboral *ol)
{
   //buscar oferta
   // recorrer inscripciones y borrar link con estudiantes
   //borrar coleccion inscripciones
   //borrar oferta de IDictionary
    string numExpediente = ol->getNumExpediente();
    String *numExp = String(numExpediente);
    OfertaLaboral *o = this->ofertasLaborales->find(numExp);

    //Quiero moverme por la coleccion de inscripciones de esta oferta e ir borranco el link con estudiante
    //luego borrar la coleccion de inscripciones, borrar el link con seccion, borrar la coleccion de asignaturas (con el destructor de oferta creo)
    //luego dar de baja la oferta de la coleccion de ofertasLaborales
}
void ManejadorOfertaLaboral::destroyManejadorOfertaLaboral()
{
     if (instance != NULL)
     {
        delete ManejadorOfertaLaboral;
     }
}

void ManejadorOfertaLaboral::ModificarOferta(string numExpediente, DataOfertaLaboral* nuevosDatos)
{
//Pre: ningun dato del nuevosDatos es vacio.
//p.e si el usuario no modifica el titulo, el DataOfertaLaboral debe contener el titulo de la oferta y no ser vacio
    OfertaLaboral* ol = this->ofertasLaborales->find(numExpediente);
    ol->setTitulo(nuevosDatos->getTitulo());
    ol->setDescripcion(nuevosDatos->getDescripcion());
    ol->setCantidadHorasSemanales(nuevosDatos->getCantidadHorasSemanales());
    ol->setRangoSalarial(nuevosDatos->getRangoSalarial());
    ol->setFechaComienzo(nuevosDatos->getFechaComienzo());
    ol->setFechaFin(nuevosDatos->getFechaFin());
    ol->setCantidadPuestosNecesarios(nuevosDatos->getCantidadPuestosNecesarios());
    ol->setInscripciones(nuevosDatos->getInscripciones());
    ol->setEntrevistas(nuevosDatos->getEntrevistas());
    ol->setAsignaturas(nuevosDatos->getAsignaturas());
}

ManejadorOfertaLaboral::~ManejadorOfertaLaboral()
{
    // debo liberar la memoria de la coleccion de ofertasLaborales
    if (this->ofertasLaborales != NULL)
        delete this->ofertasLaborales;
    delete instance;
    instance = NULL;
}
