#include "Entrevista.h"

Entrevista::Entrevista()
{
    //ctor
    this->fechaEntrevista = NULL;
    this->ofertaLab = NULL;
    this->estudiant = NULL;
}

Entrevista::Entrevista(Date* fechaEntrevista, OfertaLaboral* ofertaLab, Estudiante* estu)
{
    this->fechaEntrevista = fechaEntrevista;
    this->ofertaLab = ofertaLab;
    this->estudiant = estu;
}

/*Entrevista::Entrevista(const Entrevista &i)
{
    Date* fechaEnt = new Date(&i.fechaEntrevista);
    OfertaLaboral* oferta = new OfertaLaboral(i.ofertaLab);
    Estudiante* estu = new Estudiante(i.estudiant);

    this->fechaEntrevista = fechaEnt;
    this->ofertaLab = oferta;
    this->estudiant = estu;
}*/

Date* Entrevista::getFechaEntrevista()
{
    return this->fechaEntrevista;
}

OfertaLaboral* Entrevista::getOfertaLaboral()
{
    return this->ofertaLab;
}

Estudiante* Entrevista::getEstudiante()
{
    return this->estudiant;
}

void Entrevista::setFechaEntrevista(Date* fechaEntrevista)
{
    this->fechaEntrevista = fechaEntrevista;
}

void Entrevista::setOfertaLaboral(OfertaLaboral* ofertaLab)
{
    this->ofertaLab = ofertaLab;
}

void Entrevista::setEstudiante(Estudiante* estu)
{
    this->estudiant = estu;
}

Entrevista::~Entrevista()
{
    if (this->fechaEntrevista != NULL)
    {
        delete this->fechaEntrevista;
    }
    if (this->ofertaLab != NULL)
    {
        delete this->ofertaLab;
    }
    if (this->estudiant != NULL)
    {
        delete this->estudiant;
    }
}
