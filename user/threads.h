#ifndef _LIBC_H_
#define _LIBC_H_

#include "sys.h"

int thread_create();
int thread_exit();
int thread_join(int tid);
int thread_yield();



