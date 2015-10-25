#include <stdio.h>

#include "harddrive.h"

static void HardDrive_read(HardDrive*, long);

HardDrive* HardDrive_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	HardDrive* harddrive = addr;
	harddrive->read = HardDrive_read;

	return harddrive;
}

void HardDrive_destruct(HardDrive* harddrive)
{
}

void HardDrive_read(HardDrive* harddrive, long position)
{
	printf("Harddrive load from position %ld!\n", position);
}
