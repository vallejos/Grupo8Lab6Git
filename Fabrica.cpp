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
    return OfertaLaboralController.getInstance();
}

IEmpresaController* Fabrica::getIEmpresaController()
{
    return EmpresaController.getInstance();
}

IEstudianteController* Fabrica::getIEstudianteController()
{
    return EstudianteController.getInstance();
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
