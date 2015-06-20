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
#include "DataDatosEstudiante.h"

class Inscripcion;
class Entrevista;

//class Estudiante : public ICollectible, public IObserver
// IObserver ya es ICollectible
//class Estudiante : public IObserver
class Estudiante : public ICollectible
{
    public:

        Estudiante();
        Estudiante(string cedula, string nombre, string apellido, string telefono, Date* fechaNacimiento, int creditos,
                    string email, IDictionary* carreras, ICollection* aprobadas, ICollection* inscripciones, ICollection* entrevistas);
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
        static void setCedula(string cedula);
        static void setNombre(string nombre);
        static void setApellido(string apellido);
        static void setTelefono(string telefono);
        static void setFechaNacimiento(Date* fechaNacimiento);
        static void setCreditos(int creditos);
        static void setEmail(string email);
        static void setInscripciones(ICollection* inscripciones);
        static void setEntrevistas(ICollection* entrevistas);
        static void setCarreras(IDictionary* carreras);
        static void setAprobadas(ICollection* aprobadas);

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

#endif // ESTUDIANTE_H
