#ifndef SISTEMA_H
#define SISTEMA_H

#include <string>
#include "DataEmpresa.h"
#include "DataSucursal.h"
#include "DataSeccion.h"
#include "DataOfertaLaboral.h"
#include "DataEstudiante.h"
#include "DataAsignatura.h"
#include "Rango.h"
#include "Date.h"

class Sistema
{
    public:
        Sistema();
        ~Sistema();
        DataEmpresa** ListarEmpresas();
        void SeleccionarEmpresa(string rut);
        DataSucursal** ListarSucursales();
        void SeleccionarSucursal(string nombre);
        DataSeccion** ListarSecciones();
        void SeleccionarSeccion(string nombre);
        void AltaOfertaLaboral(string numExpediente, string titulo, string descripcion, int cantidadHorasSemanales, Rango *rangoSalarial, Date *fechaComienzo, Date *fechaFin, int cantidadPuestosNecesarios, string asig);
        DataOfertaLaboral** ListarOfertasPublicadas();
        void SeleccionarOferta(string numExpediente);
        DataEstudiante** ListarEstudiantes();
        void SeleccionarEstudiante(string cedula);
        void AltaEntrevista(Date *fechaEntrevista);
        DataEmpresa* get_infoEmpresa();
        DataSucursal* get_infoSucursal();
        DataSeccion* get_infoSeccion();
        DataOfertaLaboral* get_infoOferta();
        DataEstudiante* get_infoEstudiante();
        int getCantidadEmpresas();
        int getCantidadSucursales();
        int getCantidadSecciones();
        int getCantidadOfertasLaborales();
        int getCantidadEstudiantes();
    protected:
    private:
        DataEmpresa** empresas;
        DataSucursal** sucursales;
        DataSeccion** secciones;
        DataOfertaLaboral** ofertasPublicadas;
        DataEstudiante** estudiantes;
        DataEmpresa* infoEmpresa;
        DataSucursal* infoSucursal;
        DataSeccion* infoSeccion;
        DataOfertaLaboral* infoOferta;
        DataEstudiante* infoEstudiante;

        int topeEmpresas, topeSucursales, topeSecciones, topeOfertasLaborales, topeEstudiantes;
};

#endif // SISTEMA_H