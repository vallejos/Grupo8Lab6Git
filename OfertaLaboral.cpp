#include "OfertaLaboral.h"

OfertaLaboral::OfertaLaboral()
{
    this->numExpediente = '\0';
    this->titulo = '\0';
    this->descripcion = '\0';
    this->cantidadHorasSemanales = 0;
    this->rangoSalarial = NULL;
    this->fechaComienzo = NULL;
    this->fechaFin = NULL;
    this->cantidadPuestosNecesarios = 0;
    this->creditosMinimos = 0;
}

OfertaLaboral::OfertaLaboral(String numExpediente, String titulo, String descripcion, Integer cantidadHorasSemanales, Rango *rangoSalarial, Date *fechaComienzo, Date *fechaFin, Integer cantidadPuestosNecesarios, Integer creditosMinimos)
{
    this->numExpediente = numExpediente;
    this->titulo = titulo;
    this->descripcion = descripcion;
    this->cantidadHorasSemanales = cantidadHorasSemanales;
    this->rangoSalarial = rangoSalarial;
    this->fechaComienzo = fechaComienzo;
    this->fechaFin = fechaFin;
    this->cantidadPuestosNecesarios = cantidadPuestosNecesarios;
    this->creditosMinimos = creditosMinimos;
}

OfertaLaboral::OfertaLaboral(const OfertaLaboral &o)
{
    this->numExpediente = o.numExpediente;
    this->titulo = o.titulo;
    this->descripcion = o.descripcion;
    this->cantidadHorasSemanales = o.cantidadHorasSemanales;
    this->rangoSalarial = o.rangoSalarial;
    this->fechaComienzo = o.fechaComienzo;
    this->fechaFin = o.fechaFin;
    this->cantidadPuestosNecesarios = o.cantidadPuestosNecesarios;
    this->creditosMinimos = o.creditosMinimos;
}

String OfertaLaboral::getNumExpediente()
{
	return this->numExpediente;
}

String OfertaLaboral::getTitulo()
{
	return this->titulo;
}

String OfertaLaboral::getDescripcion()
{
	return this->descripcion;
}

Integer OfertaLaboral::getCantidadHorasSemanales()
{
	return this->cantidadHorasSemanales;
}

Rango *OfertaLaboral::getRangoSalarial()
{
	return this->rangoSalarial;
}

Date *OfertaLaboral::getFechaComienzo()
{
	return this->fechaComienzo;
}

Date *OfertaLaboral::getFechaFin()
{
	return this->fechaFin;
}

Integer OfertaLaboral::getCantidadPuestosNecesarios()
{
	return this->cantidadPuestosNecesarios;
}

Integer OfertaLaboral::getCreditosMinimos()
{
	return this->creditosMinimos;
}

void OfertaLaboral::setNumExpediente(String numExpediente)
{
    this->numExpediente = numExpediente;
}

void OfertaLaboral::setTitulo(String titulo)
{
    this->titulo = titulo;
}

void OfertaLaboral::setDescripcion(String descripcion)
{
    this->descripcion = descripcion;
}

void OfertaLaboral::setCantidadHorasSemanales(Integer cantidadHorasSemanales)
{
    this->cantidadHorasSemanales = cantidadHorasSemanales;
}

void OfertaLaboral::setRangoSalarial(Rango *rangoSalarial)
{
    this->rangoSalarial = rangoSalarial;
}

void OfertaLaboral::setFechaComienzo(Date *fechaComienzo)
{
    this->fechaComienzo = fechaComienzo;
}

void OfertaLaboral::setFechaFin(Date *fechaFin)
{
    this->fechaFin = fechaFin;
}

void OfertaLaboral::setCantidadPuestosNecesarios(Integer cantidadPuestosNecesarios)
{
    this->cantidadPuestosNecesarios = cantidadPuestosNecesarios;
}

void OfertaLaboral::setCreditosMinimos(Integer creditosMinimos)
{
    this->creditosMinimos = creditosMinimos;
}

DataOfertaLaboral *OfertaLaboral::getDataOfertaLaboral()
{
    return new DataOfertaLaboral(this->numExpediente, this->titulo, this->descripcion,
        this->cantidadHorasSemanales, this->rangoSalarial, this->fechaComienzo, this->fechaFin,
        this->cantidadPuestosNecesarios, this->creditosMinimos);
}

DataOfertaEmpresa* OfertaLaboral::getDataOfertaLaboralEmpresa()
{
    //Debería llamar al constructor de DataOfertaEmpresa.
    DataOfertaLaboral* dataOferta = new DataOfertaLaboral(this->numExpediente, this->titulo, this->descripcion,
                                                          this->cantidadHorasSemanales, new Rango(this->rangoSalarial),
                                                          new Date(this->fechaComienzo), new Date(this->fechaFin),
                                                          this->cantidadPuestosNecesarios);
    return dataOferta;
}

void OfertaLaboral::Inscripcion(Date *fechaInscripcion)
{
    //Debo llamar al constructor de inscripcion y pasarle por parametro fechaInscripcion.
    Estudiante* e = EstudianteController::getEstudiante();// esta bien getEstudiante???
    Inscripcion *i = new Inscripcion(fechaInscripcion, this, e);
    e->AsociarInscripcion(i);
    this->inscripciones->add(i);
}

bool OfertaLaboral::EsOferta(String numExpediente)
{
    //Debo corroborar que la oferta sea la oferta con numExpediente.
}

bool OfertaLaboral::EsActiva()
{
    Tiempo* hoy = Tiempo::getInstance();
    secondsInicio = difftime(hoy->now(), this->fechaComienzo);
    secondsFin = difftime(hoy->now(), this->fechaFin);

    return ((secondsInicio >= 0) && (secondsFin <= 0));
}

OfertaLaboral::~OfertaLaboral()
{

}
