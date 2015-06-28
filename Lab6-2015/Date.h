#ifndef DATE_H
#define DATE_H

using namespace std;

class Date
{
    public:
		Date();
        Date(int dd, int mm, int aaaa);
        Date(const Date &d);
        ~Date();
        int getDia();
        int getMes();
        int getAnio();

    private:
        int dd;
        int mm;
        int aaaa;
};

#endif // DATE_H
