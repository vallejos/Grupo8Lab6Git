#ifndef CARRERA_H
#define CARRERA_H

#include <exception>
#include "DataCarrera.h"
#include "interfaces/ICollectible.h"


class Carrera : public ICollectible
{
    public:
        Carrera();
        Carrera(int codigo, string nombreCarrera);
        Carrera(const Carrera &c);

        //getters
        int getCodigo();
        string getNombreCarrera();
        DataCarrera* getDataCarrera();

        //setters
        void setCodigo(int codigo);
        void setNombreCarrera(string nombreCarrera);

        ~Carrera();

    private:
       int codigo;
       string nombreCarrera;
};

#endif // CARRERA_H
