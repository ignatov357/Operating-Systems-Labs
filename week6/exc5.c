#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>

#define TRUE 1

int main() {
    pid_t child_pid;
    child_pid = fork();
    if (child_pid == 0) {
        while (TRUE) {
            printf("I'm alive\n");
            fflush(stdout);
            sleep(1);
        }

    } else {
        sleep(10);
        kill(child_pid, SIGTERM);
    }
}
