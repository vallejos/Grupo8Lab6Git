#ifndef CMD_MODIFICARESTUDIANTE_H
#define CMD_MODIFICARESTUDIANTE_H


class cmdModificarEstudiante : public IComando
{
    public:
        cmdModificarEstudiante();
        void ejecutarComando();
        ~cmdModificarEstudiante();
    protected:
    private:
};

#endif // CMD_MODIFICARESTUDIANTE_H
