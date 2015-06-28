#ifndef MANEJADOREMPRESA_H
#define MANEJADOREMPRESA_H

#include "interfaces/ICollection.h"
#include "interfaces/IDictionary.h"
#include "Empresa.h"

using namespace std;

class ManejadorEmpresa
{
    public:
        static ManejadorEmpresa *getInstance();
        ICollection *getDataEmpresas();
        Empresa *getEmpresa(string rut);
        IDictionary* getEmpresas();
        void destroyManejadorEmpresa();
    protected:
    private:
        ManejadorEmpresa();
        ManejadorEmpresa(IDictionary* empresas);
        static ManejadorEmpresa* instance;
        IDictionary* empresas;
        ~ManejadorEmpresa();
};

#endif // MANEJADOREMPRESA_H
