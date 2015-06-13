#ifndef EFECTIVIZACION_H
#define EFECTIVIZACION_H


class Efectivizacion
{
    private:
        int sueldo;
        Date* fechaEfectivizacion;
    public:
        Efectivizacion();
        Efectivizacion(int sueldo, Date* fechaEfectivizacion);

        //getters
        int getSueldo();
        Date* getFechaEfectivizacion();

        //setters
        void setSueldo(int nuevoSueldo);
        void setFechaEfectivizacion(Date* nuevaFechaEfectivizacion);

        ~Efectivizacion();
};

#endif // EFECTIVIZACION_H
