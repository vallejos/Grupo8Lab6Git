#include <iostream>
#include <string>
#include "InscripcionOfertaLaboral.h"
#include "ICollection.h"

InscripcionOfertaLaboral::InscripcionOfertaLaboral()
{
    //ctor
}

void InscripcionOfertaLaboral::ejecutarComando()
{
        //string rutaEmpresa, nomSucursal;
    //ManejadorEmpresa* mEmpresa = ManejadorEmpresa::getInstance();
    OfertaLaboralController* cOfertaLab = OfertaLaboralController::getInstance();

    try
    {
        ICollection* ofertasLaborales = cOfertaLab->ListarOfertas();

        cout << "Lista de Ofertas Laborales:\n";

        IIterator * it = ofertasLaborales->getIterator();
        while(it.hasCurrent())
        {
            DataOfertaLaboral *dOfertaLab;
            if( (dOfertaLab = dynamic_cast<DataOfertaLaboral*> (it.current())) != NULL )
            {
                cout << "Número de Expediente: " + dOfertaLab->getNumExpediente() + ", Título:" + dOfertaLab->getTitulo() + "\n";
            } else
            {
                throw std::invalid_argument("InscripcionOfertaLaboral -> El objeto no es de la clase DataOfertaLaboral.");
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

InscripcionOfertaLaboral::~InscripcionOfertaLaboral()
{
    //dtor
}
