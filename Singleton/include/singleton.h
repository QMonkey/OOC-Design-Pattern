#ifndef SINGLETON_H
#define SINGLETON_H

typedef struct _Singleton Singleton;

struct _Singleton
{
	unsigned long currentTime;
};

extern Singleton* getSingleton();

#endif
