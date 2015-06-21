#include "OfertaLaboralController.h"
#include "ManejadorOfertaLaboral.h"

OfertaLaboralController* OfertaLaboralController::instance = NULL;

OfertaLaboralController::OfertaLaboralController()
{
// constructor
}

OfertaLaboralController::~OfertaLaboralController()
{
// destructor
}

OfertaLaboralController *OfertaLaboralController::getInstance()
{
	if (instance == NULL)
		instance = new OfertaLaboralController();
	return instance;
}

IDictionary *OfertaLaboralController::ListarOfertas()
{
    ManejadorOfertaLaboral *mo = ManejadorOfertaLaboral::getInstance();
    return mo->getAllDataOfertaLaboral();
}

void OfertaLaboralController::SeleccionarOferta(string numExpediente, IDictionary *ofertasLabVigentes)
{
    ManejadorOfertaLaboral *mo = ManejadorOfertaLaboral::getInstance();
    String* numExp = new String(numExpediente.c_str());
    if(! (ofertasLabVigentes->member(numExp)))
        throw "El Número de Expediente" + numExpediente + " no es válido.";
    this->oferta = mo->SeleccionarOferta(numExpediente);
}

void OfertaLaboralController::Inscribir(Date *fechaInscripcion)
{
    if (this->oferta == NULL)
        throw "El sistema no recuerda a ninguna Oferta Laboral Seleccionada";
    this->oferta->Inscribir(fechaInscripcion);
    //BORRAR MEMORIA ?? oferta y estudiante en memoria
}

void OfertaLaboralController::Entrevistar(Date *fechaEntrevista)
{
    if (this->oferta == NULL)
        throw "El sistema no recuerda a ninguna Oferta Laboral Seleccionada";
    this->oferta->Entrevistar(fechaEntrevista);
    //BORRAR MEMORIA ?? oferta y estudiante en memoria
}

IDictionary *OfertaLaboralController::MostrarOfertasActivas()
{
    ManejadorOfertaLaboral * mol = ManejadorOfertaLaboral::getInstance();
    IDictionary *ofertasActivas = mol->getDataOfertaLaboral();
    if (ofertasActivas == NULL)
         throw "No existe una Oferta Activa";
    return ofertasActivas;
}

OfertaLaboral* OfertaLaboralController::getOfertaLaboral()
{
    if (this->oferta == NULL)
        throw "El sistema no recuerda a ninguna Oferta Laboral Seleccionada";
    return this->oferta;
}

void OfertaLaboralController::ModificarOferta(string numExpediente, string titulo, string descripcion, int cantHorasSemanales, Rango *rangoSalarial, Date *fechaIni,
            Date *fechaFin, int cantidadPuestos, IDictionary *asignaturas, Seccion *seccion, ICollection *inscripciones,
            ICollection *entrevistas)
{
    ManejadorOfertaLaboral *mol = ManejadorOfertaLaboral::getInstance();
    mol->ModificarOferta(numExpediente, titulo, descripcion, cantHorasSemanales, rangoSalarial, fechaIni,
            fechaFin, cantidadPuestos, asignaturas, seccion, inscripciones, entrevistas);
}

void OfertaLaboralController::AltaAsignacionDelCargo(Date* fechaEfectivizacion, int sueldo)
{
    //ManejadorOfertaLaboral *mo = ManejadorOfertaLaboral::getInstance();
    if (this->oferta == NULL)
        throw "El sistema no recuerda a ninguna Oferta Laboral Seleccionada";
    this->oferta->AltaAsignacionCargo(fechaEfectivizacion, sueldo);
    // BORRAR MEMORIA??
}

void OfertaLaboralController::DarBajaLlamado()
{
    if (this->oferta == NULL)
        throw "El sistema no recuerda a ninguna Oferta Laboral Seleccionada";
    ManejadorOfertaLaboral *mo = ManejadorOfertaLaboral::getInstance();
    mo->DarDeBajaLlamado(this->oferta);
}
