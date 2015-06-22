#include "OfertaLaboral.h"
#include "EstudianteController.h"
#include "ManejadorEstudiante.h"
#include "Estudiante.h"
#include "Tiempo.h"
#include <string>
#include <sstream>
#include <ctime>
#include <iostream>
#include <time.h>
#include "collections/List.h"
#include "collections/OrderedDictionary.h"

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
    this->inscripciones = new List();
    this->asignaturas = new OrderedDictionary();
    this->entrevistas = new List();

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
    if (asignaturas != NULL) {
        this->asignaturas = asignaturas;
    } else {
        this->asignaturas = new OrderedDictionary();
    }
    this->inscripciones = NULL;
    this->entrevistas = NULL;
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

IDictionary *OfertaLaboral::getAsignaturas()
{
    return this->asignaturas;
}

ICollection *OfertaLaboral::getInscripciones()
{
    return this->inscripciones;
}

ICollection *OfertaLaboral::getEntrevistas()
{
    return this->entrevistas;
}

Seccion *OfertaLaboral::getSeccion()
{
    return this->seccion;
}

void OfertaLaboral::setAsignaturas(IDictionary *asignaturas)
{
    this->asignaturas = asignaturas;
}

void OfertaLaboral::setInscripciones(ICollection *inscripciones)
{
    this->inscripciones = inscripciones;
}

void OfertaLaboral::setEntrevistas(ICollection *entrevistas)
{
    this->entrevistas = entrevistas;
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

void OfertaLaboral::setSeccion(Seccion *seccion)
{
    this->seccion = seccion;
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
//, this->asignaturas, this->seccion, this->inscripciones,        this->entrevistas);
}

DataOfertaEmpresa* OfertaLaboral::getDataOfertaLaboralEmpresa()
{

    DataEmpresa *dataEmpresa = this->seccion->getDataEmpresa();
    Rango* r = new Rango(this->rangoSalarial->getSueldoMinimo(), this->rangoSalarial->getSueldoMaximo());
    Date* fechaC = new Date(this->fechaComienzo->getDia(), this->fechaComienzo->getMes(), this->fechaComienzo->getAnio());
    Date* fechaF = new Date(this->fechaFin->getDia(), this->fechaFin->getMes(), this->fechaFin->getAnio());
    DataOfertaLaboral* dataOferta = new DataOfertaLaboral(this->numExpediente, this->titulo, this->descripcion,
                                                          this->cantidadHorasSemanales, r, fechaC, fechaF,
                                                          this->cantidadPuestosNecesarios);

    DataOfertaEmpresa *dataOfertaEmpresa = new DataOfertaEmpresa(dataEmpresa,dataOferta);
    return dataOfertaEmpresa;
}

void OfertaLaboral::Inscribir(Date *fechaInscripcion)
{
    EstudianteController* ec = EstudianteController::getInstance();
    Estudiante* e = ec->getEstudiante();
    if (e == NULL)
    {
        throw "El sistema no recuerda a ningun estudiante Seleccionado";
    }
    OfertaLaboralController *oc = OfertaLaboralController::getInstance();
    IDictionary *asigDeOL = oc->getOfertaLaboral()->getAsignaturas();
    ManejadorEstudiante* mEstu = ManejadorEstudiante::getInstance();

    if (mEstu->EstudianteCumpleRequisitos(e, asigDeOL))
    {
        Inscripcion* i = new Inscripcion(fechaInscripcion, this, e);
        e->AsociarInscripcion(i);
        this->inscripciones->add(i);
    }
    else
    {
        throw "OfertaLaboral -> El Estudiante no cumple con los requisitos para Inscribirse a la Oferta Laboral.";
    }
}

void OfertaLaboral::Entrevistar(Date *fechaEntrevista)
{
    EstudianteController* ec = EstudianteController::getInstance();
    Estudiante* e = ec->getEstudiante();
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
    string sddHoy = static_cast<ostringstream*>( &(ostringstream() << hoy->now()->getDia()) )->str();
    string smmHoy = static_cast<ostringstream*>( &(ostringstream() << hoy->now()->getMes()) )->str();
    string saaaaHoy = static_cast<ostringstream*>( &(ostringstream() << hoy->now()->getAnio()) )->str();
    string shoy = sddHoy + "/" + smmHoy + "/" + saaaaHoy;

    string sddCom = static_cast<ostringstream*>( &(ostringstream() << this->fechaComienzo->getDia()) )->str();
    string smmCom = static_cast<ostringstream*>( &(ostringstream() << this->fechaComienzo->getMes()) )->str();
    string saaaaCom = static_cast<ostringstream*>( &(ostringstream() << this->fechaComienzo->getAnio()) )->str();
    string sfechaComienzo = sddCom + "/" + smmCom + "/" + saaaaCom;

    string sddFin = static_cast<ostringstream*>( &(ostringstream() << this->fechaFin->getDia()) )->str();
    string smmFin = static_cast<ostringstream*>( &(ostringstream() << this->fechaFin->getMes()) )->str();
    string saaaaFin = static_cast<ostringstream*>( &(ostringstream() << this->fechaFin->getAnio()) )->str();
    string sfechaFin = sddFin + "/" + smmFin + "/" + saaaaFin;

    struct tm tm;
    time_t t1, t2, t3;

    strptime(shoy.c_str(), "%d\\%m\\%Y", &tm);
    t1 = mktime(&tm);//Fecha equivalente a hoy->now()

    strptime(sfechaComienzo.c_str(), "%d\\%m\\%Y", &tm);
    t2 = mktime(&tm);//Fecha equivalente a this->FechaComienzo

    strptime(sfechaFin.c_str(), "%d\\%m\\%Y", &tm);
    t3 = mktime(&tm);//Fecha equivalente a hoy->now()

    // do the same with d2
    double secondsInicio = difftime(t1, t2);
    double secondsFin = difftime(t1, t3);
    //double secondsInicio = difftime(hoy->now(), this->fechaComienzo);
    //double secondsFin = difftime(hoy->now(), this->fechaFin);

    return ((secondsInicio >= 0) && (secondsFin <= 0));
}

void OfertaLaboral::AltaAsignacionCargo(Date* fechaEfectivizacion, int sueldo)
{
    EstudianteController* ec = EstudianteController::getInstance();
    Estudiante* e = ec->getEstudiante();
    IIterator * it = e->getInscripciones()->getIterator();
    bool noEncontrada = true;
    while((it->hasCurrent())&&(noEncontrada))
    {
        Inscripcion* insc;
        if ((insc = dynamic_cast<Inscripcion*> (it->getCurrent())) != NULL )
        {
            if (insc->EstInscripto(this->numExpediente))
            {
                Efectivizacion* efe = new Efectivizacion(sueldo, fechaEfectivizacion);
                insc->setEfectivizacion(efe);
                noEncontrada = false;
            }

        } else
        {
            throw "OfertaLaboral-> El objeto no es de la clase Inscripcion.";
        }
        it->next();
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
