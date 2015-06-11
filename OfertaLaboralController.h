#ifndef OFERTALABORALCONTROLLER_H
#define OFERTALABORALCONTROLLER_H

#include <string>
#include "Date.h"
#include "DataOfertaLaboral.h"
#include "lab6-colecciones/interfaces/ICollection.h"

class OfertaLaboralController {
    public:
        OfertaLaboralController *getInstance();
        DataOfertaLaboral **ListarOfertas();
        void SeleccionarOferta(string numExpediente);
        void Inscribir(Date *fechaInscripcion);
        ICollection *MostrarOfertasActivas();
        void DarBajaLlamado();
    protected:
    private:
        OfertaLaboralController();
        ~OfertaLaboralController();
    	static OfertaLaboralController *instance;
        OfertaLaboral *oferta;
};

#endif // OFERTALABORALCONTROLLER_H
