#include <string>
#include <iostream>
#include "cmdListarNotificacionesEstudiante.h"
#include "interfaces/ICollection.h"
#include "interfaces/IDictionary.h"
#include "Fabrica.h"
#include "IEstudianteController.h"
#include "Date.h"
#include "interfaces/IIterator.h"
#include "DataEstudiante.h"
#include "Estudiante.h"
#include "String.h"

using namespace std;

cmdListarNotificacionesEstudiante::cmdListarNotificacionesEstudiante()
{
    //ctor
}

void cmdListarNotificacionesEstudiante::ejecutarComando()
{
    Fabrica* fab = Fabrica::getInstance();
    string cedEstudiante;
    IEstudianteController* cEstudiante = fab->getIEstudianteController();

    try
    {
        //LISTAR ESTUDIANTES
        IDictionary *dataEstudiantes = cEstudiante->ListarEstudiantesRegistrados();
        cout << "Lista de Estudiantes registrados en el Sistema:\n";
        IIterator *it = dataEstudiantes->getIterator();
        while(it->hasCurrent())
        {
            DataEstudiante* dEstudiante;
            if ((dEstudiante = dynamic_cast<DataEstudiante*> (it->getCurrent())) != NULL)
            {
                cout << "Cedula: " + dEstudiante->getCedula() + ", Apellido: " + dEstudiante->getApellido() + "\n";
            } else
            {
                throw "cmdListarNotificacionesEstudiante -> El objeto no es de la clase DataEstudiante.";
            }
            it->next();
        }
        delete it;

        //SELECCIONA ESTUDIANTE
        cout<< "Seleccione un Estudiante indicando la cedula\n";
        cin >> cedEstudiante;
        cEstudiante->SeleccionarEstudiante(cedEstudiante, dataEstudiantes);

        //LISTAR NOTIFICACIONES DEL ESTUDIANTE SELECCIONADO
        Estudiante* estRecordado =cEstudiante->getEstudiante();
        ICollection* notificaciones= estRecordado->getNotificaciones();
        if (notificaciones->isEmpty()) {
            cout << "\n- El Estudiante seleccionado no tiene notificaciones.\n\n";
        } else {
            IIterator *it2 = notificaciones->getIterator();
            while(it2->hasCurrent())
            {
                String* notif;
                if ((notif = dynamic_cast<String*> (it2->getCurrent())) != NULL)
                {
                    cout << "NOTIFICACION: Se dio de alta la Oferta Laboral con Nro. de Exp. " << (notif->getValue()) << "\n";
                } else
                {
                    throw "cmdListarNotificacionesEstudiante -> El objeto no es de la clase String.";
                }
                it2->next();
            }
            delete it2;
        }
    }
    catch (const char* e)
    {
    	throw;
    }
}

cmdListarNotificacionesEstudiante::~cmdListarNotificacionesEstudiante()
{
    //dtor
}
