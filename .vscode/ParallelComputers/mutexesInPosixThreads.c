/*
 * @Description: Mutexes In Posix Threads
 * @Author: aLittleMango
 * @Date: 2021-07-07 19:20:25
 * @LastEditTime: 2021-07-07 19:43:51
 * @FilePath: \VSCode-C\.vscode\ParallelComputers\mutexesInPosixThreads.c
 */

// To create a mutex:
#include <pthread.h>
pthread_mutex_t amutex = PTHREAD_MUTEX_INITIALIZER;
// or pthread_mutex_init(&amutex, NULL);

//To use it
int pthread_mutex_lock(amutex);
int pthread_mutex_unlock(amutex);

//To deallocate a mutex
int pthread_mutex_destroy(pthread_mutex_t *mutex);

//Multiple mutexes may be held, but can lead to problems:
/*
            thread1     thread2         
            lock(a)     lock(b)
            lock(b)     lock(a)     
*/
