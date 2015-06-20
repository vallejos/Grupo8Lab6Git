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
    OfertaLaboralController* o=OfertaLaboralController::getInstance();
    return o;
}

IEmpresaController* Fabrica::getIEmpresaController()
{
    EmpresaController* e= EmpresaController::getInstance();
    return e;
}

IEstudianteController* Fabrica::getIEstudianteController()
{
    EstudianteController* e=EstudianteController::getInstance();
    return e;
}

void Fabrica::destroyFabrica()
{
    if (instance != NULL)
    {
        delete Fabrica;
    }
}

Fabrica::~Fabrica()
{
    //destructor
    delete instance;
    instance = NULL;
}
