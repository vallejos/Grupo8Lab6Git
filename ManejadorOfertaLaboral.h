#ifndef MANEJADOROFERTALABORAL_H
#define MANEJADOROFERTALABORAL_H

#include "OfertaLaboral.h"
#include"interfaces/ICollection.h"
#include "interfaces/IDictionary.h"
#include <string>

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
		void ModificarOferta(string numExpediente, DataOfertaLaboral* nuevosDatos);
		destroyManejadorOfertaLaboral();

    private:
        ~ManejadorOfertaLaboral();
    	ManejadorOfertaLaboral();
        static ManejadorOfertaLaboral *instance;
        IDictionary *ofertasLaborales; //Pseudoatributo para representar la asociación con una coleccion de OfertaLaboral
};

#endif // MANEJADOROFERTALABORAL_H
