#ifndef MANEJADORESTUDIANTE_H
#define MANEJADORESTUDIANTE_H

#include "DataEstudiante.h"
#include "DataAsignatura.h"
#include "IDictionary.h"
#include "String.h"

using namespace std;

class ManejadorEstudiante
{
    public:
		static ManejadorEstudiante *getInstance();
		IDictionary *getEstNoInscriptos();
		Estudiante *SeleccionarEstudiante(String cedula);
        int CantidadPosiblesInscriptos(IDictionary *DataAsignatura);
        IDictionary *getEstudiante();
        ~ManejadorEstudiante();
    private:
        ManejadorEstudiante();
        static ManejadorEstudiante *instance;
        IDictionary * estudiantes;
};

#endif // MANEJADORESTUDIANTE_H
