#include "libc.h"
#include "threads.h"

int main(){
	puts("hellow!!!");
	return 0;
}

void *print(void *args){
	putdec(((long*)args)[0]);
	return 0;
}

void test1(){
	thread_t t1;
	thread_t t2;

	char* arg1[1];
	char* arg2[1];

	arg1[0] = "THREAD 1";
	arg2[0] = "THREAD 2";
	thread_create(&t1, &print, (void*)arg1);
	thread_create(&t2, &print, (void*)arg2);
	thread_exit();

}
