#ifndef CMD_ALTAOFERTALABORAL_H
#define CMD_ALTAOFERTALABORAL_H

#include <exception>
#include "IComando.h"

class cmdAltaOfertaLaboral: public IComando
{
    public:
        cmdAltaOfertaLaboral();
        void ejecutarComando();
        ~cmdAltaOfertaLaboral();
    protected:
    private:
};

#endif // CMD_ALTAOFERTALABORAL_H
