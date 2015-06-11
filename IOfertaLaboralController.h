#ifndef IOFERTALABORALCONTROLLER_H
#define IOFERTALABORALCONTROLLER_H

#include <string>
#include <set>
#include "Date.h"
#include "DataOfertaLaboral.h"

using namespace std;

//Interfaz
class IOfertaLaboralController {
    public:
        virtual set(DataOfertaLaboral) ListarOfertas() = 0;
        virtual DataOfertaLaboral SeleccionarOferta(numExpediente:string) = 0;
        virtual void Inscribir(fechaInscripcion:Date) = 0;
        virtual set(DataOfertaLaboral) MostrarOfertasActivas() = 0;
        virtual void DarBajaLlamado() = 0;
        virtual ~IOfertaLaboralController(){}; //virtual y vacio
};

#endif // IOFERTALABORALCONTROLLER_H
