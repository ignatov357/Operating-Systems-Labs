#include <stdio.h>
#include <pthread.h>

#define NUM 8
#define TRUE 1

long count = 0;
pthread_t p_cons[2];
char status_of_sleeping[2];


void *make_thread_working(void *id) {
    if ((long) id)
        printf("Consumer awoke\n");
    else
        printf("Producer awoke\n");
    status_of_sleeping[(long) id] = 0;
}

void *make_thread_sleeping(void *id) {
    if ((long) id)
        printf("Consumer is sleeping\n");
    else
        printf("Producer is sleeping\n");
    status_of_sleeping[(long) id] = 1;
    while (status_of_sleeping[(long) id] == 1) {}
}

void *producer(void *id) {
    while (TRUE) {
        if (count == NUM) {
            make_thread_sleeping(id);
        }

        count++;
        printf("By producer: %d\n", count);

        if (count == 1 && status_of_sleeping[1 - (long) id] == 1) make_thread_working((void *) 1);
    }
}

void *consumer(void *id) {
    while (TRUE) {
        if (count == 0) {
            make_thread_sleeping(id);
        }
        count--;
        printf("By consumer: %d\n", count);

        if (count == NUM - 1 && status_of_sleeping[1 - (long) id] == 1) make_thread_working((void *) 0);
    }
}


int main(void) {
    pthread_create(p_cons, NULL, producer, (void *) 0);
    status_of_sleeping[0] = 0;
    pthread_create(p_cons + 1, NULL, consumer, (void *) 1);
    status_of_sleeping[1] = 0;

    while (TRUE) {}
}

