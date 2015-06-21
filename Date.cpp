#include "Date.h"
#include <stdexcept>
#include <iostream>

using namespace std;

Date::Date() {
	this->dd = 1;
	this->mm = 1;
	this->aaaa = 1900;
};


Date::Date(int dd, int mm, int aaaa)
{
    //ctor
    if(dd>31 or dd<1)
        throw "Dia invalido";
    if(mm>12 or mm<1)
        throw "Mes invalido";
    if(aaaa<1900)
        throw "Año invalido";
    this->dd = dd;
    this->mm = mm;
    this->aaaa = aaaa;
};

Date::Date(const Date &d)
{
    this->dd = d.dd;
    this->mm = d.mm;
    this->aaaa = d.aaaa;
};

int Date::getDia()
{
    return this->dd;
};

int Date::getMes()
{
    return this->mm;
};

int Date::getAnio()
{
    return this->aaaa;
};

Date::~Date()
{
    //dtor
};
//
//// operadores
//Date Date::operator=(Date fecha) {
//    this->dd = fecha.dd;
//    this->mm = fecha.mm;
//    this->aaaa = fecha.aaaa;
//    return *this;
//};
