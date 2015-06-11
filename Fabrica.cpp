#include "Fabrica.h"

Fabrica* Fabrica::instance = NULL;

Fabrica* Fabrica::getInstance(){
    if (instance = NULL)
        instance = new Fabrica();
    return instance;
}

IOfertaLaboralController Fabrica::getIOfertaLaboralController(){
    return OfertaLaboralController.getInstance();
}

IEmpresaController Fabrica::getIEmpresaController(){
    return EmpresaController.getInstance();
}

IEstudianteController Fabrica::getIEstudianteController(){
    return EstudianteController.getInstance();
}

Fabrica::~Fabrica()
{
    //dtor
    delete instance;
    instance = NULL;
}
