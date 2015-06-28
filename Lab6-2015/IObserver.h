#ifndef IOBSERVER_H
#define	IOBSERVER_H

#include "interfaces/ICollectible.h"
#include <string>

using namespace std;

class IObserver: public ICollectible
{
public:
    //Estudiante debe implementar enviarMail
    IObserver();
    virtual void enviarMail(string numExpediente) = 0;
    virtual ~IObserver();
};

#endif	// IOBSERVER_H
