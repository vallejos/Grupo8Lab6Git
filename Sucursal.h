#ifndef SUCURSAL_H
#define SUCURSAL_H

#include <string>
#include "Date.h"
#include "Seccion.h"
#include "DataSeccion.h"
#include "DataSucursal.h"
#include "DataEmpresa.h"
#include "Empresa.h"
#include "interfaces/IIterator.h"
#include "interfaces/ICollection.h"

using namespace std;

class Sucursal : public ICollectible
{
    private:
        string nombre;
        string direccion;
        string telefono;
        IDictionary *secciones; //pseudoatributo;
        Empresa *empresa; //pseudoatributo;
    public:
        //operaciones
        Sucursal();
        Sucursal(string nombre, string direccion, string telefono, ICollection* secciones, Empresa *empresa);
        DataSucursal *getDataSucursal();
        ICollection *getDataSecciones();
        Seccion *getSeccion(string nombre);
        DataEmpresa *getDataEmpresa();
        //getters
        string getNombre();
        string getDireccion();
        string getTelefono();
        IDictionary *getSecciones();
        Empresa *getEmpresa();
        //setters
        void setNombre(string nombre);
        void setDireccion(string direccion);
        void setTelefono(string telefono);
        void setSecciones(ICollection *secciones);
        void setEmpresa(Empresa *empresa);
        //destructor
        ~Sucursal();
};

#endif // SUCURSAL_H
