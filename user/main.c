#include "libc.h"
#include "threads.h"

void test(void* args){
	for(int i = 0; i < 200; i++)
			puts("hello");
}

int main(){
	long id = thread_create(test, (void*)0);
	thread_join(id);
	for(int i = 0; i < 200; i++){
		putdec(i+1);
		puts("\n");
	}
	shutdown();
	return 0;
}
