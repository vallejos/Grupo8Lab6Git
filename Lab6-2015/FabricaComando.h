#ifndef FABRICACOMANDO_H
#define FABRICACOMANDO_H
#include "IComando.h"
#include <string>

using namespace std;

class FabricaComando
{
    public:
        static FabricaComando *getInstance();
        IComando* obtenerComando(char cmd);
        void destroyFabricaComando();
    private:
        ~FabricaComando();
        FabricaComando();
        static FabricaComando* instance;
};

#endif // FABRICACOMANDO_H
