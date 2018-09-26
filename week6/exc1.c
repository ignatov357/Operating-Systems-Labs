#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#define MAX_LENGTH_OF_STRING 80

int main() {
    char first_string[] = "String1", second_string[MAX_LENGTH_OF_STRING];
    int pipe_d[2];
    pipe(pipe_d);

    printf("First string: %s\n", first_string);
    write(pipe_d[1], first_string, (strlen(first_string) + 1));
    read(pipe_d[0], second_string, sizeof(second_string));
    printf("Second string: %s\n", second_string);
}
