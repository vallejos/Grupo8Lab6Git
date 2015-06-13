#ifndef SECCION_H
#define SECCION_H

#include <string>
#include "Rango.h"
#include "Date.h"
#include "DataSeccion.h"
#include "DataEmpresa.h"
#include "OfertaLaboral.h"
#include "DataAsignatura.h"
#include "IObserver.h"
#include "Sucursal.h"
#include "Encargado.h"
#include "ICollection.h"
#include "ICollectible.h"
#include "IDictionary.h"

using namespace std;

class Seccion: public ICollectible
{
    public:
		Seccion();
        Seccion(string nombre, string interno);
        Seccion(const Seccion &s);
        ~Seccion();
        string getNombre();
        string getInterno();
        void setNombre(string nombre);
        void setInterno(string interno);
        DataSeccion *getDataSeccion();
        DataEmpresa *getDataEmpresa();
        OfertaLaboral *addOferta(string numExpediente, string titulo, string descripcion, int cantidadHorasSemanales, Rango *rangoSalarial, Date *fechaComienzo, Date *fechaFin, int cantidadPuestosNecesarios, IDictionary *asignaturas);
        void addObserver(IObserver *obs);
        void removeObserver(IObserver *obs);

    private:
        string nombre;
        string interno;
        Sucursal * sucursal;//Pseudoatributo para representar la asociación con una Sucursal
        Encargado * encargado;//Pseudoatributo para representar la asociación con un Encargado
        IColeccion * observers;//Pseudoatributo para representar la asociación con una coleccion de IObserver
        IDictionary *ofertasLaborales;
};

#endif // SECCION_H
