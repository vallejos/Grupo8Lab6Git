#ifndef CMD_CARGARDATOSDEPRUEBA_H
#define CMD_CARGARDATOSDEPRUEBA_H

class cmdCargarDatosDePrueba: public IComando
{
    public:
        cmdCargarDatosDePrueba();
        void ejecutarComando();
        ~cmdCargarDatosDePrueba();
    protected:
    private:
};

#endif // CMD_CARGARDATOSDEPRUEBA_H
