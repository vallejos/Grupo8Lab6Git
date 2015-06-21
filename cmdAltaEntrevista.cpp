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
        cout << "Lista de Ofertas:\n";
        IIterator *it = dataOfertasActivas->getIterator();
        while(it->hasCurrent())
        {
            DataOfertaLaboral* dol;
            if( (dol = dynamic_cast<DataOfertaLaboral*> (it->getCurrent())) != NULL )
            {
                cout << "Numero de Expediente: " << dol->getNumExpediente() << ", Titulo:" << dol->getTitulo() << ", Descripcion:" << dol->getDescripcion() << "\n";
            } else
            {
                //throw std::bad_cast("cmdAltaEntrevista -> El objeto no es de la clase DataOfertaLaboral.")
                throw "cmdAltaEntrevista -> El objeto no es de la clase DataOfertaLaboral.";
            }
            it->next();
        }
        delete it;

        //SELECCIONAR OFERTA LABORAL
        cout<< "Seleccione una Oferta Laboral indicando el numero de expediente\n";
        cin >> numExpe;
        cOferta->SeleccionarOferta(numExpe, dataOfertasActivas);

        //LISTAR ESTUDIANTES INSCRIPTOS EN ESA OFERTA LABORAL
        IDictionary *dataEstudiantes = cEstudiante->ListarEstudiantesInscriptosEnOferta();
        cout << "Lista de Estudiantes inscriptos es la Oferta Laboral:\n";
        IIterator *it2 = dataEstudiantes->getIterator();
        while(it2->hasCurrent())
        {
            DataEstudiante* dEstudiante;
            if ((dEstudiante = dynamic_cast<DataEstudiante*> (it2->getCurrent())) != NULL)
            {
                cout << "Cedula: " << dEstudiante->getCedula() << ", Apellido: " << dEstudiante->getApellido() << "\n";
            } else
            {
                throw "cmdAltaEntrevista -> El objeto no es de la clase DataEstudiante.";
            }
            it2->next();
        }
        delete it2;

        //SELECCIONA ESTUDIANTE
        cout<< "Seleccione un Estudiante indicando la cedula\n";
        cin >> cedEstudiante;
        cEstudiante->SeleccionarEstudiante(cedEstudiante, dataEstudiantes);

        //INDICA FECHA ENTREVISTA
        cout<< "Indique la fecha de la entrevista (dd mm aaaa): \n";
        cin >> diaEnt >> mesEnt >> anioEnt;
        Date *fechaEntrevista = new Date(diaEnt, mesEnt, anioEnt);

        //DA DE ALTA ENTREVISTA
        cOferta->Entrevistar(fechaEntrevista);
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
