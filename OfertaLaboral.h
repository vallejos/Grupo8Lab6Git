#ifndef OFERTALABORAL_H
#define OFERTALABORAL_H

#include "Date.h"
#include "Rango.h"
#include "DataOfertaLaboral.h"
#include "DataOfertaEmpresa.h"
#include "Seccion.h"
#include "ICollection.h"
#include "IDictionary.h"
#include "String.h"
#include "Integer.h"

using namespace std;

class OfertaLaboral
{
    public:
		OfertaLaboral();
        OfertaLaboral(String numExpediente, String titulo, String descripcion, Integer cantidadHorasSemanales, Rango *rangoSalarial, Date *fechaComienzo, Date *fechaFin, Integer cantidadPuestosNecesarios);
        OfertaLaboral(const OfertaLaboral &o);
        ~OfertaLaboral();
        String getNumExpediente();
        String getTitulo();
        String getDescripcion();
        Integer getCantidadHorasSemanales();
        Rango *getRangoSalarial();
        Date *getFechaComienzo();
        Date *getFechaFin();
        Integer getCantidadPuestosNecesarios();
        void setNumExpediente(String numExpediente);
        void setTitulo(String titulo);
        void setDescripcion(String descripcion);
        void setCantidadHorasSemanales(Integer cantidadHorasSemanales);
        void setRangoSalarial(Rango *rangoSalarial);
        void setFechaComienzo(Date *fechaComienzo);
        void setFechaFin(Date *fechaFin);
        void setCantidadPuestosNecesarios(Integer cantidadPuestosNecesarios);
        DataOfertaLaboral *getDataOfertaLaboral();
        DataOfertaEmpresa *getDataOfertaLaboralEmpresa();
        void Inscripcion(Date *fechaInscripcion);
        bool EsOferta(String numExpediente);
        bool EsActiva();

    private:
        String numExpediente;
        String titulo;
        String descripcion;
        Integer cantidadHorasSemanales;
        Rango *rangoSalarial;
        Date *fechaComienzo;
        Date *fechaFin;
        Integer cantidadPuestosNecesarios;
        Seccion * seccion; //Pseudoatributo para representar la asociación con una Seccion
        ICollection *inscripciones; //Pseudoatributo para representar la asociación con una colección de Incripcion
        IDictionary *asignaturas;
};

#endif // OFERTALABORAL_H
