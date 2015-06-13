#ifndef CARRERA_H
#define CARRERA_H

#include "DataCarrera.h"
#include "ICollectible.h"


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
    protected:
    private:
       int codigo;
       string nombreCarrera;
};

#endif // CARRERA_H
