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
    string cedula, auxCreditos, auxNombre, auxApellido, auxTelefono, auxEmail, nombre, apellido, telefono, email, auxFechaNac, Nom, Apell;
    int creditos;
    string codigoAsig, codigoAsig2, codigoCarrera, codigoCarrera2, auxAsig, auxAsig2, auxCarrera, auxCarrera2;
    int dd, mm, aaaa, notaAprob, dia, mes, anio;
    Date *fechaNacimiento;
    Fabrica* fab = Fabrica::getInstance();
    IEstudianteController *cEstudiante = fab->getIEstudianteController();

    try
    {
        IDictionary* estudiantes = cEstudiante->ListarEstudiantesRegistrados();

        cout << "\nLista de Estudiantes del Sistema:";

        IIterator * it = estudiantes->getIterator();
        ICollection *aprobadas;
        DataEstudiante *dEstudiante;
        
        while(it->hasCurrent())
        {
            if( (dEstudiante = dynamic_cast<DataEstudiante*> (it->getCurrent())) != NULL )
            {
                cout << "\n\n---------------------------------\n";
                cout << "Cedula: " << dEstudiante->getCedula() << ", Nombre: " << dEstudiante->getNombre() << ", Apellido: " << dEstudiante->getApellido() << "\n";
                cout << "Fecha de Nacimiento: " << dEstudiante->getFechaNacimiento()->getDia() << "/" << dEstudiante->getFechaNacimiento()->getMes() << "/" << dEstudiante->getFechaNacimiento()->getAnio() << ", Telefono: " << dEstudiante->getTelefono() << "\n";
                cout << "Email: " << dEstudiante-> getEmail() << ", Creditos: " << dEstudiante->getCreditos() << "\n";

                cout << "\nCarreras del Estudiante:\n\n";
                IDictionary *carreras = dEstudiante->getCarreras();
                if (carreras->isEmpty()) {
                    cout << "- No hay Carreras asociadas al Estudiante.\n\n";
                } else {
                    IIterator * it3 = carreras->getIterator();
                    while(it3->hasCurrent())
                    {
                        Carrera *carrera;
                        if( (carrera = dynamic_cast<Carrera*> (it3->getCurrent()) ) != NULL )
                        {
                            cout << "Codigo: " << carrera->getCodigo() << ", Nombre: " << carrera->getNombreCarrera() << "\n";
                            it3->next();
                        }else
                        {
                           throw "ModificarEstudiante -> El objeto no es de la clase Carrera.";
                        }
                    }
                    delete it3;
                }
                it->next();
            } else
            {
                throw "ModificarEstudiante -> El objeto no es de la clase DataEstudiante.";
            }
        }
        delete it;

        //Lectura de Datos a Modificar
        cout<< "Seleccione el Estudiante a modificar indicando la Cedula\n";
        cin >> cedula;

        cEstudiante->SeleccionarEstudiante(cedula, estudiantes);

        cout<< "Desea Modificar el Nombre <s,n>?\n";
        cin >> auxNombre;
        if (auxNombre.compare("s") == 0)
        {
            cout<< "Ingrese el nuevo Nombre\n";
            cin >> nombre;
            getline(cin, Nom);
            nombre += Nom;
        }
        else
        {
            nombre = "";
        }

        cout<< "Desea Modificar el Apellido <s,n>?\n";
        cin >> auxApellido;
        if (auxApellido.compare("s") == 0)
        {
            cout<< "Ingrese el nuevo Apellido\n";
            cin >> apellido;
            getline(cin, Apell);
            apellido += Apell;
        }
        else
        {
            apellido = "";
        }

        cout<< "Desea Modificar el Telefono <s,n>?\n";
        cin >> auxTelefono;
        if (auxTelefono.compare("s") == 0)
        {
            cout<< "Ingrese el nuevo Telefono\n";
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
            cout<< "Ingrese la nueva Fecha de Nacimiento (dd mm aaaa)\n";
            cin >> dia >> mes >> anio;
            fechaNacimiento = new Date(dia,mes,anio);
        }
        else
        {
            fechaNacimiento = NULL;
        }

        cout<< "Desea Modificar los Creditos <s,n>?\n";
        cin >> auxCreditos;
        if (auxCreditos.compare("s") == 0)
        {
            cout<< "Ingrese la nueva cantidad de Creditos\n";
            cin >> creditos;
        }
        else
        {
            creditos = 0;
        }

        cout<< "Desea Modificar el Email <s,n>?\n";
        cin >> auxEmail;
        if (auxEmail.compare("s") == 0)
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
        cout<< "Desea Agregar Asignaturas al Estudiante <s,n>?\n";
        cin>> auxAsig;
        if (auxAsig.compare("n") == 0)
                fin = true;
        while (!fin)
        {
            IIterator * ita = allAsignaturas->getIterator();
            while(ita->hasCurrent())
            {
                Asignatura *asig;
                if( (asig = dynamic_cast<Asignatura*> (ita->getCurrent())) != NULL )
                {
                    DataAsignatura* dasig = asig->getDataAsignatura();
                    cout << "Codigo: " << dasig->getCodigo() << ", Nombre: " << dasig->getNombre() 
                            << ", Creditos: " << dasig->getCreditos() << "\n";
                    ita->next();
                }else
                {
                   throw "ModificarEstudiante -> El objeto no es de la clase Carrera.";
                }
            }
            delete ita;
            cout<< "\nIngrese el Codigo de la Asignatura que desea Agregar\n";
            cin >> codigoAsig;
            cout<< "Ingrese la Fecha de Aprobacion de la Asignatura que desea Agregar (dd mm aaaa)\n";
            cin >> dd >> mm >> aaaa;
            Date *fechaAprob = new Date(dd,mm,aaaa);
            cout<< "Ingrese la Nota de Aprobacion de la Asignatura que desea Agregar\n";
            cin >> notaAprob;
            Integer *ca = new Integer(atoi(codigoAsig.c_str()));
            Asignatura *asignatura = dynamic_cast<Asignatura*> (allAsignaturas->find(ca));
            Aprobacion *aprob = new Aprobacion(fechaAprob, notaAprob, asignatura);
            aprobacionesAAgregar->add(aprob);
            cout<< "Desea Agregar otra Asignatura <s,n>?\n";
            cin>> auxAsig;
            if (auxAsig.compare("n") == 0)
                fin = true;
        }

        //Lectura de Asignaturas a Eliminar
        bool fin2 = false;
        IDictionary * asignaturasAEliminar = new OrderedDictionary();
        cout<< "Desea Eliminar Asignaturas del Estudiante <s,n>?\n";
        cin>> auxAsig2;
        if (auxAsig2.compare("n") == 0)
                fin2 = true;
        while (!fin2)
        {
            IIterator * itV = estudiantes->getIterator();

            while(itV->hasCurrent() && !fin2)
            {
                if( (dEstudiante = dynamic_cast<DataEstudiante*> (itV->getCurrent())) != NULL )
                {
                    aprobadas = dEstudiante->getAprobadas();
                    IIterator * itap = aprobadas->getIterator();
                    while(itap->hasCurrent())
                    {
                        Aprobacion *apro;
                        if( (apro = dynamic_cast<Aprobacion*> (itap->getCurrent())) != NULL )
                        {
                            DataAsignatura* das = apro->getDataAsignatura();
                            cout << "Codigo: " << das->getCodigo() << ", Nombre: " << das->getNombre()
                                    << ", Creditos: " << das->getCreditos() << "\n";
                            itap->next();
                        }else
                        {
                           throw "ModificarEstudiante -> El objeto no es de la clase Aprobacion.";
                        }
                    }
                    delete itap;

                    cout<< "Ingrese el Codigo de la Asignatura que desea Eliminar\n";
                    cin >> codigoAsig2;
                    Integer *ca2 = new Integer(atoi(codigoAsig2.c_str()));
                    asignaturasAEliminar->add(ca2,allAsignaturas->find(ca2));
                     cout<< "Desea Eliminar otra Asignatura <s,n>?\n";
            cin>> auxAsig2;
            if (auxAsig2.compare("n") == 0)
                fin2 = true;
                } else {
                    throw "ModificarEstudiante -> El objeto no es de la clase DataEstudiante.";
                }
            }
           
        }

        IDictionary *allCarreras = cEstudiante->getCarreras(); 

        //Lectura de Carreras a Agregar
        bool fin3 = false;
        IDictionary * carrerasAAgregar = new OrderedDictionary();
        cout<< "Desea Agregar Carreras al Estudiante <s,n>?\n";
        cin>> auxCarrera;
        if (auxCarrera.compare("n") == 0)
                fin3 = true;
        while (!fin3)
        {
            cout<< "Ingrese el Codigo de la Carrera que desea Agregar al Estudiante\n";
            cin >> codigoCarrera;
            Integer *cc = new Integer(atoi(codigoCarrera.c_str()));
            carrerasAAgregar->add(cc,allCarreras->find(cc));
            cout<< "Desea Agregar otra Carrera <s,n>?\n";
            cin>> auxCarrera;
            if (auxCarrera.compare("n") == 0)
                fin3 = true;
        }

        //Lectura de Carreras a Eliminar
        bool fin4 = false;
        IDictionary * carrerasAEliminar = new OrderedDictionary();
        cout<< "Desea Eliminar Carreras del Estudiante <s,n>?\n";
        cin>> auxCarrera2;
        if (auxCarrera2.compare("n") == 0)
                fin4 = true;
        while (!fin4)
        {
            cout<< "Ingrese el Codigo de la Carrera que desea Eliminar\n";
            cin >> codigoCarrera2;
            Integer *cc2 = new Integer(atoi(codigoCarrera2.c_str()));
            carrerasAEliminar->add(cc2,allCarreras->find(cc2));
            cout<< "Desea Eliminar otra Carrera <s,n>?\n";
            cin>> auxCarrera2;
            if (auxCarrera2.compare("n") == 0)
                fin4 = true;
        }

        cEstudiante->ModificarEstudiante(cedula, nombre, apellido, telefono, fechaNacimiento, creditos, email, aprobacionesAAgregar, asignaturasAEliminar, carrerasAAgregar, carrerasAEliminar);

        cout << "\n- Se ha modificado el Estudiante correctamente.\n\n";
    }
    catch (const char* e)
    {
    	throw;
    }
}

cmdModificarEstudiante::~cmdModificarEstudiante()
{
    //dtor
}
