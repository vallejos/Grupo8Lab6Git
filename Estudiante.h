#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "ICollectible.h"
#include "ICollection.h"
#include "IDictionary.h"
#include "List.h"
#include "OrderedDictionary.h"
#include "IObserver.h"
#include "Date.h"
#include "DataEstudiante.h"
#include "DataDatosEstudiante.h"
#include "String.h"
#include "Integer.h"

class Estudiante : public ICollectible, public IObserver
{
    public:

        Estudiante();
        Estudiante(string cedula, string nombre, string apellido, string telefono, Date* fechaNacimiento, Integer creditos,
                    string email, IDictionary* carreras, ICollection* aprobadas, ICollection* inscripciones, ICollection* entrevistas);
        Estudiante(const Estudiante &e);

        //getters
        string getCedula();
        string getNombre();
        string getApellido();
        string getTelefono();
        Date* getFechaNacimiento();
        Integer getCreditos();
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
        static void setCreditos(Integer creditos);
        static void setEmail(string email);
        static void setInscripciones(ICollection* inscripciones);
        static void setEntrevistas(ICollection* entrevistas);
        static void setCarreras(IDictionary* carreras);
        static void setAprobadas(ICollection* aprobadas);

        //operaciones particulares
        DataEstudiante* getDataEstudiante();
        bool EstNoInscripto(int numExpediente);
        void AsociarInscripcion(Inscripcion *insc);
        void AsociarEntrevista(Entrevista *ent);
        DataDatosEstudiante *getDataDatosEstudiante();
        void enviarMail(string numExpediente);

        ~Estudiante();
    protected:
    private:
        string cedula;
        string nombre;
        string apellido;
        string telefono;
        Date *fechaNacimiento;
        Integer creditos;
        string email;
        IDictionary *carreras;
        ICollection *aprobadas;
        ICollection *inscripciones;
        ICollection *entrevistas;
        ICollection *notificaciones;
};

#endif // ESTUDIANTE_H
