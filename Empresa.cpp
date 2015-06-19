#include "Empresa.h"

// default constructor
Empresa::Empresa() {

}

Empresa::Empresa(string rut, string nombre) {
	this->rut = rut;
	this->nombre = nombre;
}

Empresa::Empresa(const Empresa &e)
{
    this->rut=e.rut;
    this->nombre=e.nombre;
}

// destructor
Empresa::~Empresa() {

}

Empresa::DataEmpresa *getDataEmpresa()
{
    DataEmpresa* dataEmpresa= new DataEmpresa(this->rut, this->nombre);
    return dataEmpresa;
}

string Empresa::getRut() {
	return this->rut;
}

string Empresa::getNombre() {
	return this->nombre;
}

IDictionary *Empresa::getSucursales() {
    return this->sucursales;
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

    if (this->sucursales->member(keyNombre))
    {
        Sucursal *sucursal = this->sucursales->find(keyNombre);
        delete keyNombre;
        return sucursal;
    }
    else
    {
        throw std::invalid_argument("La Sucursal de nombre " + nombre + " no existe en el Sistema.");
    }

}
