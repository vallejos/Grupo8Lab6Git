#include <iostream>
#include <string>
#include "cmdModificarLlamado.h"
#include "IOfertaLaboralController.h"
#include "interfaces/ICollection.h"
#include "DataOfertaLaboral.h"
#include "DataEstudiante.h"
#include "interfaces/IDictionary.h"
#include "Fabrica.h"
#include "String.h"

using namespace std;

// cmdModificarLlamado
void cmdModificarLlamado::ejecutarComando()
{
    string  numExpediente, nomSeccion, nomSucursal, titulo, descripcion;
//    Date *fechaEfectivizacion;
    int ddi, mmi, aaaai, ddf, mmf, aaaaf, cantHorasSemanales, salarioMinimo, salarioMaximo, cantidadPuestos;
//    int sueldo;

    Fabrica* fab = Fabrica::getInstance();
    IOfertaLaboralController *ctrlOL = fab->getIOfertaLaboralController();

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

        OrderedDictionary *nuevasAsignaturasEnOferta = new OrderedDictionary();

        cout<< "\nAsignaturas:";
        bool continuar = true;
        int codAsig;
        char respuesta;

        IEstudianteController* cEstudiante = fab->getIEstudianteController();
        IDictionary *asignaturasIngresadas = cEstudiante->getAsignaturas();

        while (continuar)
        {
            // muestro asignaturas
            cout << "Lista de Asignaturas:\n";
            IIterator * it = asignaturasIngresadas->getIterator();
            while(it->hasCurrent())
            {
                DataAsignatura *dAsignatura;
                if( (dAsignatura = dynamic_cast<DataAsignatura*> (it->getCurrent())) != NULL )
                {
                    cout << "CODIGO: " << dAsignatura->getCodigo() << ", NOMBRE:" << dAsignatura->getNombre() << "\n";
                }
                else
                {
                    throw "AltaOfertaLaboral -> El objeto no es de la clase DataAsignatura.";
                }
                it->next();
            }
            delete it;

            // pido asignatura
            cout<< "\n  Ingrese el codigo: ";
            cin >> codAsig;
            Integer* codigo = new Integer(codAsig);

            // busco la asignatura
            if (asignaturasIngresadas->member(codigo))
            {
                // la agrego
                nuevasAsignaturasEnOferta->add(codigo, asignaturasIngresadas->find(codigo));
            } else {
                throw "Codigo de Asignatura incorrecto.";
            }

            // seguir ingresando
            cout<< "\n  Desea ingresar otra asignatura?(s/n): ";
            cin >> respuesta;
            if(respuesta == 'n')
            {
                continuar = false;
            }
        }


        // en caso de no sustituir
        String *expe = new String(numExpediente.c_str());
        DataOfertaLaboral *dataAsignatura = dynamic_cast<DataOfertaLaboral*> (dataOfertasActivas->find(expe));
//        IDictionary *asignaturas = dataAsignatura->getAsignaturas();
        ICollection *inscripciones = dataAsignatura->getInscripciones();
        ICollection *entrevistas = dataAsignatura->getEntrevistas();
        Seccion *seccion = dataAsignatura->getSeccion();

        // creo el nuevo Data Oferta Laboral
//        DataOfertaLaboral *nuevosDatos = new DataOfertaLaboral(numExpediente, titulo, descripcion, cantHorasSemanales, 
//            rangoSalarial, fechaIni, fechaFin, cantidadPuestos, asignaturas, seccion, inscripciones, entrevistas);
//        DataOfertaLaboral *nuevosDatos = new DataOfertaLaboral(numExpediente, titulo, descripcion, cantHorasSemanales, 
//            rangoSalarial, fechaIni, fechaFin, cantidadPuestos);

//        DataOfertaLaboral(string numExpediente, string titulo, string descripcion, int cantidadHorasSemanales,
//                        Rango *rangoSalarial, Date *fechaComienzo, Date *fechaFin, int cantidadPuestosNecesarios);

//IDictionary *asignaturas, Seccion* seccion, ICollection *inscripciones, ICollection *entrevistas);
        // alta asignacion del cargo

//        ctrlOL->ModificarOferta(numExpediente, nuevosDatos);

        ctrlOL->ModificarOferta(numExpediente, titulo, descripcion, cantHorasSemanales, rangoSalarial, fechaIni,
            fechaFin, cantidadPuestos, nuevasAsignaturasEnOferta, seccion, inscripciones, entrevistas);

    }
    catch(exception &e)
    {
        throw;
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
