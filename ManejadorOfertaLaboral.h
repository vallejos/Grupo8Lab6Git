#ifndef MANEJADOROFERTALABORAL_H
#define MANEJADOROFERTALABORAL_H

#include "DataOfertaLaboral.h"
#include "OfertaLaboral.h"
#include "IDictionary.h"
#include "String.h"

using namespace std;

class ManejadorOfertaLaboral
{
    public:
		static ManejadorOfertaLaboral *getInstance();
		IDictionary *getDataOfertaLaboral(); // Set DataOfertaLaboral
		IDictionary *getAllDataOfertaLaboral(); // Set DataOfertaLaboral
		OfertaLaboral* SeleccionarOferta(String numExpediente); // Devuleve un DataOfertaLaboral o no devuelve nada?
		void addOfertaManejador(OfertaLaboral ol);
		void DarDeBajaLlamado();
        ~ManejadorOfertaLaboral();
    private:
    	ManejadorOfertaLaboral();
        static ManejadorOfertaLaboral *instance;
        IDictionary * ofertasLaborales; //Pseudoatributo para representar la asociación con una coleccion de OfertaLaboral
};

#endif // MANEJADOROFERTALABORAL_H
