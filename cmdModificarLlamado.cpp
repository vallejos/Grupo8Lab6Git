#include <iostream>
#include <string>
#include "cmdModificarLlamado.h"
#include "OfertaLaboralController.h"
#include "interfaces/ICollection.h"
#include "DataOfertaLaboral.h"
#include "dataEstudiante.h"
#include "IDictionary.h"

using namespace std;

// cmdModificarLlamado
void cmdModificarLlamado::ejecutarComando()
{
    string  numExpediente, nomSeccion, nomSucursal, titulo, descripcion;
    Date *fechaEfectivizacion;
    int ddi, mmi, aaaai, ddf, mmf, aaaf, sueldo, cantHorasSemanales, salarioMinimo, salarioMaximo, cantidadPuestos;
    OfertaLaboralController *ctrlOL = OfertaLaboralController::getInstance();

    try
    {
        // muestro las ofertas activas
        IDictionary* dataOfertasActivas = ctrlOL->MostrarOfertasActivas();

        cout << "Lista de Ofertas Laborales Activas:\n";

        IIterator *it = dataOfertas->getIterator();
        while (it->hasCurrent())
        {
            DataOfertaLaboral *dOferta;
            if ( (dOferta = dynamic_cast<DataOfertaLaboral*> (it->getCurrent())) != NULL )
            {
                cout << "NRO. EXPEDIENTE: " + dOferta->getNumExpediente() + ", TITULO:" + dOferta->getTitulo() + "\n";
            } else
            {
                throw std::invalid_argument("cmdAsignacionDeOfertaAEstudiante -> El objeto no es de la clase DataOfertaLaboral.");
            }
        }
        delete it;

        // selecciono el llamado
        cout<< "Seleccione una Oferta Laboral indicando el Nro. Expediente: \n";
        cin >> numExpediente;

        ctrlOL->SeleccionarOferta(numExpediente, dataOfertasActivas);

        // solicitar datos de la nueva oferta laboral
        cout<< "Ingrese los nuevos datos correspondientes a la nueva Oferta Laboral:\n";

        cout<< "\nTitulo: ";
        cin >> titulo;
        cout<< "\nDescripcion: ";
        cin >> descripcion;
        cout<< "\nCantidad de horas semanales: ";
        cin >> cantHorasSemanales;
        cout<< "\nSalario minimo: ";
        cin >> salarioMinimo;
        cout<< "\nSalario maximo: ";
        cin >> salarioMaximo;

        Rango *rangoSalarial = new Rango(salarioMinimo, salarioMaximo);

        cout<< "\nFecha de comienzo (dd mm aaaa): ";
        cin >> ddi >> mmi >> aaaai;

        Date *fechaIni = new Date(ddi, mmi, aaaai);

        cout<< "\nFecha de fin (dd mm aaaa): ";
        cin >> ddf >> mmf >> aaaaf;

        Date *fechaFin = new Date(ddf, mmf, aaaaf);

        cout<< "\nCantidad de puestos necesarios: ";
        cin >> cantidadPuestos;

        //Solicitar Asignaturas

        // creo el nuevo Data Oferta Laboral
        DataOfertaLaboral *nuevosDatos = new OfertaLaboral(numExpediente, titulo, descripcion, cantHorasSemanales, rangoSalarial, fechaIni, fechaFin, cantidadPuestos, "AGREGAR ASIGNATURAS");

        // alta asignacion del cargo
        ctrlOL->ModificarOferta(numExpediente, DataOfertaLaboral *nuevosDatos);
    }
    catch(const std::invalid_argument &e)
    {
        cout << e.what();
    }
}

// constructor
cmdModificarLlamado::cmdModificarLlamado()
{

}

// destructor
cmdModificarLlamado::~cmdModificarLlamado()
{

}
