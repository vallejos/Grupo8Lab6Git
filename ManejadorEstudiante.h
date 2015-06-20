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
		IDictionary *getEstNoInscriptos(string numExpediente);
		IDictionary *getEstInscriptosEnOferta();
		Estudiante *SeleccionarEstudiante(string cedula);
        void ModificarEstudiante(string cedula, string nombre, string apellido, string telefono, Date *fechaNacimiento, int creditos, string email, IDictionary *asignaturasAAgregar, IDictionary *asignaturasAEliminar, IDictionary *carrerasAAgregar, IDictionary *carrerasAEliminar);
        IDictionary *getEstudiante();
        IDictionary *getEstudiantes();
        IDictionary *getAsignaturas();
        IDictionary *getCarreras();
        bool EstudianteCumpleRequisitos(Estudiante* student, IDictionary* asignaturasOferta);
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
