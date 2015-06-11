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
        Estudiante(String cedula, String nombre, String apellido, String telefono, Date* fechaNacimiento, Integer creditos,
                    String email, IDictionary* carreras, ICollection* aprobadas, ICollection* inscripciones);
        Estudiante(const Estudiante &e);

        //getters
        String getCedula();
        String getNombre();
        String getApellido();
        String getTelefono();
        Date* getFechaNacimiento();
        Integer getCreditos();
        String getEmail();
        IDictionary* getCarreras();
        ICollection* getAprobadas();
        ICollection* getInscripciones();

        //setters
        static void setCedula(String cedula);
        static void setNombre(String nombre);
        static void setApellido(String apellido);
        static void setTelefono(String telefono);
        static void setFechaNacimiento(Date* fechaNacimiento);
        static void setCreditos(Integer creditos);
        static void setEmail(String email);
        static void setInscripciones(ICollection* inscripciones);
        static void setCarreras(IDictionary* carreras);
        static void setAprobadas(ICollection* aprobadas);

        //operaciones particulares
        DataEstudiante* getDataEstudiante();
        bool EstNoInscripto(int numExpediente);
        void AsociarInscripcion(Inscripcion *insc);
        DataDatosEstudiante *getDataDatosEstudiante();
        void enviarMail();

        ~Estudiante();
    protected:
    private:
        String cedula;
        String nombre;
        String apellido;
        String telefono;
        Date *fechaNacimiento;
        Integer creditos;
        String email;
        IDictionary *carreras;
        ICollection *aprobadas;
        ICollection *inscripciones;
};

#endif // ESTUDIANTE_H
