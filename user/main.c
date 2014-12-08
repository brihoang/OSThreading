#include "libc.h"

int main(){
	puts("hi in mainc \n");
	void* stck = malloc(4096);
	stck = (void*)((long)stck);

	
	long id = clone((long)stck + 4092);



	if(id == 0){
		puts("child\n");
		puts("i am definitely in the child\n");
	}
	else
		puts("parent\n");
	

	return 0;
}
