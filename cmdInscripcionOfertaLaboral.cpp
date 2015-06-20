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

        cout << "Lista de Ofertas Laborales Vigentes:\n";

        IIterator * it = ofertasLaborales->getIterator();
        while(it->hasCurrent())
        {
            DataOfertaLaboral *dOfertaLab;// Esto cambia si no traemos dataOfertas
            if( (dOfertaLab = dynamic_cast<DataOfertaLaboral*> (it->getCurrent())) != NULL )
            {
                cout << "Número de Expediente: " << dOfertaLab->getNumExpediente() << ", Título:" << dOfertaLab->getTitulo() << "\n";
                it->next();

            } else
            {
                throw "InscripcionOfertaLaboral -> El objeto no es de la clase DataOfertaLaboral.";
            }

        }
        delete it;

        cout<< "Seleccione una Oferta Laboral indicando el Número de Expediente\n";
        cin >> numExpediente;

        cOfertaLab->SeleccionarOferta(numExpediente,ofertasLaborales);

        IEstudianteController *cEstudiante = fab->getIEstudianteController();
        //Debe ser diccionario
//        IDictionary* dataEstudiante = cEstudiante->ListarEstudiantesNoInscriptos(numExpediente);
        IDictionary* dataEstudiante = cEstudiante->ListarEstudiantesNoInscriptos();

        cout << "Lista de Estudiantes no Inscriptos a la Oferta Seleccionada:\n";

        IIterator * it2 = dataEstudiante->getIterator();
        while(it2->hasCurrent())
        {
            DataEstudiante *dEstudiante;
            if( (dEstudiante = dynamic_cast<DataEstudiante*> (it2->getCurrent())) != NULL )
            {
                cout << "Cédula: " << dEstudiante->getCedula() << "Nombre: " << dEstudiante->getNombre() << "Apellido: " << dEstudiante->getApellido() << "\n";
                it2->next();

            } else
            {
                throw "InscripcionOfertaLaboral -> El objeto no es de la clase DataEstudiante.";
            }
        }
        delete it2;

        cout<< "Seleccione el Estudiante a inscribir indicando la Cédula\n";
        cin >> cedula;

        cEstudiante->SeleccionarEstudiante(cedula,dataEstudiante);

        cout<< "Ingrese la Fecha de Inscripción (dd mm aaaa)\n";
        cin >> dia >> mes >> anio;

        Date *fechaInsc = new Date(dia,mes,anio);
        cOfertaLab->Inscribir(fechaInsc);

    }
    catch(exception &e)
    {
        throw;
    }

}

cmdInscripcionOfertaLaboral::~cmdInscripcionOfertaLaboral()
{
    //dtor
}
