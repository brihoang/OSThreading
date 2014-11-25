#include "libc.h"
#include "sys.h"
#include "threads.h"

int thread_create(thread_t *thread, void *(*start_routine)(void*), void *args){
	return 0;
}

int thread_exit(){
	return 0;
}

int thread_join(thread_t *thread){
	return 0;
}

int thread_yield(){
	return 0;
}
