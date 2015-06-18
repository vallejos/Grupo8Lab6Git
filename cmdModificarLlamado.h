#ifndef CMD_MODIFICARLLAMADO_H
#define CMD_MODIFICARLLAMADO_H


class cmdModificarLlamado: public IComando
{
    public:
        cmdModificarLlamado();
        void ejecutarComando();
        ~cmdModificarLlamado();
    protected:
    private:
};

#endif // CMD_MODIFICARLLAMADO_H