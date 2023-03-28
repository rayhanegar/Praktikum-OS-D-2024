#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

void *thread_function(void *dummyPtr) {
    pthread_mutex_lock( &mutex1 );
    counter++;
    pthread_mutex_unlock( &mutex1 );
}

int main() {
    pthread_t thread_id[100];
    int i, j;

    for(i=1; i <= 100; i++) {
    printf("Create thread %d\n", i);
    pthread_create( &thread_id[i], NULL, thread_function, NULL );
    }

    for(j=1; j <= 100; j++) {
        pthread_join( thread_id[j], NULL);
    }
    /* Now that all threads are complete I can print the final result. */
    /* Without the join I could be printing a value before all the threads */
    /* have been completed. */
    printf("Final counter value: %d\n", counter);
}
