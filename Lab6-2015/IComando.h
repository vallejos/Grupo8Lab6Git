#ifndef ICOMANDO_H
#define ICOMANDO_H


class IComando
{
    public:
        IComando();
        virtual ~IComando();
        virtual void ejecutarComando() = 0;
};

#endif // ICOMANDO_H
