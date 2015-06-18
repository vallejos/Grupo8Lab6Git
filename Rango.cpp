#include "Rango.h"

Rango::Rango()
{

}

Rango::Rango(int sueldoMinimo, int sueldoMaximo)
{
    this->sueldoMinimo = sueldoMinimo;
    this->sueldoMaximo = sueldoMaximo;
}

Rango::Rango(const Rango &r)
{
//-------------------------
}

int Rango::getSueldoMinimo()
{
	return this->sueldoMinimo;
}

int Rango::getSueldoMaximo()
{
	return this->sueldoMaximo;
}

Rango::~Rango()
{

}
