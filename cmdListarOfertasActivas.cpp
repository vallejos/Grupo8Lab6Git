#include "cmdListarOfertasActivas.h"
#include <iostream>
#include <string>
#include "ICollection.h"
#include "IOfertaLaboralController.h"
#include "IIterator.h"
#include "DataOfertaLaboral.h"
#include "Rango.h"
#include "Date.h"

using namespace std;

cmdListarOfertasActivas::cmdListarOfertasActivas()
{
    //ctor
}

void cmdListarOfertasActivas::ejecutarComando()
{
    Fabrica* fab = Fabrica::getInstance();
    IOfertaLaboralController* cOferta = fab->getIOfertaLaboralController();
    int cantInscriptos;

    try
    {
        //MOSTRAR OFERTAS LABORALES ACTIVAS
        ICollection* dataOfertasActivas = cOferta->MostrarOfertasActivas();
        cout << "Lista de Ofertas Laborales Activas:\n";
        IIterator *it = dataOfertasActivas->getIterator();
        while (it.hasCurrent())
        {
            DataOfertaLaboral *dOferta;
            if ( (dOferta = dynamic_cast<DataOfertaLaboral*> (it.current())) != NULL )
            {
            //calculo la cantidad de inscriptos
                IIterator *it2 = dOferta->getInscripciones()->getIterator();
                cantInscriptos = 0;
                while (it2.hasCurrent())
                {
                    cantInscriptos ++;
                    it2.next();
                }
                delete it2;
            //IMPRIMO LOS DATOS QUE INDICA ELCASO DE USO
                cout << "NOMBRE: " + dOferta->getTitulo() +
                        ", EMPRESA:" + dOferta->getSeccion()->getSucursal()->getEmpresa()->getRut() +
                        ", UBICACION:" + dOferta->getSeccion()->getSucursal()->getDireccion() +
                        ", CANTIDAD DE INSCRIPTOS: " + cantInscriptos +
                        ", RANGO SALARIAL:" + dOferta->getRangoSalarial()->getSueldoMinimo() +
                                          " - " dOferta->getRangoSalarial()->getSueldoMaximo() +
                        ", CANTIDAD DE PLAZAS:" + dOferta->cantidadPuestosNecesarios() +
                        "\n";
            } else
            {
                throw std::invalid_argument("cmdListarOfertasActivas -> El objeto no es de la clase DataOfertaLaboral.");
            }
            it.next();
        }
        delete it;
    }
    catch(const std::invalid_argument &e)
    {
        cout << e.what();
    }
}

cmdListarOfertasActivas::~cmdListarOfertasActivas()
{
    //dtor
}
