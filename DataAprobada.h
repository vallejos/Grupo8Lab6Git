#ifndef DATAAPROBADA_H
#define DATAAPROBADA_H

#include "Date.h"
#include "DataAsignatura.h"
#include "interfaces/ICollectible.h"

class DataAprobada : public ICollectible
{
    public:
        //DataAprobada();
        DataAprobada(int nota, Date* fecha, DataAsignatura* dataAsig);
        DataAprobada(const DataAprobada &dAp);

        //getters
        int getNota();
        Date* getFecha();
        DataAsignatura* getDataAsignatura();

        ~DataAprobada();

    private:
        int nota;
        Date* fecha;
        DataAsignatura* asig;
};

#endif // DATAAPROBADA_H
