#include "ManejadorEmpresa.h"

ManejadorEmpresa* ManejadorEmpresa::instance = NULL;

ManejadorEmpresa::ManejadorEmpresa()
{
    //ctor
    this->empresas = NULL;
}

ManejadorEmpresa::ManejadorEmpresa(IDictionary* empresas)
{
    this->empresas = empresas;
}

ManejadorEmpresa* ManejadorEmpresa::getInstance()
{
    if(instance == NULL)
        instance = new ManejadorEmpresa();
    return instance;
}

ICollection* ManejadorEmpresa::getDataEmpresas()
{
    List* result = new List();
    IIterator * it = this->empresas->getElemIterator();
    while(it->hasCurrent())
    {
        result->add(it.current()->getDatosEmpresa());
        it.next();
    }
    delete it;
    return result;
}

Empresa* ManejadorEmpresa::getEmpresa(string rut)
{
    String* sRut = new String(rut);
    return this->empresas->find(sRut);
}

IDictionary* Estudiante::getEmpresas() // ???
{
    return this->empresas;
}

void ManejadorEmpresa::destroyManejadorEmpresa()
{
     if (instance != NULL)
     {
        delete ManejadorEmpresa;
     }
}

ManejadorEmpresa::~ManejadorEmpresa()
{
    //dtor
    delete instance;
    instance = NULL;
}
