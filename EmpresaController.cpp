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
        	ICollection *codAsignaturas)
{
    ManejadorEstudiante* mEstudiante = ManejadorEstudiante::getInstance();
    IDictionary* asignaturas = mEstudiante->getAsignaturas()
    IDictionary* asignaturasAdd;
    IIterator * it = codAsignaturas->getIterator();
    while(it.hasCurrent())
    {
        if(asignaturas->member(it.current()))
        {

            Asignatura* asig;
            if( (asig = dynamic_cast<Asignatura*> (this->asignaturas->find(it.current()))) != NULL )
            {
                asignaturasAdd->add(asig);
            }
            else
            {
                throw std::invalid_argument("EmpresaController -> El objeto no es de la clase Asignatura.");
            }
        }
        else
        {
            Integer* codigo;
            if( (codigo = dynamic_cast<Integer*> (it->current()))) != NULL )
            {
                throw std::invalid_argument("La Asignatura de codigo " + codigo->getValue() + " no existe en el Sistema.");
            }
            else
            {
                throw std::invalid_argument("EmpresaController -> El objeto no es de la clase Integer.");
            }
        }
        it.next();
    }
    delete it;

    this->seccion->addOferta(numExpediente,titulo,descripcion,cantidadHorasSemanales,rangoSalarial,fechaComienzo,fechaFin,cantidadPuestosNecesarios,asignaturasAdd);
}

ICollection* EmpresaController::ListarEmpresas() {
	return NULL;
}

ICollection *EmpresaController::ListarSucursales()
{
	return this->empresa->getDataSucursales();
}

ICollection* EmpresaController::ListarSecciones() {
	return NULL;
}

Empresa* EmpresaController::getEmpresa()
{
    return this->empresa;
}

Sucursal* EmpresaController::getSucursal()
{
    return this->sucursal;
}

Seccion* EmpresaController::getSeccion()
{
    return this->seccion;
}

void EmpresaController::SeleccionarEmpresa(string rut) {
	ManejadorEmpresa *me = ManejadorEmpresa::getInstance();
	this->empresa = me->getEmpresa(rut);
	// para borrar la memoria, tenemos que llamar al constru x copia
//	delete me;
}

void EmpresaController::SeleccionarSucursal(string nombre) {
	this->sucursal = this->empresa->getSucursal(nombre);
}

void EmpresaController::SeleccionarSeccion(string nombre) {
    this->seccion = this->sucursal->getSeccion(nombre);
}
