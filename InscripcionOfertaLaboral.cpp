#include <iostream>
#include <string>
#incluce "Date.h"
#include "InscripcionOfertaLaboral.h"
#include "OfertaLaboralController.h"
#include "EstudianteController.h"
#include "DataOfertaLaboral.h"
#include "DataEstudiante.h"
#include "ICollection.h"

InscripcionOfertaLaboral::InscripcionOfertaLaboral()
{
    //ctor
}

void InscripcionOfertaLaboral::ejecutarComando()
{
    string numExpediente,cedula;
    OfertaLaboralController* cOfertaLab = OfertaLaboralController::getInstance();

    try
    {
        ICollection* ofertasLaborales = cOfertaLab->MostrarOfertasActivas()();

        cout << "Lista de Ofertas Laborales Vigentes:\n";

        IIterator * it = ofertasLaborales->getIterator();
        while(it.hasCurrent())
        {
            DataOfertaLaboral *dOfertaLab;
            if( (dOfertaLab = dynamic_cast<DataOfertaLaboral*> (it.current())) != NULL )
            {
                //Tengo que cambiar las operaciones para traer los datos correctos
                cout << "Nombre: " + dOfertaLab->getNumExpediente() + ", Empresa:" + dOfertaLab->getTitulo() + ", Ubicación:" + dOfertaLab->getTitulo() + ", Cantidad de Inscriptos:" + dOfertaLab->getTitulo() + ", Rango Salarial:" + dOfertaLab->getTitulo() + ", Cantidad de Plazas:" + dOfertaLab->getTitulo() + "\n";
            } else
            {
                throw std::invalid_argument("InscripcionOfertaLaboral -> El objeto no es de la clase DataOfertaLaboral.");
            }
        }
        delete it;

        cout<< "Seleccione una Oferta Laboral indicando el Nombre\n";
        cin >> numExpediente;//O Nombre?

        cOfertaLab->SeleccionarOferta(numExpediente);

        EstudianteController *cEstudiante = EstudianteController::getInstance();
        ICollection* dataEstudiante = cEstudiante->ListarEstudiantesNoInscriptos(numExpediente);
        cout << "Lista de Estudiantes no Inscriptos a la Oferta Seleccionada:\n";

        IIterator * it2 = dataEstudiante->getIterator();
        while(it2.hasCurrent())
        {
            DataEstudiante *dEstudiante;
            if( (dEstudiante = dynamic_cast<DataEstudiante*> (it2.current())) != NULL )
            {
                cout << "Cedula: " + dEstudiante->getCedula() + "\n";
            } else
            {
                throw std::invalid_argument("InscripcionOfertaLaboral -> El objeto no es de la clase DataEstudiante.");
            }
        }
        delete it2;

        cout<< "Seleccione el Estudiante a inscribir indicando la Cedula\n";
        cin >> cedula;

        cEstudiante->SeleccionarEstudiante(string cedula);

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

InscripcionOfertaLaboral::~InscripcionOfertaLaboral()
{
    //dtor
}
