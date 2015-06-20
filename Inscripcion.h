#ifndef INSCRIPCION_H
#define INSCRIPCION_H

#include "Date.h"
#include "OfertaLaboral.h"
#include "DataOfertaLaboral.h"
#include "Estudiante.h"
#include "Efectivizacion.h"
#include "interfaces/ICollectible.h"

class Inscripcion : public ICollectible
{
    public:
        Inscripcion();
        Inscripcion(Date* fechaInscripcion, OfertaLaboral* ofertaLab, Estudiante* estu);
        Inscripcion(const Inscripcion &i);

        //getters
        Date* getFechaInscripcion();
        OfertaLaboral* getOfertaLaboral();
        Estudiante* getEstudiante();
        Efectivizacion* getEfectivizacion();
        DataOfertaLaboral* getDataOfertaLaboral();

        //setters
        void setFechaInscripcion(Date* fechaInscripcion);
        void setOfertaLaboral(OfertaLaboral* ofertaLab);
        void setEstudiante(Estudiante* estu);
        void setEfectivizacion(Efectivizacion* efe);

        //operaciones
        bool EstInscripto(string numExpediente);

        ~Inscripcion();
    protected:
    private:
        Date* fechaInscripcion;
        OfertaLaboral* ofertaLab;
        Estudiante* estudiant;
        Efectivizacion* efectivo;
};

#endif // INSCRIPCION_H
