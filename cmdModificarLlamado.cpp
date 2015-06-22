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
    string  numExpediente, nomSeccion, nomSucursal, titulo, descripcion, modif, title, des;
    Rango *rangoSalarial;
    Date *fechaIni, *fechaFin;
    int ddi, mmi, aaaai, ddf, mmf, aaaaf, cantHorasSemanales, salarioMinimo, salarioMaximo, cantidadPuestos;
    IDictionary *nuevasAsignaturasEnOferta;
    
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
            it->next();
        }
        delete it;

        // selecciono el llamado
        cout<< "Seleccione una Oferta Laboral indicando el Nro. Expediente: \n";
        cin >> numExpediente;

        ctrlOL->SeleccionarOferta(numExpediente, dataOfertasActivas);

        String *expe = new String(numExpediente.c_str());
        DataOfertaLaboral *dol = dynamic_cast<DataOfertaLaboral*> (dataOfertasActivas->find(expe));

        // solicitar datos de la nueva oferta laboral
        cout << "Desea modificar el Titulo? (s,n)\n";
        cin >> modif;
        if (modif == "s")
        {
            cin >> titulo;
            getline(cin, title);
            titulo += title;
        }
        else
        {
            titulo = dol->getTitulo(); 
        }
        modif = '\0';
        cout << "Desea modificar la Descripcion? (s,n)\n";
        cin >> modif;
        if (modif == "s")
        {
            cin >> descripcion;
            getline(cin, des);
            descripcion += des;

        }
        else
        {
            descripcion = dol->getDescripcion();
        }
        modif = '\0';
        cout << "Desea modificar la cantidad de horas semanales? (s,n)\n";
        cin >> modif;
        if (modif == "s")
        {
            cin >> cantHorasSemanales;
        }
        else
        {
            cantHorasSemanales = dol->getCantidadHorasSemanales();
        }
        modif = '\0';
        cout << "Desea modificar el Rango Salarial? (s,n)\n";
        cin >> modif;
        if (modif == "s")
        {
            cout << "Indique el Rango (rangoMinimo rangoMaximo)";
            cin >> salarioMinimo >> salarioMaximo;
            rangoSalarial = new Rango(salarioMinimo, salarioMaximo);
        }
        else
        {
            rangoSalarial = dol->getRangoSalarial();
        }
        modif = '\0';
        cout << "Desea modificar la Fecha Comienzo? (s,n)\n";
        cin >> modif;
        if (modif == "s")
        {
            cin >> ddi >> mmi >> aaaai;
            fechaIni = new Date(ddi, mmi, aaaai);
        }
        else
        {
            fechaIni = dol->getFechaComienzo();
        }
        modif = '\0';
        cout << "Desea modificar la Fecha Fin? (s,n)\n";
        cin >> modif;
        if (modif == "s")
        {
            cin >> ddf >> mmf >> aaaaf;
            fechaFin = new Date(ddf, mmf, aaaaf);
        }
        else
        {
            fechaFin = dol->getFechaFin();
        }
        modif = '\0';
        cout << "Desea modificar la cantidad de puestos necesarios? (s,n)\n";
        cin >> modif;
        if (modif == "s")
        {
            cin >> cantidadPuestos;
        }
        else
        {
            cantidadPuestos = dol->getCantidadPuestosNecesarios();
        }
        modif = '\0';
        // Solicitar Asignaturas
        cout << "Desea modificar las Asignaturas? (s,n)\n";
        cin >> modif;
        if (modif == "s")
        {
            nuevasAsignaturasEnOferta = new OrderedDictionary();
            int codAsig;
            IEstudianteController* cEstudiante = fab->getIEstudianteController();
            IDictionary *asignaturasIngresadas = cEstudiante->getAsignaturas();
            // muestro asignaturas
            cout << "Lista de Asignaturas ingresadas en el Sistema:\n";
            IIterator * it = asignaturasIngresadas->getIterator();
            while(it->hasCurrent())
            {
                Asignatura *dAsignatura;
                if( (dAsignatura = dynamic_cast<Asignatura*> (it->getCurrent())) != NULL )
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
            
            while (modif == "s")
            {
                // pido asignatura
                cout<< "\n  Ingrese el codigo de la Asignatura: ";
                cin >> codAsig;
                Integer* codigo = new Integer(codAsig);
                // busco la asignatura
                if (asignaturasIngresadas->member(codigo))
                {
                    nuevasAsignaturasEnOferta->add(codigo, asignaturasIngresadas->find(codigo));
                } else 
                {
                    throw "Codigo de Asignatura incorrecto.";
                }
                // seguir ingresando
                cout<< "\n  Desea ingresar otra asignatura?(s/n): ";
                cin >> modif;
            }
        }
        else
        {
            nuevasAsignaturasEnOferta = dol->getAsignaturas();
        }

        ICollection *inscripciones = dol->getInscripciones();
        ICollection *entrevistas = dol->getEntrevistas();
        Seccion *seccion = dol->getSeccion();

        ctrlOL->ModificarOferta(numExpediente, titulo, descripcion, cantHorasSemanales, rangoSalarial, fechaIni,
                fechaFin, cantidadPuestos, nuevasAsignaturasEnOferta, seccion, inscripciones, entrevistas);   
    }
    catch (const char* e)
    {
    	throw;
    }
}

cmdModificarLlamado::cmdModificarLlamado()
{
// constructor
}

cmdModificarLlamado::~cmdModificarLlamado()
{
// destructor
}
