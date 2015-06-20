#include "Fabrica.h"

Fabrica::Fabrica()
{
    //Constructor
}

Fabrica* Fabrica::instance = NULL;

Fabrica* Fabrica::getInstance()
{
    if (instance == NULL)
        instance = new Fabrica();
    return instance;
}

IOfertaLaboralController* Fabrica::getIOfertaLaboralController()
{
    return IOfertaLaboralController::getInstance();
}

IEmpresaController* Fabrica::getIEmpresaController()
{
    return IEmpresaController::getInstance();
}

IEstudianteController* Fabrica::getIEstudianteController()
{
    return IEstudianteController::getInstance();
}

void Fabrica::destroyFabrica()
{
    if (instance != NULL)
    {
        this->~Fabrica();
    }
}

Fabrica::~Fabrica()
{
    //destructor
    delete instance;
    instance = NULL;
}
