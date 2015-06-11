#include "ManejadorEstudiante.h"

ManejadorEstudiante* ManejadorEstudiante::instance = NULL;

ManejadorEstudiante::ManejadorEstudiante()
{
    this->estudiantes=NULL;
}

ManejadorEstudiante ManejadorEstudiante::getInstance()
{
    //Se crea una instancia de ManejadorEstudiante.
    if(instance == NULL)
        instance = new ManejadorEstudiante();
    return instance;
}

IDictionary *ManejadorEstudiante::getEstNoInscriptos()
{
    //Se va a mover por la coleccion de estudiantes que el manejador conoce, pasando por las inscripciones de cada estudiante
    //y ofertas, para corroborar si están inscriptos o no
    //por cada estudiante no inscripto se crea un DataEstudiante para luego retornar un set de DataEstudiante.
}

void ManejadorEstudiante::SeleccionarEstudiante(String cedula)
{
    //Va a buscar en la coleccion de estudiantes no inscriptos que de alguna manera recordó el manejador,
    //y va a buscar el estudiante con cedula "cedula".
    return this->estudiantes->find(cedula);
}

int ManejadorEstudiante::CantidadPosiblesInscriptos(IDictionary *DataAsignatura)
{
    //La vamos a usar?
}

IDictionary *ManejadorEstudiante::getEstudiante()
{
    //Va a recorrer los estudiantes del sistema y por cada estudiante crea un DataEstudiante para luego retornar un set.
}

ManejadorEstudiante::~ManejadorEstudiante()
{

}
