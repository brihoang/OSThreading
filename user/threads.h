#ifndef _THREADS_H_
#define _THREADS_H__

#include "sys.h"

int thread_create(void (*start_routine)(void*), void *args);
int thread_exit(long exitCode);
int thread_join(long id);
int thread_yield();

#endif

