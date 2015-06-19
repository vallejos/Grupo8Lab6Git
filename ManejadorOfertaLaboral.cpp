#include "ManejadorOfertaLaboral.h"
#include "String.h"
#include "Estudiante.h"
#include "Seccion.h"

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
    IIterator * it = this->ofertasLaborales->getIterator();
    while(it->hasCurrent())
    {
        if(it->getCurrent()->EsActiva())
            result->add(it->getCurrent()->getDataOfertaLaboral());
        it->next();
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
    while(it->hasCurrent())
    {
        result->add(it->getCurrent()->getDataOfertaLaboral());
        it->next();
    }
    delete it;
    return result;

}

IDictionary* ManejadorOfertaLaboral::getOfertasLaborales()
{
    return this->ofertasLaborales;
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
    //Quiero moverme por la coleccion de inscripciones de esta oferta e ir borrando el link con estudiante
    //luego borrar la coleccion de inscripciones, borrar el link con seccion, borrar la coleccion de asignaturas (con el destructor de oferta creo)
    //luego dar de baja la oferta de la coleccion de ofertasLaborales
    string numExpediente = ol->getNumExpediente();
    String *numExp = String(numExpediente);
    OfertaLaboral *o = this->ofertasLaborales->find(numExp);// Es necesario buscarla si ya me pasan el puntero a la oferta que debo eliminar?
    ICollection *inscripciones = o->getInscripciones();
    IIterator * it = inscripciones->getIterator();
    while(it->hasCurrent())
    {
        Estudiante *e = it->getCurrent()->getEstudiante();
        ICollection *insc = e->getInscripciones();
        insc->remove(it->getCurrent());
        it->getCurrent()->estudiant = NULL;// para que al llamar al destructor de oferta al final no destruya al estudiante cuando destruye la inscripcion
        it->next();
    }
    delete it;
    ICollection *entrevistas = o->getEntrevistas();
    IIterator * it2 = entrevistas->getIterator();
    while(it2->hasCurrent())
    {
        Estudiante *e = it2->getCurrent()->getEstudiante();
        ICollection *entre = e->getEntrevistas();
        entre->remove(it2->getCurrent());
        it2->getCurrent()->estudiant = NULL;// igual que arriba no se si esté bien
        it2->next();
    }
    delete it2;
    Seccion *seccion = o->getSeccion();
    seccion->ofertasLaborales->remove(numExp);
    o->seccion = NULL;// no se si sea asi, con aignaturas debería iterar e ir asignandole NULL antes de llamar al destructor de oferta?
    this->ofertasLaborales->remove(numExp);
    delete o;

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
