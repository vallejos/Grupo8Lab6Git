#include "Inscripcion.h"

Inscripcion::Inscripcion()
{
    //ctor
    this->fechaInscripcion = NULL;
    this->ofertaLab = NULL;
    this->estudiant = NULL;
    this->efectivo = NULL;
}

Inscripcion::Inscripcion(Date* fechaInscripcion, OfertaLaboral* ofertaLab, Estudiante* estu)
{
    this->fechaInscripcion = fechaInscripcion;
    this->ofertaLab = ofertaLab;
    this->estudiant = estu;
    this->efectivo = NULL;
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

Efectivizacion* Inscripcion::getEfectivizacion()
{
    return this->efectivo;
}

DataOfertaLaboral* Inscripcion::getDataOfertaLaboral()
{
    DataOfertaLaboral* dataOferta = new DataOfertaLaboral(this->ofertaLab->getNumExpediente(), 
        this->ofertaLab->getTitulo(),
        this->ofertaLab->getDescripcion(), this->ofertaLab->getCantidadHorasSemanales(),
        this->ofertaLab->getRangoSalarial(), this->ofertaLab->getFechaComienzo(),
        this->ofertaLab->getFechaFin(), this->ofertaLab->getCantidadPuestosNecesarios(),
        this->ofertaLab->getAsignaturas(), this->ofertaLab->getSeccion(),
        this->ofertaLab->getInscripciones(), this->ofertaLab->getEntrevistas());
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

void Inscripcion::setEfectivizacion(Efectivizacion* efe)
{
    this->efectivo = efe;
}

bool Inscripcion::EstInscripto(string numExpediente)
{
    return (this->ofertaLab->getNumExpediente() == numExpediente);
}

Inscripcion::~Inscripcion()
{
    //dtor
    if (this->fechaInscripcion != NULL)
        delete (this->fechaInscripcion);
}
