#ifndef ENCARGADO_H
#define ENCARGADO_H

#include <string>
#include "ICollection.h"
#include "Date.h"
#include "DataEncargado.h"

using namespace std;

class Encargado : public ICollectible
{
    private:
        string cedula;
        string nombre;
        string apellido;
        Date* fechaNacimiento;
    public:
        //operaciones
        Encargado();
        Encargado(string cedula, string nombre, string apellido, Date* fechaNacimiento);
        DataEncargado *getDataEncargado();
        //getters
        string getCedula();
        string getNombre();
        string getApellido();
        Date *getFechaNacimiento();
        //setters
        void setCedula(string cedula);
        void setNombre(string nombre);
        void setApellido(string apellido);
        void setFechaNacimiento(Date* fechaNacimiento);
        //destructor
        ~Encargado();
};

#endif // ENCARGADO_H
