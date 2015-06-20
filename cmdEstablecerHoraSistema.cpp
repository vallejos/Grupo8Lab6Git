#include <string>
#include <iostream>
#include "cmdListarNotificacionesEstudiante.h"
#include "Date.h"
#include "Tiempo.h"

using namespace std;

cmdEstablecerHoraSistema::cmdEstablecerHoraSistema()
{
    //ctor
}

// LA IDEA: no se si ta bien :(
void cmdEstablecerHoraSistema::ejecutarComando()
{
    cout << "¿Que fecha desea establecer en el sistema?: \n;
    cout << "1. la fecha de hoy \n";
    cout << "2. otra fecha \n";

    char opcion;
    cin >> opcion;

    Tiempo* t = Tiempo::getInstance();
    Date* fecha;
    int dd, mm, aaaa;

    switch (opcion)
    {
        case '1':
            fecha = t->now();
            dd = fecha->getDia();
            mm = fecha->getMes();
            aaaa = fecha->getAnio();
            t->setTiempo(dd, mm, aaaa);
            break;
        case '2':
            cout << "Indique la fecha (dd mm aaaa)\n";
            cin >> dd >> mm >> aaaa;
            t->setTiempo(dd, mm, aaaa);
            break;
    }
}

cmdEstablecerHoraSistema::~cmdEstablecerHoraSistema()
{
    //dtor
}
