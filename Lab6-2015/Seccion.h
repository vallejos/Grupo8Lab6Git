#ifndef SECCION_H
#define SECCION_H

#include <string>
#include "Rango.h"
#include "Date.h"
#include "String.h"
#include "DataEmpresa.h"
#include "IObserver.h"
#include "Encargado.h"
#include "interfaces/ICollection.h"
#include "interfaces/ICollectible.h"
#include "interfaces/IDictionary.h"

using namespace std;

class Sucursal;
class OfertaLaboral;
class DataSeccion;

class Seccion: public ICollectible
{
    public:
        Seccion();
        Seccion(string nombre, string interno, Sucursal *sucursal);
        Seccion(const Seccion &s);
        ~Seccion();
        string getNombre();
        string getInterno();
        Sucursal* getSucursal();
        Encargado* getEncargado();
        IDictionary *getOfertasLaborales();
        void setNombre(string nombre);
        void setInterno(string interno);
        void setEncargado(Encargado* encargado);
        void setSucursal(Sucursal *sucursal);
        DataSeccion *getDataSeccion();
        DataEmpresa *getDataEmpresa();
        OfertaLaboral *addOferta(string numExpediente, string titulo, string descripcion, int cantidadHorasSemanales, Rango *rangoSalarial, Date *fechaComienzo, Date *fechaFin, int cantidadPuestosNecesarios, IDictionary *asignaturas);
        void addObserver(IObserver *obs);
        void removeObserver(IObserver *obs);

    private:
        string nombre;
        string interno;
        Sucursal * sucursal;//Pseudoatributo para representar la asociaci�n con una Sucursal
        Encargado * encargado;//Pseudoatributo para representar la asociaci�n con un Encargado
        ICollection * observers;//Pseudoatributo para representar la asociaci�n con una coleccion de IObserver
        IDictionary *ofertasLaborales; //Pseudoatributo para representar la asociaci�n con un diccionario de ofertas laborales
};

#include "OfertaLaboral.h"
#include "Sucursal.h"
#include "OfertaLaboral.h"
#include "DataSeccion.h"

#endif // SECCION_H
