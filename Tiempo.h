#ifndef TIEMPO_H
#define TIEMPO_H

#include <ctime>
#include "Date.h"

class Tiempo
{
    public:
        static Tiempo* getInstance();
        Date* now();
        void setTiempo(int dd, int mm, int aaaa);
        ~Tiempo();

    private:
        Tiempo();
        static Tiempo* instance;
        bool fijo;
        Date* tiempoFijo;
};

#endif // TIEMPO_H
