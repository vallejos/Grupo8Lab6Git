#include <string>
#include <iostream>
#include "cmdAltaEntrevista.h"
#include "IOfertaLaboralController.h"
#include "interfaces/ICollection.h"
#include "DataOfertaLaboral.h"
#include "Fabrica.h"
#include "Date.h"
#include "interfaces/IIterator.h"
#include "IEstudianteController.h"
#include "DataEstudiante.h"

using namespace std;

cmdAltaEntrevista::cmdAltaEntrevista()
{
    //ctor
}

void cmdAltaEntrevista::ejecutarComando()
{
    string numExpe, cedEstudiante;
    int diaEnt, mesEnt, anioEnt;
    Fabrica* fab = Fabrica::getInstance();
    IOfertaLaboralController* cOferta = fab->getIOfertaLaboralController();
    IEstudianteController* cEstudiante = fab->getIEstudianteController();

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
                throw std::invalid_argument("cmdAltaEntrevista -> El objeto no es de la clase DataOfertaLaboral.");
            }
        }
        delete it;

        //SELECCIONAR OFERTA LABORAL
        cout<< "Seleccione una Oferta Laboral indicando el numero de expediente\n";
        cin >> numExpe;
        cOferta->SeleccionarOferta(numExpe);

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
                throw std::invalid_argument("cmdAltaEntrevista -> El objeto no es de la clase DataEstudiante.");
            }
        }
        delete it2;

        //SELECCIONA ESTUDIANTE
        cout<< "Seleccione un Estudiante indicando la cedula\n";
        cin >> cedEstudiante;
        cEstudiante->SeleccionarEstudiante(cedEstudiante);

        //INDICA FECHA ENTREVISTA
        cout<< "Indique la fecha de la entrevista (dd mm aaaa): \n";
        cin >> diaEnt >> mesEnt >> anioEnt;
        Date* fechaEntrevista = new Date(diaEnt, mesEnt, anioEnt);

        //DA DE ALTA ENTREVISTA
        cOferta->Entrevistar(Date(diaEnt, mesEnt, anioEnt);
    }
    catch(exception &e)
    {
    	throw;
    }
}

cmdAltaEntrevista::~cmdAltaEntrevista()
{
    //dtor
}
