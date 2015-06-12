#ifndef DATAOFERTALABORAL_H
#define DATAOFERTALABORAL_H

#include "Date.h"
#include "Rango.h"
#include <string>
#include "ICollectible.h"

using namespace std;

class DataOfertaLaboral: public ICollectible
{
    public:
		DataOfertaLaboral();
        DataOfertaLaboral(string numExpediente, string titulo, string descripcion, int cantidadHorasSemanales, Rango *rangoSalarial, Date *fechaComienzo, Date *fechaFin, int cantidadPuestosNecesarios);
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

    private:
        string numExpediente;
        string titulo;
        string descripcion;
        int cantidadHorasSemanales;
        Rango *rangoSalarial;
        Date *fechaComienzo;
        Date *fechaFin;
        int cantidadPuestosNecesarios;
};

#endif // DATAOFERTALABORAL_H
