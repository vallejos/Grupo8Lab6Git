#ifndef CMD_DARDEBAJALLAMADO_H
#define CMD_DARDEBAJALLAMADO_H

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
