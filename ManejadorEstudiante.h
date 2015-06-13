#ifndef MANEJADORESTUDIANTE_H
#define MANEJADORESTUDIANTE_H

#include "DataEstudiante.h"
#include "DataAsignatura.h"
#include "IDictionary.h"
#include <string>

using namespace std;

class ManejadorEstudiante
{
    public:
		static ManejadorEstudiante *getInstance();
		IDictionary *getEstNoInscriptos(); // No es Icollection por ser de dataEstudiante?
		void SeleccionarEstudiante(string cedula); // En diagrama de clases los seleccionar retornan datas
        int CantidadPosiblesInscriptos(IDictionary *dataAsignatura);//No es Icollection por ser de dataAsignatura?
        IDictionary *getEstudiante();// Lo mismo se traen datas
        ~ManejadorEstudiante();
    private:
        ManejadorEstudiante();
        static ManejadorEstudiante *instance;
        IDictionary * estudiantes;
};

#endif // MANEJADORESTUDIANTE_H
