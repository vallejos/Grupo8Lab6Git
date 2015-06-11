#include "Sucursal.h"

Sucursal::Sucursal()
{
    this->nombre = '\0';
    this->direccion = '\0';
    this->telefono = '\0';
    this->secciones = NULL;
    this->empresa = NULL;
}

Sucursal::Sucursal(string nombre, string direccion, string telefono, ICollection* secciones, Empresa* empresa)
{
    this->nombre = nombre;
    this->direccion = direccion;
    this->telefono = telefono;
    this->secciones = secciones;
    this->empresa = empresa;
}

DataSucursal *Sucursal::getDataSucursal()
{
    return new DataSucursal(this->nombre, this->direccion, this->telefono, this->getDataSecciones(), this->empresa->getDataEmpresa());
}

ICollection *Sucursal::getDataSecciones()
{
    List* result = new List();
    IIterator * it = this->secciones->getIterator();
    while(it.hasCurrent())
    {
        result->add(it.current()->getDataSeccion());
        it.next();
    }
    delete it;

    return result;
}

Seccion *Sucursal::getSeccion(string nombre)
{
    Iterator* i = this->seccion->getIterator();
    bool seccionEncontrada = false;
    Seccion s = NULL; // para retornar null si la seccion no pertenece a la sucursal
    while((i->hasCurrent())&&(!seccionEncontrada))
    {
        if((i->current()->get_nombre) == nombre))
        {
            s = i->current();
            seccionEncontrada = true;
        }
        else
        {
            i->next();
        }
    }
    delete i;
    return s;
}

DataEmpresa *Sucursal::getDataEmpresa()
{
    return this->empresa->getDataEmpresa();
}

string Sucursal::getNombre()
{
    return this->nombre;
}

string Sucursal::getDireccion()
{
    return this->direccion;
}

string Sucursal::getTelefono()
{
    return this->telefono;
}

ICollection* Sucursal::getSecciones()
{
    return this->secciones;
}

void Sucursal::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Sucursal::setDireccion(string direccion)
{
    this->direccion = direccion;
}

void Sucursal::setTelefono(string telefono)
{
    this->telefono = telefono;
}

void Sucursal::setSecciones(ICollection* secciones)
{
    this->secciones = secciones;
}

Sucursal::~Sucursal()
{
    //dtor
    if (this->secciones != NULL)
    {
        delete (this->secciones);
    }
    if (this->empresa != NULL)
    {
        delete (this->empresa);
    }
}