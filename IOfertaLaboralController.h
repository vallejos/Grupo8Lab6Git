#ifndef IOFERTALABORALCONTROLLER_H
#define IOFERTALABORALCONTROLLER_H

#include <string>
#include "Date.h"
#include "DataOfertaLaboral.h"
#include "interfaces/IDictionary.h"

using namespace std;

//Interfaz
class IOfertaLaboralController {
    public:
        IOfertaLaboralController();
        virtual IDictionary* ListarOfertas() = 0;
        virtual DataOfertaLaboral* SeleccionarOferta(string numExpediente, IDictionary *ofertas) = 0;
        virtual void Inscribir(Date* fechaInscripcion) = 0;
        virtual void Entrevistar(Date* fechaEntrevista) = 0;
        virtual IDictionary* MostrarOfertasActivas() = 0;
        virtual void ModificarOferta(string numExpediente, DataOfertaLaboral* nuevosDatos) = 0;
        virtual void AltaAsignacionDelCargo(Date* fechaEfectivizacion, int sueldo)=0;
        virtual void DarBajaLlamado(OfertaLaboral *ol) = 0;
        virtual ~IOfertaLaboralController() = 0; //virtual y vacio
};

#endif // IOFERTALABORALCONTROLLER_H
