#ifndef RANGO_H
#define RANGO_H

using namespace std;

class Rango
{
    public:
		Rango();
        Rango(int sueldoMinimo, int sueldoMaximo);
        Rango(const Rango &r);
        ~Rango();
        int getSueldoMinimo();
        int getSueldoMaximo();
    private:
        int sueldoMinimo;
        int sueldoMaximo;
};

#endif // RANGO_H
