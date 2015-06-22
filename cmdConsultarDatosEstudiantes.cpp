#include <iostream>
#include <string>
#include "cmdConsultarDatosEstudiantes.h"
#include "Fabrica.h"
#include "IEstudianteController.h"
#include "interfaces/ICollection.h"
#include "DataEstudiante.h"
#include "DataDatosEstudiante.h"
#include "DataAprobada.h"
#include "DataEmpresa.h"
#include "DataSucursal.h"
#include "DataSeccion.h"
#include "DataOfertaLaboral.h"
#include "Inscripcion.h"
#include "DataOfertaEmpresa.h"

using namespace std;
cmdConsultarDatosEstudiantes::cmdConsultarDatosEstudiantes()
{
    //ctor
}

void cmdConsultarDatosEstudiantes::ejecutarComando()
{
    string ci;
    int ddC, mmC, aaaaC, ddF, mmF, aaaaF;
    Fabrica* fab = Fabrica::getInstance();
    IEstudianteController* cEstudiante = fab->getIEstudianteController();

    try
    {
        IDictionary* dataEstudiantes = cEstudiante->ListarEstudiantesRegistrados();
        cout<< "Estudiantes registrados:\n";

        IIterator * it = dataEstudiantes->getIterator();
        while(it->hasCurrent())
        {
            DataEstudiante *dEstudiante;
            if( (dEstudiante = dynamic_cast<DataEstudiante*> (it->getCurrent())) != NULL )
            {
                cout << "CEDULA: " << dEstudiante->getCedula() 
                        << ", NOMBRE: " << dEstudiante->getNombre() 
                        << ", APELLIDO: " << dEstudiante->getApellido() << "\n";
            }
            else
            {
                throw "ConsultarDatosEstudiantes -> El objeto no es de la clase DataEstudiante.";
            }
            it->next();
        }
        delete it;

        cout<< "Ingrese la C.I. del Estudiante a consultar: ";
        cin >> ci;
        DataDatosEstudiante* datosEstudiantes = cEstudiante->ConsultarDatosEstudiante(ci);

        ICollection* dataAprobadas = datosEstudiantes->getDataAprobadas();
        IIterator * it2 = dataAprobadas->getIterator();
        if (it2->hasCurrent())
        {
            cout<< "\nAsignaturas aprobadas:\n";
            while(it2->hasCurrent())
            {
                DataAprobada *dAprobada;
                if( (dAprobada = dynamic_cast<DataAprobada*> (it2->getCurrent())) != NULL )
                {
                    DataAsignatura* dAsignatura = dAprobada->getDataAsignatura();
                    cout << "Nombre: " << dAsignatura->getNombre() << ", Creditos: " << dAsignatura->getCreditos() << ", Nota: " << dAprobada->getNota() << ", Fecha de aprobacion: " << dAprobada->getFecha()->getDia() << "/" << dAprobada->getFecha()->getMes() << "/" << dAprobada->getFecha()->getAnio() << "\n";
                }
                else
                {
                    throw "ConsultarDatosEstudiantes -> El objeto no es de la clase DataAprobada.";
                }
                it2->next();
            }
            delete it2;
        }
        else
        {
            cout << "- El estudiante seleccionado no cuenta con asignaturas aprobadas.\n";
        }

        ICollection* dataOfertasEmpresas = datosEstudiantes->getDataOfertasEmpresas();
        IIterator * it3 = dataOfertasEmpresas->getIterator();
        if (it3->hasCurrent())
        {
            cout<< "\nLlamados a los que se inscribio el Estudiante:\n";
            while(it3->hasCurrent())
            {
                DataOfertaLaboral *dataOfertaLab;
                if( (dataOfertaLab = dynamic_cast<DataOfertaLaboral*> (it3->getCurrent())) != NULL )
                {
                    Seccion *doSeccion = dataOfertaLab->getSeccion();
                    Sucursal *doSucursal = doSeccion->getSucursal();

                    DataEmpresa* dataEmpre = doSucursal->getEmpresa()->getDataEmpresa();
                    cout<< "Titulo: " << dataOfertaLab->getTitulo() << "(NUM EXP: " << dataOfertaLab->getNumExpediente() <<  ")\n";
                    cout<< "    Descripcion: " << dataOfertaLab->getDescripcion() << "\n";
                    cout<< "    Cantidad de horas semanales: " << dataOfertaLab->getCantidadHorasSemanales() << "\n";
                    cout<< "    Sueldo min: " << dataOfertaLab->getRangoSalarial()->getSueldoMinimo() << ", Sueldo max: " << dataOfertaLab->getRangoSalarial()->getSueldoMaximo() << "\n";
                    ddC = dataOfertaLab->getFechaComienzo()->getDia();
                    mmC = dataOfertaLab->getFechaComienzo()->getMes();
                    aaaaC = dataOfertaLab->getFechaComienzo()->getAnio();
                    ddF = dataOfertaLab->getFechaFin()->getDia();
                    mmF = dataOfertaLab->getFechaFin()->getMes();
                    aaaaF = dataOfertaLab->getFechaFin()->getAnio();
                    cout<< "    Fecha de comienzo: " << ddC << "/" << mmC << "/" << aaaaC << ", Fecha de fin: " << ddF << "/" << mmF << "/" << aaaaF << "\n";
                    cout<< "    Cantidad de puestos necesarios: " << dataOfertaLab->getCantidadPuestosNecesarios() << "\n";
                    cout<< "    Empresa: " << dataEmpre->getNombre() << "(RUT " << dataEmpre->getRut() << ")\n";
                    cout<< "    Sucursal: " << dataOfertaLab->getSeccion()->getSucursal()->getNombre() << ", Tel: " << dataOfertaLab->getSeccion()->getSucursal()->getTelefono() << "\n";
                    cout<< "    Seccion: " << dataOfertaLab->getSeccion()->getNombre() << ", Interno: " << dataOfertaLab->getSeccion()->getInterno() << ", Encargado: " << dataOfertaLab->getSeccion()->getEncargado()->getNombre() << " " << dataOfertaLab->getSeccion()->getEncargado()->getApellido() << "\n\n";
                }
                else
                {
                    throw "\nConsultarDatosEstudiantes -> El objeto no es de la clase DataOfertaEmpresa.\n";
                }
                it3->next();
            }
            delete it3;
        }
        else
        {
            cout << "- El estudiante seleccionado no se ha inscripto a ningun llamado.\n";
        }
    }
     catch (const char* e)
    {
    	throw;
    }
}

cmdConsultarDatosEstudiantes::~cmdConsultarDatosEstudiantes()
{
    //dtor
}
