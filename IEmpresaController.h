#ifndef IEMPRESACONTROLLER_H
#define IEMPRESACONTROLLER_H

#include "interfaces/ICollection.h"
#include "interfaces/IDictionary.h"
#include "collections/List.h"
#include "EstrategiaAsignaturas.h"
#include "Empresa.h"
#include "Sucursal.h"
#include "Seccion.h"
#include "Date.h"
#include "Rango.h"

class IEmpresaController
{
    public:
        IEmpresaController();
        virtual ~IEmpresaController() = 0;
        virtual void altaOfertaLaboral(string numExpediente, string titulo, string descripcion, int cantidadHorasSemanales, Rango* rangoSalarial, Date* fechaComienzo, Date* fechaFin, int cantidadPuestosNecesarios, IDictionary* asignaturas) = 0;
        virtual ICollection *ListarEmpresas() = 0;
        virtual ICollection *ListarSucursales() = 0;
        virtual ICollection *ListarSecciones() = 0;
        virtual IDictionary* obtenerAsignaturasValidas(IDictionary* asignaturasIngresadas) = 0;
        virtual void setCriterio(EstrategiaAsignaturas* criterio) = 0;
        virtual void SeleccionarEmpresa(string rut) = 0;
        virtual void SeleccionarSucursal(string nombre) = 0;
        virtual void SeleccionarSeccion(string nombre) = 0;
        virtual Seccion *getSeccion() = 0;
        virtual IDictionary *getEmpresas() = 0;
};

#endif // IEMPRESACONTROLLER_H
