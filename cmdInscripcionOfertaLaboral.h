#ifndef CMD_INSCRIPCIONOFERTALABORAL_H
#define CMD_INSCRIPCIONOFERTALABORAL_H

#include "IComando.h"

class cmdInscripcionOfertaLaboral : public IComando
{
    public:
        cmdInscripcionOfertaLaboral();
        void ejecutarComando();
        ~cmdInscripcionOfertaLaboral();
    protected:
    private:
};

#endif // CMD_INSCRIPCIONOFERTALABORAL_H
