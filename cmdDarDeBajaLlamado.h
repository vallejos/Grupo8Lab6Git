#ifndef CMD_DARDEBAJALLAMADO_H
#define CMD_DARDEBAJALLAMADO_H

#include <exception>
#include "IComando.h"

class cmdDarDeBajaLlamado: public IComando
{
    public:
        cmdDarDeBajaLlamado();
        void ejecutarComando();
        ~cmdDarDeBajaLlamado();
    protected:
    private:
};

#endif // CMD_DARDEBAJALLAMADO_H
