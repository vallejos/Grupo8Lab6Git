#include <iostream>
#include <string>
#include "cmdDarDeBajaLlamado.h"
#include "OfertaLaboralController.h"
#include "ICollection.h"
#include "DataOfertaLaboral.h"

using namespace std;

// DarDeBajaLlamado
void cmdDarDeBajaLlamado::ejecutarComando()
{
    string numExpediente;
    OfertaLaboralController *ctrlOL = OfertaLaboralController::getInstance();

    try
    {
        // muestro las ofertas
        ICollection* dataOfertas = ctrlOL->ListarOfertas();

        cout << "Lista de Ofertas Laborales:\n";

        IIterator *it = dataOfertas->getIterator();
        while (it.hasCurrent())
        {
            DataOfertaLaboral *dOferta;
            if ( (dOferta = dynamic_cast<DataOfertaLaboral*> (it.current())) != NULL )
            {
                cout << "NRO. EXPEDIENTE: " + dOferta->getNumExpediente() + ", TITULO:" + dOferta->getTitulo() + "\n";
            } else
            {
                throw std::invalid_argument("cmdDarDeBajaLlamado -> El objeto no es de la clase DataOfertaLaboral.");
            }
        }
        delete it;

        // selecciono el llamado
        cout<< "Seleccione una Oferta Laboral indicando el Nro. Expediente: \n";
        cin >> numExpediente;

        ctrlOL->SeleccionarOferta(numExpediente);

        // borro el llamado
        ctrlOL->DarBajaLlamado();
    }
    catch(const std::invalid_argument &e)
    {
    	cout << e.what();
    }
}

// constructor
cmdDarDeBajaLlamado::cmdDarDeBajaLlamado()
{

}

// destructor
cmdDarDeBajaLlamado::~cmdDarDeBajaLlamado()
{

}
