#include <iostream>
#include <string>
#include "cmdDarDeBajaLlamado.h"
#include "OfertaLaboralController.h"
#include "interfaces/ICollection.h"
#include "DataOfertaLaboral.h"
#include "interfaces/IDictionary.h"
#include "Fabrica.h"

using namespace std;

// DarDeBajaLlamado
void cmdDarDeBajaLlamado::ejecutarComando()
{
    string numExpediente;
    Fabrica* fab = Fabrica::getInstance();
    IOfertaLaboralController *ctrlOL = fab->getIOfertaLaboralController();

    try
    {
        // muestro las ofertas
        IDictionary* dataOfertas = ctrlOL->ListarOfertas();

        cout << "Lista de Ofertas Laborales:\n";

        IIterator *it = dataOfertas->getIterator();
        while (it->hasCurrent())
        {
            DataOfertaLaboral *dOferta;
            if ( (dOferta = dynamic_cast<DataOfertaLaboral*> (it->getCurrent())) != NULL )
            {
                cout << "NRO. EXPEDIENTE: " << dOferta->getNumExpediente() << ", TITULO:" << dOferta->getTitulo() << "\n";
            } else
            {
                throw "cmdDarDeBajaLlamado -> El objeto no es de la clase DataOfertaLaboral.";
            }
        }
        delete it;

        // selecciono el llamado
        cout<< "Seleccione una Oferta Laboral indicando el Nro. Expediente: \n";
        cin >> numExpediente;

        ctrlOL->SeleccionarOferta(numExpediente, dataOfertas);

        // borro el llamado
        ctrlOL->DarBajaLlamado();
    }
    catch (const char* e)
    {
    	throw;
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
