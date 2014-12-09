#include "libc.h"
#include "threads.h"

int thread_create(void (*start_routine)(void*), void *args){
	long stack = (long)malloc(4096) + 4092;
	long id = clone(stack);
	if(id == 0){
		nop((long)start_routine);
		start_routine(args);	
		thread_exit(0);
	}else{
		return id;	
	}
	return -1;
}

int thread_exit(long exitCode){
	return exit(exitCode);	
}

int thread_join(long id){
	return join(id);
}

int thread_yield(){
	return yield();
}
