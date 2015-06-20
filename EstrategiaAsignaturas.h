#ifndef ESTRATEGIAASIGNATURAS_H
#define ESTRATEGIAASIGNATURAS_H


class EstrategiaAsignaturas
{
    public:
        EstrategiaAsignaturas();
        virtual IDictionary *devolverListaAsignatura(IDictionary *asignaturas) = 0;
        virtual ~EstrategiaAsignaturas() = 0;
    protected:
    private:
};

#endif // ESTRATEGIAASIGNATURAS_H
