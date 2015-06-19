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

IDictionary *OfertaLaboralController::ListarOfertas() {
	try {
		ManejadorOfertaLaboral *mo = ManejadorOfertaLaboral::getInstance();
		return mo->getAllDataOfertaLaboral();
	} catch (e) {
    	throw e;
	}
}

void OfertaLaboralController::SeleccionarOferta(string numExpediente, IDictionary *ofertasLabVigentes) {
	try {

        ManejadorOfertaLaboral *mo = ManejadorOfertaLaboral::getInstance();
        String* numExp = new String(numExpediente);
        if(this->ofertasLabVigentes->member(numExp))
        {
            this->oferta = mo->SeleccionarOferta(numExpediente);
        }
        else
        {
            //Significa que la oferta no es válida en caso que el usuario tuviera que elegir una oferta válida
            //ó no existe en el sistema en caso que tuviera que elegir una oferta del sistema
            throw "El Número de Expediente" + numExpediente + " no es válido.";
        }

	} catch (e) {
    	throw e;
	}
}

void OfertaLaboralController::Inscribir(Date *fechaInscripcion) {
	try {
	    if (this->oferta == NULL)
            throw "El sistema no recuerda a ninguna Oferta Laboral Seleccionada";
	    this->oferta->Inscripcion(fechaInscripcion);
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

IDictionary *OfertaLaboralController::MostrarOfertasActivas()
{
	try {
	    ManejadorOfertaLaboral * mol = ManejadorOfertaLaboral::getInstance();
	    ofertasActivas = mol->getDataOfertaLaboral();
	    if (ofertasActivas == NULL)
	         throw "No existe una Oferta Activa";
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
