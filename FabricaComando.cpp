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
				break;
			case 'B':
                c = new cmdAltaEntrevista();
				break;
			case 'C':
                c = new cmdAsignacionDeOfertaAEstudiante();
				break;
			case 'D':
                c = new cmdConsultarDatosEstudiantes();
				break;
			case 'E':
                c = new cmdListarOfertasActivas();
				break;
			case 'F':
                c = new cmdModificarEstudiante();
				break;
			case 'G':
                c = new cmdModificarLlamado();
				break;
			case 'H':
                c = new cmdDarDeBajaLlamado();
                return c;
				break;
            case 'I':
                c = new cmdInscripcionOfertaLaboral();
				break;
            case 'J':
                c = new cmdCargarDatosDePrueba();
                break;
            case 'K':
                c = new cmdListarNotificacionesEstudiante();
                break;
            case 'L':
                c = new cmdEstablecerHoraSistema();
                break;
            case 'M':
                c = new cmdAnotarBorrarNotificaciones();
                break;
    }
    return c;
}

void FabricaComando::destroyFabricaComando()
{
    if (instance != NULL)
    {
        delete instance;
        instance = NULL;
    }
}

FabricaComando::~FabricaComando()
{
    //destructor
}
