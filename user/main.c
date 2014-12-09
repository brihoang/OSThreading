#include "libc.h"
#include "threads.h"

void test1(void* args);
void test2(void* args);
void test3(void* args);
void test4(void* args);
void test5(void* args);
void test6(void* args);

int global;

int main(){
    puts("testing threads\n");

    //test 1
    puts("basic thread create\n");
    long id = thread_create(test1, (void*)0);
    thread_join(id);
    puts("thread done!\n");

    //test 2
    char *word = "hello\n";
    puts(word);
    id = thread_create(test2, word);
    thread_join(id);
    puts("word has been changed!\n");
    puts(word);

    //test 3
    int ints[10] = { 0 };
    for(int i=0; i<10; i++) {
        putdec(ints[i]);
        puts(" ");
    }
    puts("\n");
    id = thread_create(test3, ints);
    thread_join(id);
    puts("ints has been changed\n");
    for(int i=0; i<10; i++) {
        putdec(ints[i]);
        puts(" ");
    }
    puts("\n");

    //test 4
    void** args = (void**)malloc(2*sizeof(void*));
    word = "word";
    int x = 1;
    args[0] = word;
    args[1] = &x;
    id = thread_create(test4, args);
    thread_join(id);

    //test 5
    global = 5;
    putdec(global);
    puts("\n");

    id = thread_create(test5, (void*)0);
    thread_join(id);

    putdec(global);
    puts("\n");    

    //test 6
    global = 0;
    id = thread_create(test6, (void*)0);
    thread_join(id);
    puts("main thread\n");

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

void test3(void* args){
    int *ints = (int*)args;

    ints[1] = 1;
}

void test4(void* args){
    char* word = ((char**)args)[0];
    int num = *((int**)args)[1];
    puts(word);
    puts(" ");
    putdec(num);
    puts("\n");
}

void test5(void* args){
    putdec(global);
    puts("\n");
    global = 4;
}

void test6(void* args){
    if(global >= 6)
        return;
    puts("thread ");
    putdec(global);
    puts("\n");
    global++;
    long id = thread_create(test6, (void*)0);
    thread_join(id);
}
