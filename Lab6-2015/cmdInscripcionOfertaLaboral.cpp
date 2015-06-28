#include "cmdInscripcionOfertaLaboral.h"
#include <iostream>
#include <string>
#include "Date.h"
#include "Fabrica.h"
#include "IOfertaLaboralController.h"
#include "IEstudianteController.h"
#include "DataOfertaLaboral.h"
#include "DataEstudiante.h"
#include "interfaces/ICollection.h"
#include "interfaces/IDictionary.h"

cmdInscripcionOfertaLaboral::cmdInscripcionOfertaLaboral()
{
    //ctor
}

void cmdInscripcionOfertaLaboral::ejecutarComando()
{
    string numExpediente, cedula;
    int dia, mes, anio;
    Fabrica* fab = Fabrica::getInstance();
    IOfertaLaboralController *cOfertaLab = fab->getIOfertaLaboralController();

    try
    {
        //Debe ser diccionario
        IDictionary* ofertasLaborales = cOfertaLab->MostrarOfertasActivas();

        cout << "\nLista de Ofertas Laborales Vigentes:\n";

        IIterator * it = ofertasLaborales->getIterator();
        while(it->hasCurrent())
        {
            DataOfertaLaboral *dOfertaLab;// Esto cambia si no traemos dataOfertas
            if( (dOfertaLab = dynamic_cast<DataOfertaLaboral*> (it->getCurrent())) != NULL )
            {
                cout << "NUM EXPEDIENTE: " << dOfertaLab->getNumExpediente() << ", TITULO:" << dOfertaLab->getTitulo() << "\n";
                it->next();

            } else
            {
                throw "InscripcionOfertaLaboral -> El objeto no es de la clase DataOfertaLaboral.";
            }

        }
        delete it;

        cout<< "Seleccione una Oferta Laboral indicando el Numero de Expediente\n";
        cin >> numExpediente;

        cOfertaLab->SeleccionarOferta(numExpediente,ofertasLaborales);

        IEstudianteController *cEstudiante = fab->getIEstudianteController();
        //Debe ser diccionario
//        IDictionary* dataEstudiante = cEstudiante->ListarEstudiantesNoInscriptos(numExpediente);
        IDictionary* dataEstudiante = cEstudiante->ListarEstudiantesNoInscriptos();

        cout << "\nLista de Estudiantes no Inscriptos a la Oferta Seleccionada:\n";

        IIterator * it2 = dataEstudiante->getIterator();
        while(it2->hasCurrent())
        {
            DataEstudiante *dEstudiante;
            if( (dEstudiante = dynamic_cast<DataEstudiante*> (it2->getCurrent())) != NULL )
            {
                cout << "CEDULA: " << dEstudiante->getCedula() 
                        << ", NOMBRE: " << dEstudiante->getNombre() 
                        << ", APELLIDO: " << dEstudiante->getApellido() << "\n";
                it2->next();

            } else
            {
                throw "InscripcionOfertaLaboral -> El objeto no es de la clase DataEstudiante.";
            }
        }
        delete it2;

        cout<< "\nSeleccione el Estudiante a inscribir indicando la Cedula\n";
        cin >> cedula;

        cEstudiante->SeleccionarEstudiante(cedula,dataEstudiante);

        cout<< "\nIngrese la Fecha de Inscripcion (dd mm aaaa)\n";
        cin >> dia >> mes >> anio;

        Date *fechaInsc = new Date(dia,mes,anio);
        cOfertaLab->Inscribir(fechaInsc);

        cout << "\nSe inscribio al Estudiante correctamente.\n\n";
    }
    catch (const char* e)
    {
    	throw;
    }
}

cmdInscripcionOfertaLaboral::~cmdInscripcionOfertaLaboral()
{
    //dtor
}
