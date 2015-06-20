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


using namespace std;

cmdListarNotificacionesEstudiante::cmdListarNotificacionesEstudiante()
{
    //ctor
}

//LA IDEA :)
void cmdListarNotificacionesEstudiante::ejecutarComando()
{
    Fabrica* fab = Fabrica::getInstance();
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
        ICollection* notificaciones =
//DUDAS:
//como obtengo las notificaciones desde la Interfaz???  getNotificaciones();
//notificacion no tiene que ser una clase? si es así que tiene como atrituros?
//se necesita un DataNotificacion?
        IIterator *it = notificaciones->getIterator();
        while(it2->hasCurrent())
        {
//            Notificaciones* notif;
//            if ((notif = dynamic_cast<Notificacion*> (it->getCurrent())) != NULL)
            {
                cout << //Imprimo los datos de la notificacion
            } else
            {
                throw "cmdListarNotificacionesEstudiante -> El objeto no es de la clase ???????????????????????.";
            }
            it2->next();
        }
        delete it2;
    }
    catch(exception &e)
    {
    	throw;
    }
}

cmdListarNotificacionesEstudiante::~cmdListarNotificacionesEstudiante()
{
    //dtor
}
