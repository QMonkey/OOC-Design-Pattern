#include <unistd.h>
#include <pthread.h>

#include <stdio.h>

#include "base.h"
#include "icommand.h"
#include "thread_pool.h"

typedef struct _Task
{
	union
	{
		ICommand;
		ICommand icommand;
	};
} Task;

void Task_execute(ICommand* icommand)
{
	printf("command, tid=%lu\n", pthread_self());
}

int main()
{
	ThreadPool* threadPool = new (ThreadPool, 10);

	Task task;
	task.execute = Task_execute;

	threadPool->start(threadPool);
	int i;
	for (i = 0; i < 20; ++i)
	{
		threadPool->execute(threadPool, &task.icommand);
	}

	sleep(3);
	threadPool->stop(threadPool);

	delete (ThreadPool, threadPool);
	return 0;
}
