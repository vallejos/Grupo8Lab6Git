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
        ICollection *getEstudiante();
        IDictionary *getEstudiantes();
        destroyManejadorEstudiante();

    private:
        ~ManejadorEstudiante();
        ManejadorEstudiante();
        static ManejadorEstudiante *instance;
        IDictionary * estudiantes;
};

#endif // MANEJADORESTUDIANTE_H
