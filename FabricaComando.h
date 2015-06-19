#ifndef FABRICACOMANDO_H
#define FABRICACOMANDO_H


class FabricaComando
{
    public:
        static FabricaComando *getInstance();
        IComando* obtenerComando(string cmd);
        void destroyFabricaComando();
    protected:
    private:
        ~FabricaComando();
        FabricaComando();
        static FabricaComando* instance;
};

#endif // FABRICACOMANDO_H
