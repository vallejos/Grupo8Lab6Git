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
    try{
        if(dd>31 or dd<1){
            throw std::invalid_argument("Dia invalido");
        }else{
            this->dd = dd;
        }

        if(mm>12 or mm<1){
            throw std::invalid_argument("Mes invalido");
        }else{
            this->mm = mm;
        }

        if(aaaa<1900){
            throw std::invalid_argument("Año invalido");
        }else{
            this->aaaa = aaaa;
        }
    }catch(const std::invalid_argument &e){
    	throw std::invalid_argument(e.what());
    }
};

Date::Date(const Date &d)
{
    this->dd = d.dd;
    this->mm = d.mm;
    this->aaaa = d.aaaa;
};

int Date::get_dd()
{
    return this->dd;
};

int Date::get_mm()
{
    return this->mm;
};

int Date::get_aaaa()
{
    return this->aaaa;
};

Date::~Date()
{
    //dtor
};

// operadores
Date Date::operator=(Date fecha) {
    this->dd = fecha.dd;
    this->mm = fecha.mm;
    this->aaaa = fecha.aaaa;
    return *this;
};
