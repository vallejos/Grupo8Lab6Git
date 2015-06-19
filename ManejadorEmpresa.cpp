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
    if (this->empresas->member(sRut))
    {
        Empresa *emp;
        if( (emp = dynamic_cast<Empresa*> (this->empresas->find(sRut))) != NULL )
        {
            return emp;
        } else
        {
            throw std::invalid_argument("ManejadorEmpresa -> El objeto no es de la clase Empresa.");
        }
    }
    else
    {
        throw std::invalid_argument("La Empresa con RUT " + rut + " no existe en el Sistema.");
    }
}

IDictionary* ManejadorEmpresa::getEmpresas()
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
