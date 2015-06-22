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
    string rutEmpresa, nomSucursal, nomSeccion, descripcion, numExpe, titulo, title, respuesta, descAux;
    int cantHorasSema, cantPuestos, salMinimo, salMaximo, ddCom, ddFin, mmCom, mmFin, aaaaCom, aaaaFin, codAsig;
    Fabrica* fab = Fabrica::getInstance();
    IEmpresaController* cEmpresa = fab->getIEmpresaController();

    try
    {
        ICollection* dataEmpresas = cEmpresa->ListarEmpresas();

        cout << "\nLista de Empresas:\n";
        IIterator * it = dataEmpresas->getIterator();
        while(it->hasCurrent())
        {
            DataEmpresa *dEmpresa;
            if( (dEmpresa = dynamic_cast<DataEmpresa*> (it->getCurrent())) != NULL )
            {
                cout << "Nombre Empresa: " << dEmpresa->getNombre() << ", RUT:" << dEmpresa->getRut() << "\n";
            }
            else
            {
                throw "AltaOfertaLaboral -> El objeto no es de la clase DataEmpresa.";
            }
            it->next();
        }
        delete it;
        cout<< "\n  Seleccione una Empresa indicando el RUT: ";
        cin >> rutEmpresa;
        cEmpresa->SeleccionarEmpresa(rutEmpresa);


        ICollection* dataSucursales = cEmpresa->ListarSucursales();
        cout << "\n\nLista de Sucursales:\n";

        IIterator * it2 = dataSucursales->getIterator();
        while(it2->hasCurrent())
        {
            DataSucursal *dSucursal;
            if( (dSucursal = dynamic_cast<DataSucursal*> (it2->getCurrent())) != NULL )
            {
                cout << "Nombre Sucursal: " << dSucursal->getNombre() << ", Direccion: " << dSucursal->getDireccion() << ", Tel: " << dSucursal->getTelefono() << "\n";
            } else
            {
                throw "AltaOfertaLaboral -> El objeto no es de la clase DataSucursal.";
            }
            it2->next();
        }
        delete it2;

        cout<< "\n  Seleccione una Sucursal indicando el nombre: ";
        cin >> nomSucursal;
        cEmpresa->SeleccionarSucursal(nomSucursal);

        IDictionary* dataSecciones = cEmpresa->ListarSecciones();
        cout<< "\n\nLista de Secciones:\n";
        IIterator * it3 = dataSecciones->getIterator();
        while(it3->hasCurrent())
        {
            DataSeccion *dSeccion;
            if( (dSeccion = dynamic_cast<DataSeccion*> (it3->getCurrent())) != NULL )
            {
                cout << "Nombre Seccion: " << dSeccion->getNombre() << ", Interno: " << dSeccion->getInterno() << "\n";
            } else
            {
                throw "AltaOfertaLaboral -> El objeto no es de la clase DataSeccion.";
            }
            it3->next();
        }
        delete it3;

        cout<< "\n  Seleccione una Seccion indicando su nombre: ";
        cin >> nomSeccion;
        cEmpresa->SeleccionarSeccion(nomSeccion);

        cout<< "\n\nIngrese los datos correspondientes a la nueva Oferta Laboral\n";
        cout<< "\n";
        cout<< "Numero de expediente: ";
        cin >> numExpe;
        cout<< "Titulo: ";
        cin >> titulo;
        getline(cin, title);
        titulo += title;
        cout<< "Descripcion: ";
        cin >> descripcion;
        getline(cin, descAux);
        descripcion += descAux;
        cout<< "Cantidad de horas semanales: ";
        cin >> cantHorasSema;
        cout<< "Salario minimo: ";
        cin >> salMinimo;
        cout<< "Salario maximo: ";
        cin >> salMaximo;
        Rango* rangoSalarial = new Rango(salMinimo, salMaximo);
        cout<< "Fecha de comienzo(dd mm aaaa): ";
        cin >> ddCom >> mmCom >> aaaaCom;
        cout<< "Fecha de fin(dd mm aaaa): ";
        cin >> ddFin >> mmFin >> aaaaFin;
        Date* fechaComienzo = new Date(ddCom, mmCom, aaaaCom);
        Date* fechaFin = new Date(ddFin, mmFin, aaaaFin);
        cout<< "Cantidad de puestos necesarios: ";
        cin >> cantPuestos;

        IDictionary *asignaturasEnOferta = new OrderedDictionary();
        //Solicitar Asignaturas
        cout<< "Asignaturas: ";
        bool desea = true;
        
        IEstudianteController* cEstudiante = fab->getIEstudianteController();
        IDictionary *asignaturasIngresadas = cEstudiante->getAsignaturas();
        cout<< "\n  Desea ingresar una asignatura?(s/n): ";
        cin >> respuesta;
        if(respuesta == "n")
        {
            desea = false;
        }
        while (desea)
        {
            // muestro asignaturas
            cout << "\nLista de Asignaturas:\n";
            IIterator * it4 = asignaturasIngresadas->getIterator();
            while(it4->hasCurrent())
            {
                Asignatura *asign;
                if( (asign = dynamic_cast<Asignatura*> (it4->getCurrent())) != NULL )
                {
                    cout << "CODIGO: " << asign->getCodigo() << ", NOMBRE:" << asign->getNombre() << "\n";
                }
                else
                {
                    throw "AltaOfertaLaboral -> El objeto no es de la clase Asignatura.";
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
        
        bool encontro = false;
        IDictionary* estudiantes = cEstudiante->getEstudiantes();
        IIterator * it5 = estudiantes->getIterator();
        while(it5->hasCurrent() && !encontro)
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
            cout << "No existen Estudiantes que tengan aprobadas todas las Asignaturas ingresadas. \nSeleccione un criterio para obtener una lista de asignaturas validas(1 o 2)\n\n";
            cout << "1 - Devolver las asignaturas aprobadas de algun estudiante.\n";
            cout << "2 - Devolver una asignatura de las asignaturas ingresadas que algun estudiante haya aprobado(en caso de que no exista se devuelve el conjunto vacio).\n\n";
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
