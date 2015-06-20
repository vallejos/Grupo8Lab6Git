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
		IDictionary *getEstInscriptosEnOferta(string numExpediente);
		Estudiante *SeleccionarEstudiante(string cedula);
        void ModificarEstudiante(string cedula, string nombre, string apellido, string telefono, Date *fechaNacimiento, int creditos, string email, ICollection *aprobacionesAAgregar, IDictionary *asignaturasAEliminar, IDictionary *carrerasAAgregar, IDictionary *carrerasAEliminar);
        IDictionary *getEstudiante();//obtiene un diccionario de DataEstudiantes
        IDictionary *getEstudiantes();
        IDictionary *getAsignaturas();
        IDictionary *getCarreras();
        bool EstudianteCumpleRequisitos(Estudiante* student, IDictionary* asignaturasOferta);
        bool PerteneceAsigACarrerasDeEst (IDictionary *carrerasDeEst, IDictionary *aprobacionesAAgregar);
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
