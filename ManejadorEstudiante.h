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
		IDictionary *getEstNoInscriptos(); // No es Icollection por ser de dataEstudiante?
		IDictionary *getEstInscriptosEnOferta(); // No es Icollection por ser de dataEstudiante?
		void SeleccionarEstudiante(String cedula); // En diagrama de clases los seleccionar retornan datas
        int CantidadPosiblesInscriptos(IDictionary *dataAsignatura);//No es Icollection por ser de dataAsignatura?
        IDictionary *getEstudiante();// Lo mismo se traen datas
        ~ManejadorEstudiante();
    private:
        ManejadorEstudiante();
        static ManejadorEstudiante *instance;
        IDictionary * estudiantes;
};

#endif // MANEJADORESTUDIANTE_H
