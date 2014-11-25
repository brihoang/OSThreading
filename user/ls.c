#include "libc.h"

int main() {
	long fd = open(".");
	long length = getlen(fd);
	char* readBytes = malloc(length);
	readFully(fd, readBytes, length);
	for(int i = 0; i < length; i+=16){
		char* word = malloc(13);	
		
		word[12] = '\0';

		memcpy(word, readBytes + i, 12);
		
		puts(word);
		puts("\n");
		free(word);
	}
	free(readBytes);
	close(fd);
    return 0;
}
