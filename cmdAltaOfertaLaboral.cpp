#include <iostream>
#include <string>
#include "cmdAltaOfertaLaboral.h"
#include "ManejadorEmpresa.h"
#include "EmpresaController.h"
#include "interfaces/ICollection.h"
#include "DataEmpresa.h"
#include "DataSucursal.h"
#include "DataSeccion.h"
#include "Fabrica.h"
#include "IEmpresaController.h"
#include "Integer.h"
#include "ManejadorEstudiante.h"
#include "String.h"
#include "collections/OrderedDictionary.h"
#include "EstrategiaAsignaturas.h"
#include "Criterio1.h"
#include "Criterio2.h"

using namespace std;

cmdAltaOfertaLaboral::cmdAltaOfertaLaboral()
{
    //ctor
}

void cmdAltaOfertaLaboral::ejecutarComando()
{
    string rutEmpresa, nomSucursal, nomSeccion, descripcion, numExpe, titulo, respuesta;
    int cantHorasSema, cantPuestos, salMinimo, salMaximo, ddCom, ddFin, mmCom, mmFin, aaaaCom, aaaaFin, codAsig;
    Fabrica* fab = Fabrica::getInstance();
    IEmpresaController* cEmpresa = fab->getIEmpresaController();

    try
    {
        ICollection* dataEmpresas = cEmpresa->ListarEmpresas();

        cout << "Lista de Empresas:\n";
        IIterator * it = dataEmpresas->getIterator();
        while(it->hasCurrent())
        {
            DataEmpresa *dEmpresa;
            if( (dEmpresa = dynamic_cast<DataEmpresa*> (it->getCurrent())) != NULL )
            {
                cout << "Nombre: " << dEmpresa->getNombre() << ", RUT:" << dEmpresa->getRut() << "\n";
            }
            else
            {
                throw "AltaOfertaLaboral -> El objeto no es de la clase DataEmpresa.";
            }
            it->next();
        }
        delete it;
        cout<< "Seleccione una Empresa indicando el RUT\n";
        cin >> rutEmpresa;
        cEmpresa->SeleccionarEmpresa(rutEmpresa);


        ICollection* dataSucursales = cEmpresa->ListarSucursales();
        cout << "Lista de Sucursales:\n";

        IIterator * it2 = dataSucursales->getIterator();
        while(it2->hasCurrent())
        {
            DataSucursal *dSucursal;
            if( (dSucursal = dynamic_cast<DataSucursal*> (it2->getCurrent())) != NULL )
            {
                cout << "Nombre: " << dSucursal->getNombre() << "\n";
            } else
            {
                throw "AltaOfertaLaboral -> El objeto no es de la clase DataSucursal.";
            }
            it2->next();
        }
        delete it2;

        cout<< "Seleccione una Sucursal indicando el nombre\n";
        cin >> nomSucursal;
        cEmpresa->SeleccionarSucursal(nomSucursal);

        IDictionary* dataSecciones = cEmpresa->ListarSecciones();
        cout<< "Lista de Secciones:\n";
        IIterator * it3 = dataSecciones->getIterator();
        while(it3->hasCurrent())
        {
            DataSeccion *dSeccion;
            if( (dSeccion = dynamic_cast<DataSeccion*> (it3->getCurrent())) != NULL )
            {
                cout << "Nombre: " << dSeccion->getNombre() << "\n";
            } else
            {
                throw "AltaOfertaLaboral -> El objeto no es de la clase DataSeccion.";
            }
            it3->next();
        }
        delete it3;

        cout<< "Seleccione una Secci�n indicando su nombre\n";
        cin >> nomSeccion;
        cEmpresa->SeleccionarSeccion(nomSeccion);

        cout<< "Ingrese los datos correspondientes a la nueva Oferta Laboral\n";
        cout<< "\n";
        cout<< "Numero de expediente: ";
        cin >> numExpe;
        cout<< "\nTitulo: ";
        cin >> titulo;
        cout<< "\nDescripcion: ";
        cin >> descripcion;
        cout<< "\nCantidad de horas semanales: ";
        cin >> cantHorasSema;
        cout<< "\nSalario minimo: ";
        cin >> salMinimo;
        cout<< "\nSalario maximo: ";
        cin >> salMaximo;
        Rango* rangoSalarial = new Rango(salMinimo, salMaximo);
        cout<< "\nFecha de comienzo(dd mm aaaa): ";
        cin >> ddCom >> mmCom >> aaaaCom;
        cout<< "\nFecha de fin(dd mm aaaa): ";
        cin >> ddFin >> mmFin >> aaaaFin;
        Date* fechaComienzo = new Date(ddCom, mmCom, aaaaCom);
        Date* fechaFin = new Date(ddFin, mmFin, aaaaFin);
        cout<< "\nCantidad de puestos necesarios: ";
        cin >> cantPuestos;

/*
        // doy de alta la oferta
        cEmpresa->altaOfertaLaboral(numExpe, titulo, descripcion, cantHorasSema, rangoSalarial, fechaComienzo, fechaFin, cantPuestos, NULL);

        // obtengo la lista de ofertas de la empresa/seccion
        IDictionary *ofertasDadasDeAlta = cEmpresa->getSeccion()->getOfertasLaborales();

        // busco la oferta en el dictionary
        String *expe = new String(numExpe.c_str());
        OfertaLaboral *ol = dynamic_cast<OfertaLaboral> (ofertasDadasDeAlta->find(expe));

        // obtengo el dictionary de asignaturas de esa oferta
        IDictionary *asignaturasEnOferta = ol->getAsignaturas();
*/

        IDictionary *asignaturasEnOferta = new OrderedDictionary();
        //Solicitar Asignaturas
        cout<< "\nAsignaturas:";
        bool desea = true;
//        bool strategyOK = false;


//        ManejadorEstudiante *me = ManejadorEstudiante::getInstance();
        IEstudianteController* cEstudiante = fab->getIEstudianteController();
        IDictionary *asignaturasIngresadas = cEstudiante->getAsignaturas();

        //while (!strategyOK)
        //{
        while (desea)
        {
            // muestro asignaturas
            cout << "Lista de Asignaturas:\n";
            IIterator * it4 = asignaturasIngresadas->getIterator();
            while(it4->hasCurrent())
            {
                DataAsignatura *dAsignatura;
                if( (dAsignatura = dynamic_cast<DataAsignatura*> (it4->getCurrent())) != NULL )
                {
                    cout << "CODIGO: " << dAsignatura->getCodigo() << ", NOMBRE:" << dAsignatura->getNombre() << "\n";
                }
                else
                {
                    throw "AltaOfertaLaboral -> El objeto no es de la clase DataAsignatura.";
                }
                it4->next();
            }
            delete it4;

            // pido asignatura
            cout<< "\n  Ingrese el codigo: ";
            cin >> codAsig;
            Integer* codigo = new Integer(codAsig);

            // busco la asignatura
            if (asignaturasIngresadas->member(codigo))
            {
                // la agrego
                asignaturasEnOferta->add(codigo, asignaturasIngresadas->find(codigo));
            } else {
                throw "Codigo de Asignatura incorrecto.";
            }

            // seguir ingresando
            cout<< "\n  Desea ingresar otra asignatura?(s/n): ";
            cin >> respuesta;
            if(respuesta == "n")
            {
                desea = false;
            }
        }

        // strategy

        // aca hay que verificar los criterios del strategy y pedir que strategy usar
        bool encontro = false;
        IDictionary* estudiantes = cEstudiante->getEstudiantes();
        IIterator * it5 = estudiantes->getIterator();
        while(it5->hasCurrent())
        {
            Estudiante *student;
            if( (student = dynamic_cast<Estudiante*> (it5->getCurrent())) != NULL )
            {
                if(cEstudiante->EstudianteCumpleRequisitos(student, asignaturasEnOferta))
                {
                    encontro = true;
                }
            }
            else
            {
                throw "AltaOfertaLaboral -> El objeto no es de la clase Estudiante.";
            }
            it5->next();
        }
        delete it5;

        if(!encontro)
        {
            //Aplicar Estrategia
            int numCriterio;
            cout << "No existen Estudiantes que tengan aprobadas todas las Asignaturas ingresadas. Seleccione un criterio para obtener una lista de asignaturas validas(1 o 2)\n";
            cout << "1- Devolver las asignaturas aprobadas de algun estudiante.\n";
            cout << "2- Devolver una asignatura de las asignaturas ingresadas que algun estudiante haya aprobado(en caso de que no exista se devuelve el conjunto vacio).\n\n";
            cin >> numCriterio;

            if(numCriterio == 1)
            {
                Criterio1* critery1 = new Criterio1();
                cEmpresa->setCriterio(critery1);
                IDictionary* asignaturasSugeridas = cEmpresa->obtenerAsignaturasValidas(asignaturasEnOferta);
                cEmpresa->AltaOfertaLaboral(numExpe, titulo, descripcion, cantHorasSema, rangoSalarial, fechaComienzo, fechaFin, cantPuestos, asignaturasSugeridas);
            }
            else if(numCriterio == 2)
            {
                Criterio2* critery2 = new Criterio2();
                cEmpresa->setCriterio(critery2);
                IDictionary* asignaturasSugeridas = cEmpresa->obtenerAsignaturasValidas(asignaturasEnOferta);
                cEmpresa->AltaOfertaLaboral(numExpe, titulo, descripcion, cantHorasSema, rangoSalarial, fechaComienzo, fechaFin, cantPuestos, asignaturasSugeridas);
            }
            else
            {
                throw "El valor ingresado es incorrecto, ingrese 1 o 2.";
            }
        }
        else
        {
            cEmpresa->AltaOfertaLaboral(numExpe, titulo, descripcion, cantHorasSema, rangoSalarial, fechaComienzo, fechaFin, cantPuestos, asignaturasEnOferta);
        }

        //}

        //cEmpresa->altaOfertaLaboral(numExpe, titulo, descripcion, cantHorasSema, rangoSalarial, fechaComienzo, fechaFin, cantPuestos, asignaturasEnOferta);

    }
    catch (const char* e)
    {
    	throw;
    }


}

cmdAltaOfertaLaboral::~cmdAltaOfertaLaboral()
{
    //dtor
}
