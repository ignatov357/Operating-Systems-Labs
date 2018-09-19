#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREADS_NUMBER 10

void *print_thread(void *id);

int main(int argc, char *argv[]) {
    int status;
    pthread_t threads[THREADS_NUMBER];
    printf("Parallel case\n");
    for (long i = 0; i < THREADS_NUMBER; i++) {
        printf("Thread number is %d\n", i);
        status = pthread_create(&threads[i], NULL, print_thread, (void *) i);
        if (status != 0) exit(status);
    }
    // Wait until previous threads are finished
    pthread_join(threads[THREADS_NUMBER - 1], NULL);
    printf("Sequential case\n");
    for (long i = 0; i < THREADS_NUMBER; i++) {
        printf("Thread  number is %d\n", i);
        status = pthread_create(&threads[i], NULL, print_thread, (void *) i);
        pthread_join(threads[i], NULL);
        if (status != 0) exit(status);
    }
}
void *print_thread(void *id) {
    printf("thread №%ld\n", (long) id);
    pthread_exit(NULL);
}
