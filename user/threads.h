#ifndef _THREADS_H_
#define _THREADS_H__

#include "sys.h"

long thread_create(void (*start_routine)(void*), void *args);
long thread_exit(long exitCode);
long thread_join(long id);
long thread_yield();

#endif

