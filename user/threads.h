#ifndef _THREADS_H_
#define _THREADS_H__

#include "sys.h"

typedef struct{
	int threadId;
}thread_t;


int thread_create(thread_t* thread, void *(*start_routine)(void*), void *args);
int thread_exit();
int thread_join(thread_t *thread);
int thread_yield();

#endif

