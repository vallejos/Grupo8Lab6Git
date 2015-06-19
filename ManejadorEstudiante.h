#ifndef MANEJADORESTUDIANTE_H
#define MANEJADORESTUDIANTE_H

#include "interfaces/ICollection.h"
#include "interfaces/IDictionary.h"
#include "Estudiante.h"
#include <string>

using namespace std;

class ManejadorEstudiante
{
    public:
		static ManejadorEstudiante *getInstance();
		ICollection *getEstNoInscriptos(string numExpediente);
		ICollection *getEstInscriptosEnOferta();
		Estudiante *SeleccionarEstudiante(string cedula);
        void ModificarEstudiante(string cedula, string nombre, string apellido, string telefono, Date *fechaNacimiento, int creditos, string email, IDictionary *asignaturasAAgregar, IDictionary *asignaturasAEliminar, IDictionary *carrerasAAgregar, IDictionary *carrerasAEliminar);
        ICollection *getEstudiante();
        IDictionary *getEstudiantes();
        IDictionary *getAsignaturas();
        IDictionary *getCarreras();
        void destroyManejadorEstudiante();

    private:
        ~ManejadorEstudiante();
        ManejadorEstudiante();
        static ManejadorEstudiante *instance;
        IDictionary *estudiantes;
        IDictionary *asignaturas;
        IDictionary *carreras;
};

#endif // MANEJADORESTUDIANTE_H
