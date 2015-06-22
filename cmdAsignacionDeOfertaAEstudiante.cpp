#include <iostream>
#include <string>
#include "cmdAsignacionDeOfertaAEstudiante.h"
#include "IOfertaLaboralController.h"
#include "IEstudianteController.h"
#include "interfaces/ICollection.h"
#include "DataOfertaLaboral.h"
#include "DataEstudiante.h"
#include "Fabrica.h"

using namespace std;

// cmdAsignacionDeOfertaAEstudiante
void cmdAsignacionDeOfertaAEstudiante::ejecutarComando()
{
    string numExpediente, cedula;
    Date *fechaEfectivizacion;
    int dd, mm, aa, sueldo;
    Fabrica* fab = Fabrica::getInstance();
    IOfertaLaboralController *ctrlOL = fab->getIOfertaLaboralController();
    IEstudianteController *ctrlE = fab->getIEstudianteController();

    try
    {
        // muestro las ofertas activas
        IDictionary* dataOfertasActivas = ctrlOL->MostrarOfertasActivas();

        cout << "Lista de Ofertas Laborales Activas:\n";

        IIterator *it = dataOfertasActivas->getIterator();
        while (it->hasCurrent())
        {
            DataOfertaLaboral *dOferta;
            if ( (dOferta = dynamic_cast<DataOfertaLaboral*> (it->getCurrent())) != NULL )
            {
                cout << "NRO. EXPEDIENTE: " << dOferta->getNumExpediente() << ", TITULO:" << dOferta->getTitulo() << "\n";
            } else
            {
                throw "cmdAsignacionDeOfertaAEstudiante -> El objeto no es de la clase DataOfertaLaboral.";
            }
            it->next();
        }
        delete it;

        // selecciono el llamado
        cout<< "Seleccione una Oferta Laboral indicando el Nro. Expediente: \n";
        cin >> numExpediente;

        ctrlOL->SeleccionarOferta(numExpediente,dataOfertasActivas);

        // listar estudiantes inscriptos en oferta
        IDictionary *estudiantes = ctrlE->ListarEstudiantesInscriptosEnOferta(); // la oferta recordada en el ctrlOL

        cout << "\nLista de Estudiantes que se pueden inscribir a la Oferta Laboral seleccionada:\n";

        if (estudiantes->isEmpty()) {
            cout << "- No hay estudiantes que cumplan los requisitos de la Oferta seleccionada.\n\n";
        } else {
            IIterator *itE = estudiantes->getIterator();
            while (itE->hasCurrent())
            {
                DataEstudiante *dEstudiante;
                if ( (dEstudiante = dynamic_cast<DataEstudiante*> (itE->getCurrent())) != NULL )
                {
                    cout << "CEDULA: " << dEstudiante->getCedula() << ", NOMBRE:" << dEstudiante->getNombre() <<
                        ", APELLIDO:" << dEstudiante->getApellido() << ", EMAIL:" << dEstudiante->getEmail() << "\n";
                } else
                {
                    throw "cmdAsignacionDeOfertaAEstudiante -> El objeto no es de la clase dataEstudiante.";
                }
                itE->next();
            }
            delete itE;

            // seleccionar estudiante (cedula)
            cout<< "\nSeleccione un Estudiante indicando la Cedula: \n";
            cin >> cedula;

            ctrlE->SeleccionarEstudiante(cedula,estudiantes);

            // solicitar datos que faltan
            cout<< "\nFecha de Efectivizacion (dd mm aaaa): ";
            cin >> dd >> mm >> aa;

            fechaEfectivizacion = new Date(dd, mm, aa);

            cout<< "\nIngrese el Sueldo: \n";
            cin >> sueldo;

            // alta asignacion del cargo
            ctrlOL->AltaAsignacionDelCargo(fechaEfectivizacion, sueldo);

            cout << "\El Estudiante se ha efectivizado correctamente.\n\n";
        }
    }
    catch (const char* e)
    {
        throw;
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
