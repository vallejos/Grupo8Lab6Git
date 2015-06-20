#ifndef CMD_ESTABLECERHORASISTEMA_H
#define CMD_ESTABLECERHORASISTEMA_H

#include <exception>
#include "IComando.h"

class cmdEstablecerHoraSistema: public IComando
{
    public:
        cmdEstablecerHoraSistema();
        void ejecutarComando();
        ~cmdEstablecerHoraSistema();
    protected:
    private:
};

#endif // CMD_ESTABLECERHORASISTEMA_H
