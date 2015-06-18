#ifndef CMD_CONSULTARDATOSESTUDIANTES_H
#define CMD_CONSULTARDATOSESTUDIANTES_H


class cmdConsultarDatosEstudiantes : public IComando
{
    public:
        cmdConsultarDatosEstudiantes();
        void ejecutarComando();
        ~cmdConsultarDatosEstudiantes();
    protected:
    private:
};

#endif // CMD_CONSULTARDATOSESTUDIANTES_H
