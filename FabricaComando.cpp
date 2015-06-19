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
			case 'AltaOfertaLaboral':
                return new cmdAltaOfertaLaboral();
				break;
			case 'AltaEntrevista':
                return new cmdAltaEntrevista();
				break;
			case 'AsignacionDeOfertaAEstudiante':
                return new cmdAsignacionDeOfertaAEstudiante();
				break;
			case 'ConsultarDatosEstudiantes':
                return new cmdConsultarDatosEstudiantes();
				break;
			case 'ListarOfertasActivas':
                return new cmdListarOfertasActivas();
				break;
			case 'ModificarEstudiante':
                return new cmdModificarEstudiante();
				break;
			case 'ModificarLlamado':
                return new cmdModificarLlamado();
				break;
			case 'DarDeBajaLlamado':
                return new cmdDarDeBajaLlamado();
				break;
            case 'InscripcionOfertaLaboral':
                return new cmdInscripcionOfertaLaboral();
				break;
            case 'CargarDatosDePrueba':
                return new cmdCargarDatosDePrueba();
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
