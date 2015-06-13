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
	ManejadorOfertaLaboral *mo = ManejadorOfertaLaboral::getInstance();
	return mo->getAllDataOfertaLaboral();
}

void OfertaLaboralController::SeleccionarOferta(string numExpediente) {
	ManejadorOfertaLaboral *mo = ManejadorOfertaLaboral::getInstance();
	this->oferta = mo->SeleccionarOferta(numExpediente);
}

void OfertaLaboralController::Inscribir(Date *fechaInscripcion) {
    this->oferta->Inscripcion(fechaInscripcion);
    //BORRAR MEMORIA ??
}

void OfertaLaboralController::Entrevistar(Date *fechaEntrevista) {
    this->oferta->Entrevista(fechaEntrevista);
    //BORRAR MEMORIA ??
}

ICollection *OfertaLaboralController::MostrarOfertasActivas()
{
    ManejadorOfertaLaboral * mol = ManejadorOfertaLaboral::getInstance();
	return mol->getDataOfertaLaboral();
}

void OfertaLaboralController::DarBajaLlamado() {

}
