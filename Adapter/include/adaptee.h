#ifndef ADAPTEE_H
#define ADAPTEE_H

typedef struct _IAdaptee IAdaptee;
typedef struct _Adaptee Adaptee;

struct _IAdaptee
{
	long (*power)(IAdaptee*, int, int);
};

struct _Adaptee
{
	union
	{
		IAdaptee;
		IAdaptee iadaptee;
	};
};

extern Adaptee* constructAdaptee(void*);
extern void destructAdaptee(Adaptee*);

#endif
