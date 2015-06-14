#include <iostream>
#include <string>
#include "AltaOfertaLaboral.h"
#include "ManejadorEmpresa.h"
#include "EmpresaController.h"
#include "ICollection.h"
#include "DataEmpresa.h"
#include "DataSucursal.h"
#include "DataSeccion.h"

using namespace std;
AltaOfertaLaboral::AltaOfertaLaboral()
{
    //ctor
}

void AltaOfertaLaboral::ejecutarComando()
{
    string rutaEmpresa, nomSucursal;
    ManejadorEmpresa* mEmpresa = ManejadorEmpresa::getInstance();
    EmpresaController* cEmpresa = EmpresaController::getInstance();

    try
    {
        ICollection* dataEmpresas = cEmpresa->ListarEmpresas();

        cout << "Lista de Empresas:\n";

        IIterator * it = dataEmpresas->getIterator();
        while(it.hasCurrent())
        {
            DataEmpresa *dEmpresa;
            if( (dEmpresa = dynamic_cast<DataEmpresa*> (it.current())) != NULL )
            {
                cout << "Nombre: " + dEmpresa->getNombre() + ", RUT:" + dEmpresa->getRut() + "\n";
            } else
            {
                throw std::invalid_argument("AltaOfertaLaboral -> El objeto no es de la clase DataEmpresa.");
            }
        }
        delete it;

        cout<< "Seleccione una Empresa indicando el RUT\n";
        cin >> rutEmpresa;

        IDictionary* empresas = mEmpresa->getEmpresas();
        String* rut = new String(rutaEmpresa);

        //Este tipo de control de errores se hacea este nivel ?????
        if(empresas->member(rut))
        {
            cEmpresa->SeleccionarEmpresa(rutaEmpresa);
        }
        else
        {
            throw std::invalid_argument("La Empresa con RUT " + rutaEmpresa + " no existe en el sistema.");
        }

        ICollection* dataSucursales = cEmpresa->ListarSucursales();
        cout << "Lista de Sucursales:\n";

        IIterator * it2 = dataEmpresas->getIterator();
        while(it2.hasCurrent())
        {
            DataSucursal *dSucursal;
            if( (dSucursal = dynamic_cast<DataSucursal*> (it2.current())) != NULL )
            {
                cout << "Nombre: " + dSucursal->getNombre() + "\n";
            } else
            {
                throw std::invalid_argument("AltaOfertaLaboral -> El objeto no es de la clase DataSucursal.");
            }
        }
        delete it2;

        cout<< "Seleccione una Sucursal indicando el nombre\n";
        cin >> nomSucursal;
        Empresa* empresa = cEmpresa->getEmpresa();
    }
    catch(const std::invalid_argument &e)
    {
    	throw std::invalid_argument(e.what());
    }


}

AltaOfertaLaboral::~AltaOfertaLaboral()
{
    //dtor
}
