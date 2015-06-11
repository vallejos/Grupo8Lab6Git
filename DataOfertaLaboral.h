#ifndef DATAOFERTALABORAL_H
#define DATAOFERTALABORAL_H

#include "Date.h"
#include "Rango.h"
#include <string>

//No tengo claro si va creditosMinimos porque no estaba en el datatype original.
using namespace std;

class DataOfertaLaboral
{
    public:
		DataOfertaLaboral();
        DataOfertaLaboral(string numExpediente, string titulo, string descripcion, int cantidadHorasSemanales, Rango *rangoSalarial, Date *fechaComienzo, Date *fechaFin, int cantidadPuestosNecesarios, int creditosMinimos);
        DataOfertaLaboral(const DataOfertaLaboral &dol);
        ~DataOfertaLaboral();
        string getNumExpediente();
        string getTitulo();
        string getDescripcion();
        int getCantidadHorasSemanales();
        Rango *getRangoSalarial();
        Date *getFechaComienzo();
        Date *getFechaFin();
        int getCantidadPuestosNecesarios();
        int getCreditosMinimos();

    private:
        string numExpediente;
        string titulo;
        string descripcion;
        int cantidadHorasSemanales;
        Rango *rangoSalarial;
        Date *fechaComienzo;
        Date *fechaFin;
        int cantidadPuestosNecesarios;
        int creditosMinimos;
};

#endif // DATAOFERTALABORAL_H
