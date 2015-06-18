#ifndef OFERTALABORAL_H
#define OFERTALABORAL_H

#include <string>
#include "Date.h"
#include "Rango.h"
#include "DataOfertaLaboral.h"
#include "DataOfertaEmpresa.h"
#include "Seccion.h"
#include "interfaces/ICollection.h"
#include "interfaces/ICollectible.h"
#include "interfaces/IDictionary.h"

using namespace std;

class OfertaLaboral: public ICollectible
{
    public:
		OfertaLaboral();
        OfertaLaboral(string numExpediente, string titulo, string descripcion, int cantidadHorasSemanales, Rango *rangoSalarial, Date *fechaComienzo, Date *fechaFin, int cantidadPuestosNecesarios, IDictionary *asignaturas);
        OfertaLaboral(const OfertaLaboral &o);
        ~OfertaLaboral();

        // getters
        string getNumExpediente();
        string getTitulo();
        string getDescripcion();
        int getCantidadHorasSemanales();
        Rango *getRangoSalarial();
        Date *getFechaComienzo();
        Date *getFechaFin();
        int getCantidadPuestosNecesarios();
        Seccion* getSeccion();
        ICollection* getInscripciones();
        ICollection* getEntrevistas();
        IDictionary* getAsignaturas();
        DataOfertaLaboral *getDataOfertaLaboral();
        DataOfertaEmpresa *getDataOfertaLaboralEmpresa();

        // setters
        void setNumExpediente(string numExpediente);
        void setTitulo(string titulo);
        void setDescripcion(string descripcion);
        void setCantidadHorasSemanales(int cantidadHorasSemanales);
        void setRangoSalarial(Rango *rangoSalarial);
        void setFechaComienzo(Date *fechaComienzo);
        void setFechaFin(Date *fechaFin);
        void setCantidadPuestosNecesarios(int cantidadPuestosNecesarios);
        void setSeccion(Seccion* seccion);
        void setInscripciones(ICollection *inscripciones);
        void setEntrevistas(ICollection *entrevistas);
        void setAsignaturas(IDictionary *asignaturas);

        // otros metodos
        void AltaAsignacionCargo(Date* fechaEfectivizacion, int sueldo);
        void Inscripcion(Date *fechaInscripcion);
        void Entrevista(Date *fechaEntrevista);
        bool EsOferta(string numExpediente);
        bool EsActiva();

    private:
        string numExpediente;
        string titulo;
        string descripcion;
        int cantidadHorasSemanales;
        Rango *rangoSalarial;
        Date *fechaComienzo;
        Date *fechaFin;
        int cantidadPuestosNecesarios;
        Seccion * seccion; //Pseudoatributo para representar la asociación con una Seccion
        ICollection *inscripciones; //Pseudoatributo para representar la asociación con una colección de Incripcion
        ICollection *entrevistas; //Pseudoatributo para representar la asociación con una colección de Entrevistas
        IDictionary *asignaturas; //Pseudoatributo para representar la asociación con un diccionario de asignaturas
};

#endif // OFERTALABORAL_H
