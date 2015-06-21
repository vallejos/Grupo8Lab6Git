#ifndef MANEJADOROFERTALABORAL_H
#define MANEJADOROFERTALABORAL_H

#include "OfertaLaboral.h"
#include "interfaces/ICollection.h"
#include "interfaces/IDictionary.h"
#include <string>
#include "Rango.h"
#include "Seccion.h"
#include "Date.h"

using namespace std;

class ManejadorOfertaLaboral
{
    public:
		static ManejadorOfertaLaboral *getInstance();
		IDictionary *getDataOfertaLaboral(); // Set DataOfertaLaboral
		IDictionary *getAllDataOfertaLaboral(); // Set DataOfertaLaboral
		OfertaLaboral *SeleccionarOferta(string numExpediente);
		void addOfertaManejador(OfertaLaboral *ol);
		IDictionary* getOfertasLaborales();
		void DarDeBajaLlamado(OfertaLaboral *ol);
		void ModificarOferta(string numExpediente, string titulo, string descripcion, int cantHorasSemanales, Rango *rangoSalarial, Date *fechaIni,
            Date *fechaFin, int cantidadPuestos, IDictionary *asignaturas, Seccion *seccion, ICollection *inscripciones, 
            ICollection *entrevistas);
		void destroyManejadorOfertaLaboral();

    private:
        ~ManejadorOfertaLaboral();
    	ManejadorOfertaLaboral();
        static ManejadorOfertaLaboral *instance;
        IDictionary *ofertasLaborales; //Pseudoatributo para representar la asociación con una coleccion de OfertaLaboral
};

#endif // MANEJADOROFERTALABORAL_H
