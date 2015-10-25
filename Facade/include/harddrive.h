#ifndef HARDDRIVE_H
#define HARDDRIVE_H

typedef struct _HardDrive HardDrive;

struct _HardDrive
{
	void (*read)(HardDrive*, long);
};

extern HardDrive* HardDrive_construct(void*);
extern void HardDrive_destruct(HardDrive*);

#endif
