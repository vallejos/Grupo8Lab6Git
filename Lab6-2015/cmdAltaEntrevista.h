#ifndef CMD_ALTAENTREVISTA_H
#define CMD_ALTAENTREVISTA_H

#include <exception>
#include "IComando.h"
#include <string>
#include <iostream>
#include "IOfertaLaboralController.h"
#include "interfaces/ICollection.h"
#include "interfaces/IDictionary.h"
#include "DataOfertaLaboral.h"
#include "Fabrica.h"
#include "Date.h"
#include "interfaces/IIterator.h"
#include "IEstudianteController.h"
#include "DataEstudiante.h"

class cmdAltaEntrevista : public IComando
{
    public:
        cmdAltaEntrevista();
        void ejecutarComando();
        ~cmdAltaEntrevista();
    private:
    protected:
};

#endif // CMD_ALTAENTREVISTA_H
