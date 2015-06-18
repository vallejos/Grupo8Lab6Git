#include <iostream>
#include <string>
#include "ConsultarDatosEstudiantes.h"
#include "Fabrica.h"
#include "IEstudianteController.h"
#include "ICollection.h"
#include "DataEstudiante.h"
#include "DataDatosEstudiante.h"
#include "DataAprobada.h"
#include "DataEmpresa.h"
#include "DataSucursal.h"
#include "DataSeccion.h"
#include "DataOfertaLaboral.h"

using namespace std;
ConsultarDatosEstudiantes::ConsultarDatosEstudiantes()
{
    //ctor
}

void ConsultarDatosEstudiantes::ejecutarComando()
{
    string ci;
    int ddC, mmC, aaaaC, ddF, mmF, aaaaF;
    Fabrica* fab = Fabrica::getInstance();
    IEstudianteController* cEstudiante = fab->getIEstudianteController();

    try
    {
        ICollection* dataEstudiantes = cEstudiante->ListarEstudiantesRegistrados();
        cout<< "Estudiantes registrados:\n";

        IIterator * it = dataEstudiantes->getIterator();
        while(it.hasCurrent())
        {
            DataEstudiante *dEstudiante;
            if( (dEstudiante = dynamic_cast<DataEstudiante*> (it.current())) != NULL )
            {
                cout << "Nombre: " + dEstudiante->getNombre() + ", C.I.:" + dEstudiante->getCedula() + "\n";
            }
            else
            {
                throw std::invalid_argument("ConsultarDatosEstudiantes -> El objeto no es de la clase DataEstudiante.");
            }
            it.next();
        }
        delete it;

        cout<< "Ingrese la C.I. del Estudiante a consultar: ";
        cin >> ci;
        DataDatosEstudiante* datosEstudiantes = cEstudiante->ConsultarDatosEstudiante(ci);

        cout<< "\n\nAsignaturas aprobadas:\n";
        ICollection* dataAprobadas = datosEstudiantes->getDataAprobadas();
        IIterator * it = dataAprobadas->getIterator();
        while(it.hasCurrent())
        {
            DataAprobada *dAprobada;
            if( (dAprobada = dynamic_cast<DataAprobada*> (it.current())) != NULL )
            {
                DataAsignatura* dAsignatura = dAprobada->getDataAsignatura();
                cout << "Nombre: " + dAsignatura->getNombre() + ", Creditos: " + dAsignatura->getCreditos() + ", Nota: " + dAprobada->getNota() + ", Fecha de aprobacion: " + dAprobada->getFecha()->getDia() + "/" + dAprobada->getFecha()->getMes() + "/" + dAprobada->getFecha()->getAnio() + "\n";
            }
            else
            {
                throw std::invalid_argument("ConsultarDatosEstudiantes -> El objeto no es de la clase DataAprobada.");
            }
            it.next();
        }
        delete it;

        cout<< "\n\nLlamados a los que se inscribio el Estudiante:\n";
        ICollection* dataOfertasEmpresas = datosEstudiantes->getDataOfertasEmpresas();
        IIterator * it = dataOfertasEmpresas->getIterator();
        while(it.hasCurrent())
        {
            DataOfertaEmpresa *dOferEmp;
            if( (dOferEmp = dynamic_cast<DataOfertaEmpresa*> (it.current())) != NULL )
            {
                DataOfertaLaboral* dataOfertaLab = dOferEmp->getDataOfertaLaboral();
                DataEmpresa* dataEmpre = dOferEmp->getDataEmpresa();
                cout<< "Titulo: " + dataOfertaLab->getTitulo() + "(N° Exp. " + dataOfertaLab->getNumExpediente() +  ")\n";
                cout<< "    Descripcion: " + dataOfertaLab->getDescripcion() + "\n";
                cout<< "    Cantidad de horas semanales: " + dataOfertaLab->getCantidadHorasSemanales() + "\n";
                cout<< "    Sueldo min: " + dataOfertaLab->getRangoSalarial()->getSueldoMinimo() + ", Sueldo max: " + dataOfertaLab->getRangoSalarial()->getSueldoMaximo() + "\n";
                ddC = dataOfertaLab->getFechaComienzo()->getDia();
                mmC = dataOfertaLab->getFechaComienzo()->getMes();
                aaaaC = dataOfertaLab->getFechaComienzo()->getAnio();
                ddF = dataOfertaLab->getFechaFin()->getDia();
                mmF = dataOfertaLab->getFechaFin()->getMes();
                aaaaF = dataOfertaLab->getFechaFin()->getAnio();
                cout<< "    Fecha de comienzo: " + ddC + "/" + mmC + "/" + aaaaC + ", Fecha de fin: " + ddF + "/" + mmF + "/" + aaaaF + "\n"
                cout<< "    Cantidad de puestos necesarios: " + dataOfertaLab->getCantidadPuestosNecesarios() + "\n";
                cout<< "    Empresa: " + dataEmpre->getNombre() + "(RUT " + dataEmpre->getRut() + ")\n";
                cout<< "    Sucursal: " + dataOfertaLab->getSeccion()->getSucursal()->getNombre() + ", Tel: " + dataOfertaLab->getSeccion()->getSucursal()->getTelefono() + "\n";
                cout<< "    Seccion: " + dataOfertaLab->getSeccion()->getNombre() + ", Interno: " + dataOfertaLab->getSeccion()->getInterno() + ", Encargado: " + dataOfertaLab->getSeccion()->getEncargado()->getNombre() + " " + dataOfertaLab->getSeccion()->getEncargado()->getApellido() + "\n\n";
            }
            else
            {
                throw std::invalid_argument("ConsultarDatosEstudiantes -> El objeto no es de la clase DataOfertaEmpresa.");
            }
            it.next();
        }
        delete it;
    }
    catch(const std::invalid_argument &e)
    {
    	throw std::invalid_argument(e.what());
    }
}

ConsultarDatosEstudiantes::~ConsultarDatosEstudiantes()
{
    //dtor
}
