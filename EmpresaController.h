#ifndef EMPRESACONTROLLER_H
#define EMPRESACONTROLLER_H

#include <string>
#include "DataEmpresa.h"
#include "DataSucursal.h"
#include "DataSeccion.h"
#include "Date.h"
#include "Rango.h"
#include "DataAsignatura.h"
#include "Empresa.h"
#include "interfaces/ICollection.h"
#include "interfaces/IDictionary.h"
#include "collections/OrderedDictionary.h"
#include "Empresa.h"
#include "Sucursal.h"
#include "Seccion.h"
#include "EstrategiaAsignaturas.h"
#include "ManejadorEmpresa.h"
#include "IEmpresaController.h"

class EmpresaController: public IEmpresaController
{
    public:
        static EmpresaController *getInstance();
        void AltaOfertaLaboral(string numExpediente, string titulo, string descripcion, int cantidadHorasSemanales,
        	Rango *rangoSalarial, Date *fechaComienzo, Date *fechaFin, int cantidadPuestosNecesarios,
        	IDictionary *asignaturas);
        ICollection* ListarEmpresas();
        ICollection* ListarSucursales();
        IDictionary* ListarSecciones();
        Empresa* getEmpresa();
        Sucursal* getSucursal();
        Seccion* getSeccion();
        IDictionary* obtenerAsignaturasValidas(IDictionary* asignaturasIngresadas);
        void setCriterio(EstrategiaAsignaturas* criterio);
        IDictionary *getEmpresas();
        void SeleccionarEmpresa(string rut);
        void SeleccionarSucursal(string nombre);
        void SeleccionarSeccion(string nombre);
        void destroyEmpresaController();

    private:
        EmpresaController();
        Empresa *empresa; // la empresa que se recuerda
        Sucursal *sucursal; // la sucursal que se recuerda
        Seccion *seccion;
        EstrategiaAsignaturas* criterio;
    	static EmpresaController *instance;
        ~EmpresaController();
};

#endif // EMPRESACONTROLLER_H
