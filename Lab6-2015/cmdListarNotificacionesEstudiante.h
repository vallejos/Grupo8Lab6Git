#ifndef CMD_LISTARNOTIFICACIONESESTUDIANTE_H
#define CMD_LISTARNOTIFICACIONESESTUDIANTE_H

#include <exception>
#include "IComando.h"

class cmdListarNotificacionesEstudiante: public IComando
{
    public:
        cmdListarNotificacionesEstudiante();
        void ejecutarComando();
        ~cmdListarNotificacionesEstudiante();
    protected:
    private:
};

#endif // CMD_LISTARNOTIFICACIONESESTUDIANTE_H
