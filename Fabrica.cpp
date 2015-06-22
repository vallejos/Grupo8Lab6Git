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
    return OfertaLaboralController::getInstance();
}

IEmpresaController* Fabrica::getIEmpresaController()
{
    return EmpresaController::getInstance();
}

IEstudianteController* Fabrica::getIEstudianteController()
{
    EstudianteController *e = EstudianteController::getInstance();
    return e;
}

void Fabrica::destroyFabrica()
{
    if (instance != NULL)
    {
        delete instance;
        instance = NULL;
    }
}

Fabrica::~Fabrica()
{
    //destructor
}
