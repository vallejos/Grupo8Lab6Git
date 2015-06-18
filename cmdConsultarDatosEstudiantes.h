#ifndef CMD_CONSULTARDATOSESTUDIANTES_H
#define CMD_CONSULTARDATOSESTUDIANTES_H

#include "IComando.h"

class cmdConsultarDatosEstudiantes : public IComando
{
    public:
        cmdConsultarDatosEstudiantes();
        void ejecutarComando();
        ~cmdConsultarDatosEstudiantes();
    protected:
    private:
};

#endif // CMD_CONSULTARDATOSESTUDIANTES_H
