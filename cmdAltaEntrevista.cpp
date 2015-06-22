#include "cmdAltaEntrevista.h"

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
        IDictionary* dataOfertasActivas = cOferta->MostrarOfertasActivas();
        cout << "\nLista de Ofertas:\n";
        IIterator *it = dataOfertasActivas->getIterator();
        while(it->hasCurrent())
        {
            DataOfertaLaboral* dol;
            if( (dol = dynamic_cast<DataOfertaLaboral*> (it->getCurrent())) != NULL )
            {
                cout << "Numero de Expediente: " << dol->getNumExpediente() << "\n TITULO:" << dol->getTitulo() << "\n DESCRIPCION:" << dol->getDescripcion() << "\n";
            } else
            {
                //throw std::bad_cast("cmdAltaEntrevista -> El objeto no es de la clase DataOfertaLaboral.")
                throw "cmdAltaEntrevista -> El objeto no es de la clase DataOfertaLaboral.";
            }
            it->next();
        }
        delete it;

        //SELECCIONAR OFERTA LABORAL
        cout<< "\nSeleccione una Oferta Laboral indicando el numero de expediente\n";
        cin >> numExpe;
        cOferta->SeleccionarOferta(numExpe, dataOfertasActivas);

        //LISTAR ESTUDIANTES INSCRIPTOS EN ESA OFERTA LABORAL
        IDictionary *dataEstudiantes = cEstudiante->ListarEstudiantesInscriptosEnOferta();
        cout << "\nLista de Estudiantes inscriptos es la Oferta Laboral:\n";
        if (dataEstudiantes->isEmpty()) {
            cout << "- No hay estudiantes inscriptos en la Oferta seleccionada.";
        } else {
            //LISTAR ESTUDIANTES INSCRIPTOS EN ESA OFERTA LABORAL
            IIterator *it2 = dataEstudiantes->getIterator();
            while(it2->hasCurrent())
            {
                DataEstudiante* dEstudiante;
                if ((dEstudiante = dynamic_cast<DataEstudiante*> (it2->getCurrent())) != NULL)
                {
                    cout << "CEDULA: " << dEstudiante->getCedula() 
                            << ", NOMBRE: " << dEstudiante->getNombre() 
                            << ", APELLIDO: " << dEstudiante->getApellido() << "\n";
                } else
                {
                    throw "cmdAltaEntrevista -> El objeto no es de la clase DataEstudiante.";
                }
                it2->next();
            }
            delete it2;

            //SELECCIONA ESTUDIANTE
            cout<< "\nSeleccione un Estudiante indicando la cedula\n";
            cin >> cedEstudiante;
            cEstudiante->SeleccionarEstudiante(cedEstudiante, dataEstudiantes);

            //INDICA FECHA ENTREVISTA
            cout<< "\nIndique la fecha de la entrevista (dd mm aaaa): \n";
            cin >> diaEnt >> mesEnt >> anioEnt;
            Date *fechaEntrevista = new Date(diaEnt, mesEnt, anioEnt);

            //DA DE ALTA ENTREVISTA
            cOferta->Entrevistar(fechaEntrevista);
            
            cout << "\nSe agendo la Entrevista al Estudiante correctamente.\n\n";
        }
/*        
        //LISTAR ESTUDIANTES NO INSCRIPTOS EN ESA OFERTA LABORAL
        IDictionary *dataEstudiantesNo = cEstudiante->ListarEstudiantesNoInscriptos();
        cout << "\nLista de Estudiantes que se pueden inscribir a la Oferta Laboral seleccionada:\n";

        if (dataEstudiantesNo->isEmpty()) {
            cout << "- No hay estudiantes que cumplan los requisitos de la Oferta seleccionada.";
        } else {
            IIterator *it3 = dataEstudiantesNo->getIterator();
            while(it3->hasCurrent())
            {
                DataEstudiante* dEstudiante;
                if ((dEstudiante = dynamic_cast<DataEstudiante*> (it3->getCurrent())) != NULL)
                {
                    cout << "CEDULA: " << dEstudiante->getCedula() 
                            << ", NOMBRE: " << dEstudiante->getNombre() 
                            << ", APELLIDO: " << dEstudiante->getApellido() << "\n";
                } else
                {
                    throw "cmdAltaEntrevista -> El objeto no es de la clase DataEstudiante.";
                }
                it3->next();
            }
            delete it3;
        }
*/
    }
    catch (const char* e)
    {
    	throw;
    }
}

cmdAltaEntrevista::~cmdAltaEntrevista()
{
    //dtor
}
