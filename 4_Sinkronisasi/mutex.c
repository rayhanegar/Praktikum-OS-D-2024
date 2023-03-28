#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;
void *increase() {
    pthread_mutex_lock( &mutex1 );
    int i;
    for(i=0; i<99999; i++) {
        counter++;
        printf("Counter value: %d\n",counter);      
    }
    pthread_mutex_unlock( &mutex1 );
}

void *decrease() {
    pthread_mutex_lock( &mutex1 );
    int i;
    for(i=0; i<99999; i++) {
        counter--;
        printf("Counter value: %d\n",counter);
    }
    pthread_mutex_unlock( &mutex1 );
}

int main() {
    int rc1, rc2;
    pthread_t thread1, thread2;
    /* Create independent threads each of which will execute increase */
    if( (rc1=pthread_create( &thread1, NULL, &increase, NULL)) ) {
        printf("Thread creation failed: %d\n", rc1);
    }

    /* Create independent threads each of which will execute decrease */
    if( (rc2=pthread_create( &thread2, NULL, &decrease, NULL)) ) {
    printf("Thread creation failed: %d\n", rc2);
    }

    /* Wait till threads are complete before main continues. Unless we */
    /* wait we run the risk of executing an exit which will terminate */
    /* the process and all threads before the threads have completed. */
    pthread_join( thread1, NULL);
    pthread_join( thread2, NULL);
    
    exit(EXIT_SUCCESS);
}
