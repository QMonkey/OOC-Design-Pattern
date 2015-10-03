#ifndef IOBSERVER_H
#define IOBSERVER_H

typedef struct _IObserved IObserved;
typedef struct _IObserver IObserver;

struct _IObserved
{
	void (*registerObserver)(IObserved*, IObserver*);
	void (*notifyObservers)(IObserved*);
	void (*removeObserver)(IObserved*, IObserver*);
};

struct _IObserver
{
	void (*handle)(IObserver*);
};

#endif
