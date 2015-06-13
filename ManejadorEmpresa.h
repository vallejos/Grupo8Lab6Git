#ifndef MANEJADOREMPRESA_H
#define MANEJADOREMPRESA_H

#include "lab6-colecciones/interfaces/ICollection.h"
#include "lab6-colecciones/interfaces/IDictionary.h"
#include "Empresa.h"

class ManejadorEmpresa
{
    public:
        static ManejadorEmpresa *getInstance();
        ICollection *getDataEmpresas();
        Empresa *getEmpresa(string rut);
        IDictionary* getEmpresas();
        //Se debe crear un getter y un setter para la coleccion???
        ~ManejadorEmpresa();
    protected:
    private:
        ManejadorEmpresa();//Se puede crear un constructor con parametros para un singleton???
        ManejadorEmpresa(IDictionary* empresas);
        static ManejadorEmpresa* instance;
        IDictionary* empresas;
};

#endif // MANEJADOREMPRESA_H
