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
    IIterator * it = this->empresas->getIterator();
    while(it->hasCurrent())
    {
        Empresa *emp;
        if ((emp = dynamic_cast<Empresa*> (it->getCurrent())) != NULL){
            result->add(emp->getDataEmpresa());
            it->next();
        }else
        {
            throw "ManejadorEmpresa -> El objeto no es de la clase Empresa.";
        }
    }
    delete it;
    return result;
}

Empresa* ManejadorEmpresa::getEmpresa(string rut)
{
    String* sRut = new String(rut.c_str());
    if (this->empresas->member(sRut))
    {
        Empresa *emp;
        if( (emp = dynamic_cast<Empresa*> (this->empresas->find(sRut))) != NULL )
        {
            return emp;
        } else
        {
            throw "ManejadorEmpresa -> El objeto no es de la clase Empresa.";
        }
    }
    else
    {
        throw "La Empresa con RUT " + rut + " no existe en el Sistema.";
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
        this->~ManejadorEmpresa();
     }
}

ManejadorEmpresa::~ManejadorEmpresa()
{
    //dtor
    delete instance;
    instance = NULL;
}
