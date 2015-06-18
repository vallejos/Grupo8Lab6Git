#ifndef CMD_LISTAROFERTASACTIVAS_H
#define CMD_LISTAROFERTASACTIVAS_H


class cmdListarOfertasActivas : public IComando
{
    public:
        cmdListarOfertasActivas();
        void ejecutarComando();
        ~cmdListarOfertasActivas();
};

#endif // CMD_LISTAROFERTASACTIVAS_H
