#include "FabricaComando.h"
#include "cmdAltaOfertaLaboral.h"
#include "cmdAltaEntrevista.h"
#include"cmdAsignacionDeOfertaAEstudiante.h"
#include "cmdConsultarDatosEstudiantes.h"
#include "cmdListarOfertasActivas.h"
#include "cmdModificarEstudiante.h"
#include "cmdModificarLlamado.h"
#include "cmdDarDeBajaLlamado.h"
#include "cmdInscripcionOfertaLaboral.h"
#include "cmdCargarDatosDePrueba.h"
#include "cmdListarNotificacionesEstudiante.h"
#include "cmdCargarDatosDePrueba.h"
#include "cmdEstablecerHoraSistema.h"
#include "cmdAnotarBorrarNotificaciones.h"

FabricaComando* FabricaComando::instance = NULL;

FabricaComando::FabricaComando()
{
    //ctor
}

FabricaComando *FabricaComando::getInstance()
{
    //Se crea una instancia de FabricaComando.
    if(instance == NULL)
        instance = new FabricaComando();
    return instance;
}

IComando* FabricaComando::obtenerComando(char cmd)
{
    IComando *c;
    switch (cmd)
    {
			case 'A':
                c = new cmdAltaOfertaLaboral();
                return c;
				break;
			case 'B':
                c = new cmdAltaEntrevista();
                return c;
				break;
			case 'C':
                c = new cmdAsignacionDeOfertaAEstudiante();
                return c;
				break;
			case 'D':
                c = new cmdConsultarDatosEstudiantes();
                return c;
				break;
			case 'E':
                c = new cmdListarOfertasActivas();
                return c;
				break;
			case 'F':
                c = new cmdModificarEstudiante();
                return c;
				break;
			case 'G':
                c = new cmdModificarLlamado();
                return c;
				break;
			case 'H':
                c = new cmdDarDeBajaLlamado();
                return c;
				break;
            case 'I':
                c = new cmdInscripcionOfertaLaboral();
                return c;
				break;
            case 'J':
                c = new cmdCargarDatosDePrueba();
                return c;
                break;
            case 'K':
                c = new cmdListarNotificacionesEstudiante();
                return c;
                break;
            case 'L':
                c = new cmdEstablecerHoraSistema();
                return c;
                break;
            case 'M':
                c = new cmdAnotarBorrarNotificaciones();
                return c;
                break;
    }
}

void FabricaComando::destroyFabricaComando()
{
    if (instance != NULL)
    {
        this->~FabricaComando();
    }
}

FabricaComando::~FabricaComando()
{
    //destructor
    delete instance;
    instance = NULL;
}
