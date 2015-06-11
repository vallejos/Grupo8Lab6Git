#include "EmpresaController.h"

// constructor
EmpresaController::EmpresaController() {
	
}

// destructor
EmpresaController::~EmpresaController() {
	
}

EmpresaController *EmpresaController::getInstance() {
	if (this->instance == NULL) {
		this->instance = new EmpresaController();
	}
	return this->instance;
}

void EmpresaController::AltaOfertaLaboral(string numExpediente, string titulo, string descripcion, int cantidadHorasSemanales, 
        	Rango *rangoSalarial, Date *fechaComienzo, Date *fechaFin, int cantidadPuestosNecesarios, 
        	DataAsignatura *asignaturas) {

}

DataEmpresa **EmpresaController::ListarEmpresas() {
	return NULL;
}

ICollection *EmpresaController::ListarSucursales()
{
	return this->empresa->getDataSucursales();
}

DataSeccion **EmpresaController::ListarSecciones() {
	return NULL;
}

void EmpresaController::SeleccionarEmpresa(string rut) {
	ManejadorEmpresa *me = ManejadorEmpresa::getInstance();
	this->empresa = me->getEmpresa(rut);
	// para borrar la memoria, tenemos que llamar al constru x copia
//	delete me;
}

void EmpresaController::SeleccionarSucursal(string nombre) {

}

void EmpresaController::SeleccionarSeccion(string nombre) {

}
