#include "ModificarEstudiante.h"
#include <iostream>
#include <string>
#incluce "Fabrica.h"
#include "IEstudianteController.h"
#include "DataEstudiante.h"

ModificarEstudiante::ModificarEstudiante()
{
    //ctor
}

void ModificarEstudiante::ejecutarComando()
{
    string cedula;
    Fabrica* fab = Fabrica::getInstance();
    IEstudianteController *cEstudiante = fab->getIEstudianteController();

    try
    {
        ICollection* estudiantes = cEstudiante->ListarEstudiantesRegistrados();

        cout << "Lista de Estudiantes del Sistema:\n";

        IIterator * it = estudiantes->getIterator();
        while(it.hasCurrent())
        {
            DataEstudiante *dEstudiante;
            if( (dEstudiante = dynamic_cast<DataEstudiante*> (it.current())) != NULL )
            {
                cout << "Cédula: " + dEstudiante->getCedula() + "Nombre: " + dEstudiante->getNombre() + "Apellido: " + dEstudiante->getApellido() + "\n";
                cout << "Fecha de Nacimiento: " + dEstudiante->getFechaNacimiento()->getDia() + "/" + dEstudiante->getFechaNacimiento()->getMes() + "/" + dEstudiante->getFechaNacimiento()->getAnio() + "Teléfono: " + dEstudiante->getTelefono() + "Email: " + dEstudiante-> getEmail() + "Créditos: " + dEstudiante->getCreditos() + "\n";
                cout << "Asignaturas Aprobadas:\n";
                ICollection *aprobadas = dEstudiante->getAprobadas();
                IIterator * it2 = aprobadas->getIterator();
                while(it2.hasCurrent())
                {
                    Aprobacion *aprobacion;
                    if( (aprobacion = dynamic_cast<Aprobacion*> (it2.current())) != NULL )
                    {
                        DataAsignatura* dasignatura = aprobacion->getDataAsignatura();
                        cout << "Código: " + dasignatura->getCedula() + "Nombre: " + dasignatura->getNombre() + "Créditos: " + dasignatura->getCreditos() + "\n";
                        it2.next();
                    }else
                    {
                       throw std::invalid_argument("ModificarEstudiante -> El objeto no es de la clase Aprobacion.");
                    }
                }
                delete it2;


                cout << "Carreras del Estudiante:\n";
                IDictionary *carreras = dEstudiante->getCarreras();
                IIterator * it3 = carreras->getIterator();
                while(it3.hasCurrent())
                {
                    Carrera *carrera;
                    if( (carrera = dynamic_cast<Carrera*> (it3.current())) != NULL )
                    {
                        cout << "Código: " + carrera->getCodigo() + "Nombre: " + carrera->getNombreCarrera() + "\n";
                        it3.next();
                    }else
                    {
                       throw std::invalid_argument("ModificarEstudiante -> El objeto no es de la clase Carrera.");
                    }
                }
                delete it3;
                it.next();
            } else
            {
                throw std::invalid_argument("ModificarEstudiante -> El objeto no es de la clase DataEstudiante.");
            }
        }
        delete it;

        //Lectura de Datos a Modificar
        cout<< "Seleccione el Estudiante a modificar indicando la Cédula\n";
        cin >> cedula;

        cEstudiante->SeleccionarEstudiante(cedula);

        cout<< "Desea Modificar el Nombre SI o NO?\n";
        cin >> auxNombre;
        if (auxNombre == 'SI')
        {
            cout<< "Ingrese el nuevo Nombre\n";
            cin >> nombre;
        }
        else
        {
            nombre = 'NULL';
        }

        cout<< "Desea Modificar el Apellido SI o NO?\n";
        cin >> auxApellido;
        if (auxApellido == 'SI')
        {
            cout<< "Ingrese el nuevo Apellido\n";
            cin >> apellido;
        }
        else
        {
            apellido = 'NULL';
        }

        cout<< "Desea Modificar el Teléfono SI o NO?\n";
        cin >> auxTelefono;
        if (auxTelefono == 'SI')
        {
            cout<< "Ingrese el nuevo Teléfono\n";
            cin >> telefono;
        }
        else
        {
            telefono = 'NULL';
        }

        cout<< "Desea Modificar la Fecha de Nacimiento SI o NO?\n";
        cin >> auxFechaNac;
        if (auxFechaNac == 'SI')
        {
            cout<< "Ingrese el Día\n";
            cin >> dia;
            cout<< "Ingrese el Mes\n";
            cin >> mes;
            cout<< "Ingrese el Año\n";
            cin >> anio;
            Date *fechaNacimiento = Date(dia,mes,anio);
        }
        else
        {
            Date *fechaNacimiento = Date();
        }

        cout<< "Desea Modificar los Créditos SI o NO?\n";
        cin >> auxCreditos;
        if (auxCreditos == 'SI')
        {
            cout<< "Ingrese la nueva cantidad de Créditos\n";
            cin >> creditos;
        }
        else
        {
            creditos = 'NULL';
        }

        cout<< "Desea Modificar el Email SI o NO?\n";
        cin >> auxEmail;
        if (auxEmail == 'SI')
        {
            cout<< "Ingrese el nuevo Email\n";
            cin >> email;
        }
        else
        {
            email = 'NULL';
        }

        IDictionary *allAsignaturas = cEstudiante->getAsignaturas(); //La va a crear el negro en IEstidianteCrontroller

        //Lectura de Asignaturas a Agregar
        bool fin = false;
        while (!fin)
        {
            cout<< "Ingrese el Código de la Asignatura que desea Agregar al Estudiante ó OK si no desea Agregar mas Asignaturas \n";
            cin >> codigoAsig;
            if (codigoAsig == 'OK'){
                fin = true;
            }else
            {
                Asignatura *asignatura = allAsignaturas->find(codigoAsig);
                IDictionary * asignaturasAAgregar = add(codigoAsig,asignatura);
            }
        }

        //Lectura de Asignaturas a Eliminar
        bool fin2 = false;
        while (!fin2)
        {
            cout<< "Ingrese el Código de la Asignatura que desea Eliminar del Estudiante ó OK si no desea Eliminar mas Asignaturas \n";
            cin >> codigoAsig2;
            if (codigoAsig2 == 'OK'){
                fin2 = true;
            }else
            {
                Asignatura *asignatura = allAsignaturas->find(codigoAsig2);
                IDictionary * asignaturasAEliminar = add(codigoAsig2,asignatura);
            }
        }

        IDictionary *allCarreras = cEstudiante->getCarreras(); //La va a crear el negro en IEstidianteCrontroller

        //Lectura de Carreras a Agregar
        bool fin3 = false;
        while (!fin3)
        {
            cout<< "Ingrese el Código de la Carrera que desea Agregar al Estudiante ó OK si no desea Agregar mas Carreras \n";
            cin >> codigoCarrera;
            if (codigoCarrera == 'OK'){
                fin3 = true;
            }else
            {
                Carrera *carrera = allCarreras->find(codigoCarrera);
                IDictionary * carrerasAAgregar = add(codigoCarrera,carrera);
            }
        }

        //Lectura de Carreras a Eliminar
        bool fin4 = false;
        while (!fin4)
        {
            cout<< "Ingrese el Código de la Carrera que desea Eliminar del Estudiante ó OK si no desea Eliminar mas Carreras \n";
            cin >> codigoCarrera2;
            if (codigoCarrera2 == 'OK'){
                fin4 = true;
            }else
            {
                Carrera *carrera = allCarreras->find(codigoCarrera2);
                IDictionary * carrerasAEliminar = add(codigoCarrera2,carrera);

            }
        }

        cEstudiante->ModificarEstudiante(cedula, nombre, apellido, telefono, fechaNacimiento, creditos, email, asignaturasAAgregar, asignaturasAEliminar, carrerasAAgregar, carrerasAEliminar);

    }
    catch(const std::invalid_argument &e)
    {
    	throw std::invalid_argument(e.what());
    }

}

ModificarEstudiante::~ModificarEstudiante()
{
    //dtor
}
