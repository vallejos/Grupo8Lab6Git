#include "cmdModificarEstudiante.h"
#include <iostream>
#include <string>
#include "Fabrica.h"
#include "IEstudianteController.h"
#include "DataEstudiante.h"

cmdModificarEstudiante::cmdModificarEstudiante()
{
    //ctor
}

void cmdModificarEstudiante::ejecutarComando()
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
                cout << "Fecha de Nacimiento: " + dEstudiante->getFechaNacimiento()->getDia() + "/" + dEstudiante->getFechaNacimiento()->getMes() + "/" + dEstudiante->getFechaNacimiento()->getAnio() + "Teléfono: " + dEstudiante->getTelefono() + "Créditos: " + dEstudiante->getCreditos() + "\n";
                cout << "Asignaturas Aprobadas:\n";
                ICollection *aprobadas = dEstudiante->getAprobadas();
                IIterator * it2 = aprobadas->getIterator();
                while(it2.hasCurrent())
                {
                    Aprobacion *aprobacion;
                    if( (aprobacion = dynamic_cast<Aprobacion*> (it2.current())) != NULL )
                    {
                        DataAsignatura* dasignatura = aprobacion->getDataAsignatura();
                        cout << "Código: " + dasignatura->getCedula() + "Nombre: " + dasignatura->getNombre() + "\n";
                        it2.next();
                    }else
                    {
                       throw std::invalid_argument("ModificarEstudiante -> El objeto no es de la clase Aprobacion.");
                    }
                }
                delete it2;
                it.next();

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
                it3.next();
            } else
            {
                throw std::invalid_argument("ModificarEstudiante -> El objeto no es de la clase DataEstudiante.");
            }
        }
        delete it;

        cout<< "Seleccione el Estudiante a modificar indicando la Cédula\n";
        cin >> cedula;

        cEstudiante->SeleccionarEstudiante(cedula);

        cout<< "Ingrese el nuevo Nombre\n";
        cin >> nombre;
        cout<< "Ingrese el nuevo Apellido\n";
        cin >> apellido;
        cout<< "Ingrese el nuevo Teléfono\n";
        cin >> telefono;

        cout<< "Ingrese la nueva Fecha de Nacimiento\n";
        cout<< "Ingrese el Día\n";
        cin >> dia;
        cout<< "Ingrese el Mes\n";
        cin >> mes;
        cout<< "Ingrese el Año\n";
        cin >> anio;
        Date *fechaNacimiento = Date(dia,mes,anio);

        cout<< "Ingrese la nueva cantidad de Creditos\n";
        cin >> creditos;
        cout<< "Ingrese el nuevo Email\n";
        cin >> email;
        //Me falta leer las asignaturas nuevas y las carreras nuevas, me sobran parámetros en DataEstudiante

        DataEstudiante *nuevosDatos = DataEstudiante(cedula, nombre, apellido, telefono, fechaNacimiento, creditos, email, carreras, aprobadas, inscripciones, entrevistas);

        cEstudiante->ModificarEstudiante(cedula,nuevosDatos);

    }
    catch(const std::invalid_argument &e)
    {
    	throw std::invalid_argument(e.what());
    }

}

cmdModificarEstudiante::~cmdModificarEstudiante()
{
    //dtor
}
