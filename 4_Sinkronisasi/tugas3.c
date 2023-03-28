#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int counter = 0;
pthread_t tid[4];

void *doSomeThing(void *arg)
{
    printf("\n Thread %d started, please wait...\n", counter);
    counter++;
    unsigned long i = 0;
    for (i = 0; i < (0xFFFFFFFF); i++)
        ;
    printf("\n Thread %d finished\n", counter);

    return NULL;
}

int main(void)
{
    int i;
    for (i = 0; i < 4; i++)
    {
        pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);
        pthread_join(tid[i], NULL);
    }
    for (i = 0; i < 4; i++)
        pthread_join(tid[i], NULL);
    return 0;
}