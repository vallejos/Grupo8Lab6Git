#include "Empresa.h"

// default constructor
Empresa::Empresa() {

}

Empresa::Empresa(string rut, string nombre) {
	this->rut = rut;
	this->nombre = nombre;
}

// destructor
Empresa::~Empresa() {

}

string Empresa::getRut() {
	return this->rut;
}

string Empresa::getNombre() {
	return this->nombre;
}

ICollection *Empresa::getDataSucursales()
{
    List* result = new List();
    IIterator * it = this->sucursales->getIterator();
    while(it->hasCurrent())
    {
        result->add(it->current()->getDataSucursal());
        it->next();

    }
    delete it;

    return result;
}

Sucursal *Empresa::getSucursal(string nombre) {
    String *keyNombre = new String(nombre);
    Sucursal *sucursal = this->sucursales->find(keyNombre);
    delete keyNombre;

	return sucursal;
}
