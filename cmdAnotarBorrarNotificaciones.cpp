#include <string>
#include <iostream>
#include "cmdAnotarBorrarNotificaciones.h"
#include "interfaces/ICollection.h"
#include "interfaces/IDictionary.h"
#include "Fabrica.h"
#include "IEstudianteController.h"
#include "interfaces/IIterator.h"
#include "Estudiante.h"
#include "DataEstudiante.h"

using namespace std;

cmdAnotarBorrarNotificaciones::cmdAnotarBorrarNotificaciones()
{
    //ctor
}

void cmdAnotarBorrarNotificaciones::ejecutarComando()
{
    string cedEstudiante;

    Fabrica* fab = Fabrica::getInstance();
    IEstudianteController* cEstudiante = fab->getIEstudianteController();
    IEmpresaController* cEmpresa = fab->getIEmpresaController();

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
        cout<< "Seleccione un Estudiante indicando la cedula: \n";
        cin >> cedEstudiante;
        cEstudiante->SeleccionarEstudiante(cedEstudiante, dataEstudiantes);

        //ANOTAR O BORRAR ESTUDIANTE DE NOTIFICACIONES
        Estudiante* estRecordado =cEstudiante->getEstudiante();
        char opcion;
        cout<< "Indique si desea anotar (A) o borrar (B) a el estudiante seleccionado de las notificaciones: \n";
        cin >> opcion;
        IDictionary* empresas = cEmpresa->getEmpresas();
        IIterator *it2 = empresas->getIterator();
        while (it2->hasCurrent())
        {
            Empresa* emp;
            if ((emp = dynamic_cast<Empresa*> (it2->getCurrent())) != NULL)
            {
                IDictionary* sucursales = emp->getSucursales();
                IIterator *it3 = sucursales->getIterator();
                while(it3->hasCurrent())
                {
                    Sucursal* suc;
                    if ((suc = dynamic_cast<Sucursal*> (it3->getCurrent())) != NULL)
                    {
                        IDictionary* secciones = suc->getSecciones();
                        IIterator *it4 = secciones->getIterator();
                        while (it4->hasCurrent())
                        {
                            Seccion* secc;
                            if ((secc = dynamic_cast<Seccion*> (it4->getCurrent())) != NULL)
                            {
                                IObserver *iobs = dynamic_cast<IObserver*> (estRecordado);
                                switch (opcion)
                                {
                                    case 'A':
                                        secc->addObserver(iobs);
                                        break;
                                    case 'B':
                                        secc->removeObserver(iobs);
                                    break;
                                }
                            } else
                            {
                                throw "cmdAnotarBorrarNotificaciones -> El objeto no es de la clase Seccion.";
                            }
                            it4->next();
                        }
                        delete it4;
                    } else
                    {
                        throw "cmdAnotarBorrarNotificaciones -> El objeto no es de la clase Sucursal.";
                    }
                    it3->next();
                }
                delete it3;
            } else
            {
                throw "cmdAnotarBorrarNotificaciones -> El objeto no es de la clase Empresa.";
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

cmdAnotarBorrarNotificaciones::~cmdAnotarBorrarNotificaciones()
{
    //dtor
}

