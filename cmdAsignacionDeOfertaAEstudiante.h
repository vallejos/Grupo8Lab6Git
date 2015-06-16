#ifndef CMD_ASIGNACIONDEOFERTAAESTUDIANTE_H
#define CMD_ASIGNACIONDEOFERTAAESTUDIANTE_H


class cmdAsignacionDeOfertaAEstudiante: public IComando
{
    public:
        cmdAsignacionDeOfertaAEstudiante();
        void ejecutarComando();
        ~cmdAsignacionDeOfertaAEstudiante();
    protected:
    private:
};

#endif // CMD_ASIGNACIONDEOFERTAAESTUDIANTE_H
