#ifndef APROBACION_H
#define APROBACION_H

#include "Date.h"
#include "DataAsignatura.h"
#include "DataAprobada.h"
#include "Asignatura.h"
#include "interfaces/ICollectible.h"

class Aprobacion : public ICollectible
{
    public:
        Aprobacion();
        Aprobacion(Date* fecha, int nota, Asignatura* asig);
        Aprobacion(const Aprobacion &a);

        //getters
        Date* getFecha();
        int getNota();
        Asignatura* getAsignatura();
        DataAprobada* getDataAprobada();
        DataAsignatura* getDataAsignatura();

        //setters
        void setFecha(Date* fecha);
        void setNota(int nota);
        void setAsignatura(Asignatura* a);

        ~Aprobacion();

    private:
        Date* fecha;
        int nota;
        Asignatura* asig;
};

#endif // APROBACION_H
