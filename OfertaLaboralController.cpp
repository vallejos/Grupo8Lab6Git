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
    //BORRAR MEMORIA ?? oferta y estudiante en memoria
}

void OfertaLaboralController::Entrevistar(Date *fechaEntrevista) {
    this->oferta->Entrevista(fechaEntrevista);
    //BORRAR MEMORIA ?? oferta y estudiante en memoria
}

ICollection *OfertaLaboralController::MostrarOfertasActivas()
{
    ManejadorOfertaLaboral * mol = ManejadorOfertaLaboral::getInstance();
	return mol->getDataOfertaLaboral();
}

OfertaLaboral* OfertaLaboralController::getOfertaLaboral()
{
    return this->oferta;
}

void OfertaLaboralController::AltaAsignacionDelCargo(Date* fechaEfectivizacion, int sueldo)
{
	ManejadorOfertaLaboral *mo = ManejadorOfertaLaboral::getInstance();
	this->oferta->AltaAsignacionCargo(fechaEfectivizacion, sueldo);
    // BORRAR MEMORIA??
}

void OfertaLaboralController::DarBajaLlamado() {

}
