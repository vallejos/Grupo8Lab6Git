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
    IDictionary* allOfertas = mo->getAllDataOfertaLaboral();
    if (allOfertas->isEmpty())
        throw "OfertaLaboralController -> No hay ofertas ingresadas en el Sistema.";
    return allOfertas;
}

void OfertaLaboralController::SeleccionarOferta(string numExpediente, IDictionary *ofertasLabVigentes)
{
    ManejadorOfertaLaboral *mo = ManejadorOfertaLaboral::getInstance();
    String* numExp = new String(numExpediente.c_str());
    if(! (ofertasLabVigentes->member(numExp)))
        throw "El Numero de Expediente no es valido.";
    this->oferta = mo->SeleccionarOferta(numExpediente);
}

void OfertaLaboralController::Inscribir(Date *fechaInscripcion)
{
    if (this->oferta == NULL)
        throw "El sistema no recuerda a ninguna Oferta Laboral Seleccionada";
    this->oferta->Inscribir(fechaInscripcion);
}

void OfertaLaboralController::Entrevistar(Date *fechaEntrevista)
{
    if (this->oferta == NULL)
        throw "El sistema no recuerda a ninguna Oferta Laboral Seleccionada";
    this->oferta->Entrevistar(fechaEntrevista);
}

IDictionary *OfertaLaboralController::MostrarOfertasActivas()
{
    ManejadorOfertaLaboral * mol = ManejadorOfertaLaboral::getInstance();
    IDictionary *ofertasActivas = mol->getDataOfertaLaboral();
    if (ofertasActivas->isEmpty())
         throw "OfertaLaboralController-> no hay Ofertas Laborales Activas en el Sistema.";
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
}

void OfertaLaboralController::DarBajaLlamado()
{
    if (this->oferta == NULL)
        throw "El sistema no recuerda a ninguna Oferta Laboral Seleccionada";
    ManejadorOfertaLaboral *mo = ManejadorOfertaLaboral::getInstance();
    mo->DarDeBajaLlamado(this->oferta);
}
