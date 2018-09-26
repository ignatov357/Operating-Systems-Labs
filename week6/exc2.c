#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define LENGTH_OF_STRING 80

int main() {
    pid_t child_pid;
    char first_string[] = "FirstString", second_string[LENGTH_OF_STRING];
    int pipe_d[2];

    pipe(pipe_d);
    child_pid = fork();
    if (child_pid == 0) {
        read(pipe_d[0], second_string, sizeof(second_string));
        printf("Second string: %s\n", second_string);
        exit(0);
    } else {
        write(pipe_d[1], first_string, (strlen(first_string) + 1));
        printf("First string: %s\n", first_string);
    }
}
