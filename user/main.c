#include "libc.h"
#include "threads.h"

void test1(void* args);
void test2(void* args);

int main(){
    puts("testing threads\n");
    puts("basic thread create\n");

    long id = thread_create(test1, (void*)0);

    thread_join(id);
    puts("thread done!\n");

    char *word = "hello";
    puts(word);

    id = thread_create(test2, word);
    thread_join(id);

    puts("word has been changed!\n");

    puts(word);

    shutdown();
    return 0;
}

void test1(void* args){
    puts("thread\n");
}

void test2(void* args){
    char *word = (char*)args;

    word[0] = 'q';
}
