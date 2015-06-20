#ifndef FABRICA_H
#define FABRICA_H

#include <string>
#include "IOfertaLaboralController.h"
#include "IEmpresaController.h"
#include "IEstudianteController.h"
#include "OfertaLaboralController.h"
#include "EmpresaController.h"
#include "EstudianteController.h"

using namespace std;

//Factory Singleton
class Fabrica
{
    private:
        Fabrica();
        static Fabrica* instance;
        ~Fabrica();

    public:
        static Fabrica* getInstance();
        IOfertaLaboralController *getIOfertaLaboralController();
        IEmpresaController *getIEmpresaController();
        IEstudianteController *getIEstudianteController();
        void destroyFabrica();
};

#endif // FABRICA_H
