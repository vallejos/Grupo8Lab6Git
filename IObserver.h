#ifndef IOBSERVER_H
#define	IOBSERVER_H

#include "interfaces/ICollectible.h"

class IObserver: public ICollectible
{
public:
    //Estudiante debe implementar enviarMail
    IObserver();
    virtual void enviarMail() = 0;
    virtual ~IObserver();
};

#endif	// IOBSERVER_H
