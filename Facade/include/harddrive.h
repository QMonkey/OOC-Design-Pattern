#ifndef HARDDRIVE_H
#define HARDDRIVE_H

typedef struct _HardDrive HardDrive;

struct _HardDrive
{
	void (*read)(HardDrive*, long);
};

extern HardDrive* constructHardDrive(void*);
extern void destructHardDrive(HardDrive*);

#endif
