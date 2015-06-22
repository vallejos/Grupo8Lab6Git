#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "interfaces/ICollectible.h"
#include "interfaces/ICollection.h"
#include "interfaces/IDictionary.h"
#include "collections/List.h"
#include "collections/OrderedDictionary.h"
#include "IObserver.h"
#include "Date.h"
#include "DataEstudiante.h"
#include "Aprobacion.h"
#include "Carrera.h"
#include "collections/OrderedDictionary.h"
#include "interfaces/IKey.h"
#include "Integer.h"

class DataDatosEstudiante;
class Inscripcion;
class Entrevista;

//class Estudiante : public ICollectible, public IObserver
// IObserver ya es ICollectible
//class Estudiante : public ICollectible
class Estudiante : public IObserver
{
    public:

        Estudiante();
        Estudiante(string cedula, string nombre, string apellido, string telefono, Date* fechaNacimiento, int creditos,
                    string email, IDictionary* carreras, ICollection* aprobadas, ICollection* inscripciones,
                    ICollection* entrevistas, ICollection* notificaciones);
        Estudiante(const Estudiante &e);

        //getters
        string getCedula();
        string getNombre();
        string getApellido();
        string getTelefono();
        Date* getFechaNacimiento();
        int getCreditos();
        string getEmail();
        IDictionary* getCarreras();
        ICollection* getAprobadas();
        ICollection* getInscripciones();
        ICollection* getEntrevistas();
        ICollection* getNotificaciones();

        //setters
        void setCedula(string cedula);
        void setNombre(string nombre);
        void setApellido(string apellido);
        void setTelefono(string telefono);
        void setFechaNacimiento(Date* fechaNacimiento);
        void setCreditos(int creditos);
        void setEmail(string email);
        void setInscripciones(ICollection* inscripciones);
        void setEntrevistas(ICollection* entrevistas);
        void setCarreras(IDictionary* carreras);
        void setAprobadas(ICollection* aprobadas);

        //operaciones particulares
        DataEstudiante* getDataEstudiante();
        bool EstNoInscripto(string numExpediente);
        bool EstInscripto(string numExpediente);
        void AsociarInscripcion(Inscripcion *insc);
        void AsociarEntrevista(Entrevista *ent);
        DataDatosEstudiante *getDataDatosEstudiante();
        void enviarMail(string numExpediente);

        ~Estudiante();

    private:
        string cedula;
        string nombre;
        string apellido;
        string telefono;
        Date *fechaNacimiento;
        int creditos;
        string email;
        IDictionary *carreras;
        ICollection *aprobadas;
        ICollection *inscripciones;
        ICollection *entrevistas;
        ICollection *notificaciones;
};

#include "Inscripcion.h"
#include "Entrevista.h"
#include "DataDatosEstudiante.h"

#endif // ESTUDIANTE_H
