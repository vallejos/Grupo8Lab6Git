#include "ManejadorOfertaLaboral.h"
#include "String.h"
#include "Estudiante.h"
#include "Seccion.h"
#include "collections/OrderedDictionary.h"

ManejadorOfertaLaboral* ManejadorOfertaLaboral::instance = NULL;

ManejadorOfertaLaboral::ManejadorOfertaLaboral()
{
    this->ofertasLaborales = new OrderedDictionary();
}

ManejadorOfertaLaboral *ManejadorOfertaLaboral::getInstance()
{
    //Se crea una instancia de ManejadorOfertaLaboral.
    if(instance == NULL)
        instance = new ManejadorOfertaLaboral();
    return instance;
}

IDictionary *ManejadorOfertaLaboral::getDataOfertaLaboral()
{
    //Se rotorna un set de DataOfertaLaboral con las ofertas activas del sistema.
    //Va a recorrer la coleccion que tiene como pseudoatributo de Ofertas e ir creando DataOfertas para luego retornar una coleccion de las mismas.
    OrderedDictionary* result = new OrderedDictionary();
    IIterator * it = this->ofertasLaborales->getIterator();
    while(it->hasCurrent())
        {
            OfertaLaboral* ol;
            if( ( ol = dynamic_cast<OfertaLaboral*> (it->getCurrent())) != NULL )
            {
                if(ol->EsActiva())
                {
                    string numExpediente = ol->getNumExpediente();
                    String *nExp = new String(numExpediente.c_str());
                    result->add(nExp,ol->getDataOfertaLaboral());
                }
            }else
            {
                throw "ManejadorOfertaLaboral -> El objeto no es de la clase OfertaLaboral.";
            }
            it->next();
        }
        delete it;
    return result;
}

IDictionary *ManejadorOfertaLaboral::getAllDataOfertaLaboral()
{
    //Se rotorna un set de DataOfertaLaboral con las ofertas del sistema.
    //Va a recorrer la coleccion que tiene como pseudoatributo de Ofertas e ir creando DataOfertas para luego retornar un una coleccion de las mismas.
    OrderedDictionary* result = new OrderedDictionary();
    IIterator * it = this->ofertasLaborales->getIterator();
    while(it->hasCurrent())
    {
        OfertaLaboral *ol;
        if (( ol = dynamic_cast<OfertaLaboral*> (it->getCurrent())) != NULL)
        {
            string numExpediente = ol->getNumExpediente();
            String *nExp = new String(numExpediente.c_str());
            result->add(nExp,ol->getDataOfertaLaboral());
        }else
        {
            throw "ManejadorOfertaLaboral -> El objeto no es de la clase OfertaLaboral.";
        }
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
    String *numExp = new String(numExpediente.c_str());
    OfertaLaboral *ol;
    if( (ol = dynamic_cast<OfertaLaboral*> (this->ofertasLaborales->find(numExp))) != NULL )
    {
        return ol;
    }else
    {
        throw "ManejadorOfertaLaboral -> El objeto no es de la clase OfertaLaboral.";
    }
}

void ManejadorOfertaLaboral::addOfertaManejador(OfertaLaboral *ol)
{
    //Se agrega a la coleccion de ofertas del manejador una oferta que fue dada de alta por seccion.
    //obtener numexpediente y hacer add (ikey, objeto)
    string numExpediente = ol->getNumExpediente();
    String *numExp = new String(numExpediente.c_str());
    this->ofertasLaborales->add(numExp,ol);
}

void ManejadorOfertaLaboral::DarDeBajaLlamado(OfertaLaboral *ol)
{
    //Quiero moverme por la coleccion de inscripciones de esta oferta e ir borrando el link con estudiante
    //luego borrar la coleccion de inscripciones, borrar el link con seccion, borrar la coleccion de asignaturas (con el destructor de oferta creo)
    //luego dar de baja la oferta de la coleccion de ofertasLaborales
    string numExpediente = ol->getNumExpediente();
    String *numExp = new String(numExpediente.c_str());
    OfertaLaboral *o;
    if( (o = dynamic_cast<OfertaLaboral*> (this->ofertasLaborales->find(numExp))) != NULL )
    {
        ICollection *inscripciones = o->getInscripciones();
        IIterator * it = inscripciones->getIterator();
        while(it->hasCurrent())
        {
            Inscripcion *inscrip;
            if( (inscrip = dynamic_cast<Inscripcion*> (it->getCurrent())) != NULL )
            {
                Estudiante *e = inscrip->getEstudiante();
                ICollection *insc = e->getInscripciones();
                insc->remove(inscrip);
            }
            else
            {
                throw "ManejadorOfertaLaboral -> El objeto no es de la clase Inscripcion.";
            }
            it->next();
        }
        delete it;
        ICollection *entrevistas = o->getEntrevistas();
        IIterator * it2 = entrevistas->getIterator();
        while(it2->hasCurrent())
        {
            Entrevista *interview;
            if( (interview = dynamic_cast<Entrevista*> (it2->getCurrent())) != NULL )
            {
                Estudiante *e = interview->getEstudiante();
                ICollection *entre = e->getEntrevistas();
                entre->remove(interview);
            }
            else
            {
                throw "ManejadorOfertaLaboral -> El objeto no es de la clase Entrevista.";
            }
        }
        delete it2;
        Seccion *seccion = o->getSeccion();
        IDictionary *ofertas = seccion->getOfertasLaborales();
        ofertas->remove(numExp);
        this->ofertasLaborales->remove(numExp);
    }else
    {
        throw "ManejadorOfertaLaboral -> El objeto no es de la clase OfertaLaboral.";
    }

}
void ManejadorOfertaLaboral::destroyManejadorOfertaLaboral()
{
     if (instance != NULL)
     {
        // debo liberar la memoria de la coleccion de ofertasLaborales
        if (! this->ofertasLaborales->isEmpty())
           delete this->ofertasLaborales;
        delete instance;
        instance = NULL;
    }
}

void ManejadorOfertaLaboral::ModificarOferta(string numExpediente, string titulo, string descripcion, int cantHorasSemanales, Rango *rangoSalarial, Date *fechaIni,
            Date *fechaFin, int cantidadPuestos, IDictionary *asignaturas, Seccion *seccion, ICollection *inscripciones,
            ICollection *entrevistas)
{
//Pre: ningun dato del nuevosDatos es vacio.
//p.e si el usuario no modifica el titulo, el DataOfertaLaboral debe contener el titulo de la oferta y no ser vacio
    String *numExp = new String(numExpediente.c_str());
    OfertaLaboral* ol;
    if( (ol = dynamic_cast<OfertaLaboral*> (this->ofertasLaborales->find(numExp))) != NULL ){
        ol->setTitulo(titulo);
        ol->setDescripcion(descripcion);
        ol->setCantidadHorasSemanales(cantHorasSemanales);
        ol->setRangoSalarial(rangoSalarial);
        ol->setFechaComienzo(fechaIni);
        ol->setFechaFin(fechaFin);
        ol->setCantidadPuestosNecesarios(cantidadPuestos);
        ol->setInscripciones(inscripciones);
        ol->setEntrevistas(entrevistas);
        ol->setAsignaturas(asignaturas);
        ol->setSeccion(seccion);
    }else
    {
        throw "ManejadorOfertaLaboral -> El objeto no es de la clase OfertaLaboral.";
    }
}

ManejadorOfertaLaboral::~ManejadorOfertaLaboral()
{

}
