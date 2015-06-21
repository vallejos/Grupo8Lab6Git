#include "Empresa.h"
#include <iostream>

using namespace std;

// default constructor
Empresa::Empresa()
{

}

Empresa::Empresa(string rut, string nombre)
{
	this->rut = rut;
	this->nombre = nombre;
}

Empresa::Empresa(const Empresa &e)
{
    this->rut=e.rut;
    this->nombre=e.nombre;
}

// destructor
Empresa::~Empresa()
{

}

DataEmpresa *Empresa::getDataEmpresa()
{
    DataEmpresa* dataEmpresa= new DataEmpresa(this->rut, this->nombre);
    return dataEmpresa;
}

string Empresa::getRut()
{
	return this->rut;
}

string Empresa::getNombre()
{
	return this->nombre;
}

IDictionary *Empresa::getSucursales()
{
    return this->sucursales;
}

ICollection *Empresa::getDataSucursales()
{
    List* result = new List();
    IIterator * it = this->sucursales->getIterator();
    while(it->hasCurrent())
    {
        Sucursal *suc;
        if ((suc = dynamic_cast<Sucursal*> (it->getCurrent())) != NULL )
        {
            result->add(suc->getDataSucursal());
        } else
        {
            throw "Empresa -> El objeto no es de la clase Sucursal.";
        }
        it->next();
    }
    delete it;

    return result;
}

Sucursal *Empresa::getSucursal(string nombre)
{
    String *keyNombre = new String(nombre.c_str());

    if (this->sucursales->member(keyNombre))
    {
        Sucursal *sucursal;
        if( (sucursal = dynamic_cast<Sucursal*> (this->sucursales->find(keyNombre))) != NULL )
        {
            return sucursal;
        } else
        {
            throw "Empresa -> El objeto no es de la clase Sucursal.";
        }
        delete keyNombre;
    }
    else
    {
        throw "La Sucursal de nombre " + nombre + " no existe en el Sistema.";
    }

}
