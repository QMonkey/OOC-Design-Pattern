#ifndef OBSERVER_H
#define OBSERVER_H

#include "iobserver.h"

typedef struct _Observer Observer;

struct _Observer
{
        IObserver iobserver;
};

extern Observer* newObserver();
extern Observer* constructObserver(void*);
extern void destructObserver(Observer*);
extern void deleteObserver(Observer*);

#endif
