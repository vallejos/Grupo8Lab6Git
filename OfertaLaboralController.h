#ifndef OFERTALABORALCONTROLLER_H
#define OFERTALABORALCONTROLLER_H

#include <string>
#include "Date.h"
#include "DataOfertaLaboral.h"
#include "interfaces/ICollection.h"
#include "IDictionary.h"

class OfertaLaboralController {
    public:
        OfertaLaboralController *getInstance();
        ICollection* ListarOfertas();
        void SeleccionarOferta(string numExpediente, IDictionary *ofertasLabVigentes);
        void Inscribir(Date *fechaInscripcion);
        void Entrevistar(Date *fechaEntrevista);
        void AltaAsignacionDelCargo(Date* fechaEfectivizacion, int sueldo);
        void ModificarOferta(string numExpediente, DataOfertaLaboral* nuevosDatos);
        ICollection *MostrarOfertasActivas();
        void DarBajaLlamado();
        OfertaLaboral *getOfertaLaboral();
    protected:
    private:
        OfertaLaboralController();
        ~OfertaLaboralController();
    	static OfertaLaboralController *instance;
        OfertaLaboral *oferta;
};

#endif // OFERTALABORALCONTROLLER_H
