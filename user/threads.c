#include "libc.h"
#include "threads.h"

long cloning(long* args){
	void (*fn)(void*) = (void (*)(void*))args[0];
	void *fn_args = (void*)args[1];
	
	long stack = (long)malloc(4096) + 4092;

	long id = clone(stack);
	if(id == 0){
		fn(fn_args);		
        free((void*)(stack - 4092));
		thread_exit(0);
	}else{
		return id;
	}
	return id;
}

int thread_create(void (*start_routine)(void*), void *args){
	long *cloning_args = malloc(8);

	cloning_args[0] = (long)start_routine;
	cloning_args[1] = (long)args;
	
	long ret = cloning(cloning_args);
	return ret;
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
