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
        Sucursal *suc;
        if( (suc = dynamic_cast<Sucursal*> (it.current())) != NULL )
        {
            result->add(suc->getDataSucursal());
        } else
        {
            throw std::invalid_argument("Empresa -> El objeto no es de la clase Sucursal.");
        }
        it.next();
    }
    delete it;

    return result;
}

Sucursal *Empresa::getSucursal(string nombre) {
    String *keyNombre = new String(nombre);

    if (this->sucursales->member(keyNombre))
    {
        Sucursal *sucursal;
        if( (sucursal = dynamic_cast<Sucursal*> (this->sucursales->find(keyNombre))) != NULL )
        {
            return sucursal;
        } else
        {
            throw std::invalid_argument("Empresa -> El objeto no es de la clase Sucursal.");
        }
        delete keyNombre;
    }
    else
    {
        throw std::invalid_argument("La Sucursal de nombre " + nombre + " no existe en el Sistema.");
    }

}
