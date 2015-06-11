#ifndef IOBSERVER_H
#define	IOBSERVER_H

class IObserver: public ICollectible
{
public:
    //Estudiante debe implementar enviarMail
    virtual void enviarMail() = 0;
    virtual ~IObserver();
};

#endif	// IOBSERVER_H
