#include "Estudiante.h"

Estudiante::Estudiante()
{
    //ctor
    this->cedula = '\0';
    this->nombre = '\0';
    this->apellido = '\0';
    this->telefono = '\0';
    this->fechaNacimiento = NULL;
    this->creditos = 0;
    this->email = '\0';
    this->carreras = NULL;
    this->aprobadas= NULL;
    this->inscripciones = NULL;

}

Estudiante::Estudiante(String cedula,String nombre,String apellido, String telefono, Date* fechaNacimiento, Integer creditos,
                        String email, IDictionary* carreras, ICollection* aprobadas, ICollection* inscripciones)
{
    this->cedula = cedula;
    this->nombre = nombre;
    this->apellido = apellido;
    this->telefono = telefono;
    this->fechaNacimiento = fechaNacimiento;
    this->creditos = creditos;
    this->email = email;
    this->carreras = carreras;
    this->aprobadas = aprobadas;
    this->inscripciones = inscripciones;
}

Estudiante::Estudiante(const Estudiante &e)
{
    this->cedula = e.cedula;
    this->nombre = e.nombre;
    this->apellido = e.apellido;
    this->telefono = e.telefono;
    this->fechaNacimiento = e.fechaNacimiento;
    this->creditos = e.creditos;
    this->email = e.email;
    //falta carreras, aprobadas e inscripciones pero es al pedo xq no lo vamos a usar
}

String Estudiante::getCedula()
{
    return this->cedula;
}

String Estudiante::getNombre()
{
    return this->nombre;
}

String Estudiante::getApellido()
{
    return this->apellido;
}

String Estudiante::getTelefono()
{
    return this->telefono;
}

Date* Estudiante::getFechaNacimiento()
{
    return this->fechaNacimiento;
}

Integer Estudiante::getCreditos()
{
    return this->creditos;
}

String Estudiante::getEmail()
{
    return this->email;
}

List* Estudiante::getCarreras()
{
    return this->carreras;
}

List* Estudiante::getAprobadas()
{
    return this->aprobadas;
}

void Estudiante::setCedula(String cedula)
{
    this->cedula = cedula;
}

void Estudiante::setNombre(String nombre)
{
    this->nombre = nombre;
}

void Estudiante::setApellido(String apellido)
{
    this->apellido = apellido;
}

void Estudiante::setTelefono(String telefono)
{
    this->telefono = telefono;
}

void Estudiante::setFechaNacimiento(Date* fechaNacimiento)
{
    this->fechaNacimiento = fechaNacimiento;
}

void Estudiante::setCreditos(Integer creditos)
{
    this->creditos = creditos;
}

void Estudiante::setEmail(String email)
{
    this->email = email;
}

DataEstudiante* getDataEstudiante()
{

}

bool EstNoInscripto()
{

}

void AsociarInscripcion (Inscripcion *insc)
{
    this->inscripciones->add(insc);
}

DataDatosEstudiante *getDataDatosEstudiante()
{

}

void enviarMail(){

}

Estudiante::~Estudiante()
{
    //dtor
}
