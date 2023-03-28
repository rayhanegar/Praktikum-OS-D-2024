#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int counter = 0;
pthread_t tid[4];
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

void *doSomeThing(void *arg)
{
    pthread_mutex_lock( &mutex1 );
    printf("\n Thread %d started, please wait...\n", counter);
    counter++;
    unsigned long i = 0;
    for (i = 0; i < (0xFFFFFFFF); i++)
        ;
    printf("\n Thread %d finished\n", counter);
    pthread_mutex_unlock( &mutex1 );
    return NULL;
}

int main(void)
{
    int i;
    for (i = 0; i < 4; i++)
        pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);
    for (i = 0; i < 4; i++)
        pthread_join(tid[i], NULL);

    return 0;
}