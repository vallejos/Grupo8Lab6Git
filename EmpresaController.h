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

class EmpresaController {
    public:
        EmpresaController *getInstance();
        void AltaOfertaLaboral(string numExpediente, string titulo, string descripcion, int cantidadHorasSemanales, 
        	Rango *rangoSalarial, Date *fechaComienzo, Date *fechaFin, int cantidadPuestosNecesarios, 
        	DataAsignatura *asignaturas);
        DataEmpresa **ListarEmpresas();
        DataSucursal **ListarSucursales();
        DataSeccion **ListarSecciones();
        void SeleccionarEmpresa(string rut);
        void SeleccionarSucursal(string nombre);
        void SeleccionarSeccion(string nombre);
        ~EmpresaController();
    protected:
    private:
        EmpresaController();
        Empresa *empresa; // la empresa que se recuerda
        Sucursal *sucursal; // la sucursal que se recuerda
    	static EmpresaController *instance;
};

#endif // EMPRESACONTROLLER_H