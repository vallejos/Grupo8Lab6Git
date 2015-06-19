#include <iostream>
#include <string>
#include "cmdAsignacionDeOfertaAEstudiante.h"
#include "OfertaLaboralController.h"
#include "interfaces/ICollection.h"
#include "DataOfertaLaboral.h"
#include "DataEstudiante.h"

using namespace std;

// cmdAsignacionDeOfertaAEstudiante
void cmdAsignacionDeOfertaAEstudiante::ejecutarComando()
{
    string numExpediente, cedula;
    Date *fechaEfectivizacion;
    int dd, mm, aa, sueldo;
    OfertaLaboralController *ctrlOL = OfertaLaboralController::getInstance();
    EstudianteController *ctrlE = EstudianteController::getInstance();

    try
    {
        // muestro las ofertas activas
        ICollection* dataOfertasActivas = ctrlOL->MostrarOfertasActivas();

        cout << "Lista de Ofertas Laborales Activas:\n";

        IIterator *it = dataOfertas->getIterator();
        while (it->hasCurrent())
        {
            DataOfertaLaboral *dOferta;
            if ( (dOferta = dynamic_cast<DataOfertaLaboral*> (it.current())) != NULL )
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

        ctrlOL->SeleccionarOferta(numExpediente);

        // listar estudiantes inscriptos en oferta
        ICollection *estudiantes = ctrlE->ListarEstudiantesInscriptosEnOferta(); // la oferta recordada en el ctrlOL

        cout << "Lista de Estudiantes inscriptos en la Oferta Laboral seleccionada:\n";

        IIterator *itE = dataEstudiante->getIterator();
        while (itE->hasCurrent())
        {
            dataEstudiante *dEstudiante;
            if ( (dEstudiante = dynamic_cast<dataEstudiante*> (itE.current())) != NULL )
            {
                cout << "CEDULA: " + dEstudiante->getCedula() + ", NOMBRE:" + dEstudiante->getNombre() + 
                    ", APELLIDO:" + dEstudiante->getApellido() + ", EMAIL:" + dEstudiante->getEmail() + "\n";
            } else
            {
                throw std::invalid_argument("cmdAsignacionDeOfertaAEstudiante -> El objeto no es de la clase dataEstudiante.");
            }
        }
        delete itE;

        // seleccionar estudiante (cedula)
        cout<< "Seleccione un Estudiante indicando la Cedula: \n";
        cin >> cedula;

        ctrlE->SeleccionarEstudiante(cedula);

        // solicitar datos que faltan
        cout<< "\nFecha de Efectivizacion (dd mm aaaa): ";
        cin >> dd >> mm >> aa;

        fechaEfectivizacion = new Date(dd, mm, aa);

        cout<< "Ingrese el Sueldo: \n";
        cin >> sueldo;

        // alta asignacion del cargo
        ctrlOL->AltaAsignacionDelCargo(fechaEfectivizacion, sueldo);
    }
    catch(const std::invalid_argument &e)
    {
        cout << e.what();
    }
}

// constructor
cmdAsignacionDeOfertaAEstudiante::cmdAsignacionDeOfertaAEstudiante()
{

}

// destructor
cmdAsignacionDeOfertaAEstudiante::~cmdAsignacionDeOfertaAEstudiante()
{

}
