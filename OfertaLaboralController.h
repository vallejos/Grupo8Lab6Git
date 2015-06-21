#ifndef OFERTALABORALCONTROLLER_H
#define OFERTALABORALCONTROLLER_H

#include <string>
#include "IOfertaLaboralController.h"

class Date;
class DataOfertaLaboral;
class OfertaLaboral;
class IDictionary;
class ICollection;
class Seccion;
class Rango;

using namespace std;

class OfertaLaboralController: public IOfertaLaboralController
{
    public:
        static OfertaLaboralController *getInstance();
        IDictionary *ListarOfertas();
        void SeleccionarOferta(string numExpediente, IDictionary *ofertasLabVigentes);
        void Inscribir(Date *fechaInscripcion);
        void Entrevistar(Date *fechaEntrevista);
        void AltaAsignacionDelCargo(Date* fechaEfectivizacion, int sueldo);
        void ModificarOferta(string numExpediente, string titulo, string descripcion, int cantHorasSemanales, Rango *rangoSalarial, Date *fechaIni,
            Date *fechaFin, int cantidadPuestos, IDictionary *asignaturas, Seccion *seccion, ICollection *inscripciones, 
            ICollection *entrevistas);
        IDictionary *MostrarOfertasActivas();
        void DarBajaLlamado();
        OfertaLaboral *getOfertaLaboral();

    private:
        OfertaLaboralController();
        ~OfertaLaboralController();
    	static OfertaLaboralController *instance;
        OfertaLaboral *oferta;
};

#include "Date.h"
#include "DataOfertaLaboral.h"
#include "interfaces/IDictionary.h"
#include "OfertaLaboral.h"
#include "Seccion.h"
#include "interfaces/ICollection.h"
#include "Rango.h"

#endif // OFERTALABORALCONTROLLER_H
