#include "libc.h"

int main(){
	puts("hi in mainc \n");
	void* stck = malloc(4096);
	stck = (void*)((long)stck);

	
	long *array = malloc(sizeof(long)*3);
	long id = clone((long)stck + 4092);




	if(id == 0){
		putdec(array[0]);
		puts("\n");
		puts("child\n");
		puts("i am definitely in the child\n");
	}
	else{
		array[0] = 5;
		puts("parent\n");
	}
	

	return 0;
}
