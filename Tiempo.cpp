#include "Tiempo.h"

Tiempo* Tiempo::instance = NULL;

Tiempo::Tiempo()
{
    //ctor
    this->tiempoFijo = NULL;
    this->fijo = false;
}

Tiempo* Tiempo::getInstance()
{
    if(instance == NULL)
        instance = new Tiempo();
    return instance;
}

void Tiempo::setTiempo(int dd, int mm, int aaaa)
{
    if(this->tiempoFijo != NULL)
    {
        delete this->tiempoFijo;
    }
    this->tiempoFijo = new Date(dd, mm, aaaa);
    this->fijo = true;
}

Date* Tiempo::now()
{
    if(this->fijo)
    {
        return this->tiempoFijo;
    }
    else
    {
        time_t currentTime;
        struct tm *localTime;

        time( &currentTime );                   // Get the current time
        localTime = localtime( &currentTime );  // Convert the current time to the local time

        int Day    = localTime->tm_mday;
        int Month  = localTime->tm_mon + 1;
        int Year   = localTime->tm_year + 1900;

        return new Date(Day, Month, Year);
    }
}

Tiempo::~Tiempo()
{
    //dtor
    if(this->fijo)
    {
        delete this->tiempoFijo;
    }
    this->fijo=false;
}
