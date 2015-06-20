#include "FabricaComando.h"

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

IComando* FabricaComando::obtenerComando(string cmd)
{
    switch (cmd)
    {
			case 'cmdAltaOfertaLaboral':
                return new cmdAltaOfertaLaboral();
				break;
			case 'cmdAltaEntrevista':
                return new cmdAltaEntrevista();
				break;
			case 'cmdAsignacionDeOfertaAEstudiante':
                return new cmdAsignacionDeOfertaAEstudiante();
				break;
			case 'cmdConsultarDatosEstudiantes':
                return new cmdConsultarDatosEstudiantes();
				break;
			case 'cmdListarOfertasActivas':
                return new cmdListarOfertasActivas();
				break;
			case 'cmdModificarEstudiante':
                return new cmdModificarEstudiante();
				break;
			case 'cmdModificarLlamado':
                return new cmdModificarLlamado();
				break;
			case 'cmdDarDeBajaLlamado':
                return new cmdDarDeBajaLlamado();
				break;
            case 'cmdInscripcionOfertaLaboral':
                return new cmdInscripcionOfertaLaboral();
				break;
            case 'cmdCargarDatosDePrueba':
                return new cmdCargarDatosDePrueba();
                break;
            case 'cmdListarNotificacionesEstudiante':
                return new cmdListarNotificacionesEstudiante();
                break;
            case 'cmdEstablecerHoraSistema':
                return new cmdEstablecerHoraSistema();
                break;
    }
}

void FabricaComando::destroyFabricaComando()
{
    if (instance != NULL)
    {
        delete FabricaComando;
    }
}

FabricaComando::~FabricaComando()
{
    //destructor
    delete instance;
    instance = NULL;
}
