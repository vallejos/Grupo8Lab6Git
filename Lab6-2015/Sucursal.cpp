#include "Sucursal.h"
#include "collections/OrderedDictionary.h"

Sucursal::Sucursal()
{
    this->nombre = '\0';
    this->direccion = '\0';
    this->telefono = '\0';
    this->secciones = new OrderedDictionary();
    this->empresa = NULL;
}

Sucursal::Sucursal(string nombre, string direccion, string telefono, IDictionary* secciones, Empresa* empresa)
{
    this->nombre = nombre;
    this->direccion = direccion;
    this->telefono = telefono;
    if (secciones == NULL)
    {
        this->secciones = new OrderedDictionary();
    } else {
        this->secciones = secciones;
    }
    this->empresa = empresa;
}

DataSucursal *Sucursal::getDataSucursal()
{
    return new DataSucursal(this->nombre, this->direccion, this->telefono, this->getDataSecciones());
}

IDictionary *Sucursal::getDataSecciones()
{
    IDictionary* result = new OrderedDictionary();
    IIterator * it = this->secciones->getIterator();
    while(it->hasCurrent())
    {
        Seccion *sec;
        if( (sec = dynamic_cast<Seccion*> (it->getCurrent())) != NULL )
        {
            String* nombreSec = new String(sec->getNombre().c_str());
            result->add(nombreSec,sec->getDataSeccion());
        } else
        {
            throw "Sucursal -> El objeto no es de la clase Estudiante.";
        }
        it->next();
    }
    delete it;

    return result;
}

Seccion *Sucursal::getSeccion(string nombre)
{
    String* nomSeccion = new String(nombre.c_str());
    if(this->secciones->member(nomSeccion))
    {
        Seccion *sec;
        if( (sec = dynamic_cast<Seccion*> (this->secciones->find(nomSeccion))) != NULL )
        {
            return sec;
        } else
        {
            throw "Sucursal -> El objeto no es de la clase Seccion.";
        }
    }
    else
    {
        throw "La Seccion no existe en el Sistema.";
    }
}

DataEmpresa *Sucursal::getDataEmpresa()
{
    return this->empresa->getDataEmpresa();
}

Empresa* Sucursal::getEmpresa()
{
    return this->empresa;
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

IDictionary* Sucursal::getSecciones()
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

void Sucursal::setSecciones(IDictionary* secciones)
{
    this->secciones = secciones;
}


Sucursal::~Sucursal()
{
    //dtor

}
