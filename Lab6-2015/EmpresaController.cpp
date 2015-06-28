#include "EmpresaController.h"

EmpresaController* EmpresaController::instance = NULL;

// constructor
EmpresaController::EmpresaController()
{

}

EmpresaController *EmpresaController::getInstance()
{
	if (instance == NULL)
		instance = new EmpresaController;
	return instance;
}

void EmpresaController::AltaOfertaLaboral(string numExpediente, string titulo, string descripcion, int cantidadHorasSemanales,
        	Rango *rangoSalarial, Date *fechaComienzo, Date *fechaFin, int cantidadPuestosNecesarios,
        	IDictionary *codAsignaturas)
{
    OfertaLaboral *o = this->seccion->addOferta(numExpediente,titulo,descripcion,cantidadHorasSemanales,rangoSalarial,fechaComienzo,fechaFin,cantidadPuestosNecesarios,codAsignaturas);
    o->setSeccion(this->seccion);
}

ICollection* EmpresaController::ListarEmpresas()
{
    ManejadorEmpresa *me = ManejadorEmpresa::getInstance();
    return (me->getDataEmpresas());
}

IDictionary* EmpresaController::getEmpresas()
{
    ManejadorEmpresa *me = ManejadorEmpresa::getInstance();
    return (me->getEmpresas());
}

ICollection *EmpresaController::ListarSucursales()
{
	return this->empresa->getDataSucursales();
}

IDictionary* EmpresaController::ListarSecciones()
{
	return this->sucursal->getDataSecciones();
}

Empresa* EmpresaController::getEmpresa()
{
    if (this->empresa)
        throw "No hay una Empresa recordada en el Sistema";
    return this->empresa;
}

Sucursal* EmpresaController::getSucursal()
{
    if (this->sucursal)
        throw "No hay una Sucursal recordada en el Sistema";
    return this->sucursal;
}

Seccion* EmpresaController::getSeccion()
{
    if (this->seccion)
        throw "No hay una Seccion recordada en el Sistema";
    return this->seccion;
}

void EmpresaController::SeleccionarEmpresa(string rut)
{
	ManejadorEmpresa *me = ManejadorEmpresa::getInstance();
	this->empresa = me->getEmpresa(rut);
}

void EmpresaController::SeleccionarSucursal(string nombre)
{
	this->sucursal = this->empresa->getSucursal(nombre);
}

void EmpresaController::SeleccionarSeccion(string nombre)
{
    this->seccion = this->sucursal->getSeccion(nombre);
}

void EmpresaController::setCriterio(EstrategiaAsignaturas* criterio)
{
    this->criterio = criterio;
}

IDictionary* EmpresaController::obtenerAsignaturasValidas(IDictionary* asignaturasIngresadas)
{
    IDictionary *asignaturasValidas = this->criterio->devolverListaAsignatura(asignaturasIngresadas);

    return asignaturasValidas;
}

void EmpresaController::destroyEmpresaController()
{
     if (instance != NULL)
     {
        delete instance;
        instance = NULL;
     }
}

EmpresaController::~EmpresaController()
{
    //dtor
}
