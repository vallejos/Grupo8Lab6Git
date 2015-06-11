#include "Sistema.h"

Sistema::Sistema()
{
    //ctor
}

DataEmpresa** Sistema::ListarEmpresas()
{
    this->empresas[0] = new DataEmpresa();
    this->empresas[1] = new DataEmpresa();
    this->topeEmpresas = 2;
    return this->empresas;
}

DataSucursal** Sistema::ListarSucursales()
{
    this->sucursales[0] = new DataSucursal();
    this->sucursales[1] = new DataSucursal();
    this->topeSucursales = 2;
    return this->sucursales;
}

DataSeccion** Sistema::ListarSecciones()
{
    this->secciones[0] = new DataSeccion();
    this->secciones[1] = new DataSeccion();
    this->topeSecciones = 2;
    return this->secciones;
}

DataOfertaLaboral** Sistema::ListarOfertasPublicadas()
{
    this->ofertasPublicadas[0] = new DataOfertaLaboral();
    this->ofertasPublicadas[1] = new DataOfertaLaboral();
    this->topeOfertasLaborales = 2;
    return this->ofertasPublicadas;
}

DataEstudiante** Sistema::ListarEstudiantes()
{
    this->estudiantes[0] = new DataEstudiante();
    this->estudiantes[1] = new DataEstudiante();
    this->topeEstudiantes = 2;
    return this->estudiantes;
}

void Sistema::SeleccionarEmpresa(string rut)
{
    //se buscaria la empresa con el rut en la coleccion de empresas
    this->infoEmpresa = this->empresas[0];
}

void Sistema::SeleccionarSucursal(string nombre)
{
    //se buscaria la sucursal con el nombre en la coleccion de sucursales
    this->infoSucursal = this->sucursales[0];
}

void Sistema::SeleccionarSeccion(string nombre)
{
    //se buscaria la seccion con el nombre en la coleccion de secciones
    this->infoSeccion = this->secciones[0];
}

void Sistema::SeleccionarOferta(string numExpediente)
{
    //se buscaria la oferta con el numExpediente en la coleccion de ofertas
    this->infoOferta = this->ofertasPublicadas[0];
}

void Sistema::SeleccionarEstudiante(string cedula)
{
    //se buscaria el estudiante con la cedula en la coleccion de estudiantes
    this->infoEstudiante = this->estudiantes[0];
}

DataEmpresa* Sistema::get_infoEmpresa()
{
    return this->infoEmpresa;
}

DataSucursal* Sistema::get_infoSucursal()
{
    return this->infoSucursal;
}

DataSeccion* Sistema::get_infoSeccion()
{
    return this->infoSeccion;
}

DataOfertaLaboral* Sistema::get_infoOferta()
{
    return this->infoOferta;
}

DataEstudiante* Sistema::get_infoEstudiante()
{
    return this->infoEstudiante;
}

void Sistema::AltaOfertaLaboral(string numExpediente, string titulo, string descripcion, int cantidadHorasSemanales, Rango *rangoSalarial, Date *fechaComienzo, Date *fechaFin, int cantidadPuestosNecesarios, string asig)
{
    //se da de alta la oferta y se realizan todos los links correspondientes
    //se libera la memoria ocupada por infoEmpres, infoSucursal, infoSeccion
}

void Sistema::AltaEntrevista(Date *fechaEntrevista)
{
    //se crea la entrevista y se realizan todos los links correspondientes
    //se libera la memoria ocupada por infoOferta, infoEstudiante
}

int Sistema::getCantidadEmpresas()
{
    return this->topeEmpresas;
}

int Sistema::getCantidadSucursales()
{
    return this->topeSucursales;
}

int Sistema::getCantidadSecciones()
{
    return this->topeSecciones;
}

int Sistema::getCantidadOfertasLaborales()
{
    return this->topeOfertasLaborales;
}

int Sistema::getCantidadEstudiantes()
{
    return this->topeEstudiantes;
}

Sistema::~Sistema()
{
    //dtor
}