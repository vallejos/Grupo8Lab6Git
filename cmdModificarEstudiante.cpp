#include "cmdModificarEstudiante.h"
#include <iostream>
#include <string>
#include "Fabrica.h"
#include "Aprobacion.h"
#include "IEstudianteController.h"
#include "DataEstudiante.h"
#include "interfaces/IDictionary.h"
#include "Integer.h"
#include "DataAsignatura.h"
#include "Carrera.h"
#include <stdlib.h>
#include "collections/List.h"
#include "collections/OrderedDictionary.h"

using namespace std;

cmdModificarEstudiante::cmdModificarEstudiante()
{
    //ctor
}

void cmdModificarEstudiante::ejecutarComando()
{
    string cedula, auxCreditos, auxNombre, auxApellido, auxTelefono, auxEmail, nombre, apellido, telefono, email, auxFechaNac;
    int creditos;
    string codigoAsig, codigoAsig2, codigoCarrera, codigoCarrera2;
    int dd, mm, aaaa, notaAprob, dia, mes, anio;
    Date *fechaNacimiento;
    Fabrica* fab = Fabrica::getInstance();
    IEstudianteController *cEstudiante = fab->getIEstudianteController();

    try
    {
        IDictionary* estudiantes = cEstudiante->ListarEstudiantesRegistrados();

        cout << "Lista de Estudiantes del Sistema:\n";

        IIterator * it = estudiantes->getIterator();
        while(it->hasCurrent())
        {
            DataEstudiante *dEstudiante;
            if( (dEstudiante = dynamic_cast<DataEstudiante*> (it->getCurrent())) != NULL )
            {
                cout << "Cédula: " << dEstudiante->getCedula() << "Nombre: " << dEstudiante->getNombre() << "Apellido: " << dEstudiante->getApellido() << "\n";
                cout << "Fecha de Nacimiento: " << dEstudiante->getFechaNacimiento()->getDia() << "/" << dEstudiante->getFechaNacimiento()->getMes() << "/" << dEstudiante->getFechaNacimiento()->getAnio() << "Teléfono: " << dEstudiante->getTelefono() << "Email: " << dEstudiante-> getEmail() << "Créditos: " << dEstudiante->getCreditos() << "\n";
                cout << "Asignaturas Aprobadas:\n";
                ICollection *aprobadas = dEstudiante->getAprobadas();
                IIterator * it2 = aprobadas->getIterator();
                while(it2->hasCurrent())
                {
                    Aprobacion *aprobacion;
                    if( (aprobacion = dynamic_cast<Aprobacion*> (it2->getCurrent())) != NULL )
                    {
                        DataAsignatura* dasignatura = aprobacion->getDataAsignatura();
                        cout << "Código: " << dasignatura->getCodigo() << "Nombre: " << dasignatura->getNombre() << "Créditos: " << dasignatura->getCreditos() << "\n";
                        it2->next();
                    }else
                    {
                       throw "ModificarEstudiante -> El objeto no es de la clase Aprobacion.";
                    }
                }
                delete it2;

                cout << "Carreras del Estudiante:\n";
                IDictionary *carreras = dEstudiante->getCarreras();
                IIterator * it3 = carreras->getIterator();
                while(it3->hasCurrent())
                {
                    Carrera *carrera;
                    if( (carrera = dynamic_cast<Carrera*> (it3->getCurrent()) ) != NULL )
                    {
                        cout << "Código: " << carrera->getCodigo() << "Nombre: " << carrera->getNombreCarrera() << "\n";
                        it3->next();
                    }else
                    {
                       throw "ModificarEstudiante -> El objeto no es de la clase Carrera.";
                    }
                }
                delete it3;
                it->next();
            } else
            {
                throw "ModificarEstudiante -> El objeto no es de la clase DataEstudiante.";
            }
        }
        delete it;

        //Lectura de Datos a Modificar
        cout<< "Seleccione el Estudiante a modificar indicando la Cédula\n";
        cin >> cedula;

        cEstudiante->SeleccionarEstudiante(cedula, estudiantes);

        cout<< "Desea Modificar el Nombre SI o NO?\n";
        cin >> auxNombre;
        if (auxNombre.compare("SI") != 0)
        {
            cout<< "Ingrese el nuevo Nombre\n";
            cin >> nombre;
        }
        else
        {
            nombre = "";
        }

        cout<< "Desea Modificar el Apellido SI o NO?\n";
        cin >> auxApellido;
        if (auxApellido.compare("SI") != 0)
        {
            cout<< "Ingrese el nuevo Apellido\n";
            cin >> apellido;
        }
        else
        {
            apellido = "";
        }

        cout<< "Desea Modificar el Teléfono SI o NO?\n";
        cin >> auxTelefono;
        if (auxTelefono.compare("SI") != 0)
        {
            cout<< "Ingrese el nuevo Teléfono\n";
            cin >> telefono;
        }
        else
        {
            telefono = "";
        }

        cout<< "Desea Modificar la Fecha de Nacimiento <s,n>?\n";
        cin >> auxFechaNac;
        if (auxFechaNac == "s")
        {
            cout<< "Ingrese el Día\n";
            cin >> dia;
            cout<< "Ingrese el Mes\n";
            cin >> mes;
            cout<< "Ingrese el Año\n";
            cin >> anio;
            fechaNacimiento = new Date(dia,mes,anio);
        }
        else
        {
            fechaNacimiento = NULL;
        }

        cout<< "Desea Modificar los Créditos SI o NO?\n";
        cin >> auxCreditos;
        if (auxCreditos.compare("SI") != 0)
        {
            cout<< "Ingrese la nueva cantidad de Créditos\n";
            cin >> creditos;
        }
        else
        {
            creditos = 0;
        }

        cout<< "Desea Modificar el Email SI o NO?\n";
        cin >> auxEmail;
        if (auxEmail.compare("SI") != 0)
        {
            cout<< "Ingrese el nuevo Email\n";
            cin >> email;
        }
        else
        {
            email = "";
        }

        IDictionary *allAsignaturas = cEstudiante->getAsignaturas();

        //Lectura de Asignaturas a Agregar
        bool fin = false;
        ICollection * aprobacionesAAgregar = new List();
        while (!fin)
        {
            cout<< "Ingrese el Código de la Asignatura que desea Agregar al Estudiante ó OK si no desea Agregar mas Asignaturas \n";
            cin >> codigoAsig;
            if (codigoAsig.compare("OK") != 0){
                fin = true;
            }else
            {
                cout<< "Ingrese la Fecha de Aprobación de la Asignatura que desea Agregar al Estudiante (dd mm aaaa)\n";
                cin >> dd >> mm >> aaaa;
                Date *fechaAprob = new Date(dd,mm,aaaa);
                cout<< "Ingrese la Nota de Aprobación de la Asignatura que desea Agregar al Estudiante\n";
                cin >> notaAprob;
                Integer *ca = new Integer(atoi(codigoAsig.c_str()));
                Asignatura *asignatura = dynamic_cast<Asignatura*> (allAsignaturas->find(ca));
                Aprobacion *aprob = new Aprobacion(fechaAprob, notaAprob, asignatura);
                aprobacionesAAgregar->add(aprob);
            }
        }

        //Lectura de Asignaturas a Eliminar
        bool fin2 = false;
        IDictionary * asignaturasAEliminar = new OrderedDictionary();
        while (!fin2)
        {
            cout<< "Ingrese el Código de la Asignatura que desea Eliminar del Estudiante ó OK si no desea Eliminar mas Asignaturas \n";
            cin >> codigoAsig2;
            if (codigoAsig2.compare("OK") != 0){
                fin2 = true;
            }else
            {
//                Asignatura *asignatura = allAsignaturas->find(codigoAsig2);
                Integer *ca2 = new Integer(atoi(codigoAsig2.c_str()));
                asignaturasAEliminar->add(ca2,allAsignaturas->find(ca2));
            }
        }

        IDictionary *allCarreras = cEstudiante->getCarreras(); //La va a crear el negro en IEstidianteCrontroller

        //Lectura de Carreras a Agregar
        bool fin3 = false;
        IDictionary * carrerasAAgregar = new OrderedDictionary();
        while (!fin3)
        {
            cout<< "Ingrese el Código de la Carrera que desea Agregar al Estudiante ó OK si no desea Agregar mas Carreras \n";
            cin >> codigoCarrera;
            if (codigoCarrera.compare("OK") != 0){
                fin3 = true;
            }else
            {
//                Carrera *carrera = allCarreras->find(codigoCarrera);
                Integer *cc = new Integer(atoi(codigoCarrera.c_str()));
                carrerasAAgregar->add(cc,allCarreras->find(cc));
            }
        }

        //Lectura de Carreras a Eliminar
        bool fin4 = false;
        IDictionary * carrerasAEliminar = new OrderedDictionary();
        while (!fin4)
        {
            cout<< "Ingrese el Código de la Carrera que desea Eliminar del Estudiante ó OK si no desea Eliminar mas Carreras \n";
            cin >> codigoCarrera2;
            if (codigoCarrera2.compare("OK") != 0){
                fin4 = true;
            }else
            {
//                Carrera *carrera = allCarreras->find(codigoCarrera2);
                Integer *cc2 = new Integer(atoi(codigoCarrera2.c_str()));
                carrerasAEliminar->add(cc2,allCarreras->find(cc2));
            }
        }

        cEstudiante->ModificarEstudiante(cedula, nombre, apellido, telefono, fechaNacimiento, creditos, email, aprobacionesAAgregar, asignaturasAEliminar, carrerasAAgregar, carrerasAEliminar);

    }
    catch(exception &e)
    {
        throw;
    }

}

cmdModificarEstudiante::~cmdModificarEstudiante()
{
    //dtor
}
