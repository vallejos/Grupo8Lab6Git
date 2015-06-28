#ifndef EFECTIVIZACION_H
#define EFECTIVIZACION_H

#include "Date.h"
#include <string>
#include "interfaces/ICollectible.h"

class Efectivizacion : public ICollectible
{
    private:
        int sueldo;
        Date* fechaEfectivizacion;

    public:
        Efectivizacion();
        Efectivizacion(int sueldo, Date* fechaEfectivizacion);
        Efectivizacion(const Efectivizacion &e);

        //getters
        int getSueldo();
        Date* getFechaEfectivizacion();

        //setters
        void setSueldo(int nuevoSueldo);
        void setFechaEfectivizacion(Date* nuevaFechaEfectivizacion);

        ~Efectivizacion();
};

#endif // EFECTIVIZACION_H
