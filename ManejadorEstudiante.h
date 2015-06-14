#ifndef MANEJADORESTUDIANTE_H
#define MANEJADORESTUDIANTE_H

#include "ICollection.h"
#include "IDictionary.h"
#include "Estudiante.h";
#include <string>

using namespace std;

class ManejadorEstudiante
{
    public:
		static ManejadorEstudiante *getInstance();
		ICollection *getEstNoInscriptos();
		ICollection *getEstInscriptosEnOferta();
		Estudiante *SeleccionarEstudiante(string cedula);
        int CantidadPosiblesInscriptos(ICollection *dataAsignatura);
        void ModificarEstudiante(string cedula, DataEstudiante* nuevosDatos);
        ICollection *getEstudiante();
        ~ManejadorEstudiante();
    private:
        ManejadorEstudiante();
        static ManejadorEstudiante *instance;
        IDictionary * estudiantes;
};

#endif // MANEJADORESTUDIANTE_H
