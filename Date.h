#ifndef DATE_H
#define DATE_H

using namespace std;

class Date
{
    public:
		Date();
        Date(int dia, int mes, int anio);
        Date(const Date &d);
        ~Date();
        int getDia();
        int getMes();
        int getAnio();
    private:
        int dia;
        int mes;
        int anio;
};

#endif // DATE_H
