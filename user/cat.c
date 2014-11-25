#include "libc.h"

int main(int argc, char** argv) {
	for(int i = 1; i < argc; i++){
		int fd = open(argv[i]);
		if(fd < 0){
			puts("cat: ");
			puts(argv[i]);
			puts(": No such file or directory\n");	
		}else{
			int length = getlen(fd);
			char* buf = malloc(length);
			readFully(fd, buf, length);
			for(int i = 0; i < length; i++){
				char current = buf[i];
				if(current != '\0')
					putchar(current);
			}	
			free(buf);
			close(fd);	
		}
	
	}
    return 0;
}
