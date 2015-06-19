#include "OfertaLaboralController.h"

// constructor
OfertaLaboralController::OfertaLaboralController() {

}

// destructor
OfertaLaboralController::~OfertaLaboralController() {

}

OfertaLaboralController *OfertaLaboralController::getInstance() {
	if (this->instance == NULL) {
		this->instance = new OfertaLaboralController();
	}
	return this->instance;
}

ICollection *OfertaLaboralController::ListarOfertas() {
	try {
		ManejadorOfertaLaboral *mo = ManejadorOfertaLaboral::getInstance();
		return mo->getAllDataOfertaLaboral();
	} catch (e) {
    	throw e;
	}
}

void OfertaLaboralController::SeleccionarOferta(string numExpediente) {
	try {
		ManejadorOfertaLaboral *mo = ManejadorOfertaLaboral::getInstance();
		this->oferta = mo->SeleccionarOferta(numExpediente);
		if (this->oferta == NULL)
            throw std::invalid_argument("No existe una Oferta Activa con el número de expediente ingresado");
	} catch (e) {
    	throw e;
	}
}

void OfertaLaboralController::Inscribir(Date *fechaInscripcion) {
	try {
	    if (this->oferta == NULL)
            throw std::invalid_argument("El sistema no recuerda a ninguna Oferta Laboral Seleccionada");
	    this->oferta->Inscripcion(fechaInscripcion);
	    delete this->oferta;
	    //BORRAR MEMORIA ?? oferta y estudiante en memoria
	} catch (e) {
    	throw e;
	}
}

void OfertaLaboralController::Entrevistar(Date *fechaEntrevista) {
	try {
	    this->oferta->Entrevista(fechaEntrevista);
	    //BORRAR MEMORIA ?? oferta y estudiante en memoria
	} catch (e) {
    	throw e;
	}
}

ICollection *OfertaLaboralController::MostrarOfertasActivas()
{
	try {
	    ManejadorOfertaLaboral * mol = ManejadorOfertaLaboral::getInstance();
	    ofertasActivas = mol->getDataOfertaLaboral();
	    if (!ofertasActivas->hasCurrent())
	         throw std::invalid_argument("No existe una Oferta Activa");
        return ofertasActivas;

	} catch (e) {
    	throw e;
	}
}

OfertaLaboral* OfertaLaboralController::getOfertaLaboral()
{
    return this->oferta;
}

void OfertaLaboralController::ModificarOferta(string numExpediente, DataOfertaLaboral* nuevosDatos)
{
	try {
	    ManejadorOfertaLaboral *mol = ManejadorOfertaLaboral::getInstance();
	    mol->ModificarOferta(numExpediente, nuevosDatos);
	} catch (e) {
    	throw e;
	}
}

void OfertaLaboralController::AltaAsignacionDelCargo(Date* fechaEfectivizacion, int sueldo)
{
	try {
		ManejadorOfertaLaboral *mo = ManejadorOfertaLaboral::getInstance();
		this->oferta->AltaAsignacionCargo(fechaEfectivizacion, sueldo);
	    // BORRAR MEMORIA??
	} catch (e) {
    	throw e;
	}
}

void OfertaLaboralController::DarBajaLlamado() {
	try {
		// TODO

		// buscar llamado

		// borrar

	} catch (e) {
    	throw e;
	}
}
