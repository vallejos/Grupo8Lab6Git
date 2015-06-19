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
<<<<<<< HEAD
        //DataCarrera* getDataCarrera();

=======
        DataCarrera* getDataCarrera();
        IDictionary* getAsignaturas();
>>>>>>> origin/CambiandoAlgunasCosas
        //setters
        void setCodigo(int codigo);
        void setNombreCarrera(string nombreCarrera);
        void setAsignaturas(IDictionary* asignaturas);
        ~Carrera();

    private:
       int codigo;
       string nombreCarrera;
       IDictionary* asignaturas;
};

#endif // CARRERA_H
