#ifndef ENTREVSTA_H
#define ENTREVSTA_H

#include "Date.h"
#include "OfertaLaboral.h"
#include "DataOfertaLaboral.h"
#include "Estudiante.h"

class Entrevista : public ICollectible
{
    private:
        Date* fechaEntrevista;
        OfertaLaboral* ofertaLab;
        Estudiante* estudiant;

    public:
        Entrevista();
        Entrevista(Date* fechaEntrevista, OfertaLaboral* ofertaLab, Estudiante* estu);
        //Entrevista(const Entrevista &i);
        //getters
        Date* getFechaEntrevista();
        OfertaLaboral* getOfertaLaboral();
        Estudiante* getEstudiante();

        //setters
        void setFechaEntrevista(Date* fechaEntrevista);
        void setOfertaLaboral(OfertaLaboral* ofertaLab);
        void setEstudiante(Estudiante* estu);

        ~Entrevista();
};

#endif // Entrevista_H
