#ifndef FABRICA_H
#define FABRICA_H

#include <string>
#include <set>

using namespace std;

//Factory Singleton
class Fabrica
{
    private:
        static Fabrica* instance;
    public:
        static Fabrica* getInstance();
        IOfertaLaboralController getIOfertaLaboralController();
        IEmpresaController getIEmpresaController();
        IEstudianteController getIEstudianteController();
        ~Fabrica();
};

#endif // FABRICA_H
