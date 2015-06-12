#ifndef FABRICA_H
#define FABRICA_H

#include <string>

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
