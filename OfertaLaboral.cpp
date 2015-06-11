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
}

OfertaLaboral::OfertaLaboral(String numExpediente, String titulo, String descripcion, Integer cantidadHorasSemanales, Rango *rangoSalarial, Date *fechaComienzo, Date *fechaFin, Integer cantidadPuestosNecesarios)
{
    this->numExpediente = numExpediente;
    this->titulo = titulo;
    this->descripcion = descripcion;
    this->cantidadHorasSemanales = cantidadHorasSemanales;
    this->rangoSalarial = rangoSalarial;
    this->fechaComienzo = fechaComienzo;
    this->fechaFin = fechaFin;
    this->cantidadPuestosNecesarios = cantidadPuestosNecesarios;
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

DataOfertaLaboral *OfertaLaboral::getDataOfertaLaboral()
{
    return new DataOfertaLaboral(this->numExpediente, this->titulo, this->descripcion,
        this->cantidadHorasSemanales, this->rangoSalarial, this->fechaComienzo, this->fechaFin,
        this->cantidadPuestosNecesarios);
}

DataOfertaEmpresa* OfertaLaboral::getDataOfertaLaboralEmpresa()
{

   /* DataOfertaLaboral* dataOferta = new DataOfertaLaboral(this->numExpediente, this->titulo, this->descripcion,
                                                          this->cantidadHorasSemanales, new Rango(this->rangoSalarial),
                                                          new Date(this->fechaComienzo), new Date(this->fechaFin),
                                                          this->cantidadPuestosNecesarios);*/
    DataEmpresa *dataEmpresa = this->seccion->getDataEmpresa();
    DataOfertaLaboral* dataOferta = new DataOfertaLaboral(this->numExpediente, this->titulo, this->descripcion,
                                                          this->cantidadHorasSemanales, new Rango(this->rangoSalarial),
                                                          new Date(this->fechaComienzo), new Date(this->fechaFin),
                                                          this->cantidadPuestosNecesarios);
    DataOfertaEmpresa *dataOfertaEmpresa = new DataOfertaEmpresa(dataEmpresa,dataOferta);
    return dataOfertaEmpresa;
}

void OfertaLaboral::Inscripcion(Date *fechaInscripcion)
{
    //Debo llamar al constructor de inscripcion y pasarle por parametro fechaInscripcion.
    Estudiante* e = EstudianteController::getEstudiante();// esta bien getEstudiante??? // me parece que EstudianteController tiene que tener un puntero a el estudiante recordado en el seleccionar, porque la op getEstudiante no es del manejador
    Inscripcion *i = new Inscripcion(fechaInscripcion, this, e);
    e->AsociarInscripcion(i);
    this->inscripciones->add(i);
}

bool OfertaLaboral::EsOferta(String numExpediente)
{
    //Debo corroborar que la oferta sea la oferta con numExpediente.
    String(const numExpediente);// que hace?
    return (compare(OrderedKey *k)== EQUAl);//No veo como pasar mis string numExpediente y this->numExpediente a un OrderedKey para pasarlo como parámetro
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
