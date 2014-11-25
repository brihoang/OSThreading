#include "libc.h"

void notFound(char* cmd) {
    puts(cmd);
    puts(": command not found\n");
}


int numTokens(char *toCount);
char **split(char *toSplit, int numWords);
//0 means equality
int equals(char* s1, char* s2);

int main() {
    while (1) {
        puts("shell> ");
        char* in = gets();
		int argc = numTokens(in);
		//ignore just whitespace
		if(argc == 0){
			free(in);
			continue;
		}
		
		char **argv = split(in, argc);
		char* cmd = argv[0];


		//open the file
		int fd = open(cmd);
		if(fd < 0)
			notFound(cmd);
		else{
			int length = getlen(fd);
			char* buf = malloc(length);
			readFully(fd, buf, length);
			
			//check if ELF file
			if(buf[0] != 0x7f || buf[1] != 'E' || buf[2] != 'L' || buf[3] != 'F'){
				for(int i = 0; i < length; i++){
					char current = buf[i];
					if(current != '\0')
						putchar(current);
				}	
			}else{ //execute elf file
				long id = fork();
				if(id == 0){
					execv(cmd, argv, argc);
					exit(0);
				}
				else
					join(id);
			}
			close(fd);	
			free(buf);
		}
			

        if (in) free(in);
    }

    return 0;
}

int equals(char* s1, char *s2){
	int counter = 0;

	while(s1[counter] == s2[counter]){
		if(s1[counter] == '\0')
			return 0;
		counter++;
	}
	return -1;
}

int numTokens(char* toSplit){
	int numWords = 0;

	char currentChar = toSplit[0];
	int firstIndex = 0;

	//ignore opening whitespace
	while(currentChar == '\t' || currentChar == ' ')
		currentChar = toSplit[++firstIndex];

	if(currentChar == '\0')
		return 0;

	toSplit = toSplit + firstIndex;
	int currentIndex = 0;

	//count number of words
	while(toSplit[currentIndex] != '\0'){
		numWords++;	
		currentIndex++;

		while(toSplit[currentIndex] != ' ' && toSplit[currentIndex] != '\t'
						&& toSplit[currentIndex] != '\0')
			currentIndex++;
		while(toSplit[currentIndex] == ' ' || toSplit[currentIndex] == '\t')
			currentIndex++;
						
	}
	return numWords;
	
}

char **split(char* toSplit, int numTokens){
	char currentChar = toSplit[0];
	int currentIndex = 0;
	char **ret;

	//ignore opening whitespace
	while(currentChar == '\t' || currentChar == ' ')
		currentChar = toSplit[++currentIndex];

	if(currentChar == '\0')
		return 0;

	toSplit = toSplit + currentIndex;
	currentIndex = 0;
	
	//load words into return array
	ret = malloc(numTokens * sizeof(char*));
	currentIndex = 0;
	int stringIndex = 0;
	//while(toSplit[currentIndex] != '\0'){
	for(int i = 0; i < numTokens; i++){
		int startIndex = currentIndex;
		currentIndex++;

		while(toSplit[currentIndex] != ' ' && toSplit[currentIndex] != '\t'
						&& toSplit[currentIndex] != '\0')
			currentIndex++;

		char *currentWord = malloc(currentIndex - startIndex + 1);
		currentWord[currentIndex - startIndex] = '\0';

		for(int i = 0; i < currentIndex - startIndex; i++){
			currentWord[i] = toSplit[startIndex + i];	
		}

		ret[stringIndex++] = currentWord;

		while(toSplit[currentIndex] == ' ' || toSplit[currentIndex] == '\t')
			currentIndex++;
						
	}

		
	return ret;
}
