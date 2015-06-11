#ifndef DATAAPROBADA_H
#define DATAAPROBADA_H


class DataAprobada
{
    public:
        DataAprobada();
        DataAprobada(int nota, Date* fecha, DataAsignatura* dataAsig);
        DataAprobada(const DataAprobada &dAp);

        //getters
        int getNota();
        Date* getFecha();
        DataAsignatura* getDataAsignatura();

        ~DataAprobada();
    protected:
    private:
        int nota;
        Date* fecha;
        DataAsignatura* asig;
};

#endif // DATAAPROBADA_H
