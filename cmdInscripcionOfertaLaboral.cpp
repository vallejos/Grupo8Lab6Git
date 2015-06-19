#include "cmdInscripcionOfertaLaboral.h"
#include <iostream>
#include <string>
#incluce "Date.h"
#incluce "Fabrica.h"
#include "IOfertaLaboralController.h"
#include "IEstudianteController.h"
#include "DataOfertaLaboral.h"
#include "DataEstudiante.h"
#include "interfaces/ICollection.h"

cmdInscripcionOfertaLaboral::cmdInscripcionOfertaLaboral()
{
    //ctor
}

void cmdInscripcionOfertaLaboral::ejecutarComando()
{
    string numExpediente, cedula;
    Fabrica* fab = Fabrica::getInstance();
    IOfertaLaboralController *cOfertaLab = fab->getIOfertaLaboralController();

    try
    {
        //Debe ser diccionario
        ICollection* ofertasLaborales = cOfertaLab->MostrarOfertasActivas();

        cout << "Lista de Ofertas Laborales Vigentes:\n";

        IIterator * it = ofertasLaborales->getIterator();
        while(it.hasCurrent())
        {
            DataOfertaLaboral *dOfertaLab;// Esto cambia si no traemos dataOfertas
            if( (dOfertaLab = dynamic_cast<DataOfertaLaboral*> (it.current())) != NULL )
            {
                cout << "Número de Expediente: " + dOfertaLab->getNumExpediente() + ", Título:" + dOfertaLab->getTitulo() + "\n";
                it.next();

            } else
            {
                throw std::invalid_argument("InscripcionOfertaLaboral -> El objeto no es de la clase DataOfertaLaboral.");
            }

        }
        delete it;

        cout<< "Seleccione una Oferta Laboral indicando el Número de Expediente\n";
        cin >> numExpediente;

        cOfertaLab->SeleccionarOferta(numExpediente,ofertasLaborales);

        IEstudianteController *cEstudiante = fab->getIEstudianteController();
        //Debe ser diccionario
        ICollection* dataEstudiante = cEstudiante->ListarEstudiantesNoInscriptos(numExpediente);

        cout << "Lista de Estudiantes no Inscriptos a la Oferta Seleccionada:\n";

        IIterator * it2 = dataEstudiante->getIterator();
        while(it2.hasCurrent())
        {
            DataEstudiante *dEstudiante;
            if( (dEstudiante = dynamic_cast<DataEstudiante*> (it2.current())) != NULL )
            {
                cout << "Cédula: " + dEstudiante->getCedula() + "Nombre: " + dEstudiante->getNombre() + "Apellido: " + dEstudiante->getApellido() + "\n";
                it2.next();

            } else
            {
                throw std::invalid_argument("InscripcionOfertaLaboral -> El objeto no es de la clase DataEstudiante.");
            }
        }
        delete it2;

        cout<< "Seleccione el Estudiante a inscribir indicando la Cédula\n";
        cin >> cedula;

        cEstudiante->SeleccionarEstudiante(cedula,dataEstudiante);

        cout<< "Ingrese la Fecha de Inscripción\n";
        cout<< "Ingrese el Día\n";
        cin >> dia;
        cout<< "Ingrese el Mes\n";
        cin >> mes;
        cout<< "Ingrese el Año\n";
        cin >> anio;
        Date *fechaInsc = Date(dia,mes,anio);
        cOfertaLab->Inscribir(fechaInsc);

    }
    catch(const std::invalid_argument &e)
    {
    	throw std::invalid_argument(e.what());
    }

}

cmdInscripcionOfertaLaboral::~cmdInscripcionOfertaLaboral()
{
    //dtor
}
