#include "OfertaLaboral.h"
#include "EstudianteController"
#include "Estudiante"

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
    this->seccion = NULL;
    this->inscripciones = NULL;
    this->asignaturas = NULL;
}

OfertaLaboral::OfertaLaboral(string numExpediente, string titulo, string descripcion, int cantidadHorasSemanales, Rango *rangoSalarial, Date *fechaComienzo, Date *fechaFin, int cantidadPuestosNecesarios, IDictionary *asignaturas)
{
    this->numExpediente = numExpediente;
    this->titulo = titulo;
    this->descripcion = descripcion;
    this->cantidadHorasSemanales = cantidadHorasSemanales;
    this->rangoSalarial = rangoSalarial;
    this->fechaComienzo = fechaComienzo;
    this->fechaFin = fechaFin;
    this->cantidadPuestosNecesarios = cantidadPuestosNecesarios;
    this->asignaturas = asignaturas;// está bien que sea asi directa la asociación? que se hace con seccion e inscripciones?
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
    this->seccion = o.seccion;// está bien?
    this->inscripciones = o.inscripciones;
    this->asignaturas = o.asignaturas;
}

string OfertaLaboral::getNumExpediente()
{
	return this->numExpediente;
}

string OfertaLaboral::getTitulo()
{
	return this->titulo;
}

string OfertaLaboral::getDescripcion()
{
	return this->descripcion;
}

int OfertaLaboral::getCantidadHorasSemanales()
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

int OfertaLaboral::getCantidadPuestosNecesarios()
{
	return this->cantidadPuestosNecesarios;
}

void OfertaLaboral::setNumExpediente(string numExpediente)
{
    this->numExpediente = numExpediente;
}

void OfertaLaboral::setTitulo(string titulo)
{
    this->titulo = titulo;
}

void OfertaLaboral::setDescripcion(string descripcion)
{
    this->descripcion = descripcion;
}

void OfertaLaboral::setCantidadHorasSemanales(int cantidadHorasSemanales)
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

void OfertaLaboral::setCantidadPuestosNecesarios(int cantidadPuestosNecesarios)
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
    Estudiante* e = EstudianteController::getEstudiante();// esta bien getEstudiante???
    Inscripcion *i = new Inscripcion(fechaInscripcion, this, e);
    e->AsociarInscripcion(i);
    this->inscripciones->add(i);
}

void OfertaLaboral::Entrevista(Date *fechaEntrevista)
{
    Estudiante* e = EstudianteController::getEstudiante();// esta bien getEstudiante??? // me parece que EstudianteController tiene que tener un puntero a el estudiante recordado en el seleccionar, porque la op getEstudiante no es del manejador
    Entrevista *ent = new Entrevista(fechaEntrevista, this, e);
    e->AsociarEntrevista(ent);
    this->entrevistas->add(ent);
}

bool OfertaLaboral::EsOferta(string numExpediente)
{
    //Debo corroborar que la oferta sea la oferta con numExpediente.
    String(const numExpediente);
    return (compare(OrderedKey *k)== EQUAl);//No veo como comparar numExpediente y this->numExpediente
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
    this->seccion->~Seccion();
    IIterator * it = this->inscripciones->getElemIterator();
    while(it.hasCurrent())
    {
        aux = it.current();
        it.next();
        delete aux;// o llama a el destructor de inscripcion
    }
    delete it;
    IIterator * it = this->asignaturas->getElemIterator();
     while(it.hasCurrent())
    {
        aux = it.current();
        it.next();
        delete aux;// o llama a el destructor de asignatura
    }
    delete it;
}
