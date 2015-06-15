#include "AltaEntrevista.h"
#include <string>
#include <iostream>
#include "OfertaLaboralController.h"
#include "ICollection.h"
#include "DataOfertaLaboral.h"
#include "ManejadorOfertaLaboral.h"
#include "Date.h"
#include "ManejadorEstudiante.h"
#include "EstudianteController.h"
#include "DataEstudiante.h"

using namespace std;

AltaEntrevista::AltaEntrevista()
{
    //ctor
}

void AltaEntrevista::ejecutarComando()
{
    string numExpe, cedEstudiante;
    int diaEnt, mesEnt, anioEnt;
    ManejadorOfertaLaboral* mOferta = ManejadorOfertaLaboral::getInstance();
    ManejadorEstudiante* mEstudiante = ManejadorEstudiante::getInstance();
    OfertaLaboralController* cOferta = OfertaLaboralController::getInstance();
    EstudianteController* cEstudiante = EstudianteController::getInstance();
    Date* fechaEntrevista;

    try
    {
        //LISTAR OFERTAS LABORALES
        ICollection* dataOfertas = cOferta->ListarOfertas();
        cout << "Lista de Ofertas:\n";
        IIterator * it = dataOfertas->getIterator();
        while(it.hasCurrent())
        {
            DataOfertaLaboral* dol;
            if( (dol = dynamic_cast<DataOfertaLaboral*> (it.current())) != NULL )
            {
                cout << "Numero de Expediente: " + dol->getNumExpediente() + ", Titulo:" + dol->getTitulo() + ", Descripcion:" + dol->getDescripcion() + "\n";
            } else
            {
                throw std::invalid_argument("AltaEntrevista -> El objeto no es de la clase DataOfertaLaboral.");
            }
        }
        delete it;
        //SELECCIONAR OFERTA LABORAL
        cout<< "Seleccione una Oferta Laboral indicando el numero de expediente\n";
        cin >> numExpe;
        IDictionary* ofertas = mOferta->getOfertasLaborales();
        String* nExpe = new String(numExpe);
        if(ofertas->member(nExpe))
        {
            cOferta->SeleccionarOferta(numExpe);
        }
        else
        {
            throw std::invalid_argument("La Oferta Laboral con numero de expediente " + numExpe + " no existe en el sistema.");
        }
        //LISTAR ESTUDIANTES INSCRIPTOS EN ESA OFERTA LABORAL
        ICollection* dataEstudiantes= cEstudiante->ListarEstudiantesInscriptosEnOferta();
        cout << "Lista de Estudiantes inscriptos es la Oferta Laboral:\n";
        IIterator* it2 = dataEstudiantes->getIterator();
        while(it2.hasCurrent())
        {
            DataEstudiante* dEstudiante;
            if ((dEstudiante = dynamic_cast<DataEstudiante*> (it2.current())) != NULL)
            {
                cout << "Cedula: " + dEstudiante->getCedula + ", Apellido: " + dEstudiante->getApellido() + "\n";
            } else
            {
                throw std::invalid_argument("AltaEntrevista -> El objeto no es de la clase DataEstudiante.");
            }
        }
        delete it2;
        //SELECCIONA ESTUDIANTE
        cout<< "Seleccione un Estudiante indicando la cedula\n";
        cin >> cedEstudiante;
        IDictionary* estudiantes = mEstudiante->getEstudiantes();
        String* cEst = new String(cedEstudiante);
        if(estudiantes->member(cEst))
        {
            cEstudiante->SeleccionarEstudiante(cedEstudiante);
        }
        else
        {
            throw std::invalid_argument("El estudiante con cedula " + cedEstudiante + " no existe en el sistema.");
        }
        //INDICA FECHA ENTREVISTA
//me parece que esta parte no esta muy prolija o bien que digamos
        cout<< "Indique el dia de la entrevista: \n";
        cin >> diaEnt;
        cout<< "Ahora indique el mes: \n";
        cin >> mesEnt;
        cout<< "Y por ultimo el año: \n";
        cin >> anioEnt;
        fechaEntrevista = Date(diaEnt, mesEnt, anioEnt);
        //DA DE ALTA ENTREVISTA
        cOferta->Entrevistar(fechaEntrevista);
    }
    catch(const std::invalid_argument &e)
    {
    	throw std::invalid_argument(e.what());
    }
}

AltaEntrevista::~AltaEntrevista()
{
    //dtor
}
