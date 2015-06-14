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
                return new AltaOfertaLaboral();
				break;

			case 'AltaEntrevista':
                return new AltaEntrevista();
				break;
			case 'AsignacionDeOfertaAEstudiante':
                return new AsignacionDeOfertaAEstudiante();
				break;
			case 'ConsultarDatosEstudiantes':
                return new ConsultarDatosEstudiantes();
				break;
			case 'ListarOfertasActivas':
                return new ListarOfertasActivas();
				break;
			case 'ModificarEstudiante':
                return new ModificarEstudiante();
				break;
			case 'ModificarLlamado':
                return new ModificarLlamado();
				break;
			case 'DarDeBajaLlamado':
                return new DarDeBajaLlamado();
				break;
            case 'InscripcionOfertaLaboral':
                return new InscripcionOfertaLaboral();
				break;
    }
}

FabricaComando::~FabricaComando()
{
    //dtor
}
