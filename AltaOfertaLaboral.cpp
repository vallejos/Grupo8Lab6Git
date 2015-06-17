#include <iostream>
#include <string>
#include "AltaOfertaLaboral.h"
#include "ManejadorEmpresa.h"
#include "EmpresaController.h"
#include "ICollection.h"
#include "DataEmpresa.h"
#include "DataSucursal.h"
#include "DataSeccion.h"
#include "Fabrica.h"
#include "IEmpresaController.h"

using namespace std;
AltaOfertaLaboral::AltaOfertaLaboral()
{
    //ctor
}

void AltaOfertaLaboral::ejecutarComando()
{
    string rutaEmpresa, nomSucursal, nomSeccion;
    Fabrica* fab = Fabrica::getInstance();
    IEmpresaController* cEmpresa = fab->getIEmpresaController();

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
            }
            else
            {
                throw std::invalid_argument("AltaOfertaLaboral -> El objeto no es de la clase DataEmpresa.");
            }
        }
        delete it;

        cout<< "Seleccione una Empresa indicando el RUT\n";
        cin >> rutEmpresa;
        cEmpresa->SeleccionarEmpresa(rutaEmpresa);


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
        cEmpresa->SeleccionarSucursal(nomSucursal);

        ICollection* dataSecciones = cEmpresa->ListarSecciones();
        cout<< "Lista de Secciones:\n";
        IIterator * it3 = dataSecciones->getIterator();
        while(it3.hasCurrent())
        {
            DataSeccion *dSeccion;
            if( (dSeccion = dynamic_cast<DataSeccion*> (it3.current())) != NULL )
            {
                cout << "Nombre: " + dSeccion->getNombre() + "\n";
            } else
            {
                throw std::invalid_argument("AltaOfertaLaboral -> El objeto no es de la clase DataSeccion.");
            }
        }
        delete it3;

        cout<< "Seleccione una Sección indicando su nombre\n";
        cin >> nomSeccion;
        cEmpresa->SeleccionarSeccion(nomSeccion);

        cout<< "Ingrese los datos correspondientes a la nueva Oferta Laboral\n";
        cout<< "\n";
        cout<< "Numero de expediente: "
        cin >> numExpe;
        cout<< "\nTitulo: ";
        cin >> titulo;
        cout<< "\nDescripcion: ";
        cin >> descripcion;
        cout<< "\nCantidad de horas semanales: ";
        cin >> cantHorasSema;
        cout<< "\nSalario minimo: ";
        cin >> salMinimo;
        cout<< "\nSalario maximo: ";
        cin >> salMaximo;
        Rango* rangoSalarial = new Rango(salMinimo, salMaximo);
        cout<< "\nFecha de comienzo(dd mm aaaa): ";
        cin >> ddCom >> mmCom >> aaaaCom;
        cout<< "\nFecha de fin(dd mm aaaa): ";
        cin >> ddFin >> mmFin >> aaaaFin;
        Date* fechaComienzo = new Date(ddCom, mmCom, aaaaCom);
        Date* fechaFin = new Date(ddFin, mmFin, aaaaFin);
        cout<< "\nCantidad de puestos necesarios: ";
        cin >> cantPuestos;
        //Solicitar Asignaturas


        cEmpresa->altaOfertaLaboral(numExpe, titulo, descripcion, cantHorasSema, rangoSalarial, fechaComienzo, fechaFin, cantPuestos, "AGREGAR ASIGNATURAS")

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
