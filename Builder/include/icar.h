#ifndef ICAR_H
#define ICAR_H

typedef struct _ICar ICar;

struct _ICar
{
	void (*run)(ICar*);
	void (*show)(ICar*);
};

#endif
