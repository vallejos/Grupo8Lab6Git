#ifndef IEMPRESACONTROLLER_H
#define IEMPRESACONTROLLER_H

#include "ICollection.h"
#include "List.h"
#include "Empresa.h"
#include "Sucursal.h"
#include "Seccion.h"
#include "Date.h"
#include "Rango.h"

class IEmpresaController
{
    public:
        virtual void altaOfertaLaboral(string numExpediente, string titulo, string descripcion, int cantidadHorasSemanales, Rango* rangoSalarial, Date* fechaComienzo, Date* fechaFin, int cantidadPuestosNecesarios, List* asignaturas) = 0;
        virtual ICollection* ListarEmpresas() = 0;
        virtual ICollection* ListarSucursales() = 0;
        virtual ICollection* ListarSecciones() = 0;
        virtual Empresa* SeleccionarEmpresa(string rut) = 0;
        virtual Sucursal* SeleccionarSucursal(string nombre) = 0;
        virtual Seccion* SeleccionarSeccion(string nombre) = 0;
};

#endif // IEMPRESACONTROLLER_H
