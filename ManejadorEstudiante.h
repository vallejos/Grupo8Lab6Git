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
        void ModificarEstudiante(string cedula, DataEstudiante* nuevosDatos);
        ICollection *getEstudiante();
        IDictionary *getEstudiantes();
        IDictionary *getAsignaturas();
        IDictionary *getCarreras();
        destroyManejadorEstudiante();

    private:
        ~ManejadorEstudiante();
        ManejadorEstudiante();
        static ManejadorEstudiante *instance;
        IDictionary * estudiantes;
        IDictionary* asignaturas:
        IDictionary* carreras;
};

#endif // MANEJADORESTUDIANTE_H
