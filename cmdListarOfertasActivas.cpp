#include "cmdListarOfertasActivas.h"
#include <iostream>
#include <string>
#include "interfaces/ICollection.h"
#include "IOfertaLaboralController.h"
#include "interfaces/IIterator.h"
#include "DataOfertaLaboral.h"
#include "Rango.h"
#include "Date.h"
#include "interfaces/IDictionary.h"
#include "Fabrica.h"

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
        IDictionary* dataOfertasActivas = cOferta->MostrarOfertasActivas();
        cout << "\nLista de Ofertas Laborales Activas:\n";
        cout << "--------------------------------------------------------\n";
        
        if (dataOfertasActivas->isEmpty()) {
            cout << "\nNo hay Ofertas Activas\n";
        } else {
            int cantOfertas = dataOfertasActivas->getSize();
            cout << "\nSe encontraron ";
            cout << cantOfertas;
            cout << " Ofertas Activas:\n";
            IIterator *it = dataOfertasActivas->getIterator();
            while (it->hasCurrent())
            {
                cantInscriptos = 0;
                DataOfertaLaboral *dOferta;
                if ( (dOferta = dynamic_cast<DataOfertaLaboral*> (it->getCurrent())) != NULL )
                {
                    //calculo la cantidad de inscriptos
                    ICollection *insc = dOferta->getInscripciones();
                    if (insc != NULL) {
                        IIterator *it2 = insc->getIterator();
                        while (it2->hasCurrent())
                        {
                            cantInscriptos ++;
                            it2->next();
                        }
                        delete it2;
                    }

                    //IMPRIMO LOS DATOS QUE INDICA ELCASO DE USO
                    string doTitulo = dOferta->getTitulo();
                    string doNumExp = dOferta->getNumExpediente();
                    Seccion *doSeccion = dOferta->getSeccion();
                    Sucursal *doSucursal = doSeccion->getSucursal(); // EXPLOTA
                    Empresa *doEmpresa = doSucursal->getEmpresa();
                    string doRut = doEmpresa->getRut();
                    string doDireccion = doSucursal->getDireccion();
                    Rango *doRango = dOferta->getRangoSalarial();
                    int doSueldoMin = doRango->getSueldoMinimo();
                    int doSueldoMax = doRango->getSueldoMaximo();
                    int doCantPuestos = dOferta->getCantidadPuestosNecesarios();

                    cout << "---------------" 
                            << "\n" << "NUM EXPEDIENTE: " << doNumExp << "\n"
                            << "NOMBRE: " << doTitulo << "\n"
                            << "EMPRESA:" << doRut << "\n" << "UBICACION:" << doDireccion << "\n" 
                            << "CANTIDAD DE INSCRIPTOS: " << cantInscriptos << "\n" << "RANGO SALARIAL:" 
                            << doSueldoMin << " - " << doSueldoMax << "\n" << "CANTIDAD DE PLAZAS:" 
                            << doCantPuestos << "\n";
    //                cout << "---------------" << "\n" << "NOMBRE: " << dOferta->getTitulo() << "\n" << ", EMPRESA:" << dOferta->getSeccion()->getSucursal()->getEmpresa()->getRut() << "\n" << ", UBICACION:" << dOferta->getSeccion()->getSucursal()->getDireccion() << "\n" << ", CANTIDAD DE INSCRIPTOS: " << cantInscriptos << "\n" << ", RANGO SALARIAL:" << dOferta->getRangoSalarial()->getSueldoMinimo() << " - " << dOferta->getRangoSalarial()->getSueldoMaximo() << "\n" << ", CANTIDAD DE PLAZAS:" << dOferta->getCantidadPuestosNecesarios() << "\n";

                } else
                {
                    throw "cmdListarOfertasActivas -> El objeto no es de la clase DataOfertaLaboral.";
                }
                it->next();
            }
            delete it;
        }
    }
    catch(exception &e)
    {
        throw;
    }
}

cmdListarOfertasActivas::~cmdListarOfertasActivas()
{
    //dtor
}
