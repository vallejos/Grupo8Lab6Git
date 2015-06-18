#ifndef CMD_ALTAENTREVISTA_H
#define CMD_ALTAENTREVISTA_H

#include "IComando.h"

class cmdAltaEntrevista : public IComando
{
    public:
        cmdAltaEntrevista();
        void ejecutarComando();
        ~cmdAltaEntrevista();
    private:
    protected:
};

#endif // CMD_ALTAENTREVISTA_H
