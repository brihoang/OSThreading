#include "libc.h"
#include "threads.h"

void test(void* args){
	puts("hello\n");
}



int main(){
	puts("hi in mainc \n");



	thread_create(test, (void*)0);
	




	

	return 0;
}
