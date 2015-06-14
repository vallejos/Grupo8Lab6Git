#ifndef OFERTALABORAL_H
#define OFERTALABORAL_H

#include <string>
#include "Date.h"
#include "Rango.h"
#include "DataOfertaLaboral.h"
#include "DataOfertaEmpresa.h"
#include "Seccion.h"
#include "ICollection.h"
#include "ICollectible";
#include "IDictionary.h"

using namespace std;

class OfertaLaboral: public ICollectible
{
    public:
		OfertaLaboral();
        OfertaLaboral(string numExpediente, string titulo, string descripcion, int cantidadHorasSemanales, Rango *rangoSalarial, Date *fechaComienzo, Date *fechaFin, int cantidadPuestosNecesarios, IDictionary *asignaturas);
        OfertaLaboral(const OfertaLaboral &o);
        ~OfertaLaboral();
        string getNumExpediente();
        string getTitulo();
        string getDescripcion();
        int getCantidadHorasSemanales();
        Rango *getRangoSalarial();
        Date *getFechaComienzo();
        Date *getFechaFin();
        int getCantidadPuestosNecesarios();
        void setNumExpediente(string numExpediente);
        void setTitulo(string titulo);
        void setDescripcion(string descripcion);
        void setCantidadHorasSemanales(int cantidadHorasSemanales);
        void setRangoSalarial(Rango *rangoSalarial);
        void setFechaComienzo(Date *fechaComienzo);
        void setFechaFin(Date *fechaFin);
        void setCantidadPuestosNecesarios(int cantidadPuestosNecesarios);
        DataOfertaLaboral *getDataOfertaLaboral();
        DataOfertaEmpresa *getDataOfertaLaboralEmpresa();
        void Inscripcion(Date *fechaInscripcion);
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
        IDictionary *asignaturas;
};

#endif // OFERTALABORAL_H
