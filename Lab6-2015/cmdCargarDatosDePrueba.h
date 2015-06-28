#ifndef CMD_CARGARDATOSDEPRUEBA_H
#define CMD_CARGARDATOSDEPRUEBA_H

#include "OfertaLaboral.h"
#include "IComando.h"

class cmdCargarDatosDePrueba: public IComando
{
    public:
        cmdCargarDatosDePrueba();
        void ejecutarComando();
        ~cmdCargarDatosDePrueba();
    protected:
    private:
};

#endif // CMD_CARGARDATOSDEPRUEBA_H
