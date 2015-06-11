#include "Inscripcion.h"

Inscripcion::Inscripcion()
{
    //ctor
    this->fechaInscripcion = NULL;
    this->ofertaLab = NULL;
    this->estudiant = NULL;
}

Inscripcion::Inscripcion(Date* fechaInscripcion, OfertaLaboral* ofertaLab, Estudiante* estu)
{
    this->fechaInscripcion = fechaInscripcion;
    this->ofertaLab = ofertaLab;
    this->estudiant = estu;
}

Inscripcion::Inscripcion(const Inscripcion &i)
{
    Date* fechaInsc = new Date(i.fechaInscripcion);
    OfertaLaboral* oferta = new OfertaLaboral(i.ofertaLab);
    Estudiante* estu = new Estudiante(i.estudiant);

    this->fechaInscripcion = fechaInsc;
    this->ofertaLab = oferta;
    this->estudiant = estu;
}

Date* Inscripcion::getFechaInscripcion()
{
    return this->fechaInscripcion;
}

OfertaLaboral* Inscripcion::getOfertaLaboral()
{
    return this->ofertaLab;
}

Estudiante* Inscripcion::getEstudiante()
{
    return this->estudiant;
}

DataOfertaLaboral* Inscripcion::getDataOfertaLaboral()
{
    DataOfertaLaboral* dataOferta = new DataOfertaLaboral(this->ofertaLab->getNumExpediente(), this->ofertaLab->getTitulo(), this->ofertaLab->getDescripcion(), this->ofertaLab->getCantidadHorasSemanales(), this->ofertaLab->getRangoSalarial(), this->ofertaLab->getFechaComienzo(), this->ofertaLab->getFechaFin(), this->ofertaLab->getCantidadPuestosNecesarios());
    return dataOferta;
}

void Inscripcion::setFechaInscripcion(Date* fechaInscripcion)
{
    this->fechaInscripcion = fechaInscripcion;
}

void Inscripcion::setOfertaLaboral(OfertaLaboral* ofertaLab)
{
    this->ofertaLab = ofertaLab;
}

void Inscripcion::setEstudiante(Estudiante* estu)
{
    this->estudiant = estu;
}

bool Inscripcion::EstInscripto(int numExpediente)
{
    return (this->ofertaLab->getNumExpediente() == numExpediente);
}


Inscripcion::~Inscripcion()
{
    //dtor
}
