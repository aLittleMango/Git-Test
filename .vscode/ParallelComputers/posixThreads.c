/*
 * @Description: Forking posix threads
 * @Author: aLittleMango
 * @Date: 2021-07-07 16:41:09
<<<<<<< HEAD
 * @LastEditTime: 2021-07-08 15:14:22
=======
 * @LastEditTime: 2021-07-07 17:37:01
>>>>>>> b0008960bb2161f96e0dae7dc58ebf4d3fc88945
 * @FilePath: \VSCode-C\.vscode\ParallelComputers\posixThreads.c
 */
#include <stdio.h>
#include <pthread.h>
#include <omp.h>

int pthread_create(pthread_t *,
                   const pthread_attr_t *,
                   void *(*)(void *),
                   void *);
/*
errcode = pthread_create(&thread_id; &thread_attribute;
                         &thread_fun; &fun_arg);

• thread_id is the thread id or handle (used to halt, etc.)
• thread_attribute various attributes
    – Standard default values obtained by passing a NULL pointer
    – Sample attributes: minimum stack size, priority
• thread_fun the function to be run (takes and returns void*)
• fun_arg an argument can be passed to thread_fun when it starts
• errorcode will be set nonzero if the create operation fails
*/

//simple threading example
void* sayhello(void *foo){
    printf("Hello, world!\n");
    getchar();
    return NULL;
}

int main(){
<<<<<<< HEAD
    pthread_t threads[8];
    int tn;
    for (tn = 0; tn < 8; tn++)
    {
        pthread_create(&threads[tn], NULL, sayhello, NULL);
    }
    for ( tn = 0; tn < 8; tn++)
=======
    pthread_t threads[16];
    int tn;
    for (tn = 0; tn < 16; tn++)
    {
        pthread_create(&threads[tn], NULL, sayhello, NULL);
    }
    for ( tn = 0; tn < 16; tn++)
>>>>>>> b0008960bb2161f96e0dae7dc58ebf4d3fc88945
    {
        pthread_join(threads[tn], NULL);
    }
    return 0;
}


