#include "OfertaLaboral.h"
#include "EstudianteController"
#include "Estudiante"
#include "Tiempo.h"

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
    this->entrevistas = NULL;

}

OfertaLaboral::OfertaLaboral(string numExpediente, string titulo, string descripcion, int cantidadHorasSemanales,
                            Rango *rangoSalarial, Date *fechaComienzo, Date *fechaFin, int cantidadPuestosNecesarios,
                            IDictionary *asignaturas)
{
    this->numExpediente = numExpediente;
    this->titulo = titulo;
    this->descripcion = descripcion;
    this->cantidadHorasSemanales = cantidadHorasSemanales;
    this->rangoSalarial = rangoSalarial;
    this->fechaComienzo = fechaComienzo;
    this->fechaFin = fechaFin;
    this->cantidadPuestosNecesarios = cantidadPuestosNecesarios;
    this->asignaturas = asignaturas;
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
    this->seccion = o.seccion;
    this->inscripciones = o.inscripciones;
    this->asignaturas = o.asignaturas;
    this->entrevistas = o.entrevistas;
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
        this->cantidadPuestosNecesarios, this->asignaturas, this->seccion, this->inscripciones,
        this->entrevistas);
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
    EstudianteController* ec = EstudianteController::getInstance();
    e = ec->getEstudiante();
    if (e == NULL)// no se si puedo hacer esto, no es necesario el try catch?
        throw std::invalid_argument("El sistema no recuerda a ningun estudiante Seleccionado");
    Inscripcion *i = new Inscripcion(fechaInscripcion, this, e);
    e->AsociarInscripcion(i);
    this->inscripciones->add(i);
    //Creo que el estudiante se elimina acá
    delete e;
}

void OfertaLaboral::Entrevista(Date *fechaEntrevista)
{
    EstudianteController* ec = EstudianteController::getInstance();
    e = ec->getEstudiante();
    Entrevista *ent = new Entrevista(fechaEntrevista, this, e);
    e->AsociarEntrevista(ent);
    this->entrevistas->add(ent);
}

bool OfertaLaboral::EsOferta(string numExpediente)
{
   return (this->numExpediente == numExpediente);
}

bool OfertaLaboral::EsActiva()
{
    Tiempo* hoy = Tiempo::getInstance();
    secondsInicio = difftime(hoy->now(), this->fechaComienzo);
    secondsFin = difftime(hoy->now(), this->fechaFin);

    return ((secondsInicio >= 0) && (secondsFin <= 0));
}

void OfertaLaboral::AltaAsignacionCargo(Date* fechaEfectivizacion, int sueldo)
{
    EstudianteController* ec = EstudianteController::getInstance();
    Estudiante* e = ec->getEstudiante();
    IIterator * it = e->inscripciones()->getIterator();
    bool noEncontrada = true;
    while((it.hasCurrent())&&(noEncontrada))
    {
        if(it.current()->EstInscripto(this->numExpediente))
        {
            Efectivizacion* efe = Efectivizacion(sueldo, fechaEfectivizacion);
            it.current()->setEfectivizacion(efe);
            noEncontrada = false;
        }
        it.next();
    }
    delete it;
}

OfertaLaboral::~OfertaLaboral()
{
    if (this->seccion != NULL)
        delete this->seccion;
    if (this->inscripciones != NULL)
        delete this->inscripciones;
    if (this->asignaturas != NULL)
        delete this->asignaturas;
    if (this->entrevistas != NULL)
        delete this->entrevistas;

}
