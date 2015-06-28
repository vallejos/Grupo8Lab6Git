#ifndef CMD_ANOTARBORRARNOTIFICACIONES_H
#define CMD_ANOTARBORRARNOTIFICACIONES_H

#include "IComando.h"

class cmdAnotarBorrarNotificaciones: public IComando
{
    public:
        cmdAnotarBorrarNotificaciones();
        void ejecutarComando();
        ~cmdAnotarBorrarNotificaciones();
};

#endif // CMD_ANOTARBORRARNOTIFICACIONES_H
