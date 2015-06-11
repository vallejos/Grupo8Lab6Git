#ifndef INSCRIPCION_H
#define INSCRIPCION_H

#include "Date.h"
#include "OfertaLaboral.h"
#include "DataOfertaLaboral.h"
#include "Estudiante.h"

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
        DataOfertaLaboral* getDataOfertaLaboral();

        //setters
        void setFechaInscripcion(Date* fechaInscripcion);
        void setOfertaLaboral(OfertaLaboral* ofertaLab);
        void setEstudiante(Estudiante* estu);

        //operaciones
        bool EstInscripto(int numExpediente);

        ~Inscripcion();
    protected:
    private:
        Date* fechaInscripcion;
        OfertaLaboral* ofertaLab;
        Estudiante* estudiant;
};

#endif // INSCRIPCION_H